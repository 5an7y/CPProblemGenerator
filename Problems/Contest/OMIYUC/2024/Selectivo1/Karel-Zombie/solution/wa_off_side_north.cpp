#include <bits/stdc++.h>
using namespace std;

int64_t gauss(int64_t N) {
    return (N) * (N + 1) / 2;
}

int64_t calc_infectados(
    int64_t N, 
    int64_t x,
    int64_t y,
    int64_t D
) { 
    int64_t infectados = D * D + (D-1) * (D-1);
    int64_t off_side_north = max((int64_t)0, y + D - N),
            off_side_south = max((int64_t)0, D - y),
            off_side_east  = max((int64_t)0, x + D - 1 - N),
            off_side_west  = max((int64_t)0, D - x);

    infectados -= off_side_north * off_side_north
                + off_side_south * off_side_south
                + off_side_east  * off_side_east
                + off_side_west  * off_side_west;

    int64_t overlap_nw = max((int64_t)0, min(off_side_north - x,  off_side_west - (N - y + 1) )),
            overlap_ne = max((int64_t)0, min(off_side_north - (N - x + 1),  off_side_east - (N - y + 1) )),
            overlap_sw = max((int64_t)0, min(off_side_south - x,  off_side_west - y)),
            overlap_se = max((int64_t)0, min(off_side_south - (N - x + 1),  off_side_east - y));
    
    infectados += gauss(overlap_ne) 
                + gauss(overlap_nw) 
                + gauss(overlap_se) 
                + gauss(overlap_sw);

    return infectados;
}

int64_t binaria(int l, int r, int N, int64_t K, int x, int y) {
    if (l == r) return l;
    int mit = (l + r) / 2;
    if (calc_infectados(N, x, y, mit) >= K)
        return binaria(l, mit, N, K, x, y);
    else
        return binaria(mit + 1, r, N, K, x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t N, K, x, y;
    cin >> N >> K >> x >> y;

    cout << binaria(1, 2 * N, N, K, x, y);

    return 0;
}