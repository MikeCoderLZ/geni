#pragma once

#include "math/scalar.hpp"

namespace geni::math {

    union Vec2 {

    public:
    
        Vec2() : x{0.0f}, y{0.0f} {}
    
        Vec2(Scalar a, Scalar b)
          : x{a}, y{b} {}

        Vec2( Vec2 const& a )
          : x{a.x}, y{a.y} {}

        Vec2( Vec2&& a )
          : x{a.x}, y{a.y} {}

        auto operator =( Vec2 const& a ) -> Vec2&
        {
            x = a.x; y = a.y;
            return *this;
        }

        Scalar& operator [] (const int index)       { return ary[index]; }
        Scalar  operator [] (const int index) const { return ary[index]; }
        
        bool operator ==( Vec2 const& a ) { return x == a.x and y == a.y; }
        bool operator !=( Vec2 const& a ) { return x != a.x or y != a.y; }

        Vec2 operator + ( Vec2 const& b ) const { return { x + b.x, y + b.y }; }
        Vec2 operator - ( Vec2 const& b ) const { return { x - b.x, y - b.y }; }
        Vec2 operator * ( Vec2 const& b ) const { return { x * b.x, y * b.y }; }
        Vec2 operator / ( Vec2 const& b ) const { return { x / b.x, y / b.y }; }
        
        operator Scalar*()
        { return ary; }

        operator Scalar const*() const
        { return ary; }

        struct {
            Scalar x,y;
        };
        
        struct {
            Scalar s,t;
        };
        
    private:
        
        struct {
            Scalar ary[2];
        };
        
        struct {
            char bytes[sizeof(Scalar) * 2];
        };

    };
    
    inline Vec2 operator+ ( Scalar s, Vec2 const& a )
    { return Vec2( s + a.x, s + a.y ); }

    inline Vec2 operator+ ( Vec2 const& a, Scalar s )
    { return Vec2( s + a.x, s + a.y ); }
    
    inline Vec2 operator- ( Scalar s, Vec2 const& a )
    { return Vec2( s - a.x, s - a.y ); }
    
    inline Vec2 operator- ( Vec2 const& a, Scalar s )
    { return Vec2( a.x - s, a.y - s ); }
    
    inline Vec2 operator* ( Scalar s, Vec2 const& a )
    { return Vec2( s * a.x, s * a.y ); }
    
    inline Vec2 operator* ( Vec2 const& a, Scalar s )
    { return Vec2( s * a.x, s * a.y ); }
    
    inline Vec2 operator/ ( Scalar s, Vec2 const& a )
    { return Vec2( s / a.x, s / a.y ); }
    
    inline Vec2 operator/ ( Vec2 const& a, Scalar s )
    { return Vec2( a.x / s, a.y / s ); }
    
    inline Vec2 mean( Vec2 const& a, Vec2 const& b )
    { return (a + b) * 0.5f; }

    inline Vec2 norm( Vec2 const& a )
    {
        Scalar m{sqrt( a.x * a.x + a.y * a.y )};
        if( m == 0.0f ) {
            return a;
        }
        return 1.0f / m * a;
    }
    
    inline Scalar dot( Vec2 const& a, Vec2 const& b )
    { return a.x * b.x + a.y * b.y; }

    inline Scalar cross( Vec2 const& a, Vec2 const& b )
    { return a.x * b.y - a.y * b.x; }


}