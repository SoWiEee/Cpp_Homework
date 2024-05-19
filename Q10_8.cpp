#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

class Television{
private:
    string displayType;
    double dimension;   // 尺寸
    string *connectivitySupport = new string;   // 連接模式
public:
    // constructor
    Television() {}
    Television(string type, double dim, string support){
        displayType = type;
        dimension = dim;
        *connectivitySupport = support;
    }
    // copy
    Television(const Television &tv){
            displayType = tv.displayType;
            dimension = tv.dimension;
            connectivitySupport = new string;
            *connectivitySupport = *tv.connectivitySupport;
    }

    // mutator
    void setDisplayType(string type) {
        displayType = type;
    }
    void setDimension(double dim) {
        dimension = dim;
    }
    void setConnectivitySupport(string *support) {
        *connectivitySupport = *support;
    }

    void display(){
        cout << "Display type: " << displayType << endl;
        cout << "dimension: " << dimension << endl;
        cout << "Connectivity support: " << *connectivitySupport << endl << endl;
    }
};

// customize TV
void customize(Television *TvList, int amount){
    int index;
    char modifier;
    string type, support;
    double dimension;

    cout << "Which TV want to customize? (0-" << amount - 1 << ")" << "=> ";
    cin >> index;

    do{
        cout << "Which attribute do you want th change?" << endl << "(t/ d/ c/ q(quit))" << "=> ";
        cin >> modifier;

        // change a value
        switch(modifier){
            case 't':
                cout << "Enter display type=> ";
                cin >> type;
                TvList[index].setDisplayType(type);
                break;

            case 'd':
                cout << "Enter dimension=> ";
                cin >> dimension;
                TvList[index].setDimension(dimension);
                break;

            case 'c':
                cout << "Enter connectivity support=> ";
                cin >> support;
                TvList[index].setConnectivitySupport(&support);
                break;
                
            case 'q':
                break;
            default:
                cout << "[X] Unknown char!" << endl;
        }
    }while(modifier != 'q');

}


int main(){
    char conti; // customized char
    int amount;
    string type, support;
    double dimension;

    cout << "Enter default display type of TV=> " ;
    cin >> type;
    cout << "Enter default dimension of TV=> " ;
    cin >> dimension;
    cout << "Enter default connectivity modes supported (3 modes)=>  ";
    cin >> support;
    Television tv0(type, dimension, support);   // default instance

    cout << "Enter total amounts of the television=> ";
    cin >> amount;

    // create TV table
    Television* TvList = new Television[amount];
    for(int i = 0; i < amount; i++){
        TvList[i] = Television(tv0);
    }
    cout << "[V] Create successfully" << endl;
    cout << "[*] Customize any of them?(y/n)=> ";
    cin >> conti;

    while(conti == 'y') {
        customize(TvList, amount);
        cout << "Continue customizing?(y/n)=> ";
        cin >> conti;
    }

    cout << endl << "[*] Overview of televisions" << endl;
    for(int i = 0; i < amount; i++){
        cout << "[ Tv " << i << " ]" << endl;
        TvList[i].display();
    }

    delete[] TvList;

    system("pause");
    return 0;
}

