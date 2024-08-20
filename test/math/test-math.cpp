#include <iostream>

#include "CppUTest/TestHarness.h"

#include "math/math.hpp"
#include "math/stringify.hpp"

using namespace geni::math;

TEST_GROUP( MathTests )
{

};

TEST( MathTests, M44ZeroxV4 )
{
  Vec4 v{ 2.4f, -5.0f, 1.2f, 0.1f };
  Vec4 vp{ Mat4x4() * v };

  CHECK_EQUAL( Vec4(), vp );
}

TEST( MathTests, M44IdentityxV4 )
{
  Vec4 v{ 2.4f, -5.0f, 1.2f, 0.1f };
  Vec4 vp{ Mat4x4::identity() * v };

  CHECK_EQUAL( v, vp );
}

TEST( MathTests, M44xV4 )
{
  Vec4 v{ 2.5f, -5.0f, 1.5f, 1.0f };
  Mat4x4 m{
     1.0f,  2.0f,  3.0f,  4.0f,
    -1.0f, -2.0f, -3.0f, -4.0f,
    -4.0f, -3.0f, -2.0f, -1.0f,
     4.0f,  3.0f,  2.0f,  1.0f
  };

  Vec4 vc{ m * v };
  Vec4 ve{ 2.5f+5.0f-6.0f+4.0f, 5.0f+10.0f-4.5f+3.0f, 7.5f+15.0f-3.0f+2.0f, 10.0f+20.0f-1.5f+1.0f };
  CHECK_EQUAL( ve, vc );
}

TEST( MathTests, V4xM44 )
{
  Vec4 v{ 2.5f, -5.0f, 1.5f, 1.0f };
  Mat4x4 m{
     1.0f,  2.0f,  3.0f,  4.0f,
    -1.0f, -2.0f, -3.0f, -4.0f,
    -4.0f, -3.0f, -2.0f, -1.0f,
     4.0f,  3.0f,  2.0f,  1.0f
  };

  Vec4 vc{ v * m };
  Vec4 ve{ 2.5f-10.0f+4.5f+4.0f, -2.5f+10.0f-4.5f-4.0f, -10.0f+15.0f-3.0f-1.0f, 10.0f-15.0f+3.0f+1.0f };
  CHECK_EQUAL( ve, vc );
}

TEST( MathTests, Mat44QtnRot)
{
  Qtn q {Qtn::rotation( {1.0f,0.0f,0.0f}, Angle::inTurns(0.25f) )};
  Mat4x4 m{Mat4x4::rotation(q) };
  Mat4x4 xm{ 1.0f,0.0f,0.0f,0.0f,
             0.0f,0.0f,1.0f,0.0f,
             0.0f,-1.0f,0.0f,0.0f,
             0.0f,0.0f,0.0f,1.0f };

  CHECK_EQUAL(xm, m);
}