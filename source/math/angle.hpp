#pragma once

#include <utility>

#include "math/constant.hpp"
#include "math/vec3.hpp"

namespace geni::math {
    
  class Angle {
    public:
      static constexpr
      Angle inTurns( DblScalar t ) { return {t * DblConstant::tau}; }
      static constexpr
      Angle inRadians( DblScalar r ) { return {r}; }

      auto toTurns() const -> DblScalar { return mRadians * DblConstant::inv_tau; }
      auto toRadians() const -> DblScalar { return mRadians; }

    private:
      DblScalar mRadians;

      constexpr
      Angle( DblScalar r ) : mRadians{r} {}
  };

  inline
  DblScalar sin( Angle a )
  { return std::sin(a.toRadians()); }

  inline
  DblScalar cos( Angle a )
  { return std::cos(a.toRadians()); }

}