#pragma once

#include <cstdlib>
#include "math/scalar.hpp"
#include "math/vec4.hpp"

namespace geni::math {

  class Mat4x4 {
    public:

      Mat4x4(){}
      Mat4x4( Scalar a00, Scalar a01, Scalar a02, Scalar a03,
              Scalar a10, Scalar a11, Scalar a12, Scalar a13,
              Scalar a20, Scalar a21, Scalar a22, Scalar a23,
              Scalar a30, Scalar a31, Scalar a32, Scalar a33 )
        : m{a00,a01,a02,a03,
            a10,a11,a12,a13,
            a20,a21,a22,a23,
            a30,a31,a32,a33}
      {}
      Mat4x4(Mat4x4 const& a) : m{a.m}{}

      static
      Mat4x4 identity()
      {
        return Mat4x4(1.0f,0.0f,0.0f,0.0f,
                      0.0f,1.0f,0.0f,0.0f,
                      0.0f,0.0f,1.0f,0.0f,
                      0.0f,0.0f,0.0f,1.0f);
      }

      static
      Mat4x4 fill( Scalar s )
      { return {s}; }

      static
      Mat4x4 columns( Vec4 const& a, Vec4 const& b, Vec4 const& c, Vec4 const& d )
      { return {(Scalar const*)a,(Scalar const*)b,(Scalar const*)c,(Scalar const*)d}; }
      static
      Mat4x4 columns( Vec4 const& a )
      { return {(Scalar const*)a,(Scalar const*)a,(Scalar const*)a,(Scalar const*)a,}; }
      static
      Mat4x4 rows( Vec4 const& a, Vec4 const& b, Vec4 const& c, Vec4 const& d )
      {
        Scalar const* ap{(Scalar const*)a};
        Scalar const* bp{(Scalar const*)b};
        Scalar const* cp{(Scalar const*)c};
        Scalar const* dp{(Scalar const*)d};
        return { *ap++,*bp++,*cp++,*dp++,
                 *ap++,*bp++,*cp++,*dp++,
                 *ap++,*bp++,*cp++,*dp++,
                 *ap,  *bp,  *cp,  *dp };
      }
      static
      Mat4x4 rows( Vec4 const& a )
      {
        Scalar const* ap{(Scalar const*)a};
        Scalar const* bp{(Scalar const*)a};
        Scalar const* cp{(Scalar const*)a};
        Scalar const* dp{(Scalar const*)a};
        return { *ap++,*bp++,*cp++,*dp++,
                 *ap++,*bp++,*cp++,*dp++,
                 *ap++,*bp++,*cp++,*dp++,
                 *ap,  *bp,  *cp,  *dp };
      }

      bool operator ==( Mat4x4 const& b )
      {
        return m.e<0,0>() == b.m.e<0,0>() and m.e<0,1>() == b.m.e<0,1>() and m.e<0,2>() == b.m.e<0,2>() and m.e<0,3>() == b.m.e<0,3>() and
               m.e<1,0>() == b.m.e<1,0>() and m.e<1,1>() == b.m.e<1,1>() and m.e<1,2>() == b.m.e<1,2>() and m.e<1,3>() == b.m.e<1,3>() and
               m.e<2,0>() == b.m.e<2,0>() and m.e<2,1>() == b.m.e<2,1>() and m.e<2,2>() == b.m.e<2,2>() and m.e<2,3>() == b.m.e<2,3>() and
               m.e<3,0>() == b.m.e<3,0>() and m.e<3,1>() == b.m.e<3,1>() and m.e<3,2>() == b.m.e<3,2>() and m.e<3,3>() == b.m.e<3,3>(); 
      }

      bool operator !=( Mat4x4 const& b )
      {
        return m.e<0,0>() != b.m.e<0,0>() or m.e<0,1>() != b.m.e<0,1>() or m.e<0,2>() != b.m.e<0,2>() or m.e<0,3>() != b.m.e<0,3>() or
               m.e<1,0>() != b.m.e<1,0>() or m.e<1,1>() != b.m.e<1,1>() or m.e<1,2>() != b.m.e<1,2>() or m.e<1,3>() != b.m.e<1,3>() or
               m.e<2,0>() != b.m.e<2,0>() or m.e<2,1>() != b.m.e<2,1>() or m.e<2,2>() != b.m.e<2,2>() or m.e<2,3>() != b.m.e<2,3>() or
               m.e<3,0>() != b.m.e<3,0>() or m.e<3,1>() != b.m.e<3,1>() or m.e<3,2>() != b.m.e<3,2>() or m.e<3,3>() != b.m.e<3,3>(); 
      }

      Scalar operator ()( std::size_t c, std::size_t r ) const { return m(c,r); }
      Scalar& operator ()( std::size_t c, std::size_t r ) { return m(c,r); }
      
      auto column(std::size_t c) const -> Vec4
      { return { m(c,0), m(c,1), m(c,2), m(c,3) }; }

      auto row(std::size_t r) const -> Vec4
      { return { m(0,r), m(1,r), m(2,r), m(3,r) }; }

      auto operator -() -> Mat4x4;
      auto operator +( Mat4x4 const& n ) -> Mat4x4;
      auto operator -( Mat4x4 const& n ) -> Mat4x4;
      auto operator *( Mat4x4 const& b ) -> Mat4x4;
      auto operator *( Vec4 const& v ) -> Vec4;

    private:

      friend auto operator *( Vec4 const& v, Mat4x4 const& m ) -> Vec4;

      class M {
        public:

          M() : m{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f} {}
          M( M const& N ) { std::memcpy(m, N.m, 16); }
          M(Scalar a) : m{a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a} {}
          M( Scalar a00, Scalar a01, Scalar a02, Scalar a03,
             Scalar a10, Scalar a11, Scalar a12, Scalar a13,
             Scalar a20, Scalar a21, Scalar a22, Scalar a23,
             Scalar a30, Scalar a31, Scalar a32, Scalar a33 )
             : m{a00,a01,a02,a03,a10,a11,a12,a13,a20,a21,a22,a23,a30,a31,a32,a33}
          {}
          M(Scalar const* a, Scalar const* b, Scalar const* c, Scalar const* d)
          {
            Scalar* i{m};
            std::memcpy( i, a, sizeof(Scalar) * 4);
            i += 4;
            std::memcpy( i, b, sizeof(Scalar) * 4);
            i += 4;
            std::memcpy( i, c, sizeof(Scalar) * 4);
            i += 4;
            std::memcpy( i, d, sizeof(Scalar) * 4);
            i += 4;
          }

          Scalar operator ()( std::size_t c, std::size_t r) const { return m[c*4u+r]; }
          Scalar& operator ()( std::size_t c, std::size_t r) { return m[c*4u+r]; }
          template< int c, int r >
          Scalar e() const { return m[c*4u+r]; }
          template< int c, int r >
          Scalar& e() { return m[c*4u+r]; }
          Scalar* operator *() { return m; }

        private:
          Scalar m[16];
      } m;

      Mat4x4(Scalar const* a, Scalar const* b, Scalar const* c, Scalar const* d) : m(a,b,c,d) {}
      Mat4x4( Scalar s ) : m{s} {}
  };

  inline
  auto Mat4x4::operator -() -> Mat4x4
  {
    return {
      -m.e<0,0>(), -m.e<0,1>(), -m.e<0,2>(), -m.e<0,3>(),
      -m.e<1,0>(), -m.e<1,1>(), -m.e<1,2>(), -m.e<1,3>(),
      -m.e<2,0>(), -m.e<2,1>(), -m.e<2,2>(), -m.e<2,3>(),
      -m.e<3,0>(), -m.e<3,1>(), -m.e<3,2>(), -m.e<3,3>()
    };
  }

  inline
  auto Mat4x4::operator +( Mat4x4 const& n ) -> Mat4x4
  {
    return {
      m.e<0,0>() + n.m.e<0,0>(), m.e<0,1>() + n.m.e<0,1>(), m.e<0,2>() + n.m.e<0,2>(), m.e<0,3>() + n.m.e<0,3>(),
      m.e<1,0>() + n.m.e<1,0>(), m.e<1,1>() + n.m.e<1,1>(), m.e<1,2>() + n.m.e<1,2>(), m.e<1,3>() + n.m.e<1,3>(),
      m.e<2,0>() + n.m.e<2,0>(), m.e<2,1>() + n.m.e<2,1>(), m.e<2,2>() + n.m.e<2,2>(), m.e<2,3>() + n.m.e<2,3>(),
      m.e<3,0>() + n.m.e<3,0>(), m.e<3,1>() + n.m.e<3,1>(), m.e<3,2>() + n.m.e<3,2>(), m.e<3,3>() + n.m.e<3,3>()
    };
  }

  inline
  auto Mat4x4::operator -( Mat4x4 const& n ) -> Mat4x4
  {
    return {
      m.e<0,0>() - n.m.e<0,0>(), m.e<0,1>() - n.m.e<0,1>(), m.e<0,2>() - n.m.e<0,2>(), m.e<0,3>() - n.m.e<0,3>(),
      m.e<1,0>() - n.m.e<1,0>(), m.e<1,1>() - n.m.e<1,1>(), m.e<1,2>() - n.m.e<1,2>(), m.e<1,3>() - n.m.e<1,3>(),
      m.e<2,0>() - n.m.e<2,0>(), m.e<2,1>() - n.m.e<2,1>(), m.e<2,2>() - n.m.e<2,2>(), m.e<2,3>() - n.m.e<2,3>(),
      m.e<3,0>() - n.m.e<3,0>(), m.e<3,1>() - n.m.e<3,1>(), m.e<3,2>() - n.m.e<3,2>(), m.e<3,3>() - n.m.e<3,3>()
    };
  }

  inline
  auto Mat4x4::operator *( Mat4x4 const& b ) -> Mat4x4
      {
        return {
          // Column 0
          m.e<0,0>() * b.m.e<0,0>() + m.e<1,0>() * b.m.e<0,1>() + m.e<2,0>() * b.m.e<0,2>() + m.e<3,0>() * b.m.e<0,3>(),
          m.e<0,1>() * b.m.e<0,0>() + m.e<1,1>() * b.m.e<0,1>() + m.e<2,1>() * b.m.e<0,2>() + m.e<3,1>() * b.m.e<0,3>(),
          m.e<0,2>() * b.m.e<0,0>() + m.e<1,2>() * b.m.e<0,1>() + m.e<2,2>() * b.m.e<0,2>() + m.e<3,2>() * b.m.e<0,3>(),
          m.e<0,3>() * b.m.e<0,0>() + m.e<1,3>() * b.m.e<0,1>() + m.e<2,3>() * b.m.e<0,2>() + m.e<3,3>() * b.m.e<0,3>(),
          // Column 1
          m.e<0,0>() * b.m.e<1,0>() + m.e<1,0>() * b.m.e<1,1>() + m.e<2,0>() * b.m.e<1,2>() + m.e<3,0>() * b.m.e<1,3>(),
          m.e<0,1>() * b.m.e<1,0>() + m.e<1,1>() * b.m.e<1,1>() + m.e<2,1>() * b.m.e<1,2>() + m.e<3,1>() * b.m.e<1,3>(),
          m.e<0,2>() * b.m.e<1,0>() + m.e<1,2>() * b.m.e<1,1>() + m.e<2,2>() * b.m.e<1,2>() + m.e<3,2>() * b.m.e<1,3>(),
          m.e<0,3>() * b.m.e<1,0>() + m.e<1,3>() * b.m.e<1,1>() + m.e<2,3>() * b.m.e<1,2>() + m.e<3,3>() * b.m.e<1,3>(),
          // Column 2
          m.e<0,0>() * b.m.e<2,0>() + m.e<1,0>() * b.m.e<2,1>() + m.e<2,0>() * b.m.e<2,2>() + m.e<3,0>() * b.m.e<2,3>(),
          m.e<0,1>() * b.m.e<2,0>() + m.e<1,1>() * b.m.e<2,1>() + m.e<2,1>() * b.m.e<2,2>() + m.e<3,1>() * b.m.e<2,3>(),
          m.e<0,2>() * b.m.e<2,0>() + m.e<1,2>() * b.m.e<2,1>() + m.e<2,2>() * b.m.e<2,2>() + m.e<3,2>() * b.m.e<2,3>(),
          m.e<0,3>() * b.m.e<2,0>() + m.e<1,3>() * b.m.e<2,1>() + m.e<2,3>() * b.m.e<2,2>() + m.e<3,3>() * b.m.e<2,3>(),
          // Column 3
          m.e<0,0>() * b.m.e<3,0>() + m.e<1,0>() * b.m.e<3,1>() + m.e<2,0>() * b.m.e<3,2>() + m.e<3,0>() * b.m.e<3,3>(),
          m.e<0,1>() * b.m.e<3,0>() + m.e<1,1>() * b.m.e<3,1>() + m.e<2,1>() * b.m.e<3,2>() + m.e<3,1>() * b.m.e<3,3>(),
          m.e<0,2>() * b.m.e<3,0>() + m.e<1,2>() * b.m.e<3,1>() + m.e<2,2>() * b.m.e<3,2>() + m.e<3,2>() * b.m.e<3,3>(),
          m.e<0,3>() * b.m.e<3,0>() + m.e<1,3>() * b.m.e<3,1>() + m.e<2,3>() * b.m.e<3,2>() + m.e<3,3>() * b.m.e<3,3>()
        };
      }

  inline
  auto Mat4x4::operator *( Vec4 const& v ) -> Vec4
  {
    return {
      m.e<0,0>() * v[0] + m.e<1,0>() * v[1] + m.e<2,0>() * v[2] + m.e<3,0>() * v[3],
      m.e<0,1>() * v[0] + m.e<1,1>() * v[1] + m.e<2,1>() * v[2] + m.e<3,1>() * v[3],
      m.e<0,2>() * v[0] + m.e<1,2>() * v[1] + m.e<2,2>() * v[2] + m.e<3,2>() * v[3],
      m.e<0,3>() * v[0] + m.e<1,3>() * v[1] + m.e<2,3>() * v[2] + m.e<3,3>() * v[3]
    };
  }

  inline
  auto operator *( Vec4 const& v, Mat4x4 const& m ) -> Vec4
  {
    return {
      v[0] * m.m.e<0,0>() + v[1] * m.m.e<0,1>() + v[2] * m.m.e<0,2>() + v[3] * m.m.e<0,3>(),
      v[0] * m.m.e<1,0>() + v[1] * m.m.e<1,1>() + v[2] * m.m.e<1,2>() + v[3] * m.m.e<1,3>(),
      v[0] * m.m.e<2,0>() + v[1] * m.m.e<2,1>() + v[2] * m.m.e<2,2>() + v[3] * m.m.e<2,3>(),
      v[0] * m.m.e<3,0>() + v[1] * m.m.e<3,1>() + v[2] * m.m.e<3,2>() + v[3] * m.m.e<3,3>()
    };
  }

}