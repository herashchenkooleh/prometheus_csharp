#pragma once

#include "vector_bool.hpp"
#include <xmmintrin.h>

namespace prometheus::core::math
{
	class vector4_bool : public vector_bool<vector4_bool>
	{
	public:
		inline vector4_bool() noexcept;

		inline vector4_bool(const bool value) noexcept;
		inline vector4_bool(const bool value0,
							const bool value1,
							const bool value2,
							const bool value3 ) noexcept;

		inline vector4_bool(const __m128&) noexcept;

		inline vector4_bool(vector4_bool&&) noexcept;
		inline vector4_bool(const vector4_bool&) noexcept;

		inline vector4_bool& operator=(vector4_bool&&) noexcept;
		inline vector4_bool& operator=(const vector4_bool&) noexcept;
		inline vector4_bool& operator=(__m128&&) noexcept;
		inline vector4_bool& operator=(const __m128&) noexcept;

		inline ~vector4_bool() noexcept;

		inline operator __m128() const noexcept;

	private:
		__m128 m_value;
	};

	inline vector4_bool operator&(const vector4_bool& lhs, const vector4_bool& rhs) noexcept;

	inline vector4_bool operator|(const vector4_bool& lhs, const vector4_bool& rhs) noexcept;

	inline vector4_bool operator^(const vector4_bool& lhs, const vector4_bool& rhs) noexcept;

	inline vector4_bool operator~(const vector4_bool& rhs) noexcept;

	inline vector4_bool operator==(const vector4_bool& lhs, const vector4_bool& rhs) noexcept;
}

#include "vector4_bool.inl"