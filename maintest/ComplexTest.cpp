#include <gtest.h>
#include "ComplexClass.h"

TEST(TComplexTest, Constructors)
{
TComplex<int> defaultComplex;
EXPECT_EQ(defaultComplex.GetRe(), 1);
EXPECT_EQ(defaultComplex.GetIm(), 0);

TComplex<double> paramComplex(3.5, -2.1);
EXPECT_DOUBLE_EQ(paramComplex.GetRe(), 3.5);
EXPECT_DOUBLE_EQ(paramComplex.GetIm(), -2.1);

TComplex<int> original(5, 7);
TComplex<int> copy(original);
EXPECT_EQ(copy.GetRe(), 5);
EXPECT_EQ(copy.GetIm(), 7);
}

TEST(TComplexTest, Accessors)
{
TComplex<float> c;
c.SetRe(3.14f);
c.SetIm(-2.71f);

EXPECT_FLOAT_EQ(c.GetRe(), 3.14f);
EXPECT_FLOAT_EQ(c.GetIm(), -2.71f);
}

TEST(TComplexTest, BasicArithmetic)
{
TComplex<int> a(2, 3);
TComplex<int> b(4, 5);

TComplex<int> sum = a + b;
EXPECT_EQ(sum.GetRe(), 6);
EXPECT_EQ(sum.GetIm(), 8);

TComplex<int> diff = a - b;
EXPECT_EQ(diff.GetRe(), -2);
EXPECT_EQ(diff.GetIm(), -2);

TComplex<int> mul = a * b;
EXPECT_EQ(mul.GetRe(), 2*4 - 3*5); // -7
EXPECT_EQ(mul.GetIm(), 2*5 + 3*4); // 22

TComplex<double> div1(4.0, 4.0);
TComplex<double> div2(2.0, 0.0);
TComplex<double> quotient = div1 / div2;
EXPECT_DOUBLE_EQ(quotient.GetRe(), 2.0);
EXPECT_DOUBLE_EQ(quotient.GetIm(), 2.0);
}

TEST(TComplexTest, CompoundOperators)
{
TComplex<int> a(1, 2);
TComplex<int> b(3, 4);

a += b;
EXPECT_EQ(a.GetRe(), 4);
EXPECT_EQ(a.GetIm(), 6);

a -= b;
EXPECT_EQ(a.GetRe(), 1);
EXPECT_EQ(a.GetIm(), 2);

TComplex<int> c(2, 3);
c *= TComplex<int>(1, 0);
EXPECT_EQ(c.GetRe(), 2);
EXPECT_EQ(c.GetIm(), 3);
}

TEST(TComplexTest, ComparisonOperators)
{
TComplex<int> a(2, 3);
TComplex<int> b(2, 3);
TComplex<int> c(3, 2);

EXPECT_TRUE(a == b);
EXPECT_FALSE(a == c);
EXPECT_TRUE(a != c);
EXPECT_FALSE(a != b);
}

TEST(TComplexTest, AbsoluteValue)
{
TComplex<double> c(3.0, 4.0);
EXPECT_DOUBLE_EQ(c.ComplexAbs(), 5.0);

TComplex<float> d(0.0f, 0.0f);
EXPECT_FLOAT_EQ(d.ComplexAbs(), 0.0f);
}

TEST(TComplexTest, AssignmentOperator)
{
TComplex<int> a(5, 6);
TComplex<int> b;
b = a;
EXPECT_EQ(b.GetRe(), 5);
EXPECT_EQ(b.GetIm(), 6);
}

TEST(TComplexTest, DivideEqualsOperator)
{
TComplex<double> a(4.0, 4.0);
TComplex<double> b(2.0, 0.0);
a /= b;
EXPECT_DOUBLE_EQ(a.GetRe(), 2.0);
EXPECT_DOUBLE_EQ(a.GetIm(), 2.0);
}

TEST(TComplexTest, EdgeCases)
{
TComplex<int> zero(0, 0);
TComplex<int> c(2, 3);
EXPECT_EQ((c * zero).GetRe(), 0);
EXPECT_EQ((c * zero).GetIm(), 0);

TComplex<double> one(1.0, 0.0);
TComplex<double> d(5.0, -3.0);
TComplex<double> res = d / one;
EXPECT_DOUBLE_EQ(res.GetRe(), 5.0);
EXPECT_DOUBLE_EQ(res.GetIm(), -3.0);
}


TEST(TComplexTest, AbsMethod) {
  TComplex<double> c(3.0, 4.0);
  EXPECT_DOUBLE_EQ(c.ComplexAbs(), 5.0);
}

TEST(TComplexTest, FractionalPowerBasic) {
  TComplex<double> c(4.0, 0.0);
  TComplex<double> res = c.Power(0.5);
  EXPECT_NEAR(res.GetRe(), 2.0, 1e-6);
  EXPECT_NEAR(res.GetIm(), 0.0, 1e-6);
}

TEST(TComplexTest, NegativeBaseFractionalPower) {
  TComplex<double> c(-1, 0);
  TComplex<double> res = c.Power(0.5);
  EXPECT_NEAR(res.GetRe(), 0.0, 1e-6);
  EXPECT_NEAR(res.GetIm(), 1.0, 1e-6);
}

TEST(TComplexTest, ComplexNumberFractionalPower) {
  TComplex<double> c(1, 1);
  TComplex<double> res = c.Power(0.5);
  EXPECT_NEAR(res.GetRe(), 1.098684, 1e-6);
  EXPECT_NEAR(res.GetIm(), 0.455090, 1e-6);
}

TEST(TComplexTest, NegativeExponent) {
  TComplex<double> c(2, 0);
  TComplex<double> res = c.Power(-1.5);
  EXPECT_NEAR(res.GetRe(), 0.353553, 1e-6);
  EXPECT_NEAR(res.GetIm(), 0.0, 1e-6);
}

TEST(TComplexTest, ZeroToFractionalPower) {
  TComplex<double> c(0, 0);
  TComplex<double> res = c.Power(3.5);
  EXPECT_DOUBLE_EQ(res.GetRe(), 0.0);
  EXPECT_DOUBLE_EQ(res.GetIm(), 0.0);
}

TEST(TComplexTest, InvalidZeroPower) {
  TComplex<double> c(0, 0);
  EXPECT_THROW(c.Power(-2.5), std::invalid_argument);
  EXPECT_THROW(c.Power(0.0), std::invalid_argument);
}