#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "math/vec2.hpp"
#include "math/stringify.hpp"

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
    CHECK_EQUAL( Vec2(), a);
    CHECK_EQUAL( Vec2(1.0f,2.0f), b);
}

TEST( Vec2Tests, Subscript )
{
    CHECK_EQUAL( 0.0f , a[0] );
    CHECK_EQUAL( 0.0f , a[1] );
    CHECK_EQUAL( 1.0f , b[0] );
    CHECK_EQUAL( 2.0f , b[1] );

    CHECK_EQUAL( 0.0f , c[0] );
    CHECK_EQUAL( 0.0f , c[1] );
    CHECK_EQUAL( 1.0f , d[0] );
    CHECK_EQUAL( 2.0f , d[1] );
}

TEST( Vec2Tests, Equality )
{
    CHECK_COMPARE( a, !=, b );
    a.x = 1.0f;
    a.y = 2.0f;
    CHECK_EQUAL( b, a );
}

TEST( Vec2Tests, Addition )
{
    a = a + b;
    CHECK_EQUAL( b , a );
}

TEST( Vec2Tests, AdditionScalarVec )
{
    a = b + 2.0f;
    CHECK_EQUAL( Vec2(3.0f,4.0f), a );
    a = 2.0f + b;
    CHECK_EQUAL( Vec2(3.0f,4.0f), a );
}

TEST( Vec2Tests, Subtraction )
{
    a = b - a;
    CHECK_EQUAL( b, a );
}


TEST( Vec2Tests, SubtractionScalarVec )
{
    a = b - 2.0f;
    CHECK_EQUAL( Vec2(-1.0f,0.0f), a );
    a = 2.0f - b;
    CHECK_EQUAL( Vec2(1.0f,0.0f), a );
}

TEST( Vec2Tests, Multiplication )
{
    a = e * b;
    CHECK_EQUAL( Vec2(2.0f,8.0f), a );
}

TEST( Vec2Tests, MultiplicationScalarVec )
{
    a = b * 2.0f;
    CHECK_EQUAL( Vec2(2.0f,4.0f), a );
    a = 2.0f * b;
    CHECK_EQUAL( Vec2(2.0f,4.0f), a );
}

TEST( Vec2Tests, Division )
{
    a = e / b;
    CHECK_EQUAL( Vec2(2.0f,2.0f), a );
}

TEST( Vec2Tests, DivisionScalarVec )
{
    a = b / 2.0f;
    CHECK_EQUAL( Vec2(1.0f / 2.0f,2.0f / 2.0f), a );
    a = 2.0f / b;
    CHECK_EQUAL( Vec2(2.0f,1.0f), a );
}

TEST( Vec2Tests, Mean )
{
    a = mean( a, b );
    CHECK_EQUAL( Vec2(0.5f,1.0f), a );
}

TEST( Vec2Tests, Norm )
{
    a = norm( a );
    CHECK_EQUAL( Vec2(), a );
    a = norm( f );
    CHECK_EQUAL( Vec2(3.0f / 5.0f,4.0f / 5.0f), a );
}

TEST( Vec2Tests, Dot )
{
    Scalar proj = dot( a, a );
    CHECK_EQUAL( 0.0f , proj );
    proj = dot( a, b );
    CHECK_EQUAL( 0.0f , proj );
    proj = dot( b, e );
    CHECK_EQUAL( 10.0f , proj );
}

TEST( Vec2Tests, Cross )
{
    Scalar doubleArea = cross( a, a );
    CHECK_EQUAL( 0.0f, doubleArea );
    doubleArea = cross( b, e );
    CHECK_EQUAL( 0.0f, doubleArea );
    doubleArea = cross( b, f );
    CHECK_EQUAL( -2.0f, doubleArea );
}