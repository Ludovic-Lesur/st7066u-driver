# Description

This repository contains the **ST7066U** LCD screen driver. For the moment it does not support neither the RW pin (only write operations are performed) nor the 4-bits interface.

# Dependencies

The driver relies on:

* An external `types.h` header file defining the **standard C types** of the targeted MCU.
* The **embedded utility functions** defined in the [embedded-utils](https://github.com/Ludovic-Lesur/embedded-utils) repository.

Here is the versions compatibility table:

| **st7066u-driver** | **embedded-utils** |
|:---:|:---:|
| [sw1.5](https://github.com/Ludovic-Lesur/st7066u-driver/releases/tag/sw1.5) | >= [sw7.0](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw7.0) |
| [sw1.4](https://github.com/Ludovic-Lesur/st7066u-driver/releases/tag/sw1.4) | >= [sw7.0](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw7.0) |
| [sw1.3](https://github.com/Ludovic-Lesur/st7066u-driver/releases/tag/sw1.3) | >= [sw7.0](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw7.0) |
| [sw1.2](https://github.com/Ludovic-Lesur/st7066u-driver/releases/tag/sw1.2) | [sw1.3](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw1.3) to [sw6.2](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw6.2) |
| [sw1.1](https://github.com/Ludovic-Lesur/st7066u-driver/releases/tag/sw1.1) | [sw1.3](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw1.3) to [sw6.2](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw6.2) |
| [sw1.0](https://github.com/Ludovic-Lesur/st7066u-driver/releases/tag/sw1.0) | [sw1.3](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw1.3) to [sw6.2](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw6.2) |

# Compilation flags

| **Flag name** | **Value** | **Description** |
|:---:|:---:|:---:|
| `ST7066U_DRIVER_DISABLE_FLAGS_FILE` | `defined` / `undefined` | Disable the `st7066u_driver_flags.h` header file inclusion when compilation flags are given in the project settings or by command line. |
| `ST7066U_DRIVER_DISABLE` | `defined` / `undefined` | Disable the ST7066U driver. |
| `ST7066U_DRIVER_GPIO_ERROR_BASE_LAST` | `<value>` | Last error base of the low level GPIO driver. |
| `ST7066U_DRIVER_DELAY_ERROR_BASE_LAST` | `<value>` | Last error base of the low level delay driver. |
| `ST7066U_DRIVER_SCREEN_WIDTH` | `<value>` | LCD screen width (number of characters per row). |
| `ST7066U_DRIVER_SCREEN_HEIGHT` | `1` / `2` | LCD screen height (number of rows). |
