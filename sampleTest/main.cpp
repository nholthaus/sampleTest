#include <gtest/gtest.h>

#include <string>
#include <math.h>

namespace {

	class SampleTest : public ::testing::Test {
	protected:

		SampleTest() {};
		virtual ~SampleTest() {};
		virtual void SetUp() {};
		virtual void TearDown() {};
	};
}

bool less_than(int a, int b) { return a < b; }
bool negative(int a) { return a < 0; }

TEST_F(SampleTest, expectTrue)
{
	bool test = false;
	EXPECT_TRUE(test);
	EXPECT_TRUE(false);
}

TEST_F(SampleTest, expectFalse)
{
	bool test = true;
	EXPECT_FALSE(test);
	EXPECT_FALSE(true);
}

TEST_F(SampleTest, expectEqual)
{
	int lhs = 1;
	int rhs = 2;
	EXPECT_EQ(lhs, rhs);
	EXPECT_EQ(3, 4);
}

TEST_F(SampleTest, expectNotEqual)
{
	int lhs = 1;
	int rhs = 1;
	EXPECT_NE(lhs, rhs);
	EXPECT_NE(2, 2);
}

TEST_F(SampleTest, expectLessThan)
{
	int lhs = 2;
	int rhs = 1;
	EXPECT_LT(lhs, rhs);
	EXPECT_LT(4, 3);
}

TEST_F(SampleTest, expectLessThanOrEqual)
{
	int lhs = 2;
	int rhs = 1;
	EXPECT_LE(lhs, rhs);
	EXPECT_LE(4, 3);
}

TEST_F(SampleTest, expectGreaterThan)
{
	int lhs = 1;
	int rhs = 2;
	EXPECT_GT(lhs, rhs);
	EXPECT_GT(3, 4);
}

TEST_F(SampleTest, expectGreaterThanOrEqual)
{
	int lhs = 1;
	int rhs = 2;
	EXPECT_GE(lhs, rhs);
	EXPECT_GE(3, 4);
}

TEST_F(SampleTest, expectStringEqual)
{
	std::string lhs("hello");
	std::string rhs("world");
	EXPECT_STREQ(lhs.c_str(), rhs.c_str());
	EXPECT_STREQ("not", "equal");
}

TEST_F(SampleTest, expectStringNotEqual)
{
	std::string lhs("hello");
	std::string rhs("hello");
	EXPECT_STRNE(lhs.c_str(), rhs.c_str());
	EXPECT_STRNE("equal", "equal");
}

TEST_F(SampleTest, expectStringCaseEqual)
{
	std::string lhs("hello");
	std::string rhs("world");
	EXPECT_STRCASEEQ(lhs.c_str(), rhs.c_str());
	EXPECT_STRCASEEQ("not", "equal");
}

TEST_F(SampleTest, expectStringCaseNotEqual)
{
	std::string lhs("hello");
	std::string rhs("hello");
	EXPECT_STRCASENE(lhs.c_str(), rhs.c_str());
	EXPECT_STRCASENE("equal", "equal");
}

TEST_F(SampleTest, expectFloatEqual)
{
	float lhs = 1.2345;
	float rhs = 2.3456;
	EXPECT_FLOAT_EQ(lhs, rhs);
	EXPECT_FLOAT_EQ(3.0, 4.0);
}

TEST_F(SampleTest, expectDoubleEqual)
{
	double lhs = 1.2345;
	double rhs = 2.3456;
	EXPECT_DOUBLE_EQ(lhs, rhs);
	EXPECT_DOUBLE_EQ(3.0, 4.0);
}

TEST_F(SampleTest, expectNear)
{
	double lhs = 1.2345;
	double rhs = 2.3456;
	double tol = 0.5;
	EXPECT_NEAR(lhs, rhs, tol);
	EXPECT_NEAR(3.0, 4.0, 0.5);
}

TEST_F(SampleTest, expextThrow)
{
	int i = 1;
	EXPECT_THROW(negative(i), std::out_of_range);
	EXPECT_THROW(negative(2), std::out_of_range);
}

TEST_F(SampleTest, expextAnyThrow)
{
	int i = 1;
	EXPECT_ANY_THROW(negative(i));
	EXPECT_ANY_THROW(negative(2));
}

TEST_F(SampleTest, expextNoThrow)
{
	EXPECT_NO_THROW(throw std::bad_alloc());
	EXPECT_NO_THROW(throw std::bad_alloc());
}

TEST_F(SampleTest, expexctDeath)
{
	int i = 1;
	EXPECT_DEATH(negative(i), "death");
	EXPECT_DEATH(negative(2), "death");
}

TEST_F(SampleTest, expectExit)
{
	int i = 1;
	EXPECT_EXIT(negative(i), negative, "exit");
	EXPECT_EXIT(negative(2), negative, "exit");
}

TEST_F(SampleTest, addFailure)
{
	ADD_FAILURE();
}

TEST_F(SampleTest, addFailureAt)
{
	ADD_FAILURE_AT("C:/workspace/sampleTest/sampleTest/main.cpp", 106);
}

TEST_F(SampleTest, expectPred1)
{
	EXPECT_PRED1(negative, 1);
}

TEST_F(SampleTest, expectPred2)
{
	EXPECT_PRED2(less_than, 2, 1);
}
int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}