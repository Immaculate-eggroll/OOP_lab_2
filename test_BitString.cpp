#include "BitString.h"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(BitStringTest, DefaultConstructorCreatesEmpty) {
    BitString b;
    ASSERT_EQ(b.size(), 0);
}

TEST(BitStringTest, InitListConstructor) {
    BitString b{1, 0, 1, 1};
    ASSERT_EQ(b.size(), 4);
    ASSERT_EQ(b.ToString(), "1011");
}

TEST(BitStringTest, FillConstructorAllZeros) {
    BitString b(5, 0);
    ASSERT_EQ(b.ToString(), "00000");
}

TEST(BitStringTest, FillConstructorAllOnes) {
    BitString b(3, 1);
    ASSERT_EQ(b.ToString(), "111");
}

TEST(BitStringTest, CopyConstructorCreatesExactCopy) {
    BitString a{1, 0, 1};
    BitString b = a;
    ASSERT_EQ(a.ToString(), b.ToString());
    ASSERT_NE(&a, &b);
}

TEST(BitStringTest, AndOperation) {
    BitString a{1, 0, 1, 1};
    BitString b{1, 1, 0, 0};
    BitString c = a.And(b);
    ASSERT_EQ(c.ToString(), "1000");
}

TEST(BitStringTest, OrOperation) {
    BitString a{1, 0, 1, 1};
    BitString b{1, 1, 0, 0};
    BitString c = a.Or(b);
    ASSERT_EQ(c.ToString(), "1111");
}

TEST(BitStringTest, XorOperation) {
    BitString a{1, 0, 1, 1};
    BitString b{1, 1, 0, 0};
    BitString c = a.Xor(b);
    ASSERT_EQ(c.ToString(), "0111");
}

TEST(BitStringTest, NotOperation) {
    BitString a{1, 0, 1, 1};
    BitString c = a.Not();
    ASSERT_EQ(c.ToString(), "0100");
}

TEST(BitStringTest, ThrowsOnInvalidBitValue) {
    ASSERT_THROW(BitString({2, 1, 0}), std::invalid_argument);
    ASSERT_THROW(BitString(5, 3), std::invalid_argument);
}

TEST(BitStringTest, OriginalUnchangedAfterOperation) {
    BitString a{1, 0, 1};
    BitString b{1, 1, 1};
    BitString result = a.And(b);
    ASSERT_EQ(a.ToString(), "101");
    ASSERT_EQ(result.ToString(), "101");
}

