#ifndef EMPLOYEE.H
#define EMPLOYEE.H
#include <string>

using std::string;

namespace SavitchEmployees {
    class Employee {
    private:
        string name;
        string ssn;
        double netPay;
    public:
        Employee();
        Employee(const string& theName, const string& theNumber);
        string getName() const;
        string getSsn() const;
        double getNetPay() const;
        void setName(const string& newName);
        void setSsn(const string& newSsn);
        void setNetPay (double newNetPay);
        void printCheck() const;
    };
}


#endif