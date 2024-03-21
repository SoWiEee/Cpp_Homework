#include <iostream>
using namespace std;

// pace -> mph
double convertToMPH(int minutes, int seconds) {
    double hours = (minutes + seconds / 60.0) / 60.0;
    return 1.0 / hours;
}

// kph -> mph
double convertToMPH(double kph) {
    return kph / 1.61;
}

int main() {
    // Test the function with pace
    int minutes = 5, seconds = 30;
    cout << "Enter speed per miles(M S):";
    cin >> minutes;

    cout << "The speed in mph for a pace of " << minutes << ":" << seconds << " per mile is " << convertToMPH(minutes, seconds) << " mph." << endl;

    // Test the function with kph
    double kph = 10.0;
    cout << "The speed in mph for a speed of " << kph << " kph is " << convertToMPH(kph) << " mph." << endl;

    return 0;
}
