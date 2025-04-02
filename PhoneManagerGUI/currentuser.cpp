#include "includes/currentuser.h"

int CurrentUser::UID = 0;

int CurrentUser::getCurrentUserID(){
    return UID;
}

void CurrentUser::setCurrentUserID(const int uId){
    UID = uId;
}
