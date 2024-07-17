#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "math/vec3.hpp"
#include "math/stringify.hpp"

using namespace geni::math;

TEST_GROUP( Vec3Tests ) {
    Vec3 a;
    Vec3 b;
    Vec3 const c;
    Vec3 const d{1.0f,2.0f,-3.0f};
    Vec3 e;
    Vec3 f;
    void setup()
    {
        a.x = 0.0f; a.y = 0.0f; a.z = 0.0f;
        b.x = 1.0f; b.y = 2.0f; b.z = -3.0f;
        e.x = 2.0f; e.y = 4.0f; e.z = 8.0f;
        f.x = 4.0f; f.y = 4.0f; f.z = 2.0f;
    }
};

TEST( Vec3Tests, Construction )
{
    CHECK_EQUAL( 0.0f , a.x );
    CHECK_EQUAL( 0.0f , a.y );
    CHECK_EQUAL( 0.0f , a.z );
    CHECK_EQUAL( 1.0f , b.x );
    CHECK_EQUAL( 2.0f , b.y );
    CHECK_EQUAL( -3.0f , b.z );
}

TEST( Vec3Tests, Subscript )
{
    CHECK_EQUAL( 0.0f , a[0] );
    CHECK_EQUAL( 0.0f , a[1] );
    CHECK_EQUAL( 0.0f , a[2] );
    CHECK_EQUAL( 1.0f , b[0] );
    CHECK_EQUAL( 2.0f , b[1] );
    CHECK_EQUAL( -3.0f , b[2] );

    CHECK_EQUAL( 0.0f , c[0] );
    CHECK_EQUAL( 0.0f , c[1] );
    CHECK_EQUAL( 0.0f , c[2] );
    CHECK_EQUAL( 1.0f , d[0] );
    CHECK_EQUAL( 2.0f , d[1] );
    CHECK_EQUAL( -3.0f , d[2] );
}

TEST( Vec3Tests, Equality )
{
    CHECK_COMPARE( a, !=, b );
    a.x = 1.0f;
    a.y = 2.0f;
    a.z = -3.0f;
    CHECK_EQUAL( b, a );
}

TEST( Vec3Tests, Addition )
{
    a = a + b;
    CHECK_EQUAL( b, a );
    a = b + e;
    CHECK_EQUAL( Vec3(3.0f,6.0f,5.0f), a );
    a = e + b;
    CHECK_EQUAL( Vec3(3.0f,6.0f,5.0f), a );
}

TEST( Vec3Tests, AdditionScalarVec )
{
    a = b + 2.0f;
    CHECK_EQUAL( Vec3(3.0f,4.0f,-1.0f), a);
    a = 2.0f + b;
    CHECK_EQUAL( Vec3(3.0f,4.0f,-1.0f) , a );
}

TEST( Vec3Tests, Subtraction )
{
    a = b - a;
    CHECK_EQUAL( b, a );
    a = b - e;
    CHECK_EQUAL( Vec3(-1.0f,-2.0f,-11.0f), a );
    a = e - b;
    CHECK_EQUAL( Vec3(1.0f,2.0f,11.0f), a );

}

TEST( Vec3Tests, SubtractionScalarVec )
{
    a = b - 2.0f;
    CHECK_EQUAL( Vec3(-1.0f,0.0f,-5.0f), a );
    a = 2.0f - b;
    CHECK_EQUAL( Vec3(1.0f,0.0f,5.0f), a );
}

TEST( Vec3Tests, Multiplication )
{
    a = e * b;
    CHECK_EQUAL( Vec3(2.0f,8.0f,-24.0f), a );
}

TEST( Vec3Tests, MultiplicationScalarVec )
{
    a = b * 2.0f;
    CHECK_EQUAL( Vec3(2.0f,4.0f,-6.0f), a );
    a = 2.0f * b;
    CHECK_EQUAL( Vec3(2.0f,4.0f,-6.0f), a );
}

TEST( Vec3Tests, Division )
{
    a = e / b;
    CHECK_EQUAL( Vec3(2.0f,2.0f,8.0f/-3.0f), a );
}

TEST( Vec3Tests, DivisionScalarVec )
{
    a = b / 2.0f;
    CHECK_EQUAL( Vec3(1.0f / 2.0f,2.0f / 2.0f,-3.0f / 2.0f), a );
    a = 2.0f / b;
    CHECK_EQUAL( Vec3(2.0f,1.0f,2.0f / -3.0f), a );
}

TEST( Vec3Tests, Mean )
{
    a = mean( a, b );
    CHECK_EQUAL( Vec3(0.5f,1.0f,-1.5f), a );
}

TEST( Vec3Tests, Norm )
{
    a = norm( a );
    CHECK_EQUAL( Vec3(), a );
    a = norm( f );
    CHECK_EQUAL( Vec3(4.0f / 6.0f,4.0f / 6.0f,2.0f / 6.0f), a );
}

TEST( Vec3Tests, Dot )
{
    Scalar proj = dot( a, a );
    CHECK_EQUAL( 0.0f , proj );
    proj = dot( a, b );
    CHECK_EQUAL( 0.0f , proj );
    proj = dot( b, e );
    CHECK_EQUAL( -14.0f , proj );
}

TEST( Vec3Tests, Cross )
{
    Vec3 ortho = cross( a, a );
    CHECK_EQUAL( a , ortho);
    ortho = cross( b, e );
    CHECK_EQUAL( Vec3(28.0f, -14.0f, 0.0f), ortho );
    ortho = cross( b, f );
    CHECK_EQUAL( Vec3(16.0f, -14.0f, -4.0f), ortho );
}