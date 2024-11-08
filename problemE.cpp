#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double maxVolume(double S) {
    double low = 0, high = sqrt(S);
    double bestVolume = 0.0;

    // The precision threshold to stop binary search
    while (high - low > 1e-4) {  
        double a = (low + high) / 2.0;
        // Calculate slant height 'l' and height 'h' from surface area S
        double l = (S - a * a) / (2 * a);  // slant height
        double h = sqrt(l * l - (a * a) / 4);  // height

        if (h > 0) {
            // Calculate the volume of the pyramid
            double volume = (1.0 / 3.0) * a * a * h;
            bestVolume = max(bestVolume, volume);
            low = a; // Move search to the higher range
        } else {
            high = a; // Move search to the lower range
        }
    }
    return bestVolume;
}

int main() {
    double S;
    while (cin >> S && S >= 0) {
        double result = maxVolume(S);
        cout << fixed << setprecision(4) << result << endl;
    }
    return 0;
}