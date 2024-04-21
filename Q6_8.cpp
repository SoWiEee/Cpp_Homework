#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Money{
    private:
        int dollar;
        double cent;
    
    public:
        void construct(int d, int c){
            dollar = d;
            cent = c;
        }
        double display(){
            return (dollar + cent/100);
        }
};

int main(void){
    Money m1, m2;
    m1.construct(10, 50);
    m2.construct(20, 75);
    
    // display result
    cout <<"Money 1: " << m1.display() << endl;
    cout <<"Money 2: " << m2.display() << endl;

    system("pause");
    return 0;
}