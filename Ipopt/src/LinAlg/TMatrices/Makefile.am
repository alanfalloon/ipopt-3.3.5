# Copyright (C) 2004, 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 1010 2007-06-21 15:54:36Z andreasw $

# Authors:  Carl Laird, Andreas Waechter     IBM    2004-08-13

AUTOMAKE_OPTIONS = foreign

noinst_LTLIBRARIES = libtmatrices.la

libtmatrices_la_SOURCES = \
	IpGenTMatrix.cpp IpGenTMatrix.hpp \
	IpSymTMatrix.cpp IpSymTMatrix.hpp \
	IpTripletHelper.cpp IpTripletHelper.hpp

libtmatrices_la_LDFLAGS = $(LT_LDFLAGS)

AM_CPPFLAGS = -I`$(CYGPATH_W) $(srcdir)/../../Common` \
	-I`$(CYGPATH_W) $(srcdir)/..`

# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

# Astyle stuff

ASTYLE_FILES = \
	IpGenTMatrix.cppbak IpGenTMatrix.hppbak \
	IpSymTMatrix.cppbak IpSymTMatrix.hppbak \
	IpTripletHelper.cppbak IpTripletHelper.hppbak

ASTYLE = @ASTYLE@
ASTYLEFLAGS = @ASTYLEFLAGS@

DISTCLEANFILES = $(ASTYLE_FILES)

SUFFIXES = .cppbak .hppbak

astyle: $(ASTYLE_FILES)

.hpp.hppbak:
	mv $< $@
	$(ASTYLE) $(ASTYLEFLAGS) < $@ > $<
	touch $@

.cpp.cppbak:
	mv $< $@
	$(ASTYLE) $(ASTYLEFLAGS) < $@ > $<
	touch $@
