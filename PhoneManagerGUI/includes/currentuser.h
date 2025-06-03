#ifndef CURRENTUSER_H
#define CURRENTUSER_H

class CurrentUser
{
private:
    CurrentUser() = delete;
    ~CurrentUser() = delete;
    CurrentUser(const CurrentUser&) = delete;
    CurrentUser& operator=(const CurrentUser&) = delete;
public:
    static unsigned int getCurrentUserID();
    static unsigned int getCurrentEmployeeID();
    static void setCurrentUserID(const unsigned int);
    static void setCurrentEmployeeID(const unsigned int);
private:
    static unsigned int UID;
    static unsigned int EMPL_ID;
};

#endif // CURRENTUSER_H
