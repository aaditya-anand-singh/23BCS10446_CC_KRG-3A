#include <bits/stdc++.h>
using namespace std;

vector<int> computeZ(string s) {
    int n = s.length();
    vector<int> z(n, 0);

    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {
        if (i <= R)
            z[i] = min(R - i + 1, z[i - L]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string text, pattern;

    cout << "Enter Text: ";
    cin >> text;

    cout << "Enter Pattern: ";
    cin >> pattern;

    string concat = pattern + "$" + text;
    vector<int> z = computeZ(concat);

    bool found = false;

    for (int i = 0; i < z.size(); i++) {
        if (z[i] == pattern.length()) {
            cout << "Pattern found at index: " 
                 << i - pattern.length() - 1 << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Pattern not found";

    return 0;
}