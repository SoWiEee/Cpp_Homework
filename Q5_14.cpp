#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int findClosest(int score[][6], int rate[], int movie[]){
    int closest, i, j;
    double distance, min_distance = 9999;

    for(i = 0; i < 4; i++) {
        distance = 0;
        for(j = 0; j < 3; j++){
            distance += pow(rate[j] - score[i][movie[j]], 2);
        }
        distance = sqrt(distance);

        if(distance < min_distance) {

            min_distance = distance;
            closest = i;

        }
    }
    return closest;
}

bool in_array(int element, int array[]) {

    for(int i = 0;i < 3;i++) {

        if(array[i] == element)
            return true;

    }
    return false;
}

int main(){
    int score[4][6] = { { 3, 1, 5, 2, 1, 5 },
                        { 4, 2, 1, 4, 2, 4 },
                        { 3, 1, 2, 4, 4, 1 },
                        { 5, 1, 4, 2, 4, 2 }
                      };
    int movie[3];
    int rate[3];
    bool check[6] = { false };
    int closest, i;

    // get input
    for(i = 0; i < 3; i++){
        cout <<"Enter a movie number(100~105): " << endl;
        cin >> rate[i];
        cout <<"Enter a vote for movie(1~5): " << endl;
        cin >> movie[i];
    }

    // fin closest
    closest = findClosest(score, rate, movie);

    for(i = 0; i <6; i++) {

        if(!(in_array(i, movie)))
            cout << "Predicted rate for movie 10" << i << ": " << score[closest][i] << endl;

    }

    system("pause");
    return 0;
}
