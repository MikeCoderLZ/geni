#pragma once

#include <cstring>
#include <utility>
#include "math/scalar.hpp"
#include "math/fuzzy.hpp"
#include "math/vec4.hpp"
#include "math/envoy.hpp"

namespace geni::math {

  class Qtn;

  class Mat4 {
    public:

      Mat4(){}
      Mat4( Scalar a00, Scalar a01, Scalar a02, Scalar a03,
            Scalar a10, Scalar a11, Scalar a12, Scalar a13,
            Scalar a20, Scalar a21, Scalar a22, Scalar a23,
            Scalar a30, Scalar a31, Scalar a32, Scalar a33 )
        : m{a00,a01,a02,a03,
            a10,a11,a12,a13,
            a20,a21,a22,a23,
            a30,a31,a32,a33}
      {}
      Mat4(Mat4 const& a) : m{a.m}{}

      static
      Mat4 identity()
      {
        return Mat4(1.0f,0.0f,0.0f,0.0f,
                    0.0f,1.0f,0.0f,0.0f,
                    0.0f,0.0f,1.0f,0.0f,
                    0.0f,0.0f,0.0f,1.0f);
      }

      static
      Mat4 fill( Scalar s )
      { return {s}; }

      static
      Mat4 columns( Vec4 const& a, Vec4 const& b, Vec4 const& c, Vec4 const& d )
      { return {(Scalar const*)a,(Scalar const*)b,(Scalar const*)c,(Scalar const*)d}; }
      static
      Mat4 columns( Vec4 const& a )
      { return {(Scalar const*)a,(Scalar const*)a,(Scalar const*)a,(Scalar const*)a}; }
      static
      Mat4 rows( Vec4 const& a, Vec4 const& b, Vec4 const& c, Vec4 const& d )
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
      Mat4 rows( Vec4 const& a )
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
      static
      Mat4 rotation( Qtn const& q )
      {
        Mat4 m;
        Envoy::construct(m,q);
        return std::move(m);
      }

      bool operator ==( Mat4 const& b )
      {
        using namespace fuzzy;
        return eq(m.e<0,0>(),b.m.e<0,0>()) and eq(m.e<0,1>(),b.m.e<0,1>()) and eq(m.e<0,2>(),b.m.e<0,2>()) and eq(m.e<0,3>(),b.m.e<0,3>()) and
               eq(m.e<1,0>(),b.m.e<1,0>()) and eq(m.e<1,1>(),b.m.e<1,1>()) and eq(m.e<1,2>(),b.m.e<1,2>()) and eq(m.e<1,3>(),b.m.e<1,3>()) and
               eq(m.e<2,0>(),b.m.e<2,0>()) and eq(m.e<2,1>(),b.m.e<2,1>()) and eq(m.e<2,2>(),b.m.e<2,2>()) and eq(m.e<2,3>(),b.m.e<2,3>()) and
               eq(m.e<3,0>(),b.m.e<3,0>()) and eq(m.e<3,1>(),b.m.e<3,1>()) and eq(m.e<3,2>(),b.m.e<3,2>()) and eq(m.e<3,3>(),b.m.e<3,3>()); 
      }

      bool operator !=( Mat4 const& b )
      {
        using namespace fuzzy;
        return neq(m.e<0,0>(),b.m.e<0,0>()) or neq(m.e<0,1>(),b.m.e<0,1>()) or neq(m.e<0,2>(),b.m.e<0,2>()) or neq(m.e<0,3>(),b.m.e<0,3>()) or
               neq(m.e<1,0>(),b.m.e<1,0>()) or neq(m.e<1,1>(),b.m.e<1,1>()) or neq(m.e<1,2>(),b.m.e<1,2>()) or neq(m.e<1,3>(),b.m.e<1,3>()) or
               neq(m.e<2,0>(),b.m.e<2,0>()) or neq(m.e<2,1>(),b.m.e<2,1>()) or neq(m.e<2,2>(),b.m.e<2,2>()) or neq(m.e<2,3>(),b.m.e<2,3>()) or
               neq(m.e<3,0>(),b.m.e<3,0>()) or neq(m.e<3,1>(),b.m.e<3,1>()) or neq(m.e<3,2>(),b.m.e<3,2>()) or neq(m.e<3,3>(),b.m.e<3,3>()); 
      }

      Scalar operator ()( std::size_t c, std::size_t r ) const { return m(c,r); }
      Scalar& operator ()( std::size_t c, std::size_t r ) { return m(c,r); }
      
      auto column(std::size_t c) const -> Vec4
      { return { m(c,0), m(c,1), m(c,2), m(c,3) }; }

      auto row(std::size_t r) const -> Vec4
      { return { m(0,r), m(1,r), m(2,r), m(3,r) }; }

      auto operator -() -> Mat4;
      auto operator +( Mat4 const& n ) -> Mat4;
      auto operator -( Mat4 const& n ) -> Mat4;
      auto operator *( Mat4 const& b ) -> Mat4;
      auto operator *( Scalar v ) -> Mat4;
      auto operator /( Scalar v ) -> Mat4;
      auto operator *( Vec4 const& v ) -> Vec4;

      auto transpose() -> Mat4;
      auto trace() -> Scalar;

    private:

      friend auto operator *( Vec4 const& v, Mat4 const& m ) -> Vec4;
      friend auto operator *( Scalar s, Mat4 const& m ) -> Mat4;

      class M {
        public:

          M() : m{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f} {}
          M( M const& N )
            : m{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}
          { std::memcpy(m, N.m, sizeof(Scalar) * 16); }
          M(Scalar a) : m{a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a} {}
          M( Scalar a00, Scalar a01, Scalar a02, Scalar a03,
             Scalar a10, Scalar a11, Scalar a12, Scalar a13,
             Scalar a20, Scalar a21, Scalar a22, Scalar a23,
             Scalar a30, Scalar a31, Scalar a32, Scalar a33 )
             : m{a00,a01,a02,a03,a10,a11,a12,a13,a20,a21,a22,a23,a30,a31,a32,a33}
          {}
          M(Scalar const* a, Scalar const* b, Scalar const* c, Scalar const* d)
            : m{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}
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

      Mat4(Scalar const* a, Scalar const* b, Scalar const* c, Scalar const* d) : m(a,b,c,d) {}
      Mat4( Scalar s ) : m{s} {}
  };

  inline
  auto Mat4::operator -() -> Mat4
  {
    return {
      -m.e<0,0>(), -m.e<0,1>(), -m.e<0,2>(), -m.e<0,3>(),
      -m.e<1,0>(), -m.e<1,1>(), -m.e<1,2>(), -m.e<1,3>(),
      -m.e<2,0>(), -m.e<2,1>(), -m.e<2,2>(), -m.e<2,3>(),
      -m.e<3,0>(), -m.e<3,1>(), -m.e<3,2>(), -m.e<3,3>()
    };
  }

  inline
  auto Mat4::operator +( Mat4 const& n ) -> Mat4
  {
    return {
      m.e<0,0>() + n.m.e<0,0>(), m.e<0,1>() + n.m.e<0,1>(), m.e<0,2>() + n.m.e<0,2>(), m.e<0,3>() + n.m.e<0,3>(),
      m.e<1,0>() + n.m.e<1,0>(), m.e<1,1>() + n.m.e<1,1>(), m.e<1,2>() + n.m.e<1,2>(), m.e<1,3>() + n.m.e<1,3>(),
      m.e<2,0>() + n.m.e<2,0>(), m.e<2,1>() + n.m.e<2,1>(), m.e<2,2>() + n.m.e<2,2>(), m.e<2,3>() + n.m.e<2,3>(),
      m.e<3,0>() + n.m.e<3,0>(), m.e<3,1>() + n.m.e<3,1>(), m.e<3,2>() + n.m.e<3,2>(), m.e<3,3>() + n.m.e<3,3>()
    };
  }

  inline
  auto Mat4::operator -( Mat4 const& n ) -> Mat4
  {
    return {
      m.e<0,0>() - n.m.e<0,0>(), m.e<0,1>() - n.m.e<0,1>(), m.e<0,2>() - n.m.e<0,2>(), m.e<0,3>() - n.m.e<0,3>(),
      m.e<1,0>() - n.m.e<1,0>(), m.e<1,1>() - n.m.e<1,1>(), m.e<1,2>() - n.m.e<1,2>(), m.e<1,3>() - n.m.e<1,3>(),
      m.e<2,0>() - n.m.e<2,0>(), m.e<2,1>() - n.m.e<2,1>(), m.e<2,2>() - n.m.e<2,2>(), m.e<2,3>() - n.m.e<2,3>(),
      m.e<3,0>() - n.m.e<3,0>(), m.e<3,1>() - n.m.e<3,1>(), m.e<3,2>() - n.m.e<3,2>(), m.e<3,3>() - n.m.e<3,3>()
    };
  }

  inline
  auto Mat4::operator *( Scalar s ) -> Mat4
  {
    return {
      m.e<0,0>() * s, m.e<0,1>() * s, m.e<0,2>() * s, m.e<0,3>() * s,
      m.e<1,0>() * s, m.e<1,1>() * s, m.e<1,2>() * s, m.e<1,3>() * s,
      m.e<2,0>() * s, m.e<2,1>() * s, m.e<2,2>() * s, m.e<2,3>() * s,
      m.e<3,0>() * s, m.e<3,1>() * s, m.e<3,2>() * s, m.e<3,3>() * s
    };
  }

  inline
  auto Mat4::operator /( Scalar s ) -> Mat4
  {
    return {
      m.e<0,0>() / s, m.e<0,1>() / s, m.e<0,2>() / s, m.e<0,3>() / s,
      m.e<1,0>() / s, m.e<1,1>() / s, m.e<1,2>() / s, m.e<1,3>() / s,
      m.e<2,0>() / s, m.e<2,1>() / s, m.e<2,2>() / s, m.e<2,3>() / s,
      m.e<3,0>() / s, m.e<3,1>() / s, m.e<3,2>() / s, m.e<3,3>() / s
    };
  }

  inline
  auto operator *( Scalar s, Mat4 const& m ) -> Mat4
  {
    return {
      m.m.e<0,0>() * s, m.m.e<0,1>() * s, m.m.e<0,2>() * s, m.m.e<0,3>() * s,
      m.m.e<1,0>() * s, m.m.e<1,1>() * s, m.m.e<1,2>() * s, m.m.e<1,3>() * s,
      m.m.e<2,0>() * s, m.m.e<2,1>() * s, m.m.e<2,2>() * s, m.m.e<2,3>() * s,
      m.m.e<3,0>() * s, m.m.e<3,1>() * s, m.m.e<3,2>() * s, m.m.e<3,3>() * s
    };
  }

  inline
  auto Mat4::operator *( Mat4 const& b ) -> Mat4
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
  auto Mat4::operator *( Vec4 const& v ) -> Vec4
  {
    return {
      m.e<0,0>() * v[0] + m.e<1,0>() * v[1] + m.e<2,0>() * v[2] + m.e<3,0>() * v[3],
      m.e<0,1>() * v[0] + m.e<1,1>() * v[1] + m.e<2,1>() * v[2] + m.e<3,1>() * v[3],
      m.e<0,2>() * v[0] + m.e<1,2>() * v[1] + m.e<2,2>() * v[2] + m.e<3,2>() * v[3],
      m.e<0,3>() * v[0] + m.e<1,3>() * v[1] + m.e<2,3>() * v[2] + m.e<3,3>() * v[3]
    };
  }

  inline
  auto operator *( Vec4 const& v, Mat4 const& m ) -> Vec4
  {
    return {
      v[0] * m.m.e<0,0>() + v[1] * m.m.e<0,1>() + v[2] * m.m.e<0,2>() + v[3] * m.m.e<0,3>(),
      v[0] * m.m.e<1,0>() + v[1] * m.m.e<1,1>() + v[2] * m.m.e<1,2>() + v[3] * m.m.e<1,3>(),
      v[0] * m.m.e<2,0>() + v[1] * m.m.e<2,1>() + v[2] * m.m.e<2,2>() + v[3] * m.m.e<2,3>(),
      v[0] * m.m.e<3,0>() + v[1] * m.m.e<3,1>() + v[2] * m.m.e<3,2>() + v[3] * m.m.e<3,3>()
    };
  }

  inline
  auto Mat4::transpose() -> Mat4
  {
    return {
      m.e<0,0>(), m.e<1,0>(), m.e<2,0>(), m.e<3,0>(),
      m.e<0,1>(), m.e<1,1>(), m.e<2,1>(), m.e<3,1>(),
      m.e<0,2>(), m.e<1,2>(), m.e<2,2>(), m.e<3,2>(),
      m.e<0,3>(), m.e<1,3>(), m.e<2,3>(), m.e<3,3>()
    };
  }

  inline
  auto Mat4::trace() -> Scalar
  { return m.e<0,0>() + m.e<1,1>() + m.e<2,2>() + m.e<3,3>(); }

}