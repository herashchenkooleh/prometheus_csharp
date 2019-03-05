#include "gtest/gtest.h"
#include "vector4.hpp"

TEST(vector4, default_contructor)
{
	const float default_value = 0.0f;
	prometheus::core::math::vector4 vec;

	EXPECT_FLOAT_EQ(vec.x(), default_value);
	EXPECT_FLOAT_EQ(vec.y(), default_value);
	EXPECT_FLOAT_EQ(vec.z(), default_value);
	EXPECT_FLOAT_EQ(vec.w(), default_value);
}

TEST(vector4, single_value_contructor)
{
	const float default_value = 55.45f;
	prometheus::core::math::vector4 vec(default_value);

	EXPECT_FLOAT_EQ(vec.x(), default_value);
	EXPECT_FLOAT_EQ(vec.y(), default_value);
	EXPECT_FLOAT_EQ(vec.z(), default_value);
	EXPECT_FLOAT_EQ(vec.w(), default_value);
}

TEST(vector4, multi_value_contructor2)
{
	const float default_value_x = 45.45f;
	const float default_value_y = -55.55f;
	const float default_value_z = 65.65f;
	const float default_value_w = -75.75f;

	prometheus::core::math::vector4 vec(default_value_x,
										default_value_y,
										default_value_z,
										default_value_w);

	EXPECT_FLOAT_EQ(vec.x(), default_value_x);
	EXPECT_FLOAT_EQ(vec.y(), default_value_y);
	EXPECT_FLOAT_EQ(vec.z(), default_value_z);
	EXPECT_FLOAT_EQ(vec.w(), default_value_w);
}

TEST(vector4, constructor)
{
	const float default_value_x = 45.45f;
	const float default_value_y = -55.55f;
	const float default_value_z = 65.65f;
	const float default_value_w = -75.75f;

	prometheus::core::math::vector4 vec(default_value_x,
										default_value_y,
										default_value_z,
										default_value_w);

	auto vec2 = vec;

	EXPECT_FLOAT_EQ(vec.x(), default_value_x);
	EXPECT_FLOAT_EQ(vec.y(), default_value_y);
	EXPECT_FLOAT_EQ(vec.z(), default_value_z);
	EXPECT_FLOAT_EQ(vec.w(), default_value_w);

	EXPECT_FLOAT_EQ(vec2.x(), default_value_x);
	EXPECT_FLOAT_EQ(vec2.y(), default_value_y);
	EXPECT_FLOAT_EQ(vec2.z(), default_value_z);
	EXPECT_FLOAT_EQ(vec2.w(), default_value_w);
}

