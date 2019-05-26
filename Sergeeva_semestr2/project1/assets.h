#ifndef ASSETS_H
#define ASSETS_H
#include <string>

using namespace std;

class assets
{
    string name;
    string category;
    double income;
    double consumption;
    double profit;

public:
    assets(string n, string c, double in, double con);

    string getName() const;
    void setName(const string &value);

    string getCategory() const;
    void setCategory(const string &value);

    double getIncome() const;
    void setIncome(double value);

    double getConsumption() const;
    void setConsumption(double value);

    double getProfit() const;
};

#endif // ASSETS_H
