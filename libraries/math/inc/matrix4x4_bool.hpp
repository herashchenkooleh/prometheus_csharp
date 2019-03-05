#pragma once

#include "matrix_bool.hpp"

namespace prometheus::core::math
{
	class matrix4x4_bool : public matrix_bool<matrix4x4_bool>
	{
	public:
		inline matrix4x4_bool() noexcept;

		inline matrix4x4_bool(matrix4x4_bool&&) noexcept;
		inline matrix4x4_bool(const matrix4x4_bool&) noexcept;

		inline matrix4x4_bool& operator=(matrix4x4_bool&&) noexcept;
		inline matrix4x4_bool& operator=(const matrix4x4_bool&) noexcept;

		inline ~matrix4x4_bool() noexcept;
	};
}

#include "matrix4x4_bool.inl"