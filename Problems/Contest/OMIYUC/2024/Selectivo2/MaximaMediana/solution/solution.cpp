#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<int> nums;

bool can_be(int median) {
    int suma = 0, sumb = 0, mini = 0;
    for (int i = 0; i < L; i++) suma += (nums[i] >= median)? 1 : -1;
    for (int i = L; i < N; i++) {
        if (suma - mini > 0) return true;
        suma += (nums[i] >= median)? 1 : -1;
        sumb += (nums[i-L] >= median)? 1 : -1;
        mini = min(mini, sumb);
    }
    return suma - mini > 0;
}

int binaria(int ini, int fin) {
    if (ini == fin) return ini;
    int mit = (ini + fin) / 2;
    if (can_be(mit)) return binaria(mit + 1, fin);
    return binaria(ini, mit);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L;
    nums.resize(N);
    int maxi = 0;
    for (auto& it : nums) cin >> it, maxi = max(it, maxi);

    cout << binaria(0, maxi+1) - 1;

    return 0;
}