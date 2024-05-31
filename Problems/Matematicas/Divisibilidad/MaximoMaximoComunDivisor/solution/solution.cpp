#include <bits/stdc++.h>
using namespace std;

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);

    vector<int> bucket(1000001);

    int N; cin >> N;
    int x, maxi = 1;
    while (N--) {
        cin >> x;
        bucket[x]++;
        maxi = max(maxi, x);
    }

    for (int i = maxi; i >= 1; i--) {
        int sum = 0;
        for (int j = i; j <= maxi; j += i)
            sum += bucket[j];

        if (sum >= 2) { 
            cout << i;
            break;
        }
    }

    return 0;
}