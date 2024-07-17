#pragma once

#include <string>

#include "CppUTest/SimpleString.h"
#include "math/vector.hpp"

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