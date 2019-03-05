#pragma once

namespace prometheus::core::math
{
	template<typename type_t>
	/*inline*/ matrix_bool<type_t>::matrix_bool() noexcept
	{
	}

	template<typename type_t>
	/*inline*/ matrix_bool<type_t>::matrix_bool(matrix_bool&&) noexcept
	{
	}

	template<typename type_t>
	/*inline*/ matrix_bool<type_t>::matrix_bool(const matrix_bool&) noexcept
	{
	}

	template<typename type_t>
	/*inline*/ matrix_bool<type_t>& matrix_bool<type_t>::operator=(matrix_bool&&) noexcept
	{
		return *this;
	}

	template<typename type_t>
	/*inline*/ matrix_bool<type_t>& matrix_bool<type_t>::operator=(const matrix_bool&) noexcept
	{
		return *this;
	}

	template<typename type_t>
	/*inline*/ matrix_bool<type_t>::~matrix_bool() noexcept
	{
	}
}