#pragma once

#include "math/vector.hpp"
#include "math/matrix.hpp"
#include "math/qtn.hpp"

#include <iostream>

namespace geni::math {

    inline
    auto operator <<( std::ostream& s, Vec2 const& v ) -> std::ostream& {
        s << "<" << v[0] << ", " << v[1] << ">";
        return s;
    }

    inline
    auto operator <<( std::ostream& s, Vec3 const& v ) -> std::ostream& {
        s << "<" << v[0] << ", " << v[1] << ", " << v[2] << ">";
        return s;
    }

    inline
    auto operator <<( std::ostream& s, Vec4 const& v ) -> std::ostream& {
        s << "<" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ">";
        return s;
    }

    inline
    auto operator <<( std::ostream& s, Qtn const& v ) -> std::ostream& {
        s << v.toString();
        return s;
    }

    inline
    auto operator <<( std::ostream& s, Mat4 const& m ) -> std::ostream& {
        s << "[<" << m(0,0) << ", " << m(0,1) << ", " << m(0,2) << ", " << m(0,3) << ">, <";
        s << m(1,0) << ", " << m(1,1) << ", " << m(1,2) << ", " << m(1,3) << ">, <";
        s << m(2,0) << ", " << m(2,1) << ", " << m(2,2) << ", " << m(2,3) << ">, <";
        s << m(3,0) << ", " << m(3,1) << ", " << m(3,2) << ", " << m(3,3) << ">]";
        return s;
    }

}