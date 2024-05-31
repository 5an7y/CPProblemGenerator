#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> vec(N);
    for (auto& xi : vec) cin >> xi;
    sort(vec.begin(), vec.end());

    int j = N - 2;
    while (j >= 0 && vec[j] == vec[N-1]) j--;
    cout << j + 1 << '\n';

    return 0;
}