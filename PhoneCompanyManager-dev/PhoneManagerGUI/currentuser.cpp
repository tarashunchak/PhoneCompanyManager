#include "includes/currentuser.h"

unsigned int CurrentUser::UID = 0;

unsigned int CurrentUser::EMPL_ID = 0;

unsigned int CurrentUser::getCurrentUserID(){
    return UID;
}

void CurrentUser::setCurrentUserID(const unsigned int uId){
    UID = uId;
}

unsigned int CurrentUser::getCurrentEmployeeID(){
    return EMPL_ID;
}

void CurrentUser::setCurrentEmployeeID(const unsigned int uId){
    EMPL_ID = uId;
}
