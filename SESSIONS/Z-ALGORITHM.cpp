#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> freq;
    string team, winner;
    int maxCount = 0;

    for(int i = 0; i < n; i++) {
        cin >> team;
        freq[team]++;
        
        if(freq[team] > maxCount) {
            maxCount = freq[team];
            winner = team;
        }
    }

    cout << winner << endl;

    return 0;
}