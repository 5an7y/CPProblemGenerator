#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int mat[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << (int)(
                mat[i][j] == 1 ||
                (0 <= i-1 && mat[i-1][j] == 1) ||
                (0 <= j-1 && mat[i][j-1] == 1) ||
                (j+1 < M && mat[i][j+1] == 1) ||
                (i+1 < N && mat[i+1][j] == 1)
            ) << " ";
        }
        cout << '\n';
    }

    return 0;
}