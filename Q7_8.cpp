#include <iostream>
#include <vector>

using namespace std;

void reserveVector(vector<int>& score, int input) {
    score.reserve(input + 1);
    for(int i = score.capacity(); i < input + 1; i++){
        score.push_back(0);
    }
}

void draw(int length) {
    for(int i = 0;i < length;i++){
        cout << '*';
    }
}

int main(void) {

    int input_score;
    vector<int> score(0);

    cout << "Enter the score separated by spaces (enter -1 to end)" << endl << "> ";

    while(true) {
        cin >> input_score;
        if(input_score != -1) {
            if(input_score > score.capacity() - 1 ){
                reserveVector(score, input_score);
            }
            score[input_score] += 1;
        }
        else{
            break;
        }   
    }

    for(int i = 0; i < score.size(); i++) {
        cout << i << " |";
        draw(score[i]);
        cout << endl;
    }

    system("pause");
    return 0;

}
