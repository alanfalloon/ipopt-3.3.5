# Copyright (C) 2006, 2007 International Business Machines.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: configure.ac 913 2008-01-07 15:39:43Z andreasw $

# Author:  Andreas Waechter            IBM    2006-04-13

#############################################################################
#                       Names and other basic things                        #
#############################################################################

AC_PREREQ(2.59)

AC_INIT([ThirdPartyLapack],[1.0.11],
        [http://projects.coin-or.org/BuildTools/newticket])

AC_COPYRIGHT([
Copyright 2006 International Business Machines and others.
All Rights Reserved.
This file is part of the open source package Coin which is distributed
under the Common Public License.])

# List one file in the package so that the configure script can test
# whether the package is actually there
AC_CONFIG_SRCDIR(LAPACK/SRC/dlarf.f)

# Where should everything be installed by default?  Here, we want it
# to be installed directly in 'bin', 'lib', 'include' subdirectories
# of the directory where configure is run.  The default would be
# /usr/local.
AC_PREFIX_DEFAULT([`pwd`])

AC_COIN_PROJECTDIR_INIT

#############################################################################
#                         Standard build tool stuff                         #
#############################################################################

# Get the system type
AC_CANONICAL_BUILD

#turn off warnings and pedantic mode since they could make trouble on some platforms,
#and we couldn't fix them anyway
coin_skip_warn_fflags=yes

# Check if user wants to produce debugging code
AC_COIN_DEBUG_COMPILE(Lapack)

# Get the name of the Fortran compiler and appropriate compiler options
AC_COIN_PROG_F77

# Initialize autotools
AC_COIN_INIT_AUTO_TOOLS

# Check if Lapack is already available on the system or provided by user
#save_LIBS="$LIBS"
AC_COIN_HAS_BLAS
#LIBS="$save_LIBS" # we need to make sure that blas libraries are not in LIBS

AC_COIN_HAS_LAPACK
MAKEOKFILE=.MakeOk
if test $coin_has_lapack = yes && test "$use_lapack" != BUILD; then
  rm -f $MAKEOKFILE
  AC_MSG_NOTICE([The Lapack sources don't need to be compiled])
  MAKEOKFILE=
else
  touch $MAKEOKFILE
fi
AC_SUBST(MAKEOKFILE)
AM_CONDITIONAL(SKIPMAKE, test -z "$MAKEOKFILE")

#############################################################################
#               Create links to the required source files                   #
#############################################################################

if test x"$MAKEOKFILE" != x; then
  lapack_source_files='dgetf2.f dgetrf.f dgetrs.f dlae2.f dlaev2.f dlanst.f dlansy.f dlapy2.f dlarf.f dlarfb.f dlarfg.f dlarft.f dlartg.f dlascl.f dlaset.f dlasr.f dlasrt.f dlassq.f dlaswp.f dlatrd.f dorg2l.f dorg2r.f dorgql.f dorgqr.f dorgtr.f dpotf2.f dpotrf.f dpotrs.f dsteqr.f dsterf.f dsyev.f dsytd2.f dsytrd.f ieeeck.f ilaenv.f iparmq.f'
  for file in $lapack_source_files; do
    AC_CONFIG_LINKS($file:LAPACK/SRC/$file)
  done
  AC_CONFIG_LINKS(dlamch.f:LAPACK/INSTALL/dlamch.f)
fi

AC_CONFIG_FILES([Makefile])

AC_COIN_FINALIZE
