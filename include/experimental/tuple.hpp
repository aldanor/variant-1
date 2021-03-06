// Copyright Michael Park 2015
//
// Distributed under the Boost Software License, Version 1.0.(See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef EXPERIMENTAL_TUPLE_HPP
#define EXPERIMENTAL_TUPLE_HPP

#include <array>
#include <tuple>
#include <utility>

#include <experimental/__lib.hpp>

namespace std {
namespace experimental {
inline namespace fundamentals_v3 {

// `variant`
template <typename... Ts>
class variant;

// `tuple_not_found`
static constexpr size_t tuple_not_found = lib::npos;

template <typename T, typename Tuple>
struct tuple_count;  // undefined

template <typename T, typename Tuple>
static constexpr size_t tuple_count_v = tuple_count<T, Tuple>::value;

template <typename T, typename U, size_t N>
struct tuple_count<T, array<U, N>> : lib::size_constant<std::is_same<T, U>::value ? N : 0> {};

template <typename T, typename T1, typename T2>
struct tuple_count<T, pair<T1, T2>> : tuple_count<T, tuple<T1, T2>> {};

template <typename T, typename... Ts>
struct tuple_count<T, tuple<Ts...>> : lib::size_constant<lib::count({is_same<T, Ts>::value...}, true)> {};

template <typename T, typename... Ts>
struct tuple_count<T, variant<Ts...>> : tuple_count<T, tuple<Ts...>> {};

template <typename T, typename Tuple>
struct tuple_count<T, const Tuple> : tuple_count<T, Tuple> {};

template <typename T, typename Tuple>
struct tuple_count<T, volatile Tuple> : tuple_count<T, Tuple> {};

template <typename T, typename Tuple>
struct tuple_count<T, const volatile Tuple> : tuple_count<T, Tuple> {};

// `tuple_find`
template <typename T, typename Tuple>
struct tuple_find;  // undefined

template <typename T, typename Tuple>
static constexpr size_t tuple_find_v = tuple_find<T, Tuple>::value;

template <typename T, typename U, size_t N>
struct tuple_find<T, array<U, N>> : lib::size_constant<std::is_same<T, U>::value ? 0 : tuple_not_found> {};

template <typename T, typename T1, typename T2>
struct tuple_find<T, pair<T1, T2>> : tuple_find<T, tuple<T1, T2>> {};

template <typename T, typename... Ts>
struct tuple_find<T, tuple<Ts...>> : lib::size_constant<lib::find({is_same<T, Ts>::value...}, true)> {};

template <typename T, typename... Ts>
struct tuple_find<T, variant<Ts...>> : tuple_find<T, tuple<Ts...>> {};

template <typename T, typename Tuple>
struct tuple_find<T, const Tuple> : tuple_find<T, Tuple> {};

template <typename T, typename Tuple>
struct tuple_find<T, volatile Tuple> : tuple_find<T, Tuple> {};

template <typename T, typename Tuple>
struct tuple_find<T, const volatile Tuple> : tuple_find<T, Tuple> {};

// `tuple_size`
template <typename Tuple>
struct tuple_size : std::tuple_size<Tuple> {};

template <typename... Ts>
struct tuple_size<variant<Ts...>> : tuple_size<tuple<Ts...>> {};

template <typename Tuple>
static constexpr size_t tuple_size_v = tuple_size<Tuple>::value;

// `tuple_element`
template <size_t I, typename Tuple>
struct tuple_element : std::tuple_element<I, Tuple> {};

template <size_t I, typename... Ts>
struct tuple_element<I, variant<Ts...>> : tuple_element<I, tuple<Ts...>> {};

template <size_t I, typename Tuple>
using tuple_element_t = typename tuple_element<I, Tuple>::type;

}  // namespace fundamentals_v3
}  // namespace experimental
}  // namespace std

#endif  // EXPERIMENTAL_TUPLE_HPP
