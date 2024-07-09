#pragma once

#include <cmath>

namespace geni::math {

    using Scalar = float;

    inline
    Scalar invSqrt( Scalar const a )
    { return 1.0f / std::sqrt(a); }

    inline
    Scalar sqrt( Scalar const a )
    { return std::sqrt(a); }

}