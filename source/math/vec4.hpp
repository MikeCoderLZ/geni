#pragma once

#include "math/scalar.hpp"

namespace geni::math {

    union Vec4 {

    public:
    
        Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
        
        Vec4(Scalar a, Scalar b, Scalar c, Scalar d )
          : x(a), y(b), z(c), w(d) {}
          
        Vec4(Vec2 const& a, Scalar b, Scalar c )
          : x(a.x), y(a.y), z(b), w(c) {}
          
        Vec4(Scalar a, Vec2 const& b, Scalar c )
          : x(a), y(b.x), z(b.y), w(c) {}
          
        Vec4(Scalar a, Scalar b, Vec2 const& c )
          : x(a), y(b), z(c.x), w(c.y) {}

        Vec4(Vec3 const& a, Scalar b )
          : x(a.x), y(a.y), z(a.z), w(b) {}
          
        Vec4(Scalar a, Vec3 const& b )
          : x(a), y(b.x), z(b.y), w(b.z) {}
          
        Scalar& operator [] (const int index)       { return ary[index]; }
        Scalar  operator [] (const int index) const { return ary[index]; }
        
        Vec4 operator + ( Vec4 const& b ) const { return Vec4( x + b.x, y + b.y, z + b.z, w + b.w ); }
        Vec4 operator - ( Vec4 const& b ) const { return Vec4( x - b.x, y - b.y, z - b.z, w - b.w ); }
        Vec4 operator * ( Vec4 const& b ) const { return Vec4( x * b.x, y * b.y, z * b.z, w * b.w ); }
        Vec4 operator / ( Vec4 const& b ) const { return Vec4( x / b.x, y / b.y, z / b.z, w / b.w ); }
        
        operator Scalar*()
        { return ary; }

        struct {
            Scalar x,y,z;
            Scalar w;
        };
        
        struct {
            Scalar s,t,p;
            Scalar q;
        };
        
        struct {
            Scalar theta, phi, radius;
            Scalar zeta;
        };
        
    private:
    
        struct {
            Scalar ary[4];
        };
        
        struct {
            char bytes[sizeof(Scalar) * 4];
        };

    };
    
    inline Vec4 operator+ ( Scalar s, Vec4 const& a )
    { return Vec4( s + a.x, s + a.y, s + a.z, s + a.w ); }
    
    inline Vec4 operator- ( Vec4 const& a, Scalar s )
    { return Vec4( s - a.x, s - a.y, s - a.z, s - a.w ); }
    
    inline Vec4 operator* ( Scalar s, Vec4 const& a )
    { return Vec4( s * a.x, s * a.y, s * a.z, s * a.w ); }
    
    inline Vec4 operator* ( Vec4 const& a, Scalar s )
    { return Vec4( s * a.x, s * a.y, s * a.z, s * a.w ); }
    
    inline Vec4 operator/ ( Scalar s, Vec4 const& a )
    { return Vec4( s / a.x, s / a.y, s / a.z, s / a.w ); }
    
    inline Vec4 operator/ ( Vec4 const& a, Scalar s )
    { return Vec4( s / a.x, s / a.y, s / a.z, s / a.w ); }
    
    inline Vec4 mean( Vec4 const& a, Vec4 const& b )
    { return (a + b) * 0.5f; }
    
    inline Vec4 norm( Vec4 const& a )
    { return a * invSqrt( a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w ); }
    
    inline Scalar dot( Vec4 const& a, Vec4 const& b )
    { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
}