#include <iostream>
using namespace std;

// Function to check if the given points can be valid
bool isValidPointTable(int pa, int pb, int pc) {
    // Simulate all possible match results:
    // A vs B: 3 outcomes (A wins, B wins, draw)
    // A vs C: 3 outcomes (A wins, C wins, draw)
    // B vs C: 3 outcomes (B wins, C wins, draw)

    for (int resultAB = 0; resultAB <= 2; resultAB++) { // 0: A wins, 1: Draw, 2: B wins
        for (int resultAC = 0; resultAC <= 2; resultAC++) { // 0: A wins, 1: Draw, 2: C wins
            for (int resultBC = 0; resultBC <= 2; resultBC++) { // 0: B wins, 1: Draw, 2: C wins

                // Calculate points for A, B, and C based on match results
                int pointsA = (resultAB == 0 ? 3 : (resultAB == 1 ? 1 : 0)) + // Points from A vs B
                              (resultAC == 0 ? 3 : (resultAC == 1 ? 1 : 0));   // Points from A vs C

                int pointsB = (resultAB == 2 ? 3 : (resultAB == 1 ? 1 : 0)) + // Points from A vs B
                              (resultBC == 0 ? 3 : (resultBC == 1 ? 1 : 0));   // Points from B vs C

                int pointsC = (resultAC == 2 ? 3 : (resultAC == 1 ? 1 : 0)) + // Points from A vs C
                              (resultBC == 2 ? 3 : (resultBC == 1 ? 1 : 0));   // Points from B vs C

                // Check if calculated points match the input
                if (pointsA == pa && pointsB == pb && pointsC == pc) {
                    return true;
                }
            }
        }
    }
    return false; // No valid combination found
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int pa, pb, pc;
        cin >> pa >> pb >> pc;

        // Check validity of the point table
        if (isValidPointTable(pa, pb, pc)) {
            cout << "Case " << i << ": perfectus" << endl;
        } else {
            cout << "Case " << i << ": invalidum" << endl;
        }
    }
    return 0;
}