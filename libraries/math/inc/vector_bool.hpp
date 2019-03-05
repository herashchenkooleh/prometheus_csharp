#pragma once

namespace prometheus::core::math
{
	template<typename type_t>
	class vector_bool
	{
	public:
		inline vector_bool() noexcept;

		inline vector_bool(vector_bool&&) noexcept;
		inline vector_bool(const vector_bool&) noexcept;

		inline vector_bool& operator=(vector_bool&&) noexcept;
		inline vector_bool& operator=(const vector_bool&) noexcept;

		inline ~vector_bool() noexcept;

		inline type_t& operator()() noexcept;
		inline const type_t& operator()() const noexcept;

		inline type_t& operator&=(const type_t& rhs) noexcept;
		inline type_t& operator|=(const type_t& rhs) noexcept;
		inline type_t& operator^=(const type_t& rhs) noexcept;
	};

	template <class type_t>
	inline type_t operator&&(const vector_bool<type_t>& lhs,
							const vector_bool<type_t>& rhs) noexcept;

	template <class type_t>
	inline type_t operator&&(const vector_bool<type_t>& lhs, bool rhs) noexcept;

	template <class type_t>
	inline type_t operator&&(bool lhs, const vector_bool<type_t>& rhs) noexcept;

	template <class type_t>
	inline type_t operator||(const vector_bool<type_t>& lhs,
							const vector_bool<type_t>& rhs) noexcept;

	template <class type_t>
	inline type_t operator||(const vector_bool<type_t>& lhs, bool rhs) noexcept;

	template <class type_t>
	inline type_t operator||(bool lhs, const vector_bool<type_t>& rhs) noexcept;

	template <class type_t>
	inline type_t operator!(const vector_bool<type_t>& rhs) noexcept;
}

#include "vector_bool.inl"