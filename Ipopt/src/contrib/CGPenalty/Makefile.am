# Copyright (C) 2007 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 984 2007-05-30 23:03:22Z andreasw $

# Authors:  Andreas Waechter        IBM       2007-06-01

AUTOMAKE_OPTIONS = foreign

noinst_LTLIBRARIES = libcgpenalty.la

libcgpenalty_la_SOURCES = \
	IpCGPenaltyCq.cpp IpCGPenaltyCq.hpp \
	IpCGPenaltyData.cpp IpCGPenaltyData.hpp \
	IpCGPenaltyLSAcceptor.cpp IpCGPenaltyLSAcceptor.hpp \
	IpCGPenaltyRegOp.cpp IpCGPenaltyRegOp.hpp \
	IpCGPerturbationHandler.cpp IpCGPerturbationHandler.hpp \
	IpCGSearchDirCalc.cpp IpCGSearchDirCalc.hpp \
	IpPiecewisePenalty.cpp IpPiecewisePenalty.hpp

libcgpenalty_la_LDFLAGS = $(LT_LDFLAGS)

AM_CPPFLAGS = -I`$(CYGPATH_W) $(srcdir)/../../Common` \
	-I`$(CYGPATH_W) $(srcdir)/../../LinAlg` \
	-I`$(CYGPATH_W) $(srcdir)/../../LinAlg/TMatrices` \
	-I`$(CYGPATH_W) $(srcdir)/../../Interfaces` \
	-I`$(CYGPATH_W) $(srcdir)/../../Algorithm`

# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

# Astyle stuff

ASTYLE_FILES = \
	IpCGPenaltyCq.cppbak IpCGPenaltyCq.hppbak \
	IpCGPenaltyData.cppbak IpCGPenaltyData.hppbak \
	IpCGPenaltyLSAcceptor.cppbak IpCGPenaltyLSAcceptor.hppbak \
	IpCGPenaltyRegOp.cppbak IpCGPenaltyRegOp.hppbak \
	IpCGPerturbationHandler.cppbak IpCGPerturbationHandler.hppbak \
	IpCGSearchDirCalc.cppbak IpCGSearchDirCalc.hppbak \
	IpPiecewisePenalty.cppbak IpPiecewisePenalty.hppbak

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
