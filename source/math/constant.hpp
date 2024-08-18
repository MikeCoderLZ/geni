#pragma once

#include "math/scalar.hpp"

namespace geni::math {

  template< typename Type >
  struct C {
    static constexpr Type none{0};
    static constexpr Type delta{0.000001};
    static constexpr Type pi{3.141592653589793115997963468544185};
    static constexpr Type tau{6.283185307179586476925286766559005};
    static constexpr Type inv_pi{1.0 / pi};
    static constexpr Type inv_tau{1.0 / tau};
  };

  template<>
  struct C<Scalar> {
    static constexpr Scalar none{0.0f};
    static constexpr Scalar delta{0.000000001f};
    static constexpr Scalar pi{3.141592653589793115997963468544185f };
    static constexpr Scalar tau{6.283185307179586476925286766559005f };
    static constexpr Scalar inv_pi{ 1.0f / pi };
    static constexpr Scalar inv_tau{ 1.0f / tau };
  };

  template<>
  struct C<DblScalar> {
    static constexpr DblScalar none{0.0};
    static constexpr DblScalar delta{0.000001};
    static constexpr DblScalar pi{3.141592653589793115997963468544185};
    static constexpr DblScalar tau{6.283185307179586476925286766559005};
    static constexpr DblScalar inv_pi{ 1.0 / pi };
    static constexpr DblScalar inv_tau{ 1.0 / tau };
  };

  using Constant = C<Scalar>;
  using DblConstant = C<DblScalar>;

}