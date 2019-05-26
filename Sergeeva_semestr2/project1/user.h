#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

class user
{
    string login;
    string password;
    string fullName;
    string rights;
    int yearOfBirth;

public:
    user(string l, string p, string f, int y, string r);

    string getLogin() const;
    void setLogin(const string &value);

    string getPassword() const;
    void setPassword(const string &value);

    string getRights() const;
    void setRights(const string &value);

    string getFullName() const;
    void setFullName(const string &value);

    int getYearOfBirth() const;
    void setYearOfBirth(int value);
};

#endif // USER_H
