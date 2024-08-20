#pragma once

namespace geni::math {

  class Mat4x4;
  class Qtn;

  class Envoy {
    public:
      static
      void construct( Mat4x4& m, Qtn const& q );
  };
}