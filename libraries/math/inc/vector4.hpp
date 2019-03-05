#pragma once

#include "vector.hpp"
#include "vector4_bool.hpp"

namespace prometheus::core::math
{
	class vector4;

	template <>
	struct vector_traits<vector4>
	{
		typedef float value_type;
		typedef vector4_bool vector_bool;
	};

	class vector4 : public vector<vector4>
	{
	public:
		inline vector4() noexcept;

		inline vector4(const float) noexcept;
		inline vector4(const float, const float, const float, const float) noexcept;
		inline vector4(const __m128&) noexcept;

		inline vector4(vector4&&) noexcept;
		inline vector4(const vector4&) noexcept;

		inline vector4& operator=(vector4&&) noexcept;
		inline vector4& operator=(const vector4&) noexcept;
		inline vector4& operator=(__m128&&) noexcept;
		inline vector4& operator=(const __m128&) noexcept;

		inline ~vector4() noexcept;

		inline operator __m128() const noexcept;

		inline float x() const noexcept;
		inline float y() const noexcept;
		inline float z() const noexcept;
		inline float w() const noexcept;

	private:
		__m128 m_value;
	};

	inline vector4_bool operator!=(const vector4&, const vector4_bool&) noexcept;
	inline vector4_bool operator==(const vector4&, const vector4&) noexcept;
	inline vector4_bool operator!=(const vector4&, const vector4&) noexcept;
	inline vector4_bool operator<(const vector4&, const vector4&) noexcept;
	inline vector4_bool operator<=(const vector4&, const vector4&) noexcept;

	inline vector4 operator+(const vector4& lhs, const vector4& rhs) noexcept;
	inline vector4 operator-(const vector4& lhs, const vector4& rhs) noexcept;
	inline vector4 operator*(const vector4& lhs, const vector4& rhs) noexcept;
	inline vector4 operator/(const vector4& lhs, const vector4& rhs) noexcept;
}

#include "vector4.inl"