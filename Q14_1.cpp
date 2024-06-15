#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// parent class
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

// child class
class SalariedEmployee: public Employee {
public:
    // constructor
    SalariedEmployee(): Employee(), salary(0) {}
    SalariedEmployee(const string& theName, const string& theNumber, double theWeeklyPay) : Employee(theName, theNumber), salary(theWeeklyPay) {}
    double getSalary() const {
        return salary;
    }
    void setSalary(double newSalary) {
        salary = newSalary;
    }
    void printCheck() {
        setNetPay(salary);
        cout << "\n____________________________________________\n";
        cout << "Pay to the order of " << getName( ) << endl;
        cout << "The sum of " << getNetPay( ) << " Dollars\n";
        cout << "_____________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << getSsn( ) << endl;
        cout << "Salaried Employee. Regular Pay: " << salary << endl;
        cout << "_____________________________________________\n";
    }

protected:
    double salary;  //weekly
};

// child class
class Administrator: public SalariedEmployee {
private:
    string title;
    string responsibility;
    string supervisor;

public:
    // constructor
    Administrator() {
        SalariedEmployee();
        title = "No title yet";
        responsibility = "No responsibility yet";
        supervisor = "No supervisor yet";
    }
    Administrator(const string& theName, const string& theNumber, double theWeeklyPay, const string& adminTitle, const string& responsibility, const string& supervisorName) {
        SalariedEmployee(theName, theName, theWeeklyPay);
        this->title = adminTitle;
        this->responsibility = responsibility;
        this->supervisor = supervisorName;
    }

    void setSupervisor(const string& supervisorName) {
        this->supervisor = supervisorName;
    }

    void inputAdministratorData() {
        cout << "Enter the administrator's title=> ";
        cin >> this->title;
        cout << "Enter the administrator's the company area of responsibility=> ";
        cin >> this->responsibility;
        cout << "Enter the administrator's immediate supervisor=> ";
        cin >> this->supervisor;
    }

    void print() const {
        cout << "[*] Administrator:" << endl;
        cout << "[*] name: " << getName() << endl;
        cout << "[*] title: " << title << endl;
        cout << "[*] responsibility: " << responsibility << endl;
        cout << "[*] immediate supervisor: " << supervisor << endl;
    }

    void printCheck( ) {
        setNetPay(salary);
        cout << "\n____________________________________________\n";
        cout << "Pay to the order of " << getName( ) << endl;
        cout << "The sum of " << getNetPay( ) << " Dollars\n";
        cout << "Employee Number: " << getSsn( ) << endl;
        cout << "Salaried Employee (Administrator). Regular Pay: " << salary << endl;
    }
};

int main(void){
    Administrator admin;
    string name, title, responsibility, supervisor;

    cout << "Enter the admin's name=> ";
    cin >> name;
    admin.setName(name);
    admin.inputAdministratorData();

    cout << endl;
    admin.print();
    system("pause");
    return 0;
}