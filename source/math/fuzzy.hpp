#pragma once

#include "math/scalar.hpp"
#include "math/constant.hpp"

namespace geni::math::fuzzy {

  // Do not use fuzzy comparisons at the same time you use arithmetic,
  // at least not until fuzzy arithmetic is implemented. It will lead
  // to unexpected and surprising bugs.

  inline bool eq( Scalar a, Scalar b ) { return mag(a - b) < C<Scalar>::delta; }
  inline bool neq( Scalar a, Scalar b ) { return mag(a - b) > C<Scalar>::delta; }
  inline bool lt( Scalar a, Scalar b ) { return a != b && a < b; }
  inline bool gt( Scalar a, Scalar b ) { return a != b && a > b; }
  inline bool gteq( Scalar a, Scalar b ) { return a >= b; }
  inline bool lteq( Scalar a, Scalar b ) { return a <= b; }

  inline bool eq( DblScalar a, DblScalar b ) { return mag(a - b) < C<DblScalar>::delta; }
  inline bool neq( DblScalar a, DblScalar b ) { return mag(a - b) > C<DblScalar>::delta; }
  inline bool lt( DblScalar a, DblScalar b ) { return a != b && a < b; }
  inline bool gt( DblScalar a, DblScalar b ) { return a != b && a > b; }
  inline bool gteq( DblScalar a, DblScalar b ) { return a >= b; }
  inline bool lteq( DblScalar a, DblScalar b ) { return a <= b; }
}
