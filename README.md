# crumbs
An interface for game programming.
<br/>
This mainly functions as an exercise in API design.

## Building the Reference Implementation on Linux
Requires GNU autotools

Copy the build files from the build directory.
```
cp build/* .
./autogen.sh
```

Configure the release build
```
./configure
```
or configure the debug build
```
./configure CPPFLAGS=-DDEBUG CFLAGS="-g -O0"
```

build and install
```
make
sudo make install
```
<br/>

## Debugging the Demo Application

Example launch.json for VS Code on Linux:
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "cwd": "${workspaceFolder}/demo/Makefiles/linux",
            "name": "(gdb) Attach",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/demo/Makefiles/linux/demo.out",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Set Disassembly Flavor to Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ]
        }

    ]
}
```
