#include <iostream>

#include "CppUTest/TestHarness.h"

#include "math/mat4x4.hpp"
#include "math/stringify.hpp"

using namespace geni::math;

TEST_GROUP( Mat4x4Tests ) {
    Mat4x4 m0;
    Mat4x4 mI;
    Mat4x4 m3;
    Mat4x4 m4;
    Mat4x4 m5;
    Mat4x4 m6;

    void setup()
    {
        m0 = Mat4x4();
        mI = Mat4x4::identity();
        m3 = Mat4x4::fill(4.0f);
        m4 = Mat4x4::columns( Vec4(1.0f,2.0f,3.0f,4.0f) );

        m5 = Mat4x4::columns( Vec4(1.0f,2.0f,3.0f,4.0f),
                              Vec4(-1.0f,-2.0f,-3.0f,-4.0f),
                              Vec4(5.0f,6.0f,7.0f,8.0f),
                              Vec4(-5.0f,-6.0f,-7.0f,-8.0f) );

        m6 = Mat4x4::columns( Vec4(2.0f,7.0f,-8.0f,10.0f),
                              Vec4(5.0f,3.0f,9.0f,6.0f),
                              Vec4(-7.0f,-4.0f,-2.0f,-9.0f),
                              Vec4(-1.0f,0.0f,1.0f,-6.0f) );
    }
};

TEST( Mat4x4Tests, DefaultConstruction )
{
    CHECK_EQUAL( 0.0f, m0(0,0) );
    CHECK_EQUAL( 0.0f, m0(0,1) );
    CHECK_EQUAL( 0.0f, m0(0,2) );
    CHECK_EQUAL( 0.0f, m0(0,3) );

    CHECK_EQUAL( 0.0f, m0(1,0) );
    CHECK_EQUAL( 0.0f, m0(1,1) );
    CHECK_EQUAL( 0.0f, m0(1,2) );
    CHECK_EQUAL( 0.0f, m0(1,3) );
    
    CHECK_EQUAL( 0.0f, m0(2,0) );
    CHECK_EQUAL( 0.0f, m0(2,1) );
    CHECK_EQUAL( 0.0f, m0(2,2) );
    CHECK_EQUAL( 0.0f, m0(2,3) );
    
    CHECK_EQUAL( 0.0f, m0(3,0) );
    CHECK_EQUAL( 0.0f, m0(3,1) );
    CHECK_EQUAL( 0.0f, m0(3,2) );
    CHECK_EQUAL( 0.0f, m0(3,3) );
}

TEST( Mat4x4Tests, mIdentityConstruction )
{
    CHECK_EQUAL( 1.0f, mI(0,0) );
    CHECK_EQUAL( 0.0f, mI(0,1) );
    CHECK_EQUAL( 0.0f, mI(0,2) );
    CHECK_EQUAL( 0.0f, mI(0,3) );

    CHECK_EQUAL( 0.0f, mI(1,0) );
    CHECK_EQUAL( 1.0f, mI(1,1) );
    CHECK_EQUAL( 0.0f, mI(1,2) );
    CHECK_EQUAL( 0.0f, mI(1,3) );
    
    CHECK_EQUAL( 0.0f, mI(2,0) );
    CHECK_EQUAL( 0.0f, mI(2,1) );
    CHECK_EQUAL( 1.0f, mI(2,2) );
    CHECK_EQUAL( 0.0f, mI(2,3) );
    
    CHECK_EQUAL( 0.0f, mI(3,0) );
    CHECK_EQUAL( 0.0f, mI(3,1) );
    CHECK_EQUAL( 0.0f, mI(3,2) );
    CHECK_EQUAL( 1.0f, mI(3,3) );
}

TEST( Mat4x4Tests, FillConstruction )
{
    CHECK_EQUAL( 4.0f, m3(0,0) );
    CHECK_EQUAL( 4.0f, m3(0,1) );
    CHECK_EQUAL( 4.0f, m3(0,2) );
    CHECK_EQUAL( 4.0f, m3(0,3) );

    CHECK_EQUAL( 4.0f, m3(1,0) );
    CHECK_EQUAL( 4.0f, m3(1,1) );
    CHECK_EQUAL( 4.0f, m3(1,2) );
    CHECK_EQUAL( 4.0f, m3(1,3) );
    
    CHECK_EQUAL( 4.0f, m3(2,0) );
    CHECK_EQUAL( 4.0f, m3(2,1) );
    CHECK_EQUAL( 4.0f, m3(2,2) );
    CHECK_EQUAL( 4.0f, m3(2,3) );
    
    CHECK_EQUAL( 4.0f, m3(3,0) );
    CHECK_EQUAL( 4.0f, m3(3,1) );
    CHECK_EQUAL( 4.0f, m3(3,2) );
    CHECK_EQUAL( 4.0f, m3(3,3) );
}

TEST( Mat4x4Tests, ColumnConstruction )
{
    CHECK_EQUAL( 1.0f, m4(0,0) );
    CHECK_EQUAL( 2.0f, m4(0,1) );
    CHECK_EQUAL( 3.0f, m4(0,2) );
    CHECK_EQUAL( 4.0f, m4(0,3) );

    CHECK_EQUAL( 1.0f, m4(1,0) );
    CHECK_EQUAL( 2.0f, m4(1,1) );
    CHECK_EQUAL( 3.0f, m4(1,2) );
    CHECK_EQUAL( 4.0f, m4(1,3) );
    
    CHECK_EQUAL( 1.0f, m4(2,0) );
    CHECK_EQUAL( 2.0f, m4(2,1) );
    CHECK_EQUAL( 3.0f, m4(2,2) );
    CHECK_EQUAL( 4.0f, m4(2,3) );
    
    CHECK_EQUAL( 1.0f, m4(3,0) );
    CHECK_EQUAL( 2.0f, m4(3,1) );
    CHECK_EQUAL( 3.0f, m4(3,2) );
    CHECK_EQUAL( 4.0f, m4(3,3) );
}

TEST( Mat4x4Tests, MultiColumnConstruction )
{
    CHECK_EQUAL( 1.0f, m5(0,0) );
    CHECK_EQUAL( 2.0f, m5(0,1) );
    CHECK_EQUAL( 3.0f, m5(0,2) );
    CHECK_EQUAL( 4.0f, m5(0,3) );

    CHECK_EQUAL( -1.0f, m5(1,0) );
    CHECK_EQUAL( -2.0f, m5(1,1) );
    CHECK_EQUAL( -3.0f, m5(1,2) );
    CHECK_EQUAL( -4.0f, m5(1,3) );
    
    CHECK_EQUAL( 5.0f, m5(2,0) );
    CHECK_EQUAL( 6.0f, m5(2,1) );
    CHECK_EQUAL( 7.0f, m5(2,2) );
    CHECK_EQUAL( 8.0f, m5(2,3) );
    
    CHECK_EQUAL( -5.0f, m5(3,0) );
    CHECK_EQUAL( -6.0f, m5(3,1) );
    CHECK_EQUAL( -7.0f, m5(3,2) );
    CHECK_EQUAL( -8.0f, m5(3,3) );
}

TEST( Mat4x4Tests, MatrixAddition_ZeroMatrix )
{
    // This happens to be commutative
    Mat4x4 c{ m5+m0 };
    CHECK_EQUAL(m5, c);
    c = m0+m5;
    CHECK_EQUAL(m5, c);
}

TEST( Mat4x4Tests, MatrixAddition )
{
    // This happens to be commutative
    Mat4x4 c{ m5+m6 };
    Mat4x4 e{ 3.0f,9.0f,-5.0f,14.0f, 4.0f,1.0f,6.0f,2.0f, -2.0f,2.0f,5.0f,-1.0f, -6.0f,-6.0f,-6.0f,-14.0f };
    CHECK_EQUAL(e, c);
    c = m6+m5;
    CHECK_EQUAL(e, c);
}

TEST( Mat4x4Tests, MatrixMultiplication_ZeroMatrix )
{
    // This happens to be commutative
    Mat4x4 c{ m5*m0 };
    CHECK_EQUAL(m0, c);
    c = m0*m5;
    CHECK_EQUAL(m0, c);
}

TEST( Mat4x4Tests, MatrixMultiplication_mIdentityMatrix )
{
    // This happens to be commutative
    Mat4x4 c{ m5*mI };
    CHECK_EQUAL(m5, c);
    c = mI*m5;
    CHECK_EQUAL(m5, c);
}
TEST( Mat4x4Tests, MatrixMultiplication_NontrivialMatrices )
{
    Mat4x4 p{ -95.0f, -118.0f, -141.0f, -164.0f,
              17.0f, 22.0f, 27.0f, 32.0f,
              32.0f, 36.0f, 40.0f, 44.0f,
              34.0f, 40.0f, 46.0f, 52.0f };
    Mat4x4 c{ m5*m6 };
    CHECK_EQUAL(p, c);
}

