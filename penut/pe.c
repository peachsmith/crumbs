#include "pe.h"

#include <windows.h>

#define PENUT_FORMAT_PE32 0x10B
#define PENUT_FORMAT_PE32_PLUS 0x20B

// based on the size of the table at
// https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#optional-header-data-directories-image-only
#define PENUT_MAX_DATA_DIRS 16

static const char *DATA_DIR_NAMES[PENUT_MAX_DATA_DIRS] = {
    "Export Table",
    "Import Table",
    "Resource Table",
    "Exception Table",
    "Certificate Table",
    "Base Relocation Table",
    "Debug",
    "Architecture",
    "Global Ptr",
    "TLS Table",
    "Load Config Table",
    "Bound Import",
    "IAT",
    "Delay Import Descriptor",
    "CLR Runtime Header",
    "Reserved"};

static FILE *open_file(const char *name, const char *mode)
{
    FILE *f;

#if (defined(__STDC_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ == 1) || \
    (defined(_WIN32) && !defined(_CRT_SECURE_NO_WARNINGS))
    if (fopen_s(&f, name, mode))
    {
        return NULL;
    }
#else
    f = fopen(name, mode);
    if (f == NULL)
    {
        return NULL;
    }
#endif

    return f;
}

#define read_dword_or_qword(i, field, file)                           \
    {                                                                 \
        if (i.opt.magic == PENUT_FORMAT_PE32)                         \
        {                                                             \
            fread(&(i.opt.field##_dword), sizeof(pe_dword), 1, file); \
        }                                                             \
        else                                                          \
        {                                                             \
            fread(&(i.opt.field##_qword), sizeof(pe_qword), 1, file); \
        }                                                             \
    }

void penut_open(const char *name)
{
    FILE *pe_file = open_file(name, "rb");
    if (pe_file == NULL)
    {
        fprintf(stderr, "failed to open executable file\n");
        return;
    }

    // PE sections:
    // MS-DOS Stub
    //   A small program inserted by the linker
    //   At location 0x3C, the stub contains the location of the signature
    //
    // Signature
    //   Located at the offset specified at 0x3C.
    //   Four bytes "PE\0\0"
    //
    // COFF File Header
    //   Immediately after the signature
    //   Offset Size   Field Description
    //   0      2      Machine
    //   2      2      NumberOfSections
    //   4      4      TimeDateStamp
    //   8      4      PointerToSymbolTable
    //   12     4      NumberOfSymbols
    //   16     2      SizeOfOptionalHeader
    //   18     2      Characteristics

    //------------------------------------------------------------------------
    // signature

    pe_dword sigLoc;
    pe_info info;
    fseek(pe_file, 0x3C, SEEK_SET);
    fread(&sigLoc, sizeof(pe_dword), 1, pe_file);
    fseek(pe_file, sigLoc, SEEK_SET);
    fread(info.signature, sizeof(char), 4, pe_file);
    if (info.signature[0] != 'P' ||
        info.signature[1] != 'E' ||
        info.signature[2] != '\0' ||
        info.signature[3] != '\0')
    {
        fprintf(stderr, "failed to read PE signature\n");
        fclose(pe_file);
        return;
    }
    printf("%-21s %12s\n", "Signature", info.signature);

    //------------------------------------------------------------------------
    // COFF header

    fread(&(info.coff.machine), sizeof(pe_word), 1, pe_file);
    fread(&(info.coff.num_sections), sizeof(pe_word), 1, pe_file);
    fread(&(info.coff.time_stamp), sizeof(pe_dword), 1, pe_file);
    fread(&(info.coff.symbol_table), sizeof(pe_dword), 1, pe_file);
    fread(&(info.coff.num_symbols), sizeof(pe_dword), 1, pe_file);
    fread(&(info.coff.opt_header_size), sizeof(pe_word), 1, pe_file);
    fread(&(info.coff.characteristics), sizeof(pe_word), 1, pe_file);

    printf("\nCOFF Header\n------------------------\n");

    printf("%-21s %12X\n", "Machine", info.coff.machine);
    printf("%-21s %12X\n", "NumberOfSections", info.coff.num_sections);
    printf("%-21s %12u\n", "TimeDateStamp", info.coff.time_stamp);
    printf("%-21s %12u\n", "PointerToSymbolTable", info.coff.symbol_table); // should be 0 because COFF debugging information is deprecated
    printf("%-21s %12u\n", "NumberOfSymbols", info.coff.num_symbols);       // should be 0 because COFF debugging information is deprecated
    printf("%-21s %12u\n", "SizeOfOptionalHeader", info.coff.opt_header_size);
    printf("%-21s %12s\n", "Executable", info.coff.characteristics & IMAGE_FILE_EXECUTABLE_IMAGE ? "yes" : "no");
    printf("%-21s %12s\n", "DLL", info.coff.characteristics & IMAGE_FILE_DLL ? "yes" : "no");

    //------------------------------------------------------------------------
    // optional header standard fields

    fread(&(info.opt.magic), sizeof(pe_word), 1, pe_file);
    fread(&(info.opt.major_link_ver), sizeof(pe_byte), 1, pe_file);
    fread(&(info.opt.minor_link_ver), sizeof(pe_byte), 1, pe_file);
    fread(&(info.opt.size_of_code), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.size_of_init_data), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.size_of_uninit_data), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.entry_point), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.base_of_code), sizeof(pe_dword), 1, pe_file);
    if (info.opt.magic == PENUT_FORMAT_PE32)
    {
        fread(&(info.opt.base_of_data), sizeof(pe_dword), 1, pe_file);
    }

    printf("\nOptional Header Standard Fields\n------------------------\n");

    printf("%-23s %12X\n", "Magic", info.opt.magic);
    printf("%-23s %12u\n", "MajorLinkerVersion", info.opt.major_link_ver);
    printf("%-23s %12u\n", "MinorLinkerVersion", info.opt.minor_link_ver);
    printf("%-23s %12u\n", "SizeOfCode", info.opt.size_of_code);
    printf("%-23s %12u\n", "SizeOfInitializedData", info.opt.size_of_init_data);
    printf("%-23s %12u\n", "SizeOfUninitializedData", info.opt.size_of_uninit_data);
    printf("%-23s %12X\n", "AddressOfEntryPoint", info.opt.entry_point);
    printf("%-23s %12X\n", "BaseOfCode", info.opt.base_of_code);
    if (info.opt.magic == PENUT_FORMAT_PE32)
    {
        printf("%-23s %12X\n", "BaseOfData", info.opt.base_of_data);
    }

    //------------------------------------------------------------------------
    // optional header Windows-specific fields

    read_dword_or_qword(info, image_base, pe_file);
    fread(&(info.opt.section_alignment), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.file_alignment), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.major_os_ver), sizeof(pe_word), 1, pe_file);
    fread(&(info.opt.minor_os_ver), sizeof(pe_word), 1, pe_file);
    fread(&(info.opt.major_image_ver), sizeof(pe_word), 1, pe_file);
    fread(&(info.opt.minor_image_ver), sizeof(pe_word), 1, pe_file);
    fread(&(info.opt.major_subsys_ver), sizeof(pe_word), 1, pe_file);
    fread(&(info.opt.minor_subsys_ver), sizeof(pe_word), 1, pe_file);
    fread(&(info.opt.win32_ver), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.size_of_image), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.size_of_headers), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.check_sum), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.subsystem), sizeof(pe_word), 1, pe_file);
    fread(&(info.opt.dll_characteristics), sizeof(pe_word), 1, pe_file);
    read_dword_or_qword(info, size_of_stack_reserve, pe_file);
    read_dword_or_qword(info, size_of_stack_commit, pe_file);
    read_dword_or_qword(info, size_of_heap_reserve, pe_file);
    read_dword_or_qword(info, size_of_heap_commit, pe_file);
    fread(&(info.opt.loader_flags), sizeof(pe_dword), 1, pe_file);
    fread(&(info.opt.num_rva_and_sizes), sizeof(pe_dword), 1, pe_file);

    printf("\nOptional Header Windows-Specific Fields\n------------------------\n");

    if (info.opt.magic == PENUT_FORMAT_PE32)
    {
        printf("%-28s %12X\n", "ImageBase", info.opt.image_base_dword);
    }
    else
    {
        printf("%-28s %12llX\n", "ImageBase", info.opt.image_base_qword);
    }
    printf("%-28s %12u\n", "SectionAlignment", info.opt.section_alignment);
    printf("%-28s %12u\n", "FileAlignment", info.opt.file_alignment);
    printf("%-28s %12u\n", "MajorOperatingSystemVersion", info.opt.major_os_ver);
    printf("%-28s %12u\n", "MinorOperatingSystemVersion", info.opt.minor_os_ver);
    printf("%-28s %12u\n", "MajorImageVersion", info.opt.major_image_ver);
    printf("%-28s %12u\n", "MinorImageVersion", info.opt.minor_image_ver);
    printf("%-28s %12u\n", "MajorSubsystemVersion", info.opt.major_subsys_ver);
    printf("%-28s %12u\n", "MinorSubsystemVersion", info.opt.minor_subsys_ver);
    printf("%-28s %12u\n", "Win32VersionValue", info.opt.win32_ver);
    printf("%-28s %12u\n", "SizeOfImage", info.opt.size_of_image);
    printf("%-28s %12u\n", "SizeOfHeaders", info.opt.size_of_headers);
    printf("%-28s %12u\n", "CheckSum", info.opt.check_sum);
    printf("%-28s %12u\n", "Subsystem", info.opt.subsystem);
    printf("%-28s %12u\n", "DllCharacteristics", info.opt.dll_characteristics);

    if (info.opt.magic == PENUT_FORMAT_PE32)
    {
        printf("%-28s %12u\n", "SizeOfStackReserve", info.opt.size_of_stack_reserve_dword);
    }
    else
    {
        printf("%-28s %12llu\n", "SizeOfStackReserve", info.opt.size_of_stack_reserve_qword);
    }

    if (info.opt.magic == PENUT_FORMAT_PE32)
    {
        printf("%-28s %12u\n", "SizeOfStackCommit", info.opt.size_of_stack_commit_dword);
    }
    else
    {
        printf("%-28s %12llu\n", "SizeOfStackCommit", info.opt.size_of_stack_commit_qword);
    }

    if (info.opt.magic == PENUT_FORMAT_PE32)
    {
        printf("%-28s %12u\n", "SizeOfHeapReserve", info.opt.size_of_heap_reserve_dword);
    }
    else
    {
        printf("%-28s %12llu\n", "SizeOfHeapReserve", info.opt.size_of_heap_reserve_qword);
    }

    if (info.opt.magic == PENUT_FORMAT_PE32)
    {
        printf("%-28s %12u\n", "SizeOfHeapCommit", info.opt.size_of_heap_commit_dword);
    }
    else
    {
        printf("%-28s %12llu\n", "SizeOfHeapCommit", info.opt.size_of_heap_commit_qword);
    }

    printf("%-28s %12u\n", "LoaderFlags", info.opt.loader_flags);
    printf("%-28s %12u\n", "NumberOfRvaAndSizes", info.opt.num_rva_and_sizes);

    pe_image_data_directory data_dirs[PENUT_MAX_DATA_DIRS];
    for (pe_dword i = 0; i < PENUT_MAX_DATA_DIRS && i < info.opt.num_rva_and_sizes; i++)
    {
        fread(&(data_dirs[i].address), sizeof(pe_dword), 1, pe_file);
        fread(&(data_dirs[i].size), sizeof(pe_dword), 1, pe_file);

        printf("%-28s %-7s %12X\n", DATA_DIR_NAMES[i], "address", data_dirs[i].address);
        printf("%-28s %-7s %12u\n", DATA_DIR_NAMES[i], "size", data_dirs[i].size);
    }

    fclose(pe_file);
}
