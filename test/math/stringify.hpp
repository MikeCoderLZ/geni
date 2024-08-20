#pragma once

#include <string>

#include "CppUTest/SimpleString.h"
#include "math/math.hpp"

inline
SimpleString StringFrom( geni::math::Scalar const& s )
{
    return {std::to_string(s).c_str()};
}

inline
SimpleString StringFrom( geni::math::Vec2 const& v )
{
    return SimpleString("<")
            + StringFrom( v.x )
            + SimpleString(", ")
            + StringFrom( v.y )
            + SimpleString(">");
}

inline
SimpleString StringFrom( geni::math::Vec3 const& v )
{
    return SimpleString("<")
            + StringFrom( v.x )
            + SimpleString(", ")
            + StringFrom( v.y )
            + SimpleString(", ")
            + StringFrom( v.z )
            + SimpleString(">");
}

inline
SimpleString StringFrom( geni::math::Vec4 const& v )
{
    return SimpleString("<")
            + StringFrom( v.x )
            + SimpleString(", ")
            + StringFrom( v.y )
            + SimpleString(", ")
            + StringFrom( v.z )
            + SimpleString(", ")
            + StringFrom( v.w )
            + SimpleString(">");
}

inline
SimpleString StringFrom( geni::math::Qtn const& v )
{
    return v.toString().c_str();
}

inline
SimpleString StringFrom( geni::math::Mat4 const& m )
{
    return SimpleString("[<")
            + StringFrom( m(0,0) )
            + SimpleString(", ")
            + StringFrom( m(0,1) )
            + SimpleString(", ")
            + StringFrom( m(0,2) )
            + SimpleString(", ")
            + StringFrom( m(0,3) )
            + SimpleString(">, <")

            + StringFrom( m(1,0) )
            + SimpleString(", ")
            + StringFrom( m(1,1) )
            + SimpleString(", ")
            + StringFrom( m(1,2) )
            + SimpleString(", ")
            + StringFrom( m(1,3) )
            + SimpleString(">, <")

            + StringFrom( m(2,0) )
            + SimpleString(", ")
            + StringFrom( m(2,1) )
            + SimpleString(", ")
            + StringFrom( m(2,2) )
            + SimpleString(", ")
            + StringFrom( m(2,3) )
            + SimpleString(">, <")
            
            + StringFrom( m(3,0) )
            + SimpleString(", ")
            + StringFrom( m(3,1) )
            + SimpleString(", ")
            + StringFrom( m(3,2) )
            + SimpleString(", ")
            + StringFrom( m(3,3) )
            + SimpleString(">]");
}
