#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

const string TYPE[3] = { "deep dish", "hand tossed", "pan" };
const string SIZE[3] = { "small", "medium", "large" };

class Pizza{
    private:
        string type;    // deep dish, hand tossed, pan
        string size;    // small(10), medium(14), large(17)
        int pepperoni;
        int cheese;
        int price;

    public:
        // set members
        void construct(string TYPE, string SIZE, int PEPP, int CHE){
            type = TYPE;
            size = SIZE;
            pepperoni = PEPP;
            cheese = CHE;
        }
        void outputDescription(){
            cout << "Type: " << type << endl;
            cout << "Size: " << size << endl;
            cout << "Topping: " << "pepperoni *" << pepperoni << ", cheese *" << cheese << endl;
            cout << "Price: $" << price << endl;
        }
        double computePrice(){
            if(size.compare("small") == 0){
                price = 10;
            }else if(size.compare("medium") == 0){
                price = 14;
            }else {
                price = 17;
            }
            price += 2*(pepperoni + cheese);
        }
};

int main(void){
    int type, size, pepperoni, cheese;

	cout << "1) deep dish" << endl << "2) hand tossed" << endl << "3) pan" << endl;
	cout << "Enter the type you want: ";
	cin >> type;

	cout << "1) small" << endl << "2) medium" << endl << "3) large" << endl;
	cout << "Enter the size you want: ";
	cin >> size;

	cout << "Enter the number of pepperoni: ";
	cin >> pepperoni;

	cout << "Enter the number of cheese: ";
	cin >> cheese;

    // create instance
    Pizza pizza1;
    pizza1.construct(TYPE[type-1], SIZE[size-1], pepperoni, cheese);
    pizza1.computePrice();

    // display result
    pizza1.outputDescription();

    system("pause");
    return 0;
}

