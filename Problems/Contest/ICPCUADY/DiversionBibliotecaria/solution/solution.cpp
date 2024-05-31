#include <bits/stdc++.h>
using namespace std;

vector<int> bucket(28);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin >> a;
    for (auto& it : a)
        bucket[it - 'A']++;
    
    for (char i = 'A'; i <= 'Z'; i++) {
        for (int j = 0; j < bucket[i - 'A']/2; j++) 
            cout << i;
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        if (bucket[i - 'A'] % 2 == 1) {
            cout << i;
            break;
        }
    }
    for (char i = 'Z'; i >= 'A'; i--) {
        for (int j = 0; j < bucket[i - 'A']/2; j++) 
            cout << i;
    }

    return 0;
}