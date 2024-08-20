#pragma once

#include <cmath>

namespace geni::math {

    using Scalar = float;
    using DblScalar = double;

    inline
    Scalar invSqrt( Scalar const a )
    { return 1.0f / std::sqrt(a); }

    inline
    Scalar sqrt( Scalar const a )
    { return std::sqrt(a); }

    inline
    DblScalar invSqrt( DblScalar const a )
    { return 1.0 / std::sqrt(a); }

    inline
    DblScalar sqrt( DblScalar const a )
    { return std::sqrt(a); }

    inline
    DblScalar sin( DblScalar const a )
    { return std::sin(a); }

    inline
    DblScalar cos( DblScalar const a )
    { return std::cos(a); }

    inline
    Scalar mag( Scalar a )
    {return std::abs(a); }

}