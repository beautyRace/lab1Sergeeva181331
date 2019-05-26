#include "user.h"

user::user(string l, string p, string f, int y, string r)
{
    login = l;
    password = p;
    rights = r;
    fullName = f;
    yearOfBirth = y;
}

int user::getYearOfBirth() const
{
    return yearOfBirth;
}

void user::setYearOfBirth(int value)
{
    yearOfBirth = value;
}

string user::getPassword() const
{
    return password;
}

void user::setPassword(const string &value)
{
    password = value;
}

string user::getRights() const
{
    return rights;
}

void user::setRights(const string &value)
{
    rights = value;
}

string user::getFullName() const
{
    return fullName;
}

void user::setFullName(const string &value)
{
    fullName = value;
}

string user::getLogin() const
{
    return login;
}

void user::setLogin(const string &value)
{
    login = value;
}
