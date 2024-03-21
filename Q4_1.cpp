#include <iostream>
using namespace std;

// Function to get the input
void getInput(int& hour, int& minute) {
    cout << "Enter the time in 24-hour format (HH MM): ";
    cin >> hour >> minute;
}

// Function to convert the time
void convertTime(int& hour, char& am_pm) {
    if (hour < 12) {
        am_pm = 'A';
    } else {
        am_pm = 'P';
        hour -= 12;
    }
    if (hour == 0) {
        hour = 12;
    }
}

// Function to output the time
void outputTime(int hour, int minute, char am_pm) {
    cout << "The time in 12-hour format is: " << hour << ":" << minute << " ";
    if (am_pm == 'A') {
        cout << "A.M." << endl;
    } else {
        cout << "P.M." << endl;
    }
}

int main() {
    char repeat = 'Y';
    while (repeat == 'Y' || repeat == 'y') {
        int hour, minute;
        char am_pm;
        getInput(hour, minute);
        convertTime(hour, am_pm);
        outputTime(hour, minute, am_pm);
        cout << "Do you want to convert another time? (Y/N): ";
        cin >> repeat;
    }
    system("pause");
    return 0;
}
