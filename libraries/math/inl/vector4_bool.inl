#pragma once

#include <emmintrin.h>
#include <utility>

namespace prometheus::core::math
{
	/*inline*/ vector4_bool::vector4_bool() noexcept
		: m_value(_mm_setzero_ps())
	{
	}

	/*inline*/ vector4_bool::vector4_bool(const bool value) noexcept
		: m_value(_mm_castsi128_ps(_mm_set1_epi32(-(int)value)))
	{
	}

	/*inline*/ vector4_bool::vector4_bool(const bool value0,
										const bool value1,
										const bool value2,
										const bool value3) noexcept
		: m_value(_mm_castsi128_ps(_mm_setr_epi32(-(int)value0, -(int)value1, -(int)value2, -(int)value3)))
	{
	}

	/*inline*/ vector4_bool::vector4_bool(const __m128& value) noexcept
		: m_value(value)
	{
	}

	/*inline*/ vector4_bool::vector4_bool(vector4_bool&& vector) noexcept
		: m_value(std::move(vector.m_value))
	{
	}

	/*inline*/ vector4_bool::vector4_bool(const vector4_bool& vector) noexcept
		: m_value(vector.m_value)
	{
	}

	/*inline*/ vector4_bool& vector4_bool::operator=(vector4_bool&& vector) noexcept
	{
		if (this != &vector)
		{
			m_value = std::move(vector.m_value);
		}

		return *this;
	}

	/*inline*/ vector4_bool& vector4_bool::operator=(const vector4_bool& vector) noexcept
	{
		if (this != &vector)
		{
			m_value = vector.m_value;
		}

		return *this;
	}

	/*inline*/ vector4_bool& vector4_bool::operator=(__m128&& value) noexcept
	{
		m_value = std::move(value);

		return *this;
	}

	/*inline*/ vector4_bool& vector4_bool::operator=(const __m128& value) noexcept
	{
		m_value = value;

		return *this;
	}

	/*inline*/ vector4_bool::~vector4_bool() noexcept
	{
	}

	/*inline*/ vector4_bool::operator __m128() const noexcept
	{
		return m_value;
	}

	/*inline*/ vector4_bool operator&(const vector4_bool& lhs, const vector4_bool& rhs) noexcept
	{
		return _mm_and_ps(lhs, rhs);
	}

	/*inline*/ vector4_bool operator|(const vector4_bool& lhs, const vector4_bool& rhs) noexcept
	{
		return _mm_or_ps(lhs, rhs);
	}

	/*inline*/ vector4_bool operator^(const vector4_bool& lhs, const vector4_bool& rhs) noexcept
	{
		return _mm_xor_ps(lhs, rhs);
	}

	/*inline*/ vector4_bool operator~(const vector4_bool& rhs) noexcept
	{
		return _mm_xor_ps(rhs, _mm_castsi128_ps(_mm_set1_epi32(-1)));
	}

	/*inline*/ vector4_bool operator==(const vector4_bool& lhs, const vector4_bool& rhs) noexcept
	{
		return _mm_cmpeq_ps(lhs, rhs);
	}


}