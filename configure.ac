#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
#AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_INIT(testadd, 1.0, jianzhang)

AM_INIT_AUTOMAKE(testadd, 1.0)

AC_PROG_LIBTOOL
AC_CONFIG_SRCDIR([src/testadd.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LIBTOOL
# Checks for libraries.
# FIXME: Replace `main' with a function in `-ladd':
AC_CHECK_LIB([add], [main])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 lib/Makefile
                 lib/src/Makefile
                 src/Makefile])
AC_OUTPUT
