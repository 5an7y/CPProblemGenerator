#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> vec(N);
    for (auto& it : vec) cin >> it;
    sort(vec.begin(), vec.end());

    for (int i = 0; i < N; i++) {
        if (i + 1 != vec[i]) {
            cout << "No";
            return 0;
        }
    }
    
    cout << "Si";
    return 0;
}