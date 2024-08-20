#include <bits/stdc++.h>
using namespace std;

int N, sz, no_rot_count, rot_iz_count, rot_der_count, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> sz;
        bool no_rot = false;
        bool rot_iz = false;
        bool rot_der = false;
        while (sz--) {
            cin >> x;
            if (x == i) no_rot = true;
            if (x != (i + 2) % N) rot_der = true;
            if (x != (i - 2 + N) % N) rot_iz = true;
        }
        if (no_rot) no_rot_count++;
        if (rot_iz) rot_iz_count++;
        if (rot_der) rot_der_count++;
    }

    if (no_rot_count == N) cout << 0;
    else if (rot_der_count == N || rot_iz_count == N) cout << 1;
    else cout << 2;

    return 0;
}