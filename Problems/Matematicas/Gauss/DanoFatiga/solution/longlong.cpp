#include <bits/stdc++.h>
using namespace std;

int64_t Gauss(int64_t x) {
    if (x % 2 == 0) return (x / 2) * (x + 1);
    else return (x + 1) / 2 * x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t N, M, X, turno = 1;
    cin >> N >> M >> X; 
    while (true) {
        auto dan_ramon = Gauss(Gauss(turno));
        if (dan_ramon >= M) {
            cout << "Santy";
            return 0;
        }
        if (X >= N) {
            cout << "Ramon";
            return 0;
        }
        N -= X;
        auto dan_santy = Gauss(turno);
        if (dan_santy >= N) {
            cout << "Ramon";
            return 0;
        }
        turno++;
    }

    return 0;
}