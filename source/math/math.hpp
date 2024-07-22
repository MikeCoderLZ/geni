#pragma once

#include "math/vector.hpp"
#include <iostream>

namespace geni::math {

    inline
    auto operator <<( std::ostream& s, Vec2 const& v ) -> std::ostream& {
        s << "<" << v[0] << ", " << v[1] << ">";
        return s;
    }

    inline
    auto operator <<( std::ostream& s, Vec3 const& m ) -> std::ostream& {
        s << "<" << v[0] << ", " << v[1] << ", " << v[2] << ">";
        return s;
    }

    inline
    auto operator <<( std::ostream& s, Vec4 const& m ) -> std::ostream& {
        s << "<" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ">";
        return s;
    }
}