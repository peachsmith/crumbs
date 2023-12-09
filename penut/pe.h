#ifndef PENUT_PE_H
#define PENUT_PE_H

#include "penut.h"

// Sizes of C data types on Microsoft Windows:
// +---------------------+
// | Type          Size  |
// +---------------------+
// | char          1     |
// | short         2     |
// | int           4     |
// | long          4     |
// | long long     8     |
// | float         4     |
// | double        8     |
// | long double   8     |
// +---------------------+

typedef unsigned char pe_byte;
typedef unsigned short pe_word;
typedef unsigned int pe_dword;
typedef unsigned long long pe_qword;

typedef struct pe_image_data_directory
{
    pe_dword address;
    pe_dword size;
} pe_image_data_directory;

typedef struct pe_coff
{
    pe_word machine;
    pe_word num_sections;
    pe_dword time_stamp;
    pe_dword symbol_table;   // deprecated and should be 0
    pe_dword num_symbols;    // deprecated and should be 0
    pe_word opt_header_size; // required for image files, should be 0 for object files
    pe_word characteristics;
} pe_coff;

// +----------------------+
// | Magic Number  Format |
// +----------------------+
// | 0x10B         PE32   |
// | 0x20B         PE32+  |
// +----------------------+

typedef struct pe_opt
{
    //------------------------------------------------------------------------
    // standard fields
    pe_word magic;
    pe_byte major_link_ver;
    pe_byte minor_link_ver;
    pe_dword size_of_code;
    pe_dword size_of_init_data;
    pe_dword size_of_uninit_data;
    pe_dword entry_point;
    pe_dword base_of_code;
    pe_dword base_of_data; // for PE32+ format

    //------------------------------------------------------------------------
    // Windows-specific fields
    union
    {
        pe_dword image_base_dword;
        pe_qword image_base_qword;
    };
    pe_dword section_alignment; // must be greater than or equal to file_alignment
    pe_dword file_alignment;
    pe_word major_os_ver;
    pe_word minor_os_ver;
    pe_word major_image_ver;
    pe_word minor_image_ver;
    pe_word major_subsys_ver;
    pe_word minor_subsys_ver;
    pe_dword win32_ver;     // reserved, must be 0
    pe_dword size_of_image; // must be a multiple of section_alignment
    pe_dword size_of_headers;
    pe_dword check_sum;
    pe_word subsystem;
    pe_word dll_characteristics;
    union
    {
        pe_dword size_of_stack_reserve_dword;
        pe_qword size_of_stack_reserve_qword;
    };
    union
    {
        pe_dword size_of_stack_commit_dword;
        pe_qword size_of_stack_commit_qword;
    };
    union
    {
        pe_dword size_of_heap_reserve_dword;
        pe_qword size_of_heap_reserve_qword;
    };
    union
    {
        pe_dword size_of_heap_commit_dword;
        pe_qword size_of_heap_commit_qword;
    };
    pe_dword loader_flags; // reserved, must be 0
    pe_dword num_rva_and_sizes;
} pe_opt;

typedef struct pe_info
{
    char signature[4];
    pe_coff coff;
    pe_opt opt;
} pe_info;

void penut_open(const char *name);

#endif