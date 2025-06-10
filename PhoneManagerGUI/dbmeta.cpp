#include "includes/databasemanager.h"

QMap<QString, QStringList> DatabaseManager::Columns::columns = {
    {"customers", {"first_name", "last_name", "phone"
                   , "email", "date_of_B",  "tariff_id", "employee_id"}}
    ,{"employees", {"first_name", "last_name", "phone", "email", "date_of_B"
                    , "hire_date", "department_id", "position_id"}}
    ,{"tariffs", {"tariff_name", "monthly_price", "daily_price", "call_minutes", "internet_GB"}}
    ,{"messages",{"text", "sender_participant_id", "chat_id"}}
};
