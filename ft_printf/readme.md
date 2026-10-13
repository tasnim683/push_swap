*This project has been created as part of the 42 curriculum by nmokashi*

## Description

This library is an in-house implementation of C's standard printf. It is not required to implement the buffer management of the original printf. Currently it supports these flags.

* %c - character
* %s - string
* %p - pointer address in hexadecimal format
* %d - signed decimal numbers
* %i - signed integer
* %u - unsigned decimal integer
* %x - hexadecimal number (lowercase)
* %X - hexadecimal number (uppercase)
* %% - percent sign

## Instructions

1. To compile the code, run `make` in the terminal. This will create the `libftprintf.a` library.
1. To clean the object (.o) files and library, run `make clean`.
1. To clean the program `libftprintf.a`, run `make fclean.`
1. To include this library in your project, simply write `#include "ft_printf.h"` in your project files.

The library is accompanied by a header file called `ft_printf.h`, which contains prototypes for all the functions in the library.

### Resources
The C Standard Library documentation (man pages), 42 Intra subject pdfs, Peer collaboration, Online C programming tutorials and forums. (e.g., youtube, reddit forums etc)

### Testing
This project has been tested with [Tripouille](https://github.com/Tripouille/printfTester) and [paulo-santana](https://github.com/paulo-santana/ft_printf_tester)

#### Required addition
No complicated algorithms or complex data structures were used in creating ft_printf.
