#pragma once

#include "matrix.hpp"

namespace prometheus::core::math
{
	class matrix4x4 : public matrix<matrix4x4>
	{
	public:
		inline matrix4x4() noexcept;

		inline matrix4x4(matrix4x4&&) noexcept;
		inline matrix4x4(const matrix4x4&) noexcept;

		inline matrix4x4& operator=(matrix4x4&&) noexcept;
		inline matrix4x4& operator=(const matrix4x4&) noexcept;

		inline ~matrix4x4() noexcept;
	};
}

#include "matrix4x4.inl"