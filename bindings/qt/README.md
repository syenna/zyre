```
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
```
# qzyre

## Overview

qzyre is a Qt wrapper for zyre. It's possible to
statically or dynamically link against it as well as use it as internal or external
library.

## Internal library

You can use the Qt wrapper as internal library by including the
`qzyre.pri` file. Here is a minimal example app:

```make
QT += core
QT -= gui

include(<path to pri file>/qzyre.pri)

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
```

To link statically against the wrapper you need to change the
`QZYRE_LIBRARY` variable in `config.pri` to `no`.

To link dynamically against the wrapper you need to change the
`QZYRE_LIBRARY` variable in `config.pri` to `yes`.

## External library

To install qzyre as a shared library do the following:

```sh
qmake
make
sudo make install
```

The default installation directory prefix on unix is `/usr/local/`. If you like
to change the prefix define the PREFIX variable when calling qmake:

```sh
qmake PREFIX=/usr
```

## Notes

### Dependent classes

If the bindings are generated as part of a zproject that depends on another
zproject (e.g. zyre on czmq), the Qt bindings will automatically detect all
dependent classes and generate bindings for them too. Check the ./generate.sh
output the see which dependent classes couldn't be resolved.

### Format methods

Whenever a c method takes a format followed by variadic arguments, this is
replaced in the Qt bindings by one string instead.

### Excluded methods

If you're missing some methods in the bindings then because they have been
excluded. Currently methods are excluded if,

    * they have variadic arguments and don't have a sibling method that
      accepts a va_list. Most prominent example is probably printf and vprintf.

    * they have char** arguments, as they might get freed which doesn't play
      well with QString.

```
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
```
