#include "math/envoy.hpp"
#include "math/qtn.hpp"
#include "math/mat4x4.hpp"

namespace geni::math {

  void Envoy::construct( Mat4x4& m, Qtn const& q )
  {
    DblScalar bb{ (q.bI*q.bI).a * 2.0 };
    DblScalar bc{ (q.bI*q.cJ).d * 2.0 };
    DblScalar bd{ (q.dK*q.bI).c * 2.0 };
    DblScalar ba{ (q.bI*q.a1).b * 2.0 };

    DblScalar cc{ (q.cJ*q.cJ).a * 2.0 };
    DblScalar cd{ (q.cJ*q.dK).b * 2.0 };
    DblScalar ca{ (q.cJ*q.a1).c * 2.0 };
    
    DblScalar dd{ (q.dK*q.dK).a * 2.0 };
    DblScalar da{ (q.dK*q.a1).d * 2.0 };

    m = {
      static_cast<Scalar>(1.0 + cc + dd), static_cast<Scalar>(bc + da),       static_cast<Scalar>(bd - ca),       0.0f,
      static_cast<Scalar>(bc - da),       static_cast<Scalar>(1.0 + bb + dd), static_cast<Scalar>(cd + ba),       0.0f,
      static_cast<Scalar>(bd + ca),       static_cast<Scalar>(cd - ba),       static_cast<Scalar>(1.0 + bb + cc), 0.0f,
      0.0f,                               0.0f,                               0.0f,                               1.0f
    };
  }
}