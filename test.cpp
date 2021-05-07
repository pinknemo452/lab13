#include "gtest/gtest.h"
#include "../lab13/IntSet.h"
#include  "../lab13/IntSet.cpp"
TEST(operatorstests, sum) {
	int a[3] = { 1,2,3 };
	int b[3] = { 4,5,6 };
	const IntSet set1(a, 3),set2(b,3);
	const auto set3 = set1 + set2;
	int res[6] = { 1,2,3,4,5,6 };
	const IntSet set4(res, 6);
		EXPECT_TRUE(set3 == set4);
}

TEST(operatorstests, minus) {
	int a[4] = { 1,2,3,4 };
	int b[3] = { 4,5,6 };
	const IntSet set1(a, 4), set2(b, 3);
	const auto set3 = set1 - set2;
	int res[3] = { 1,2,3 };
	const IntSet set4(res, 3);
	EXPECT_TRUE(set3 == set4);
}

TEST(operatorstests, multiply) {
	int a[4] = { 1,2,4 };
	int b[3] = { 4,5,6 };
	const IntSet set1(a, 3), set2(b, 3);
	const auto set3 = set1 * set2;
	int res[1] = { 4 };
	const IntSet set4(res, 1);
	EXPECT_TRUE(set3 == set4);
}
TEST(operatorstests, greater) {
	int a[5] = { 1,2,4,5,6 };
	int b[3] = { 4,5,6 };
	const IntSet set1(a, 5), set2(b, 3);
	EXPECT_TRUE(set1 > set2);
}
TEST(operatorstests, less) {
	int a[5] = { 1,2,4,5,6 };
	int b[3] = { 4,5,6 };
	const IntSet set1(a, 5), set2(b, 3);
	EXPECT_TRUE(set2 < set1);
}

TEST(operatorstests, sumint) {
	int a[5] = { 1,2,4,5,6 };
	IntSet set1(a, 5);
	set1 + 7;
	int b[6] = { 1,2,4,5,6,7 };
	const IntSet set2(b, 6);
	EXPECT_TRUE(set2 == set1);
}
TEST(operatorstests, minusint) {
	int a[5] = { 1,2,4,5,6 };
	IntSet set1(a, 5);
	set1 - 6;
	int b[4] = { 1,2,4,5 };
	const IntSet set2(b, 4);
	EXPECT_TRUE(set2 == set1);
}