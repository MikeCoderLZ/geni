#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "math/vector.hpp"

using namespace geni::math;

TEST_GROUP( Vec2Tests ) {
    Vec2 a;
    Vec2 b;
    Vec2 const c;
    Vec2 const d{1.0f,2.0f};
    Vec2 e;
    Vec2 f;
    void setup()
    {
        a.x = 0.0f; a.y = 0.0f;
        b.x = 1.0f; b.y = 2.0f;
        e.x = 2.0f; e.y = 4.0f;
        f.x = 3.0f; f.y = 4.0f;
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

TEST( Vec2Tests, Addition )
{
    a = a + b;
    CHECK( a == b );
    CHECK_FALSE( a != b );
}

TEST( Vec2Tests, AdditionScalarVec )
{
    a = b + 2.0f;
    CHECK( a.x == 3.0f );
    CHECK( a.y == 4.0f );
    a = 2.0f + b;
    CHECK( a.x == 3.0f );
    CHECK( a.y == 4.0f );
}

TEST( Vec2Tests, Subtraction )
{
    a = b - a;
    CHECK( a == b );
    CHECK_FALSE( a != b );
}


TEST( Vec2Tests, SubtractionScalarVec )
{
    a = b - 2.0f;
    CHECK( a.x == -1.0f );
    CHECK( a.y == 0.0f );
    a = 2.0f - b;
    CHECK( a.x == 1.0f );
    CHECK( a.y == 0.0f );
}

TEST( Vec2Tests, Multiplication )
{
    a = e * b;
    CHECK( a.x == 2.0f );
    CHECK( a.y == 8.0f );
}

TEST( Vec2Tests, MultiplicationScalarVec )
{
    a = b * 2.0f;
    CHECK( a.x == 2.0f );
    CHECK( a.y == 4.0f );
    a = 2.0f * b;
    CHECK( a.x == 2.0f );
    CHECK( a.y == 4.0f );
}

TEST( Vec2Tests, Division )
{
    a = e / b;
    CHECK( a.x == 2.0f );
    CHECK( a.y == 2.0f );
}

TEST( Vec2Tests, DivisionScalarVec )
{
    a = b / 2.0f;
    CHECK( a.x == 1.0f / 2.0f );
    CHECK( a.y == 2.0f / 2.0f );
    a = 2.0f / b;
    CHECK( a.x == 2.0f );
    CHECK( a.y == 1.0f );
}

TEST( Vec2Tests, Mean )
{
    a = mean( a, b );
    CHECK( a.x == 0.5f );
    CHECK( a.y == 1.0f );
}

TEST( Vec2Tests, Norm )
{
    a = norm( a );
    CHECK( a.x == 0.0f );
    CHECK( a.y == 0.0f );
    a = norm( f );
    CHECK( a.x == 3.0f / 5.0f );
    CHECK( a.y == 4.0f / 5.0f );
}

TEST( Vec2Tests, Dot )
{
    Scalar proj = dot( a, a );
    CHECK( proj == 0.0f );
    proj = dot( a, b );
    CHECK( proj == 0.0f );
    proj = dot( b, e );
    CHECK( proj == 10.0f );
}

TEST( Vec2Tests, Cross )
{
    Scalar doubleArea = cross( a, a );
    CHECK( doubleArea == 0.0f );
    doubleArea = cross( b, e );
    CHECK( doubleArea == 0.0f );
    doubleArea = cross( b, f );
    CHECK( doubleArea == -2.0f );
}

int main( int argc, const char** argv )
{
    return RUN_ALL_TESTS(argc, argv);
}