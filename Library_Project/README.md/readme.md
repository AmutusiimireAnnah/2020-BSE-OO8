# LM35 Temperature Sensor Library

## Overview

This C library facilitates interfacing with the LM35 temperature sensor. It provides functions for initializing UART communication, reading temperature values from the LM35, and sending the temperature data over UART. The library is intended for use with microcontrollers, and the provided example code is optimized for AVR architectures.

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Initializing UART](#initializing-uart)
  - [Reading Temperature](#reading-temperature)
  - [Sending Data over UART](#sending-data-over-uart)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

### Prerequisites

- A microcontroller with an AVR architecture (e.g., Arduino Uno)
- Basic knowledge of C programming
- UART communication knowledge

### Installation

1. Download the `lm35.h` and `lm35.c` files and include them in your C project.
2. Adjust the code according to your specific microcontroller setup.
3. Include the `lm35.h` file in your main C program: `#include "lm35.h"`

## Usage

### Initializing UART

```c
#include "lm35.h"

int main(void) {
    initUART();

    // Your code here

    return 0;
}

## Reading Temperature
#include "lm35.h"

int main(void) {
    float temperature = readTemperature();

    // Your code here

    return 0;
}

## Sending Data over UART
#include "lm35.h"

int main(void) {
    sendString("Hello, UART!");

    // Your code here

    return 0;
}
