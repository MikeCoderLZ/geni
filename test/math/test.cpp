#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "math/vector.hpp"
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