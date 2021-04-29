#ifndef _FINANCE_H_
#define _FINANCE_H_

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

class Investment {
   public:
    Investment(const double& rhs) : m_capital(rhs) {}
    virtual double settle() = 0;
    friend class Person;

   protected:
    double m_capital;
};

class Saving : public Investment {
   public:
    Saving(const double& rhs) : Investment(rhs) {}
    double settle() {
        m_capital = m_capital * (1 + 1.78 / 100);
        return m_capital;
    }
};

class Fund : public Investment {
   public:
    Fund(const double& rhs) : Investment(rhs) {}
    double settle() {
        m_capital = m_capital * (rand() % 20 + 90) / 100;
        return m_capital;
    }
};

class Person {
   public:
    Person(const double& rhs) : m_principal(rhs) {}
    void addInvestment(Investment&& rhs) {
        manage.push_back(&rhs);
        this->m_principal -= rhs.m_capital;
    }
    double settle() {
        double value = 0;
        for (auto it = this->manage.begin(); it != this->manage.end(); ++it) {
            value += (*it)->settle();
        }
        return value;
    };

   private:
    double m_principal;
    vector<Investment*> manage;
};

#endif
