#ifndef CHAT_TYPE_TRAITS_H
#define CHAT_TYPE_TRAITS_H

#include <type_traits>
#include "employeeschatpage.h"

template <typename T>
struct is_corporate : public std::false_type{};

template <>
struct is_corporate<EmployeesChatPage> : public std::true_type{};

template <typename T>
concept HasChatUnits = requires{
    T::ChatUnits::chat_id;
    T::ChatUnits::partner_id;
    T::ChatUnits::my_participant_id;
    T::ChatUnits::partner_participant_id;
};

#endif // CHAT_TYPE_TRAITS_H
