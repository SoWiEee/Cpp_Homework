#include <iostream>
#include <vector>

using namespace std;

class MyInteger {
private:
    vector<int> number;

public:
    // constructor
    MyInteger(int number) {
        setNum(number);
    };
    MyInteger() {}
    void setNum(int number) {
        int capacity =  this->number.capacity();

        while(number != 0) {

            this->number.reserve(capacity++);
            this->number.push_back(number % 10);
            number /= 10;

        }

    }
    
    vector<int> getNum() const { return number; }

    int operator [](int index) {
        if(index >= number.capacity())
            return -1;
        else {
            return  number[index];
        }
    }

    friend istream& operator >>(istream& is, MyInteger& num) {
        int number;
        is >> number;
        num.setNum(number);
        
        return is;
    }
};

int main(void) {
    int index = -2;
    MyInteger num(0);

    cout << "Enter a number=> ";
    cin >> num;

    while(true) {

        cout << "Enter an index (-1 to end)=> ";
        cin >> index;
        
        if(index == -1)
            break;
        else if(num[index] != -1)
            cout << "The index " << index << " of the number is " << num[index] << '.' << endl << endl;
        else
            cout << "index out of range." << endl << endl;

    }

    system("pause");
    return 0;
}

