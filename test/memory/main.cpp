#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "memory/Memory.hpp"

TEST_GROUP(Bytes) {

};

TEST(Bytes, ZeroLengthBytes)
{
    geni::mem::Bytes<0> noBytes;
    CHECK_TEXT(!noBytes, "Zero length Bytes converts to true.");
}

int main( int argc, const char** argv )
{
    return RUN_ALL_TESTS(argc, argv);
}
