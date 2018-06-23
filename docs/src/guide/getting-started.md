# Getting Started

The easiest way for you to learn about modm's APIs is to look at and 
experiment with [our examples][examples], especially if you have a development 
board that modm supports out-of-box.

Make sure you've [installed all tools required for building modm](installation).

Here are our favorite examples for our supported development boards:

<!--checkrepourls-->
- Arduino Uno:
[Blinky](https://github.com/modm-io/modm/blob/develop/examples/arduino_uno/basic/blink/main.cpp),
[Button & Serial](https://github.com/modm-io/modm/blob/develop/examples/arduino_uno/basic/digital_read_serial/main.cpp),
[Analog & Serial](https://github.com/modm-io/modm/blob/develop/examples/arduino_uno/basic/read_analog_voltage/main.cpp).
- NUCLEO-F031K6:
[Blinky & Serial](https://github.com/modm-io/modm/tree/develop/examples/nucleo_f031k6/blink).
- NUCLEO-F103RB:
[Blinky & Serial](https://github.com/modm-io/modm/blob/develop/examples/nucleo_f103rb/blink/main.cpp).
- STM32F072 Discovery:
[Blinky](https://github.com/modm-io/modm/blob/develop/examples/stm32f072_discovery/blink/main.cpp),
[CAN](https://github.com/modm-io/modm/blob/develop/examples/stm32f072_discovery/can/main.cpp),
[Gyroscope](https://github.com/modm-io/modm/blob/develop/examples/stm32f072_discovery/rotation/main.cpp).
- STM32F3 Discovery:
[Blinky](https://github.com/modm-io/modm/blob/develop/examples/stm32f3_discovery/blink/main.cpp),
[CAN](https://github.com/modm-io/modm/blob/develop/examples/stm32f3_discovery/can/main.cpp),
[Accelerometer](https://github.com/modm-io/modm/blob/develop/examples/stm32f3_discovery/accelerometer/main.cpp),
[Gyroscope](https://github.com/modm-io/modm/blob/develop/examples/stm32f3_discovery/rotation/main.cpp),
[Debugging with GDB](https://github.com/modm-io/modm/tree/develop/examples/stm32f3_discovery/gdb).
- STM32F4 Discovery:
[Blinky](https://github.com/modm-io/modm/blob/develop/examples/stm32f4_discovery/blink/main.cpp),
[CAN](https://github.com/modm-io/modm/blob/develop/examples/stm32f4_discovery/can/main.cpp),
[Accelerometer](https://github.com/modm-io/modm/blob/develop/examples/stm32f4_discovery/accelerometer/main.cpp),
[Timer & LED Animations](https://github.com/modm-io/modm/blob/develop/examples/stm32f4_discovery/timer/main.cpp),
[Debugging hard faults](https://github.com/modm-io/modm/blob/develop/examples/stm32f4_discovery/hard_fault/main.cpp).
- STM32F469 Discovery:
[Blinky](https://github.com/modm-io/modm/blob/develop/examples/stm32f469_discovery/blink/main.cpp),
[Drawing on display](https://github.com/modm-io/modm/blob/develop/examples/stm32f469_discovery/display/main.cpp),
[Touchscreen inputs](https://github.com/modm-io/modm/blob/develop/examples/stm32f469_discovery/touchscreen/main.cpp),
[Multi-heap with external 16MB memory](https://github.com/modm-io/modm/blob/develop/examples/stm32f469_discovery/tlsf-allocator/main.cpp),
[Game of Life in Color with Multitouch](https://github.com/modm-io/modm/tree/develop/examples/stm32f469_discovery/game_of_life)
- STM32F769 Discovery:
[FPU with double precision](https://github.com/modm-io/modm/blob/develop/examples/stm32f769i_discovery/blink/main.cpp)


Here are some additional examples of displays and sensors we like:

- [SSD1306 OLED display](https://github.com/modm-io/modm/blob/develop/examples/stm32f4_discovery/oled_display/main.cpp): Draws text and graphics onto I2C display.
- [BMP085/BMP180 barometer](https://github.com/modm-io/modm/blob/develop/examples/stm32f4_discovery/barometer_bmp085_bmp180/main.cpp): Reads atmospheric pressure and temperature from I2C sensor.
- [BMP180/BME280 barometer](https://github.com/modm-io/modm/tree/develop/examples/stm32f103c8t6_blue_pill/environment): Reads atmospheric pressure and temperature from multiple I2C sensors.
- [VL6180 time-of-flight distance sensor](https://github.com/modm-io/modm/blob/develop/examples/stm32f4_discovery/distance_vl6180/main.cpp): Reads distance and ambient light from I2C sensor.
- [VL53L0  time-of-flight distance sensor](https://github.com/modm-io/modm/tree/develop/examples/nucleo_f401re/distance_vl53l0/main.cpp): Much improved version of the VL6180 sensor.
- [ADNS9800 motion sensor](https://github.com/modm-io/modm/tree/develop/examples/stm32f103c8t6_blue_pill/adns_9800/main.cpp): Reads 2D motion from SPI sensor used in gaming mice.
- [TCS3414 color sensor](https://github.com/modm-io/modm/blob/develop/examples/stm32f4_discovery/colour_tcs3414/main.cpp): Reads RGB color from I2C sensor.
- [HD44780 over I2C-GPIO expander](https://github.com/modm-io/modm/blob/develop/examples/stm32f4_discovery/display/hd44780/main.cpp): Draws text via native GPIO port or I2C-GPIO expander port onto character display.
<!--/checkrepourls-->

Have a look at the [build system references](../reference/build-systems/#scons) to 
see how to compile and program your targets.


## Your own Project

To generate a modm library for your own project, you need to define a `project.xml`
file, which contains the path to where modm is, as well as repository and module options
and of course which modules you want to have generated.
Even though modm will generate a library that is self-contained, we still recommend adding modm as a git submodule for reproducibility.


### Using a Board Support Package

To build on a BSP,  just inherit from an existing project configuration using the `<extends>` element.
Our BSPs declare a minimal set of modules as dependencies as well as pre-define several important options for this board.
You can then add all the modules you need and configure them as you want.

```xml
<?xml version='1.0' encoding='UTF-8'?>
<library>
  <extends>../../../src/modm/board/disco_f469ni/board.xml</extends>
  <options>
    <option name=":build.scons:build.path">../../../build/stm32f469_discovery/blink</option>
  </options>
  <modules>
    <module>:build.scons</module>
  </modules>
</library>
```

!!! info "Chose a build system"
    Our BSPs do not specify a build system generator, so you need to add the 
    module yourself if you want. Here we chose to use the SCons build system
    generator, but you [can choose others as well](../reference/build-systems).

Our board support packages provide their configuration in the `Board` namespace,
which you can use to initialize the target and several board subsystems.
If a serial connection is available on the board, you can directly use the modm
logging functions.

```cpp
#include <modm/board/board.hpp>

int main()
{
    Board::initialize();
    Board::Leds::setOutput();

    while (1)
    {
        Board::Leds::toggle();
        modm::delayMilliseconds(Board::Button::read() ? 250 : 500);
#ifdef MODM_BOARD_HAS_LOGGER
        static uint32_t counter(0);
        MODM_LOG_INFO << "Loop counter: " << (counter++) << modm::endl;
#endif
    }
    return 0;
}
```


### Discovering modm

To generate your custom library, modm uses the [Library Builder][lbuild], which
is the interface to discover available modules and their configuration options.

To list all available repository options call `lbuild discover-repository`.
This will show you how to *spell* the supported targets correctly.

```
 $ lbuild discover-repository
modm:target = [at90can128, at90can32, at90can64, at90pwm1, at90pwm161, at90pwm2,
               at90pwm81, at90usb1286, at90usb1287, at90usb162, at90usb646,
...
               stm32l4s5ziy, stm32l4s7aii, stm32l4s7vit, stm32l4s7zit,
               stm32l4s9zit, stm32l4s9ziy]
```

Once you've specified this repository option (for example `<option name="modm:target">stm32f469nih</option>`), you can call `lbuild discover-modules`
to list all available modules for this target.

```
 $ lbuild discover-modules
modm:architecture:adc
modm:board.disco-f469ni
...
modm:ui:led
modm:utils
```

`lbuild discover-module-options` lists all the module options with a short
description and a list or range of possible values.

```
 $ lbuild discover-module-options
...
modm:platform:core:allocator = newlib  [block, newlib, tlsf]

  Dynamic memory allocation strategy

modm:platform:core:main_stack_size = 3040  [256 ... 65536]

  Minimum size of the application main stack

modm:platform:core:vector_table_location = fastest  [fastest, ram, rom]

  Vector table location in ROM or RAM

...
modm:platform:uart:1:buffer.rx = 16  [1 ... 65534]
modm:platform:uart:1:buffer.tx = 250  [1 ... 65534]
```

Call `lbuild discover-option -o "modm:platform:core:main_stack_size"` to get a
detailed description of the option.

```
 $ lbuild discover-option -o "modm:platform:core:main_stack_size"
modm:platform:core:main_stack_size
==================================

Current value: 3040
Possible values: 256 ... 65536

Minimum size of the application main stack

The ARM Cortex-M uses a descending stack mechanism which is placed so that it
grows towards the beginning of RAM. In case of a stack overflow the hardware
then attempts to stack into invalid memory which triggers a HardFault. A stack
overflow will therefore never overwrite any static or heap memory and this
protection works without the MPU and therefore also on ARM Cortex-M0 devices.
...
```

!!! info "Options are checked"
    `lbuild` checks all your project options against the possible values in the
    module and outputs an error if they are incorrect.

!!! tip "Visualize your dependencies"
    Create a dependency graph with `lbuild dependencies -m "modm:module" | dot -Tsvg -Grankdir=BT -o dependencies.svg`
    to help you understand what code is pulled in when you generate your library.


### Custom Configuration

In case modm doesn't have a BSP for your board or the BSP uses the hardware in
ways you don't like, you can define your own completely custom configuration.
Here a completely minimal library is generated for a STM32F469NIH device only
with the Cortex-M, GPIO and time modules and their dependencies.
Since no build system generator module is specified, you will only get the raw
source code.

```xml
<?xml version='1.0' encoding='UTF-8'?>
<library xmlns:xsd="http://www.w3.org/2001/XMLSchema-instance"
         xsd:noNamespaceSchemaLocation="https://github.com/dergraaf/library-builder/lbuild/resources/configuration.xsd">
  <repositories>
    <repository><path>../../modm/repo.lb</path></repository>
  </repositories>

  <options>
    <option name="modm:target">stm32f469nih</option>
  </options>
  <modules>
    <module>modm:platform:clock</module>
    <module>modm:platform:core</module>
    <module>modm:platform:gpio</module>
  </modules>
</library>
```

A minimal `main.cpp` for this configuration would look like this:

```cpp
#include <modm/platform/platform.hpp>
using namespace modm::platform;

int main()
{
    GpioA0::setOutput();
    while(1) {
        GpioA0::toggle();
        modm::delayMilliseconds(500);
    }
}
```

We recommend to start your custom projects with a known-good configuration from
one of our examples and then work your way into your specialization.


### Generate and Compile

Once you have your `project.xml` set up, you can call `lbuild build`, which 
generates the target and configuration specific library from modm.
This will create a few files and folders:

```sh
 $ ls
main.cpp    project.xml
 $ lbuild build
 $ ls
SConstruct      main.cpp        modm            project.xml     project.xml.log
```

You can add these folders and files to your `.gitignore` file, however, we 
recommend eventually committing these files (yes, *all* these files) into your
project repository so that you don't have issues reproducing the build.

!!! tip "Generate custom documentation"
    Include the `modm:docs` module (or execute `lbuild build --module "modm:docs"`), 
    then call `doxygen doxyfile` inside the generated `docs`folder.
    The documentation for your target and configuration will then be available
    in `docs/api/index.html`.

For this project we included the `modm:build.scons` generator, so we can just
call `scons build size`, which will compile the entire source code and output
the resource consumption:

```
 $ scons build size
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
Compiling C++·· build/main.o
...
Indexing······· build/libmodm.a
Linking········ build/project.elf
Memory usage··· build/project.elf

Program:    3612B (0.3% used)
(.fastcode + .fastdata + .hardware_init + .reset + .rodata + .table.copy.intern +
 .table.section_heap + .table.zero.intern + .text)

Data:       3184B (1.6% used) = 144B static (0.1%) + 3040B stack (1.5%)
(.bss + .fastdata + .stack)

Heap:     197520B (98.4% available)
(.heap0 + .heap1 + .heap2 + .heap5)
```

You can program your target by calling `scons program`. Additional tools are documented in [Reference/Build Systems](../reference/build-systems).

If you have any questions, [open an issue][issues] or ping [@salkinium](https://github.com/salkinium).


[examples]: https://github.com/modm-io/modm/tree/develop/examples
[issues]: https://github.com/modm-io/modm/issues
[lbuild]: https://github.com/dergraaf/library-builder
