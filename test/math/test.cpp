#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "math/vector.hpp"

using namespace geni::math;

TEST_GROUP( Vec2Tests ) {
    Vec2 a;
    Vec2 b;
    Vec2 const c;
    Vec2 const d{1.0f,2.0f};
    void setup()
    {
        a.x = 0.0f; a.y = 0.0f;
        b.x = 1.0f; b.y = 2.0f;
    }
};

TEST( Vec2Tests, Construction )
{
    CHECK( a.x == 0.0f );
    CHECK( a.y == 0.0f );
    CHECK( b.x == 1.0f );
    CHECK( b.y == 2.0f );
}

TEST( Vec2Tests, Subscript )
{
    CHECK( a[0] == 0.0f );
    CHECK( a[1] == 0.0f );
    CHECK( b[0] == 1.0f );
    CHECK( b[1] == 2.0f );

    CHECK( c[0] == 0.0f );
    CHECK( c[1] == 0.0f );
    CHECK( d[0] == 1.0f );
    CHECK( d[1] == 2.0f );
}

TEST( Vec2Tests, Equality )
{
    CHECK_FALSE( a == b );
    CHECK( a != b );
    a.x = 1.0f;
    a.y = 2.0f;
    CHECK( a == b );
    CHECK_FALSE( a != b );
}



int main( int argc, const char** argv )
{
    return RUN_ALL_TESTS(argc, argv);
}