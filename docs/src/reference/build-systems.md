# Build Systems

<!-- Before modm we used [SCons][] for both the HAL generation as well as compilation.
This worked great for us, however, 
made it very difficult to include our code into other build systems.
This was especially annoying for developers who  -->

modm is best tested with the [SCons][] build system, even though modm itself is 
build system agnostic.

<!-- This page describes how to use `lbuild` to automatically gather the data relevant
to generate the files required for your build system.

## Module metadata -->


## SCons

We use the [SCons build system][scons] to build and program your application.
We've [extended it with many utilities][scons_tools] to allow a smooth integration of embedded tools.
Include the [`modm:build.scons` module](module/modm-build-scons) to enable this.

You can use these command in all our examples to get a feel of how it works.

<!-- ### Common -->

```sh
 $ scons build       # Compiles your program into an executable.
 $ scons size        # Displays the static Flash and RAM consumption.
 $ scons program     # Writes the executable onto your target.
 $ scons             # maps to `scons build size`
 $ scons symbols     # the symbol table for your executable.
 $ scons listing     # Decompiles your executable into an annotated assembly listing.
 $ scons -c          # removes the build files.
 $ scons verbose=1   # Makes the printout more verbose.
```

<!-- - `optimization=[0,1,2,3,s]`: Forces compilation with specified optimization level. Can be used for debug builds. -->


<!-- ### AVR only:

- `fuse`: Writes the fuse bits onto your target.
- `eeprom`: Writes the EEPROM memory onto your target.

### ARM Cortex-M only:

- `debug`: Starts the GDB debug session of your current application in text UI mode.  
           You must execute `openocd-debug` or `lpclink-debug` before running this command!
- `openocd-debug`: Starts the OpenOCD debug server for your target.
- `lpclink-debug`: Starts the LPC-Link debug server for your target.
- `lpclink-init`: Initialize the LPC-Link with its proprietary firmware. -->


## CMake

You can also use [CMake][] to build and program your application.
Include the [`modm:build.cmake` module](module/modm-build-cmake) to enable this.
This module ships with a Makefile that wraps all of the cmake commands, so you
can use these commands:

```sh
 $ make                # Generates CMake files and compiles your program into an executable.
 $ make build-release  # Compiles your program into an executable.
 $ make build-debug    # Compiles your program into a debugable executable.
 $ make upload-release # Writes the executable onto your target.
 $ make upload-debug   # Writes the debugable executable onto your target.
 $ make gdb            # starts a debug session for the debugable executable.
```

[cmake]: https://cmake.org
[scons]: http://scons.org
[scons_tools]: https://github.com/modm-io/scons-build-tools