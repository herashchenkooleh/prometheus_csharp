#pragma once

namespace prometheus::core::math
{
	template<typename type_t>
	class matrix
	{
	public:
		inline matrix() noexcept;

		inline matrix(matrix&&) noexcept;
		inline matrix(const matrix&) noexcept;

		inline matrix& operator=(matrix&&) noexcept;
		inline matrix& operator=(const matrix&) noexcept;

		inline ~matrix() noexcept;
	};
}

#include "matrix.inl"