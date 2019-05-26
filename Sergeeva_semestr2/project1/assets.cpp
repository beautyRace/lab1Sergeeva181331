#include "assets.h"

assets::assets(string n, string c, double in, double con){
    name = n;
    category = c;
    income = in;
    consumption = con;
    profit = income-consumption;
}

string assets::getCategory() const
{
    return category;
}

void assets::setCategory(const string &value)
{
    category = value;
}

double assets::getIncome() const
{
    return income;
}

void assets::setIncome(double value)
{
    income = value;
    profit = income-consumption;
}

double assets::getConsumption() const
{
    return consumption;
}

void assets::setConsumption(double value)
{
    consumption = value;
    profit = income-consumption;
}


double assets::getProfit() const
{
    return profit;
}

string assets::getName() const
{
    return name;
}

void assets::setName(const string &value)
{
    name = value;
}
