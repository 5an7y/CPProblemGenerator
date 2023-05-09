#include <bits/stdc++.h>
using namespace std;

int N, ans;
vector<int> vec, depth;

int main() {
    cin >> N;
    vec.resize(N + 2);
    depth.resize(N + 2);

    for (int i = 1; i <= N; i++)
        cin >> vec[i];
    
    for (int i = 0; i <= N; i++) {
        if (vec[i] != -1) {
            int r = N+1;
            int color = vec[i];

            while (vec[r] != color) r--;
            for (int j = i; j <= r; j++) {
                if (vec[j] == -1) {
                    cout << "-1";
                    return 0;
                }
                if (vec[j] == color) vec[j] = -1;
                ans = max(++depth[j], ans);
            }
        }
    }

    cout << ans - 1;

    return 0;
}