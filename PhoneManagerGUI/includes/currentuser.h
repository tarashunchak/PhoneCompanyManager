#ifndef CURRENTUSER_H
#define CURRENTUSER_H

class CurrentUser
{
private:
    CurrentUser() = default;
    ~CurrentUser() = default;
    CurrentUser(const CurrentUser&) = delete;
    CurrentUser& operator=(const CurrentUser&) = delete;
public:
    static int getCurrentUserID();
    static void setCurrentUserID(const int);
private:
    static int UID;
};

#endif // CURRENTUSER_H
