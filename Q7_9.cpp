#include <iostream>

// fuck you

using namespace std;

class Postnet {
    public:
        // default
        Postnet() {};
        // zip -> bar
        Postnet(int zipCode) {
            convertIntToBarcode(zipCode);
        }
        // bar -> zip
        Postnet(string barCode) {
            convertStrToBarcode(barCode);
        }

        void outputZipCode(){
            int index = 0, digit;

            for(int i = 0; i < 5; i++) {

                digit = 0;
                for(int j = 0; j < 5; j++){
                    digit += barCode[index + j] * numList[j];
                }
                if(digit != 11){
                    cout << digit;
                }else{
                    cout << 0;
                }
                index += 5;
            }
        }
        
        void outputBarCode() const {
            cout << 1;
            for(int i = 0; i < 25; i++){
                cout << barCode[i];
            }
            cout << 1;
        }

    private:
        int barCode[25];
        int numList[5] = {7, 4, 2, 1, 0};   // encode parameter
        // 
        void convertStrToBarcode(string barCode) {
            for(int i = 1; i < 26; i++) {
                this->barCode[i-1] = barCode[i] - 48;
            }
        }
        void convertIntToBarcode(int);

};

int main(void) {
    int zipCode;
    string barCode;

    cout << "Enter the bar code as a 25-digit number => ";  // 110100101000101011000010011
    cin >> barCode;
    // construct
    Postnet postnet(barCode);
    cout << "ZIP CODE: ";
    postnet.outputZipCode();
    cout << endl << endl;

    cout << "Enter the zip code as a 5-digit number => ";   // 47210
    cin >> zipCode;
    postnet = Postnet(zipCode);
    cout << "BAR CODE: ";
    postnet.outputBarCode();
    cout << endl;

    system("pause");
    return 0;
}


void Postnet::convertIntToBarcode(int zipcode) {

    int index, amountOf1;
    int zipcode_slice[5];

    for(int i = 4; i >= 0; i--) {
        if(zipcode % 10 != 0){
            zipcode_slice[i] = zipcode % 10;
        }else{
            zipcode_slice[i] = 11;
        } 
        zipcode /= 10;
    }

    for(int i = 0; i < 25; i++){
        barCode[i] = -1;
    }
        
    index = 0;
    for(int i = 0; i < 5; i++) {

        amountOf1 = 0;
        for(int j = 0; j < 5; j++) {

            if(zipcode_slice[i] >= numList[j] && zipcode_slice[i] != 0) {
                barCode[index + j] = 1;
                zipcode_slice[i] -= numList[j];
                amountOf1++;
            }
            else{
                barCode[index + j] = 0;
            }
        }

        if(amountOf1 != 2){
            barCode[index + 4] = 1;
        }
            
        index += 5;
    }
}
