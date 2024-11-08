#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find all possible grid dimensions for a given character pair
vector<pair<int, int>> findPossibleDimensions(char c1, char c2) {
    int index1 = c1 - 33;  // Convert character to its position in the ASCII range
    int index2 = c2 - 33;
    
    vector<pair<int, int>> possibleDimensions;
    
    for (int R = 1; R <= 94; ++R) {
        int C = (94 + R - 1) / R;  // Calculate minimum columns needed for R rows (ceil division)
        
        // Check if R x C grid can hold all 94 characters
        if (R * C >= 94) {
            // Check if both characters appear in the same row in this R x C grid
            if ((index1 % R) == (index2 % R)) {
                possibleDimensions.emplace_back(R, C);
            }
        }
    }
    
    // Sort dimensions by the number of rows
    sort(possibleDimensions.begin(), possibleDimensions.end());
    return possibleDimensions;
}

int main() {
    int T;
    cin >> T;  // Number of test cases
    while (T--) {
        char c1, c2;
        cin >> c1 >> c2;
        
        vector<pair<int, int>> results = findPossibleDimensions(c1, c2);
        
        for (const auto& dimension : results) {
            cout << dimension.first << " " << dimension.second << endl;
        }
        cout << endl;  // Blank line after each test case
    }
    
    return 0;
}