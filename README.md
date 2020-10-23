# Studying Using the automake

## 1 tools needed
	sudo apt-get install automake

## 2 project structure

	root@govpp:~/code/gittestCcallCplus/testAutoMake# tree
	.
	|-- lib
	|   |-- include
	|   |   |-- CppAdd.h
	|   |   `-- CppAddWrapper.h
	|   |-- Makefile.am
	|   `-- src
	|       |-- CppAdd.cpp
	|       |-- CppAddWrapper.cpp
	|       `-- Makefile.am
	|-- Makefile.am
	|-- README.md
	`-- src
	    |-- Makefile.am
	    `-- testadd.c
	
	4 directories, 10 files
	
## 3 make the share lib
we use the add as a share library. and c function to call c++ funtion. 

`extern "C"` is used to call C++ funtion.
### 3.1 add the Makefile.am

   /lib/src/Makefile.am

	AUTOMAKE_OPTIONS=foreign
	
	INCLUDES=-I../include/
	
	lib_LTLIBRARIES=libaddd.la
	
	libaddd_la_SOURCES=CppAdd.cpp CppAddWrapper.cpp

### 3.2 autoscan to generate the configure

change the configure.scan to configure.ac, add macro

/lib/src/configure.ac

	#                                               -*- Autoconf -*-
	# Process this file with autoconf to produce a configure script.
	
	AC_PREREQ([2.69])
	#AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
	AC_INIT(testadd, 1.0, jianzhang)
	
	AM_INIT_AUTOMAKE(testadd, 1.0)
	
	AC_CONFIG_SRCDIR([CppAddWrapper.cpp])
	AC_CONFIG_HEADERS([config.h])
	
	# Checks for programs.
	AC_PROG_CXX
	AC_PROG_LIBTOOL
	# Checks for libraries.
	
	# Checks for header files.
	
	# Checks for typedefs, structures, and compiler characteristics.
	
	# Checks for library functions.
	
	AC_CONFIG_FILES([Makefile])
	AC_OUTPUT


### 3.3 aclocal

    `aclocal.m4`
     

### 3.4 libtoolize

    `libtoolize -f -c`
### 3.5 autoheader

### 3.6 autoreconf -vif
 if there is error, execute this command.
	configure: error: cannot find install-sh, install.sh, or shtool in "." "./.." "./../.."

### 3.7 autoconf
There will be a `configure` file after execute 

	autoconf

### 3.8 automake --add-missing

### 3.9 configure
It will generate the 'Makefile' under all defined directories.

	./configure

### 3.10 make & make install

If success, you will see the libaddd.so:

	root@govpp:/usr/local/lib# ls -lrt
	total 80
	drwxrwsr-x 3 root staff  4096 2æœˆ   4  2020 python3.6
	drwxrwsr-x 4 root staff  4096 10æœˆ 23 06:44 python2.7
	-rwxr-xr-x 1 root root  13368 10æœˆ 23 13:04 libaddd.so.0.0.0
	lrwxrwxrwx 1 root root     16 10æœˆ 23 13:04 libaddd.so.0 -> libaddd.so.0.0.0
	lrwxrwxrwx 1 root root     16 10æœˆ 23 13:04 libaddd.so -> libaddd.so.0.0.0
	-rwxr-xr-x 1 root root    931 10æœˆ 23 13:04 libaddd.la
	-rw-r--r-- 1 root root  14986 10æœˆ 23 13:04 libaddd.a
	root@govpp:/usr/local/lib# 



## 4 use the library

### 4.1 Modify /etc/ld.so.conf , add the lib path,
	/usr/local/lib
	/usr/lib
	/lib

### 4.2 update the ldconfig
You will hit this error:

	./testadd: error while loading shared libraries: libaddd.so.0: cannot open shared object file: No such file or directory

Need load the new configure:

	/sbin/ldconfig

## 5 make the bin program

### 5.1 add the Makefile.am
The libaddd.so is loaded.

/src/Makefile.am

	AUTOMAKE_OPTIONS=foreign
	
	INCLUDES=-I../lib/include/
	
	bin_PROGRAMS=testadd
	
	testadd_SOURCES=testadd.c
	
	testadd_LDADD=-laddd

### 5.2 the top dir

Makefile.am

	AUTOMAKE_OPTIONS=foreign
	
	SUBDIRS=lib src

configure.ac

	root@govpp:~/code/testCcallCplus# cat configure.ac
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
	root@govpp:~/code/testCcallCplus# 

### 5.3 

all the command executed under top directory:

	autoscan
    aclocal
    autoheader
    libtoolize -f -c
    autoreconf -vif
    autoconf
    automake --add-missing
    ./configure
    make
    make install


the bin will located under:

	root@govpp:~/code/gittestCcallCplus/testAutoMake/src# ls -lrt
	total 68
	-rw-r--r-- 1 root root   141 10æœˆ 23 11:27 testadd.c
	-rw-r--r-- 1 root root   124 10æœˆ 23 11:27 Makefile.am
	-rw-r--r-- 1 root root 19137 10æœˆ 23 13:26 Makefile.in
	-rw-r--r-- 1 root root 18873 10æœˆ 23 13:27 Makefile
	-rw-r--r-- 1 root root  7416 10æœˆ 23 13:32 testadd.o
	-rwxr-xr-x 1 root root 11536 10æœˆ 23 13:32 testadd


