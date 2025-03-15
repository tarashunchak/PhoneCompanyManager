#ifndef CURRENTUSER_H
#define CURRENTUSER_H

class CurrentUser
{
private:
    CurrentUser() = default;
public:
    static int getCurrentUserID();
    static void setCurrentUserID(const int);
private:
    static int UID;

};

#endif // CURRENTUSER_H
