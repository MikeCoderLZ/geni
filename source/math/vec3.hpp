#pragma once

#include "math/scalar.hpp"

namespace geni::math {

    union Vec3 {

    public:
    
        Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    
        Vec3(Scalar a, Scalar b, Scalar c )
          : x(a), y(b), z(c) {}

        Vec3( Vec2 const& a, Scalar b )
          : x(a.x), y(a.y), z(b) {}
          
        Vec3( Scalar b, Vec2 const& a )
          : x(b), y(a.x), z(a.y) {}
          
        Scalar& operator [] (const int index)       { return ary[index]; }
        Scalar  operator [] (const int index) const { return ary[index]; }
        
        Vec3 operator + ( Vec3 const& b ) const { return Vec3( x + b.x, y + b.y, z + b.z); }
        Vec3 operator - ( Vec3 const& b ) const { return Vec3( x - b.x, y - b.y, z - b.z ); }
        Vec3 operator * ( Vec3 const& b ) const { return Vec3( x * b.x, y * b.y, z * b.z ); }
        Vec3 operator / ( Vec3 const& b ) const { return Vec3( x / b.x, y / b.y, z / b.z ); }
        
        operator Scalar*()
        { return ary; }

        struct {
            Scalar x,y,z;
        };
        
        struct {
            Scalar s,t,p;
        };
        
        struct {
            Scalar theta, phi, radius;
        };
        
    private:
        struct {
            Scalar ary[3];
        };
        
        struct {
            char bytes[sizeof(Scalar) * 3];
        };

    };
    
    inline Vec3 operator+ ( Scalar s, Vec3 const& a )
    { return Vec3( s + a.x, s + a.y, s + a.z ); }
    
    inline Vec3 operator- ( Vec3 const& a, Scalar s )
    { return Vec3( s - a.x, s - a.y, s - a.z ); }
    
    inline Vec3 operator* ( Scalar s, Vec3 const& a )
    { return Vec3( s * a.x, s * a.y, s * a.z ); }
    
    inline Vec3 operator* ( Vec3 const& a, Scalar s )
    { return Vec3( s * a.x, s * a.y, s * a.z ); }
    
    inline Vec3 operator/ ( Scalar s, Vec3 const& a )
    { return Vec3( s / a.x, s / a.y, s / a.z ); }
    
    inline Vec3 operator/ ( Vec3 const& a, Scalar s )
    { return Vec3( s / a.x, s / a.y, s / a.z ); }
    
    inline Vec3 mean( Vec3 const& a, Vec3 const& b )
    { return (a + b) * 0.5f; }
    
    inline Vec3 norm( Vec3 const& a )
    { return a * invSqrt( a.x * a.x + a.y * a.y + a.z * a.z ); }
    
    inline Scalar dot( Vec3 const& a, Vec3 const& b )
    { return a.x * b.x + a.y * b.y + a.z * b.z; }
    
    inline Vec3 cross( Vec3 const& a, Vec3 const& b )
    {
        return Vec3( a.y * b.z - a.z * b.y,
                     a.z * b.x - a.x * b.z,
                     a.x * b.y - a.y * b.x );
    };
    
}