#include <iostream>
#include <queue>
#include <stack>

#include "Generator.hpp"
#include "Random.hpp"

int N, M, K;
std::vector<int> posx = {1, -1, 0, 0},
                 posy = {0, 0, 1, -1};
std::vector<std::vector<int>> mat;

void dfs(int x, int y) {
    std::stack<std::pair<int, int>> dfs;
    dfs.push({x, y});
    while (!dfs.empty()) {
        if (K == 0) break;
        int xi = dfs.top().first,
            yi = dfs.top().second;
        dfs.pop();
        std::vector<int> available_moves;
        for (int i = 0; i < 4; i++) {
            int nx = xi + posx[i];
            int ny = yi + posy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && !mat[nx][ny])
                available_moves.push_back(i);
        }
        if (available_moves.size() == 0) continue;
        int r_move = available_moves[Random::rnd<int>(0, available_moves.size()-1)];
        int nx = xi + posx[r_move], ny = yi + posy[r_move];
        mat[nx][ny] = 1;
        K--;
        dfs.push({xi, yi});
        dfs.push({nx, ny});
    }
    return;
}

void dfs2(int x, int y) {
    std::queue<std::pair<int, int>> bfs;
    bfs.push({x, y});
    mat[x][y] = 2;
    while (!bfs.empty()) {
        int xi = bfs.front().first;
        int yi = bfs.front().second;
        bfs.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xi + posx[i];
            int ny = yi + posy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && mat[nx][ny] == 0) {
                mat[nx][ny] = 2;
                bfs.push({nx, ny});
            }
        }
    }
    return;
}

void fill_spaces() {
    for (int i = 0; i < M; i++) {
        if (mat[0][i] == 0) dfs2(0, i);
        if (mat[N-1][i] == 0) dfs2(N-1, i);
    }
    for (int i = 0; i < N; i++) {
        if (mat[i][0] == 0) dfs2(i, 0);
        if (mat[i][M-1] == 0) dfs2(i, M-1);
    }
    for (auto& vec : mat)
        for (auto& it : vec)
            if (it == 0) it = 1;
            else if (it == 2) it = 0;

    return;
}

void generate_rnd_matrix() {
    mat.resize(N, std::vector<int>(M, 0));
    int ini_posx = Random::rnd(0, N-1);
    int ini_posy = Random::rnd(0, M-1);
    mat[ini_posx][ini_posy] = 1;
    K--;
    dfs(ini_posx, ini_posy);
}

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    Generator::arguments >> N >> M >> K;
    generate_rnd_matrix();
    fill_spaces();
    Generator::case_in << N << ' ' << M << '\n';
    for (auto& vec : mat) {
        for (auto& it : vec)
            Generator::case_in << it << ' ';
        Generator::case_in << '\n';
    }

    return 0;
}