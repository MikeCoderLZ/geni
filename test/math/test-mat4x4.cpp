#include <iostream>

#include "CppUTest/TestHarness.h"

#include "math/mat4x4.hpp"
#include "math/stringify.hpp"

using namespace geni::math;

TEST_GROUP( Mat4x4Tests ) {
    Mat4x4 m1;
    Mat4x4 m2;
    Mat4x4 m3;
    Mat4x4 m4;
    Mat4x4 m5;

    void setup()
    {
        m1 = Mat4x4();
        m2 = Mat4x4::identity();
        m3 = Mat4x4::fill(4.0f);
        m4 = Mat4x4::columns( Vec4(1.0f,2.0f,3.0f,4.0f) );
        m5 = Mat4x4::columns( Vec4(1.0f,2.0f,3.0f,4.0f),
                              Vec4(-1.0f,-2.0f,-3.0f,-4.0f),
                              Vec4(4.0f,3.0f,2.0f,1.0f),
                              Vec4(-4.0f,-3.0f,-2.0f,-1.0f) );
    }
};

TEST( Mat4x4Tests, DefaultConstruction )
{
    CHECK_EQUAL( 0.0f, m1(0,0) );
    CHECK_EQUAL( 0.0f, m1(0,1) );
    CHECK_EQUAL( 0.0f, m1(0,2) );
    CHECK_EQUAL( 0.0f, m1(0,3) );

    CHECK_EQUAL( 0.0f, m1(1,0) );
    CHECK_EQUAL( 0.0f, m1(1,1) );
    CHECK_EQUAL( 0.0f, m1(1,2) );
    CHECK_EQUAL( 0.0f, m1(1,3) );
    
    CHECK_EQUAL( 0.0f, m1(2,0) );
    CHECK_EQUAL( 0.0f, m1(2,1) );
    CHECK_EQUAL( 0.0f, m1(2,2) );
    CHECK_EQUAL( 0.0f, m1(2,3) );
    
    CHECK_EQUAL( 0.0f, m1(3,0) );
    CHECK_EQUAL( 0.0f, m1(3,1) );
    CHECK_EQUAL( 0.0f, m1(3,2) );
    CHECK_EQUAL( 0.0f, m1(3,3) );
}

TEST( Mat4x4Tests, IdentityConstruction )
{
    CHECK_EQUAL( 1.0f, m2(0,0) );
    CHECK_EQUAL( 0.0f, m2(0,1) );
    CHECK_EQUAL( 0.0f, m2(0,2) );
    CHECK_EQUAL( 0.0f, m2(0,3) );

    CHECK_EQUAL( 0.0f, m2(1,0) );
    CHECK_EQUAL( 1.0f, m2(1,1) );
    CHECK_EQUAL( 0.0f, m2(1,2) );
    CHECK_EQUAL( 0.0f, m2(1,3) );
    
    CHECK_EQUAL( 0.0f, m2(2,0) );
    CHECK_EQUAL( 0.0f, m2(2,1) );
    CHECK_EQUAL( 1.0f, m2(2,2) );
    CHECK_EQUAL( 0.0f, m2(2,3) );
    
    CHECK_EQUAL( 0.0f, m2(3,0) );
    CHECK_EQUAL( 0.0f, m2(3,1) );
    CHECK_EQUAL( 0.0f, m2(3,2) );
    CHECK_EQUAL( 1.0f, m2(3,3) );
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
    
    CHECK_EQUAL( 4.0f, m5(2,0) );
    CHECK_EQUAL( 3.0f, m5(2,1) );
    CHECK_EQUAL( 2.0f, m5(2,2) );
    CHECK_EQUAL( 1.0f, m5(2,3) );
    
    CHECK_EQUAL( -4.0f, m5(3,0) );
    CHECK_EQUAL( -3.0f, m5(3,1) );
    CHECK_EQUAL( -2.0f, m5(3,2) );
    CHECK_EQUAL( -1.0f, m5(3,3) );
}