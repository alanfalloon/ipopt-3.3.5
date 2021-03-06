// Copyright (C) 2005, 2007 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Common Public License.
//
// $Id: IpUtils.cpp 1148 2008-01-15 03:17:44Z andreasw $
//
// Authors:  Carl Laird, Andreas Waechter    IBM       2005-08-12

#include "IpoptConfig.h"
#include "IpUtils.hpp"

#ifdef HAVE_CSTDLIB
# include <cstdlib>
#else
# ifdef HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif

#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
# else
#  error "don't have header file for math"
# endif
#endif

#ifdef HAVE_CFLOAT
# include <cfloat>
#else
# ifdef HAVE_FLOAT_H
#  include <float.h>
# endif
#endif

#ifdef HAVE_CIEEEFP
# include <cieeefp>
#else
# ifdef HAVE_IEEEFP_H
#  include <ieeefp.h>
# endif
#endif

namespace Ipopt
{

  bool IsFiniteNumber(Number val)
  {
#ifdef MY_C_FINITE
    return (bool)MY_C_FINITE(val);
#else

    return true;
#endif

  }

  Number IpRandom01()
  {
#ifdef HAVE_DRAND48
    return Number(drand48());
#else
# ifdef HAVE_RAND
    return Number(rand())/Number(RAND_MAX);
# else
#  ifdef HAVE_STD__RAND
    return Number(std::rand())/Number(RAND_MAX);
#  else
#   error "don't have function for random number generator"
#  endif
# endif
#endif
  }

  void IpResetRandom01()
  {
#ifdef HAVE_DRAND48
    srand48(1);
#else
# ifdef HAVE_RAND
    srand(1);
# else
#  ifdef HAVE_STD__RAND
    std::srand(1);
#  else
#   error "don't have function for random number generator"
#  endif
# endif
#endif
  }

} //namespace Ipopt
