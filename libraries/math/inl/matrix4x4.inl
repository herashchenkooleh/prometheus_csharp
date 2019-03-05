#pragma once

namespace prometheus::core::math
{
	/*inline*/ matrix4x4::matrix4x4() noexcept
	{
	}

	/*inline*/ matrix4x4::matrix4x4(matrix4x4&&) noexcept
	{
	}

	/*inline*/ matrix4x4::matrix4x4(const matrix4x4&) noexcept
	{
	}

	/*inline*/ matrix4x4& matrix4x4::operator=(matrix4x4&&) noexcept
	{
		return *this;
	}

	/*inline*/ matrix4x4& matrix4x4::operator=(const matrix4x4&) noexcept
	{
		return *this;
	}

	/*inline*/ matrix4x4::~matrix4x4() noexcept
	{
	}
}