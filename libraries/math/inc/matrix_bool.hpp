#pragma once

namespace prometheus::core::math
{
	template<typename type_t>
	class matrix_bool
	{
	public:
		inline matrix_bool() noexcept;

		inline matrix_bool(matrix_bool&&) noexcept;
		inline matrix_bool(const matrix_bool&) noexcept;

		inline matrix_bool& operator=(matrix_bool&&) noexcept;
		inline matrix_bool& operator=(const matrix_bool&) noexcept;

		inline ~matrix_bool() noexcept;
	};
}

#include "matrix_bool.inl"