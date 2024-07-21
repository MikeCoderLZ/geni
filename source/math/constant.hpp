#pragma once

#include "math/scalar.hpp"

namespace geni::math {

  template< typename Type >
  struct C {
    static constexpr Type none{0};
  };

  template<>
  struct C<Scalar> {
    static constexpr Scalar none{0.0f};
  };

}