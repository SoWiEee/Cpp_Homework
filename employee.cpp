#include <string>
#include <cstdlib>
#include <iostream>
#include "employee.h"

using std::string;
using std::cout;

namespace SavitchEmployees {

    class Employee {
    private:
        string name;
        string ssn;
        double netPay;
    public:
        Employee() : name("No name yet"), ssn("No number yet"), netPay(0) {}
        Employee(const string& theName, const string& theNumber) : name(theName), ssn(theNumber), netPay(0) {}
        string getName() const {
            return name;
        }
        string getSsn() const {
            return ssn;
        }

        double getNetPay() const {
            return netPay;
        }
        void setName(const string& newName) {
            name = newName;
        }
        void setSsn(const string& newSsn) {
            ssn = newSsn;
        }
        void setNetPay (double newNetPay) {
            netPay = newNetPay;
        }
        void printCheck() const {
            cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
                << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
                << "Check with the author of the program about this bug.\n";
            exit(1);
        }
    };

}