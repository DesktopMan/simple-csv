[![Windows](https://github.com/desktopman/simple-csv/workflows/Windows/badge.svg)](https://github.com/desktopman/simple-csv/actions?query=workflow%3AWindows)
[![macOS](https://github.com/desktopman/simple-csv/workflows/macOS/badge.svg)](https://github.com/desktopman/simple-csv/actions?query=workflow%3AmacOS)
[![Ubuntu](https://github.com/desktopman/simple-csv/workflows/Ubuntu/badge.svg)](https://github.com/desktopman/simple-csv/actions?query=workflow%3AUbuntu)

- [About](#about)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [Features](#features)
- [Limitations](#limitations)
- [TODO](#todo)

## About

Simple CSV is a C++ library for parsing CSV. The design goals for the library are as follows:

* No dynamic memory allocation
* No use of exceptions
* Small code size (~1 KByte added)
* Low stack usage (~100 bytes)
* Few dependencies

This library is currently in alpha.

## Installation

Put the files from the _include_ directory in your project and include _scsv.hpp_.

## Usage

The included examples use cstdio and printf, and should run on even very limited microcontrollers. How the values are
used is of course up to you.

[Examples](/examples)

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

* Decimal separators other than dot
* Support for \\" quote escaping
* Byte by byte parsing (e.g. from a stream)
