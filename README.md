[![Windows](https://github.com/desktopman/simple-csv/workflows/Windows/badge.svg)](https://github.com/desktopman/simple-csv/actions?query=workflow%3AWindows)
[![macOS](https://github.com/desktopman/simple-csv/workflows/macOS/badge.svg)](https://github.com/desktopman/simple-csv/actions?query=workflow%3AmacOS)
[![Ubuntu](https://github.com/desktopman/simple-csv/workflows/Ubuntu/badge.svg)](https://github.com/desktopman/simple-csv/actions?query=workflow%3AUbuntu)

- [About](#about)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [Features](#features)
- [Limitations](#limitations)
- [Example](#example)
- [TODO](#todo)

## About

Simple CSV is a C++ library for reading CSV files. The design goals for the library are as follows:

* No dynamic memory allocation
* No use of exceptions
* Small code size (~1 KByte added)
* Low stack usage (~100 bytes)
* Few dependencies

The library is suitable for use on embedded microcontrollers, and has been tested on GCC 7.3 as well as
ARM Compiler 6.15.  

This library is currently in alpha.

## Usage

Put the files from the _include_ directory in your project and include _simple_csv.hpp_. See below for a basic code
example.

## Dependencies

The library does not have any external dependencies and should build as long as your platform library provides:

* size_t
* strtol()
* strtod()

## Features

* Support for custom field separators
* Support for both quoted and unquoted strings
* Support for quotes inside string values with ""

## Limitations

* Expects well-formed CSV
* Limited support for UTF-8
* No support for UTF-16

## Example

This example uses cstdio and printf, and should run on even very limited microcontrollers. How the value is used is of
course up to you.

```cpp
#include <cstdio>

#include "simple_csv.hpp"

int main()
{
    const char csv[] = "1,2,3\n4,5,6\n7,8,9";

    simple_csv::reader<> reader(csv);

    for (auto row: reader) {
        for (auto col: row) {
            int value;

            col.get(value));
            printf("Value: %d\n", value);
        }
    }
}
```

## TODO

* More examples
* Error codes
* Decimal separators other than dot
* Support for \\" quote escaping
* Support for \\n newlines in string values
* Byte by byte parsing (e.g. from a stream)