#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>

using namespace std;

int main(){
    int slice = 0;
    string str;
    cout << "Enter a sentence=> ";
    getline(cin, str);

    // replace
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i])){
            slice++;
            if(slice == 4){
                str = str.replace(i - 3, 4, "love");
                if(i - 3 == 0){
                    str[i-3] = 'L';
                }
            }
        }else{
            slice = 0;
        }
    }

    cout << "After replaced=> " << str << endl;

    system("pause");
    return 0;
}
