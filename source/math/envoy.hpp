#pragma once

namespace geni::math {

  class Mat4;
  class Qtn;

  class Envoy {
    public:
      static
      void construct( Mat4& m, Qtn const& q );
  };
}