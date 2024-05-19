#include <iostream>

using namespace std;

class PrimeNumber {
private:
    int prime;

public:
    // constructor
    PrimeNumber() : prime(1) {}
    PrimeNumber(int p) : prime(p) {}

    int getPrime() const {
        return prime;
    }

    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }

    // overloading function
    PrimeNumber& operator++() {
        int num = prime + 1;
        while (!isPrime(num)) num++;
        prime = num;
        return *this;
    }

    PrimeNumber operator++(int) {
        PrimeNumber temp = *this;
        ++*this;
        return temp;
    }

    PrimeNumber& operator--() {
        if (prime <= 2) {
            prime = 1;
            return *this;
        }
        int num = prime - 1;
        while (!isPrime(num)) num--;
        prime = num;
        return *this;
    }

    PrimeNumber operator--(int) {
        PrimeNumber temp = *this;
        --*this;
        return temp;
    }
};

int main(void) {
    PrimeNumber p(13);
    cout << "Prime: " << p.getPrime() << endl;
    ++p;
    cout << "Next Prime: " << p.getPrime() << endl;
    p--;
    cout << "Previous Prime: " << p.getPrime() << endl;

    system("pause");
    return 0;
}
