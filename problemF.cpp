#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    string message = "Ei Matha-Mota-Rogchota joddin achhe, non-profit diye kon ghaash ta katbo!";

    // Print the message T times
    while (T--) {
        cout << message << endl;
    }

    return 0;
}