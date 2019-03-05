#pragma once

namespace prometheus::core::math
{
	/*inline*/ vector4::vector4() noexcept
		: m_value(_mm_setzero_ps())
	{
	}

	/*inline*/ vector4::vector4(const float f) noexcept
		: m_value(_mm_set1_ps(f))
	{
	}

	/*inline*/ vector4::vector4(const float f0, const float f1, const float f2, const float f3) noexcept
		: m_value(_mm_setr_ps(f0, f1, f2, f3))
	{
	}

	/*inline*/ vector4::vector4(const __m128& rhs) noexcept
		: m_value(rhs)
	{
	}

	/*inline*/ vector4::vector4(vector4&& vector) noexcept
		: m_value(std::move(vector.m_value))
	{
	}

	/*inline*/ vector4::vector4(const vector4& vector) noexcept
		: m_value(vector.m_value)
	{
	}

	/*inline*/ vector4& vector4::operator=(vector4&& vector) noexcept
	{
		if (this != &vector)
		{
			m_value = std::move(vector.m_value);
		}

		return *this;
	}

	/*inline*/ vector4& vector4::operator=(const vector4& vector) noexcept
	{
		if (this != &vector)
		{
			m_value = vector.m_value;
		}

		return *this;
	}

	/*inline*/ vector4& vector4::operator=(__m128&& value) noexcept
	{
		m_value = std::move(value);

		return *this;
	}

	/*inline*/ vector4& vector4::operator=(const __m128& value) noexcept
	{
		m_value = value;

		return *this;
	}

	/*inline*/ vector4::~vector4() noexcept
	{
	}

	/*inline*/ vector4::operator __m128() const noexcept
	{
		return m_value;
	}

	/*inline*/ vector4_bool operator!=(const vector4& lhs, const vector4_bool& rhs) noexcept
	{
		return _mm_cmpneq_ps(lhs, rhs);
	}

	/*inline*/ vector4_bool operator==(const vector4& lhs, const vector4& rhs) noexcept
	{
		return _mm_cmpeq_ps(lhs, rhs);
	}

	/*inline*/ vector4_bool operator!=(const vector4& lhs, const vector4& rhs) noexcept
	{
		return _mm_cmpneq_ps(lhs, rhs);
	}

	/*inline*/ vector4_bool operator<(const vector4& lhs, const vector4& rhs) noexcept
	{
		return _mm_cmplt_ps(lhs, rhs);
	}

	/*inline*/ vector4_bool operator<=(const vector4& lhs, const vector4& rhs) noexcept
	{
		return _mm_cmple_ps(lhs, rhs);
	}

	/*inline*/ vector4 operator+(const vector4& lhs, const vector4& rhs) noexcept
	{
		return _mm_add_ps(lhs, rhs);
	}

	/*inline*/ vector4 operator-(const vector4& lhs, const vector4& rhs) noexcept
	{
		return _mm_sub_ps(lhs, rhs);
	}

	/*inline*/ vector4 operator*(const vector4& lhs, const vector4& rhs) noexcept
	{
		return _mm_mul_ps(lhs, rhs);
	}

	/*inline*/ vector4 operator/(const vector4& lhs, const vector4& rhs) noexcept
	{
		return _mm_div_ps(lhs, rhs);
	}

	/*inline*/ float vector4::x() const noexcept
	{
		return m_value.m128_f32[0];
	}

	/*inline*/ float vector4::y() const noexcept
	{
		return m_value.m128_f32[1];
	}

	/*inline*/ float vector4::z() const noexcept
	{
		return m_value.m128_f32[2];
	}

	/*inline*/ float vector4::w() const noexcept
	{
		return m_value.m128_f32[3];
	}
}