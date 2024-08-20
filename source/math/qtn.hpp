#pragma once

#include <string>
#include <sstream>
#include "math/scalar.hpp"
#include "math/vec3.hpp"
#include "math/angle.hpp"
#include "math/envoy.hpp"

namespace geni::math {

  class Mat4;

  class Qtn {
    public:
      
      Qtn() : bI{0.0f}, cJ{0.0f}, dK{0.0f}, a1{0.0f} {}
      Qtn( Scalar b, Scalar c, Scalar d, Scalar a )
        : bI{b}, cJ{c}, dK{d}, a1{a} {}
      static
      Qtn pure( Scalar x, Scalar y, Scalar z ) { return { x, y, z, 0.0f }; }
      static
      Qtn pure( Vec3 const& p ) { return { p.x, p.y, p.z, 0.0f }; }
      static
      Qtn real( Scalar s ) { return { 0.0f, 0.0f, 0.0f, s }; }
      static
      Qtn rotation( Vec3 axis, Angle const a )
      {
        auto halfA{ a.toRadians() * 0.5 };
        axis = norm(axis);
        auto sine{ sin(halfA) };
        return { static_cast<Scalar>(axis[0] * sine),
                 static_cast<Scalar>(axis[1] * sine),
                 static_cast<Scalar>(axis[2] * sine),
                 static_cast<Scalar>(cos( halfA ))   };
      }

      bool operator ==( Qtn const& q ) const;
      bool operator !=( Qtn const& q ) const;
      Qtn operator ~() const;
      Qtn operator +( Qtn const& q ) const;
      Qtn operator -( Qtn const& q ) const;
      Qtn operator *( Scalar s ) const;
      Qtn operator /( Scalar s ) const;
      Qtn operator *( Qtn const& q ) const;
      Qtn operator /( Qtn const& q ) const;
      
      auto toString() const -> std::string;
      
    private:
      friend Qtn norm( Qtn const& q );
      friend void Envoy::construct( Mat4& m, Qtn const& q );

      class I;
      class J;
      class K;
      class A;

      struct I {
          Scalar b;
          I() : b{0.0f} {}
          explicit
          I( Scalar i ) : b{i}{}
          I operator -() const { return I{-b}; }
          I operator +( I i ) const { return I{b + i.b}; }
          I operator -( I i ) const { return I{b - i.b}; }
          A operator *( I i ) const;
          K operator *( J j ) const;
          J operator *( K k ) const;
          I operator *( A a ) const;
          I operator *( Scalar a ) const;
          operator Scalar() const {return b;}
      } bI;

      struct J {
          Scalar c;
          J() : c{0.0f} {}
          explicit
          J( Scalar j ) : c{j}{}
          J operator -() const { return J{-c}; }
          J operator +( J j ) const { return J{c + j.c}; }
          J operator -( J j ) const { return J{c - j.c}; }
          A operator *( J j ) const;
          I operator *( K k ) const;
          K operator *( I i ) const;
          J operator *( A a ) const;
          J operator *( Scalar a ) const;
          operator Scalar() const {return c;}
      } cJ;

      struct K {
          Scalar d;
          K() : d{0.0f} {}
          explicit
          K( Scalar k ) : d{k} {}
          K operator -() const { return K{-d}; }
          K operator +( K k ) const { return K{d + k.d}; }
          K operator -( K k ) const { return K{d - k.d}; }
          A operator *( K k ) const;
          J operator *( I i ) const;
          I operator *( J j ) const;
          K operator *( A a ) const;
          K operator *( Scalar a ) const;
          operator Scalar() const {return d;}
      } dK;

      struct A {
          Scalar a;
          A() : a{1.0f} {}
          explicit
          A( Scalar a ) : a{a} {}
          A operator -() const { return A{-a}; }
          A operator +( A a ) const { return A{this->a + a.a}; }
          A operator -( A a ) const { return A{this->a - a.a}; }
          A operator *( A a ) const;
          I operator *( I i ) const;
          J operator *( J j ) const;
          K operator *( K k ) const;
          A operator *( Scalar a ) const;
          operator Scalar() const {return a;}
      } a1;

      Qtn( I b, J c, K d, A a )
        : bI{b}, cJ{c}, dK{d}, a1{a} {}
  };


  inline
  bool Qtn::operator ==( Qtn const& q ) const
  {
    return      bI.b == q.bI.b
            and cJ.c == q.cJ.c
            and dK.d == q.dK.d
            and a1.a == q.a1.a;
            
  }

  inline
  bool Qtn::operator !=( Qtn const& q ) const
  {
    return     bI.b != q.bI.b
            or cJ.c != q.cJ.c
            or dK.d != q.dK.d
            or a1.a != q.a1.a;
  }

  inline
  Qtn Qtn::operator ~() const { return { -bI, -cJ, -dK, a1 }; }
  
  inline
  Qtn Qtn::operator +( Qtn const& q ) const
  { return { bI + q.bI, cJ + q.cJ, dK + q.dK, a1 + q.a1 }; }

  inline
  Qtn Qtn::operator -( Qtn const& q ) const
  { return { bI - q.bI, cJ - q.cJ, dK - q.dK, a1 - q.a1 }; }

  inline
  Qtn Qtn::operator *( Scalar s ) const
  { return { bI * s, cJ * s, dK * s, a1 * s }; }

  inline
  Qtn Qtn::operator /( Scalar s ) const
  { return { bI / s, cJ / s, dK / s, a1 / s }; }

  inline
  Qtn Qtn::operator *( Qtn const& q ) const
  {
    return {
      a1*q.bI + q.a1*bI + cJ*q.dK + dK*q.cJ,
      a1*q.cJ + q.a1*cJ + bI*q.dK + dK*q.bI,
      a1*q.dK + q.a1*dK + bI*q.cJ + cJ*q.bI,
      bI*q.bI + q.cJ*cJ + dK*q.dK + q.a1*a1
    };
  }

  inline
  Qtn Qtn::operator /( Qtn const& q ) const
  { return *this * ~q; }

  inline
  Qtn norm( Qtn const& q )
  {
    Scalar mag{ sqrt((q * ~q).a1) };
    if( mag == 0.0f ) {
      return q;
    }
    Scalar invmag{ 1.0f / mag };
    return {q.bI * invmag, q.cJ * invmag, q.dK * invmag, q.a1 * invmag};
  }

  inline
  auto Qtn::toString() const -> std::string
  {
    std::stringstream s;
    s << "<" << bI.b << ", " << cJ.c << ", " << dK.d << ", " << a1.a << ">";
    return s.str();
  }

  inline Qtn operator*( Scalar s, Qtn const& q ) { return q*s; }

  inline Qtn::A Qtn::I::operator *( I i ) const { return A{-b*i.b}; }
  inline Qtn::K Qtn::I::operator *( J j ) const { return K{b*j.c}; }
  inline Qtn::J Qtn::I::operator *( K k ) const { return J{-b*k.d}; }
  inline Qtn::I Qtn::I::operator *( A a ) const { return I{b*a.a}; }
  inline Qtn::I Qtn::I::operator *( Scalar a ) const { return I{b*a}; }

  inline Qtn::A Qtn::J::operator *( J j ) const { return A{-c*j.c}; }
  inline Qtn::K Qtn::J::operator *( I i ) const { return K{-c*i.b}; }
  inline Qtn::I Qtn::J::operator *( K k ) const { return I{c*k.d}; }
  inline Qtn::J Qtn::J::operator *( A a ) const { return J{c*a.a}; }
  inline Qtn::J Qtn::J::operator *( Scalar a ) const { return J{c*a}; }

  inline Qtn::A Qtn::K::operator *( K k ) const { return A{-d*k.d}; }
  inline Qtn::J Qtn::K::operator *( I i ) const { return J{d*i.b}; }
  inline Qtn::I Qtn::K::operator *( J j ) const { return I{-d*j.c}; }
  inline Qtn::K Qtn::K::operator *( A a ) const { return K{d*a.a}; }
  inline Qtn::K Qtn::K::operator *( Scalar a ) const { return K{d*a}; }

  inline Qtn::A Qtn::A::operator *( A a ) const { return A{this->a*a.a}; }
  inline Qtn::I Qtn::A::operator *( I i ) const { return I{a*i.b}; }
  inline Qtn::J Qtn::A::operator *( J j ) const { return J{a*j.c}; }
  inline Qtn::K Qtn::A::operator *( K k ) const { return K{a*k.d}; }
  inline Qtn::A Qtn::A::operator *( Scalar a ) const { return A{this->a*a}; }

}
