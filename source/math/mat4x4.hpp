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

      Scalar operator ()( std::size_t c, std::size_t r ) const { return m(c,r); }
      Scalar& operator ()( std::size_t c, std::size_t r ) { return m(c,r); }
      
      auto column(std::size_t c) const -> Vec4
      { return { m(c,0), m(c,1), m(c,2), m(c,3) }; }

    private:

      class M {
        public:

          M() : e{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f} {}
          M( M const& N ) { std::memcpy(e, N.e, 16); }
          M(Scalar a) : e{a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a} {}
          M( Scalar a00, Scalar a01, Scalar a02, Scalar a03,
             Scalar a10, Scalar a11, Scalar a12, Scalar a13,
             Scalar a20, Scalar a21, Scalar a22, Scalar a23,
             Scalar a30, Scalar a31, Scalar a32, Scalar a33 )
             : e{a00,a01,a02,a03,a10,a11,a12,a13,a20,a21,a22,a23,a30,a31,a32,a33}
          {}
          M(Scalar const* a, Scalar const* b, Scalar const* c, Scalar const* d)
          {
            Scalar* i{e};
            std::memcpy( i, a, sizeof(Scalar) * 4);
            i += 4;
            std::memcpy( i, b, sizeof(Scalar) * 4);
            i += 4;
            std::memcpy( i, c, sizeof(Scalar) * 4);
            i += 4;
            std::memcpy( i, d, sizeof(Scalar) * 4);
            i += 4;
          }

          Scalar operator ()( std::size_t c, std::size_t r) const { return e[c*4u+r]; }
          Scalar& operator ()( std::size_t c, std::size_t r) { return e[c*4u+r]; }
          template< std::size_t c, std::size_t r >
          Scalar operator ()() const { return e[c*4u+r]; }
          template< std::size_t c, std::size_t r >
          Scalar& operator ()() { return e[c*4u+r]; }
          Scalar* operator *() { return e; }

        private:
          Scalar e[16];
      } m;

      Mat4x4(Scalar const* a, Scalar const* b, Scalar const* c, Scalar const* d) : m(a,b,c,d) {}
      Mat4x4( Scalar s ) : m{s} {}
  };

}