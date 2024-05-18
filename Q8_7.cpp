#include <iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class PrimeNumber{
private:
    int prime;

public:
    // constructor
    PrimeNumber(): prime(1){}
    PrimeNumber(int p): prime(p){}

    bool isPrime(int number) const {
        if(number == 2 || number == 3)
            return true;
        else if(number > 4){

            int remainder = number % 6;

            if(remainder != 1 && remainder != 5)
                return false;

            int nSqrt = (int)floor(sqrt(number));

            for(int i = 5; i <= nSqrt; i++) {
                if(number % i == 0 || number % (i + 2) == 0)
                    return false;
            }
            return true;
        }
        else{
            return false;
        }
    }

    void setPrime(int p){
        while(!isPrime(p)){
            p--;
        }
        prime = p;
    }

    PrimeNumber operator++() {

        prime++;
        while(!isPrime(prime))
            prime++;

        return PrimeNumber(prime);

    }

    PrimeNumber operator++(int) {

        int temp = prime;

        prime++;
        while(!isPrime(prime))
            prime++;

        if(temp == 1)
            return PrimeNumber();
        else
            return PrimeNumber(temp);

    }

    PrimeNumber operator--() {

        if(prime <= 2) {
            prime = 1;
            return PrimeNumber();
        }
        else{
            prime--;
            while(!isPrime(prime))
                prime--;
        }

        return PrimeNumber(prime);

    }

    PrimeNumber operator--(int) {

        int temp = prime;

        if(temp < 2)
            return PrimeNumber();
        else if(temp == 2) {
            prime = 1;
            return PrimeNumber(temp);
        }
        else{
            prime--;
            while(!isPrime(prime))
                prime--; 
        }

        return PrimeNumber(temp);

    }

    friend istream& operator >>(istream& is, PrimeNumber& primeNumber) {

        int num;

        do{
            is >> num;
        }while(num < 2);

        primeNumber.setPrime(num);

        return is;

    }

    friend ostream& operator <<(ostream& outputStream, const PrimeNumber& primeNumber) {

        outputStream << primeNumber.prime;
        
        return outputStream;

    }
};


int main(){


    system("pause");
    return 0;
}

