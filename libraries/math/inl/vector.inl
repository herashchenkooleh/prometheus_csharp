#pragma once

namespace prometheus::core::math
{
	template<typename type_t>
	/*inline*/ vector<type_t>::vector() noexcept
	{
	}

	template<typename type_t>
	/*inline*/ vector<type_t>::vector(vector&&) noexcept
	{
	}

	template<typename type_t>
	/*inline*/ vector<type_t>::vector(const vector&) noexcept
	{
	}

	template<typename type_t>
	/*inline*/ vector<type_t>& vector<type_t>::operator=(vector&&) noexcept
	{
		return *this;
	}

	template<typename type_t>
	/*inline*/ vector<type_t>& vector<type_t>::operator=(const vector&) noexcept
	{
		return *this;
	}

	template<typename type_t>
	/*inline*/ vector<type_t>::~vector() noexcept
	{
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator()() noexcept
	{
		return *static_cast<type_t*>(this);
	}

	template<typename type_t>
	/*inline*/ const type_t& vector<type_t>::operator()() const noexcept
	{
		return *static_cast<const type_t*>(this);
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator+=(const type_t& rhs) noexcept
	{
		(*this)() = *(this)() + rhs;

		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator+=(const value_type& rhs) noexcept
	{
		(*this)() = *(this)() + type_t(rhs);

		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator-=(const type_t& rhs) noexcept
	{
		(*this)() = *(this)() - rhs;

		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator-=(const value_type& rhs) noexcept
	{
		(*this)() = *(this)() - type_t(rhs);

		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator*=(const type_t& rhs) noexcept
	{
		(*this)() = *(this)() * rhs;

		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator*=(const value_type& rhs) noexcept
	{
		(*this)() = *(this)() * type_t(rhs);

		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator/=(const type_t& rhs) noexcept
	{
		(*this)() = *(this)() / rhs;

		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator/=(const value_type& rhs) noexcept
	{
		(*this)() = *(this)() / type_t(rhs);

		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t vector<type_t>::operator++(int) noexcept
	{
		type_t tmp = (*this)();
		(*this) += value_type(1);

		return tmp;
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator++() noexcept
	{
		(*this)() += value_type(1);
		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t vector<type_t>::operator--(int) noexcept
	{
		type_t tmp = (*this)();
		(*this) -= value_type(1);

		return tmp;
	}

	template<typename type_t>
	/*inline*/ type_t& vector<type_t>::operator--() noexcept
	{
		(*this)() -= value_type(1);
		return (*this)();
	}

	template <typename type_t>
	/*inline*/ vector<type_t> operator+(const vector<type_t>& lhs, const typename vector_traits<type_t>::type& rhs) noexcept
	{
		return lhs() + type_t(rhs);
	}

	template <typename type_t>
	/*inline*/ vector<type_t> operator+(const typename vector_traits<type_t>::type& lhs, const vector<type_t>& rhs) noexcept
	{
		return type_t(lhs) + rhs();
	}

	template <typename type_t>
	/*inline*/ vector<type_t> operator-(const vector<type_t>& lhs, const typename vector_traits<type_t>::type& rhs) noexcept
	{
		return lhs() - type_t(rhs);
	}

	template <typename type_t>
	/*inline*/ vector<type_t> operator-(const typename vector_traits<type_t>::type& lhs, const vector<type_t>& rhs) noexcept
	{
		return type_t(lhs) - rhs();
	}

	template <typename type_t>
	/*inline*/ vector<type_t> operator*(const vector<type_t>& lhs, const typename vector_traits<type_t>::type& rhs) noexcept
	{
		return lhs() * type_t(rhs);
	}

	template <typename type_t>
	/*inline*/ vector<type_t> operator*(const typename vector_traits<type_t>::type& lhs, const vector<type_t>& rhs) noexcept
	{
		return type_t(lhs) * rhs();
	}

	template <typename type_t>
	/*inline*/ vector<type_t> operator/(const vector<type_t>& lhs, const typename vector_traits<type_t>::type& rhs) noexcept
	{
		return lhs() / type_t(rhs);
	}

	template <typename type_t>
	/*inline*/ vector<type_t> operator/(const typename vector_traits<type_t>::type& lhs, const vector<type_t>& rhs) noexcept
	{
		return type_t(lhs) / rhs();
	}

	template <typename type_t>
	/*inline*/ typename vector_traits<type_t>::vector_bool
		operator>(const vector<type_t>& lhs, const vector<type_t>& rhs) noexcept
	{
		return rhs() <= lhs();
	}

	template <typename type_t>
	/*inline*/ typename vector_traits<type_t>::vector_bool
		operator>=(const vector<type_t>& lhs, const vector<type_t>& rhs) noexcept
	{
		return rhs() < lhs();
	}

	template <typename type_t>
	/*inline*/ typename vector_traits<type_t>::vector_bool
		operator<(const vector<type_t>& lhs, const vector<type_t>& rhs) noexcept
	{
		return rhs() >= lhs();
	}

	template <typename type_t>
	/*inline*/ typename vector_traits<type_t>::vector_bool
		operator<=(const vector<type_t>& lhs, const vector<type_t>& rhs) noexcept
	{
		return rhs() > lhs();
	}
}