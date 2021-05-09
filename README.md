## About Simple CSV

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

Put the files from the _include_ directory in your project and include _simple_csv.hpp_. See _main.cpp_ for example
usage.

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

## TODO

* More examples
* Unit tests
* Error codes
* Decimal separators other than dot
* Support for \\" quote escaping
* Support for \\n newlines in string values
* Byte by byte parsing (e.g. from a stream)