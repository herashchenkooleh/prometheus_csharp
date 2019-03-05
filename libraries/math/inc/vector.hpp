#pragma once

namespace prometheus::core::math
{
	template<typename traits_type_t>
	class vector_traits;

	template<typename type_t>
	class vector
	{
	public:
		typedef typename vector_traits<type_t>::value_type value_type;

		inline vector() noexcept;

		inline vector(vector&&) noexcept;
		inline vector(const vector&) noexcept;

		inline vector& operator=(vector&&) noexcept;
		inline vector& operator=(const vector&) noexcept;

		inline ~vector() noexcept;

		inline type_t& operator()() noexcept;
		inline const type_t& operator()() const noexcept;

		inline type_t& operator+=(const type_t& rhs) noexcept;
		inline type_t& operator+=(const value_type& rhs) noexcept;

		inline type_t& operator-=(const type_t& rhs) noexcept;
		inline type_t& operator-=(const value_type& rhs) noexcept;

		inline type_t& operator*=(const type_t& rhs) noexcept;
		inline type_t& operator*=(const value_type& rhs) noexcept;

		inline type_t& operator/=(const type_t& rhs) noexcept;
		inline type_t& operator/=(const value_type& rhs) noexcept;

		inline type_t operator++(int) noexcept;
		inline type_t& operator++() noexcept;

		inline type_t operator--(int) noexcept;
		inline type_t& operator--() noexcept;
	};

	template <typename type_t>
	inline vector<type_t> operator+(const vector<type_t>& lhs,
									const typename vector_traits<type_t>::type& rhs) noexcept;
	template <typename type_t>
	inline vector<type_t> operator+(const typename vector_traits<type_t>::type& lhs,
									const vector<type_t>& rhs) noexcept;

	template <typename type_t>
	inline vector<type_t> operator-(const vector<type_t>& lhs,
									const typename vector_traits<type_t>::type& rhs) noexcept;
	template <typename type_t>
	inline vector<type_t> operator-(const typename vector_traits<type_t>::type& lhs,
									const vector<type_t>& rhs) noexcept;

	template <typename type_t>
	inline vector<type_t> operator*(const vector<type_t>& lhs,
									const typename vector_traits<type_t>::type& rhs) noexcept;
	template <typename type_t>
	inline vector<type_t> operator*(const typename vector_traits<type_t>::type& lhs,
									const vector<type_t>& rhs) noexcept;

	template <typename type_t>
	inline vector<type_t> operator/(const vector<type_t>& lhs,
									const typename vector_traits<type_t>::type& rhs) noexcept;
	template <typename type_t>
	inline vector<type_t> operator/(const typename vector_traits<type_t>::type& lhs,
									const vector<type_t>& rhs) noexcept;

	template <typename type_t>
	inline typename vector_traits<type_t>::vector_bool
		operator>(const vector<type_t>& lhs, const vector<type_t>& rhs) noexcept;

	template <typename type_t>
	inline typename vector_traits<type_t>::vector_bool
		operator>=(const vector<type_t>& lhs, const vector<type_t>& rhs) noexcept;

	template <typename type_t>
	inline typename vector_traits<type_t>::vector_bool
		operator<(const vector<type_t>& lhs, const vector<type_t>& rhs) noexcept;

	template <typename type_t>
	inline typename vector_traits<type_t>::vector_bool
		operator<=(const vector<type_t>& lhs, const vector<type_t>& rhs) noexcept;
}

#include "vector.inl"
