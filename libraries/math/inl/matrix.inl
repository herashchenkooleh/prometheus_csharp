#pragma once

namespace prometheus::core::math
{
	template<typename type_t>
	/*inline*/ matrix<type_t>::matrix() noexcept
	{
	}

	template<typename type_t>
	/*inline*/ matrix<type_t>::matrix(matrix&&) noexcept
	{
	}

	template<typename type_t>
	/*inline*/ matrix<type_t>::matrix(const matrix&) noexcept
	{
	}

	template<typename type_t>
	/*inline*/ matrix<type_t>& matrix<type_t>::operator=(matrix&&) noexcept
	{
		return *this;
	}

	template<typename type_t>
	/*inline*/ matrix<type_t>& matrix<type_t>::operator=(const matrix&) noexcept
	{
		return *this;
	}

	template<typename type_t>
	/*inline*/ matrix<type_t>::~matrix() noexcept
	{
	}
}