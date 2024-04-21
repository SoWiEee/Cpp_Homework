#include <iostream>

using namespace std;

class Weight{
    public:
        void setWeightPounds(double pounds) {
            weight = pounds;
        }
        void setWeightKilograms(double kilograms) {
            weight = kilograms * 2.21;
        }
        void setWeightOunces(double ounces) {
            weight = ounces / 16;
        }
        double getWeightPounds() {
            return weight;
        }
        double getWeightKilograms() {
            return weight / 2.21;
        }
        double getWeightOunces() {
            return weight * 16;
        }

    private:
        double weight;
};

int main(void) {
    Weight weight;
    double input_weight;

    cout << "CLASS TEST START..." << endl << endl;

    cout << "Enter the weight in pounds > ";
    cin >> input_weight;
    weight.setWeightPounds(input_weight);
    cout << "Kilograms: " << weight.getWeightKilograms() << endl;
    cout << "Ounces: " << weight.getWeightOunces() << endl << endl;

    cout << "Enter the weight in kilograms > ";
    cin >> input_weight;
    weight.setWeightKilograms(input_weight);
    cout << "Pounds: " << weight.getWeightPounds() << endl;
    cout << "Ounces: " << weight.getWeightOunces() << endl << endl;

    cout << "Enter the weight in ounces > ";
    cin >> input_weight;
    weight.setWeightOunces(input_weight);
    cout << "Pounds: " << weight.getWeightPounds() << endl;
    cout << "Kilograms: " << weight.getWeightKilograms() << endl << endl;

    system("pause");
    return 0;
}
