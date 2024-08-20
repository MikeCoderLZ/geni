#include <utility>
#include "math/mat4x4.hpp"
#include "math/qtn.hpp"
#include "math/envoy.hpp"
namespace geni::math {

  Mat4x4 Mat4x4::rotation( Qtn const& q )
  {
    Mat4x4 m;
    Envoy::construct(m,q);
    return std::move(m);
  }

}
