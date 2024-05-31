#include <bits/stdc++.h>
using namespace std;

vector<int> movx = {1, -1, 0, 0}, movy = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> mat(N, vector<int>(M));
    for (auto& vec : mat) 
        for (auto& it : vec) cin >> it;

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int ni = i + movx[k];
                    int nj = j + movy[k];
                    if (!(0 <= ni && ni < N && 0 <= nj && nj < M && mat[ni][nj]==1))
                        ans++;
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}