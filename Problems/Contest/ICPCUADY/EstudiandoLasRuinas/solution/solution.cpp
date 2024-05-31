#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> mat;
vector<int> movx = {-1, 1, 0, 0}, movy = {0, 0, -1, 1};
int N, M;

void BFS(int x, int y) {
    mat[x][y] = true;
    queue<pair<int, int>> bfs;
    bfs.push({x, y});
    while (!bfs.empty()) {
        auto [xi, yi] = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xi + movx[i],
                ny = yi + movy[i];
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && mat[nx][ny] == false) {
                mat[nx][ny] = true;
                bfs.push({nx, ny});
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    mat.resize(N, vector<bool>(M, false));
    for (auto&& vec : mat) 
        for (auto&& it : vec) {
            int xi; cin >> xi;
            it = (xi == 1);
        }

    for (int i = 0; i < M; i++) {
        if (mat[0][i] == false) BFS(0, i);
        if (mat[N-1][i] == false) BFS(N-1, i);
    }

    for (int i = 0; i < N; i++) {
        if (mat[i][0] == false) BFS(i, 0);
        if (mat[i][M-1] == false) BFS(i, M-1);
    }

    int ans = 0;
    for (auto&& vec : mat) 
        for (auto&& it : vec)
            if (!it) ans++;

    cout << ans;

    return 0;
}