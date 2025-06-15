#ifndef CHAT_TYPE_TRAITS_H
#define CHAT_TYPE_TRAITS_H

#include "employeeschatpage.h"

struct true_type {
    static constexpr bool value = true;
};

struct false_type {
    static constexpr bool value = false;
};

template <bool>
struct bool_constant : true_type {};

template <>
struct bool_constant<false> : false_type{};

template <typename T>
struct is_corporate : public false_type{};

template <>
struct is_corporate<EmployeesChatPage> : public true_type{};

template <typename T>
struct is_not_corporate : public bool_constant<!is_corporate<T>::value>{};

template <typename T>
concept HasChatUnits = requires{
    T::ChatUnits::chat_id;
    T::ChatUnits::partner_id;
    T::ChatUnits::my_participant_id;
    T::ChatUnits::partner_participant_id;
};

#endif // CHAT_TYPE_TRAITS_H
