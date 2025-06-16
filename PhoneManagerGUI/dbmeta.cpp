#include "includes/databasemanager.h"

QMap<QString, QStringList> DatabaseManager::Columns::columns = {
    {"customers", {"first_name", "last_name", "phone"
                   , "email", "date_of_B",  "tariff_id", "added_by_id"}}
    ,{"employees", {"first_name", "last_name", "phone", "email", "date_of_B"
                    , "hire_date", "department_id", "position_id"}}
    ,{"tariffs", {"tariff_name", "monthly_price", "daily_price", "call_minutes", "internet_GB"}}
    ,{"messages",{"text", "sender_participant_id", "chat_id"}}
};

QMap<QString, QStringList> DatabaseManager::Columns::all_columns = {
    {"customers", {"id", "first_name", "last_name", "phone", "email", "date_of_B", "is_visible"
                   , "date", "tariff_id", "employee_id", "added_by_id", "is_active", "comment_id", "balance"}}
    ,{"employees", {"id", "first_name", "last_name", "phone", "email", "date_of_B", "hire_date", "is_visible"
                    , "department_id", "position_id", "salary", "photo", "is_active", "comment_id", "is_visible"}}
    ,{"tariffs", {"id", "tariff_name", "monthly_price", "daily_price", "call_minutes", "internet_gb"
                    , "is_active", "is_visible"}}
    ,{"messages",{"id", "text", "sender_participant_id", "chat_id"}}
    ,{"users", {"id", "empl_id", "username", "password"}}
    ,{"payments", {"id", "cust_id", "amount", "payment_method", "payment_date", "status"}}
    ,{"positions", {"id", "position_name"}}
    ,{"departments", {"id", "department_name"}}
    ,{"chats", {"id", "is_corporate"}}
    ,{"participants", {"id", "role", "reference_id"}}
    ,{"chat_participants", {"id", "chat_id", "participants_id", "last_seen"}}
    ,{"comments", {"id", "comment_text", "date_time", "written_by_id"}}
    ,{"requests", {"id", "cust_id", "request_type", "status", "date", "assigned_to_id"}}
};
