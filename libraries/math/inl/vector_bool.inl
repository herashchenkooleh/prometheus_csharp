#pragma once

namespace prometheus::core::math
{
	template<typename type_t>
	/*inline*/ vector_bool<type_t>::vector_bool() noexcept
	{
	}

	template<typename type_t>
	/*inline*/ vector_bool<type_t>::vector_bool(vector_bool&&) noexcept
	{
	}

	template<typename type_t>
	/*inline*/ vector_bool<type_t>::vector_bool(const vector_bool&) noexcept
	{
	}

	template<typename type_t>
	/*inline*/ vector_bool<type_t>& vector_bool<type_t>::operator=(vector_bool&&) noexcept
	{
		return *this;
	}

	template<typename type_t>
	/*inline*/ vector_bool<type_t>& vector_bool<type_t>::operator=(const vector_bool&) noexcept
	{
		return *this;
	}

	template<typename type_t>
	/*inline*/ vector_bool<type_t>::~vector_bool() noexcept
	{
	}

	template<typename type_t>
	/*inline*/ type_t& vector_bool<type_t>::operator()() noexcept
	{
		return *static_cast<type_t*>(this);
	}

	template<typename type_t>
	/*inline*/ const type_t& vector_bool<type_t>::operator()() const noexcept
	{
		return *static_cast<const type_t*>(this);
	}

	template<typename type_t>
	/*inline*/ type_t& vector_bool<type_t>::operator&=(const type_t& rhs) noexcept
	{
		(*this) = (*this) && rhs;
		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t& vector_bool<type_t>::operator|=(const type_t& rhs) noexcept
	{
		(*this) = (*this) || rhs;
		return (*this)();
	}

	template<typename type_t>
	/*inline*/ type_t& vector_bool<type_t>::operator^=(const type_t& rhs) noexcept
	{
		(*this) = (*this) ^ rhs;
		return (*this)();
	}

	template <class type_t>
	/*inline*/ type_t operator&&(const vector_bool<type_t>& lhs, const vector_bool<type_t>& rhs) noexcept
	{
		return lhs() & rhs();
	}

	template <class type_t>
	/*inline*/ type_t operator&&(const vector_bool<type_t>& lhs, bool rhs) noexcept
	{
		return lhs() & rhs;
	}

	template <class type_t>
	/*inline*/ type_t operator&&(bool lhs, const vector_bool<type_t>& rhs) noexcept
	{
		return lhs & rhs();
	}

	template <class type_t>
	/*inline*/ type_t operator||(const vector_bool<type_t>& lhs, const vector_bool<type_t>& rhs) noexcept
	{
		return lhs() | rhs();
	}

	template <class type_t>
	/*inline*/ type_t operator||(const vector_bool<type_t>& lhs, bool rhs) noexcept
	{
		return lhs() | rhs;
	}

	template <class type_t>
	/*inline*/ type_t operator||(bool lhs, const vector_bool<type_t>& rhs) noexcept
	{
		return lhs | rhs();
	}

	template <class type_t>
	/*inline*/ type_t operator!(const vector_bool<type_t>& rhs) noexcept
	{
		return rhs() == 0;
	}
}