#include "CppUTest/TestHarness.h"

#include "math/qtn.hpp"
#include "math/stringify.hpp"

using namespace geni::math;

TEST_GROUP( QtnTests ) {
    Qtn a;
    Qtn b;
    Qtn c;
    Qtn d;
    Qtn e;
    Qtn f;
    Qtn g;
    void setup()
    {
        a = Qtn();
        b = Qtn::pure( 1.0f, 1.0f, 1.0f );
        c = Qtn::real( 1.0f );
        d = Qtn( 1.0f,2.0f,3.0f,0.25f );
        e = Qtn( 3.0f,1.0f,2.0f,0.25f );
        f = Qtn( 2.0f,3.0f,1.0f,0.25f );
        g = Qtn( 4.0f,2.0f,2.0f,1.0f );
    }
};

TEST( QtnTests, Equality )
{
    CHECK_EQUAL( Qtn(), a );
    CHECK_COMPARE( b, !=, a );
    CHECK_COMPARE( c, !=, a );
    CHECK_COMPARE( d, !=, a );
    CHECK_COMPARE( e, !=, a );
    a = Qtn::pure( 1.0f, 1.0f, 1.0f );
    CHECK_EQUAL( b, a );
    a = Qtn::real( 1.0f );
    CHECK_EQUAL( c, a );
}

TEST( QtnTests, Addition )
{
    a = a + b;
    CHECK_EQUAL( b, a );
    a = b + c;
    CHECK_EQUAL( Qtn(1.0f,1.0f,1.0f,1.0f), a );
}

TEST( QtnTests, Subtraction )
{
    a = b - a;
    CHECK_EQUAL( b, a );
    a = b - c;
    CHECK_EQUAL( Qtn(1.0f,1.0f,1.0f,-1.0f), a );
}

TEST( QtnTests, Multiplication )
{
    a = b * c;
    CHECK_EQUAL( b, a );
}

TEST( QtnTests, MultiplicationScalarVec )
{
    a = b * 2.0f;
    CHECK_EQUAL( Qtn(2.0f,2.0f,2.0f,0.0f), a );
    a = 2.0f * b;
    CHECK_EQUAL( Qtn(2.0f,2.0f,2.0f,0.0f), a );
}

TEST( QtnTests, Division )
{
    a = d / e;
    CHECK_EQUAL( Qtn(-1.5f,-6.75f,5.25f,11.0625f), a );
}

TEST( QtnTests, DivisionScalarVec )
{
    a = b / 2.0f;
    CHECK_EQUAL( Qtn(0.5f,0.5,0.5,0.0f), a );
}

TEST( QtnTests, Normalize )
{
    a.normalize();
    CHECK_EQUAL( Qtn(), a );
    c.normalize();
    CHECK_EQUAL( c, c );
    g.normalize();
    CHECK_EQUAL( Qtn(0.8f,0.4f,0.4f,0.2f), g );
}