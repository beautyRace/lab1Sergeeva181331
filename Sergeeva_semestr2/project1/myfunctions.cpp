#include "myfunctions.h"
#include "user.h"
#include <QList>
#include <fstream>
#include <sstream>
#include <QMessageBox>
#include <string>

using namespace std;

QList<user> myFunctions::getUser(){
    QList <user> users;
    string str, token, login, password, fullName, rights;
    int yearOfBirth;
    ifstream file("C:/Users/Margarita/QT/Projects/project1/users.txt", ios::app);
    if(file){
        while(!file.eof()){
            getline(file,str);
            int k = 0;
            istringstream streamS(str);
            while(getline(streamS, token, ':')){
                if(k == 0) login = token;
                if(k == 1) password = token;
                if(k == 2) fullName = token;
                if(k == 3) yearOfBirth = stoi(token);
                if(k == 4) rights = token;
                k++;
            }
            users.push_back(user(login, password, fullName, yearOfBirth, rights));
        }  
    }
    file.close();
    return users;
}

QList<assets> myFunctions::getAssets(){
    QList<assets> assetses;
    string str, token, name, category;
    double income, consumption;
    ifstream file("C:/Users/Margarita/QT/Projects/project1/assets.txt", ios::app);
    if(file){
        while(!file.eof()){
            getline(file,str);
            int k = 0;
            istringstream streamS(str);
            while(getline(streamS, token, ':')){
                if(k == 0) name = token;
                if(k == 1) category = token;
                if(k == 2) income = stod(token);
                if(k == 3) consumption = stod(token);
                k++;
            }
            assetses.push_back(assets(name,category,income,consumption));
        }
    }
    file.close();
    return assetses;
}

void myFunctions::setUser(QList<user> u){
    ofstream file("C:/Users/Margarita/QT/Projects/project1/users.txt");
    if (file.is_open()){
        file.clear();
        for(int i=0; i<u.size(); i++){
            file<<u[i].getLogin()+":"+u[i].getPassword()+":"+u[i].getFullName()+":"+to_string(u[i].getYearOfBirth())+":"+u[i].getRights();
            if (i!=u.size()-1) file<<endl;
        }
        file.close();
    }
}



