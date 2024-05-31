#include <bits/stdc++.h>
using namespace std;

uint64_t Gauss(uint64_t x) {
    if (x % 2 == 0) return (x / 2) * (x + 1);
    else return (x + 1) / 2 * x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    uint64_t N, M = 59999, X = 5346456736, turno = 60000;

//    cout << Gauss(M) + M * X << " " << Gauss(Gauss(turno)) << '\n';
//    cout << log10( Gauss(M) + M * X ) << " " << log10( Gauss(Gauss(turno)) );
    cout << "Santy";
    return 0;
}