#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> A(N);
    for(auto& it : A) cin >> it;
    cin >> M;
    vector<int> B(M);
    for(auto& it : B) cin >> it;

    bool vacio = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i] == B[j]) {
                B[j] = -1;
                cout << A[i] << ' ';
                vacio = false;
                break;
            }
        }
    }

    if (vacio) { 
        cout << "-1\n";
    }

    return 0;
}