#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "math/vector.hpp"
#include "math/stringify.hpp"

using namespace geni::math;

TEST_GROUP( Vec4Tests ) {
    Vec4 a;
    Vec4 b;
    Vec4 const c;
    Vec4 const d{1.0f,2.0f,-3.0f,-5.0f};
    Vec4 e;
    Vec4 f;
    void setup()
    {
        a.x = 0.0f; a.y = 0.0f; a.z = 0.0f; a.w = 0.0f;
        b.x = 1.0f; b.y = 2.0f; b.z = -3.0f; b.w = -5.0f;
        e.x = 2.0f; e.y = 4.0f; e.z = 8.0f; e.w = 8.0f; 
        f.x = 5.0f; f.y = 4.0f; f.z = 2.0f; f.w = 2.0f;
    }
};

TEST( Vec4Tests, Construction )
{
    CHECK_EQUAL( Vec4() , a );
    CHECK_EQUAL( Vec4(1.0f,2.0f,-3.0f,-5.0f), b );
}

TEST( Vec4Tests, Subscript )
{
    CHECK_EQUAL( 0.0f , a[0] );
    CHECK_EQUAL( 0.0f , a[1] );
    CHECK_EQUAL( 0.0f , a[2] );
    CHECK_EQUAL( 0.0f , a[3] );

    CHECK_EQUAL( 1.0f , b[0] );
    CHECK_EQUAL( 2.0f , b[1] );
    CHECK_EQUAL( -3.0f , b[2] );
    CHECK_EQUAL( -5.0f , b[3] );

    CHECK_EQUAL( 0.0f , c[0] );
    CHECK_EQUAL( 0.0f , c[1] );
    CHECK_EQUAL( 0.0f , c[2] );
    CHECK_EQUAL( 0.0f , c[3] );

    CHECK_EQUAL( 1.0f , d[0] );
    CHECK_EQUAL( 2.0f , d[1] );
    CHECK_EQUAL( -3.0f , d[2] );
    CHECK_EQUAL( -5.0f , d[3] );
}

TEST( Vec4Tests, Equality )
{
    CHECK_COMPARE( a, !=, b );
    a.x = 1.0f;
    a.y = 2.0f;
    a.z = -3.0f;
    a.w = -5.0f;
    CHECK_EQUAL( b , a );
}

TEST( Vec4Tests, Addition )
{
    a = a + b;
    CHECK_EQUAL( b, a );
    a = b + e;
    CHECK_EQUAL( Vec4(3.0f,6.0f,5.0f,3.0f), a );
    a = e + b;
    CHECK_EQUAL( Vec4(3.0f,6.0f,5.0f,3.0f), a );
}

TEST( Vec4Tests, AdditionScalarVec )
{
    a = b + 2.0f;
    CHECK_EQUAL( Vec4(3.0f,4.0f,-1.0f,-3.0f), a );
    a = 2.0f + b;
    CHECK_EQUAL( Vec4(3.0f,4.0f,-1.0f,-3.0f), a );
}

TEST( Vec4Tests, Subtraction )
{
    a = b - a;
    CHECK_EQUAL( b, a );
    a = b - e;
    CHECK_EQUAL( Vec4(-1.0f,-2.0f,-11.0f,-13.0f), a );
    a = e - b;
    CHECK_EQUAL( Vec4(1.0f,2.0f,11.0f,13.0f), a );
}

TEST( Vec4Tests, SubtractionScalarVec )
{
    a = b - 2.0f;
    CHECK_EQUAL( Vec4(-1.0f,0.0f,-5.0f,-7.0f), a );
    a = 2.0f - b;
    CHECK_EQUAL( Vec4(1.0f,0.0f,5.0f,7.0f), a );
}

TEST( Vec4Tests, Multiplication )
{
    a = e * b;
    CHECK_EQUAL( Vec4(2.0f,8.0f,-24.0f, -40.0f), a );
    a = b * e;
    CHECK_EQUAL( Vec4(2.0f,8.0f,-24.0f, -40.0f), a );
}

TEST( Vec4Tests, MultiplicationScalarVec )
{
    a = b * 2.0f;
    CHECK_EQUAL( Vec4(2.0f,4.0f,-6.0f,-10.0f), a );
    a = 2.0f * b;
    CHECK_EQUAL( Vec4(2.0f,4.0f,-6.0f,-10.0f), a );
}

TEST( Vec4Tests, Division )
{
    a = e / b;
    CHECK_EQUAL( Vec4(2.0f,2.0f,8.0f / -3.0f,8.0f / -5.0f), a );
    a = b / e;
    CHECK_EQUAL( Vec4(0.5f,0.5f,-3.0f/8.0f,-5.0f/8.0f), a );
}

TEST( Vec4Tests, DivisionScalarVec )
{
    a = b / 2.0f;
    CHECK_EQUAL( Vec4(0.5f,1.0f,-3.0f/2.0f,-5.0f/2.0f), a );
    a = 2.0f / b;
    CHECK_EQUAL( Vec4(2.0f,1.0f,2.0f/-3.0f,2.0f/-5.0f), a );
}

TEST( Vec4Tests, Mean )
{
    a = mean( a, b );
    CHECK_EQUAL( Vec4(0.5f,1.0f,-1.5f,-2.5f), a );
    a = mean( b, e );
    CHECK_EQUAL( Vec4(3.0f/2.0f,3.0f,2.5f,1.5f), a );
}

TEST( Vec4Tests, Norm )
{
    a = norm( a );
    CHECK_EQUAL( Vec4(), a );
    a = norm( f );
    CHECK_EQUAL( Vec4(5.0f/7.0f, 4.0f/7.0f, 2.0f/7.0f, 2.0f/7.0f), a );
}

TEST( Vec4Tests, Dot )
{
    Scalar proj = dot( a, a );
    CHECK_EQUAL( 0.0f , proj );
    proj = dot( a, b );
    CHECK_EQUAL( 0.0f , proj );
    proj = dot( b, e );
    CHECK_EQUAL( -54.0f , proj );
}

int main( int argc, const char** argv )
{
    return RUN_ALL_TESTS(argc, argv);
}