#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<char> personajes(N);
    vector<int64_t> vals(N);

    for (auto& it : personajes) cin >> it;
    for (auto& it : vals) cin >> it;

    priority_queue<int64_t> tomar;
    for (int i = 0; i < N; i++) {
        if (personajes[i] == 'D') tomar.push(-vals[i]);
        else {
            while (tomar.size() > vals[i]) tomar.pop();
        }
    }

    int64_t suma = 0;
    while (!tomar.empty()) {
        suma -= tomar.top();
        tomar.pop();
    }

    cout << suma << '\n';
    return 0;
}