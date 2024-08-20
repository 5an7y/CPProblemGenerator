#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> meses = {
        "ENE", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DIC"
    };
    vector<int> dias = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    string mes1, mes2; int d1, d2;
    cin >> mes1 >> d1 >> mes2 >> d2;
    pair<int, int> dia1, dia2;

    for (int i = 0; i < 12; i++) {
        if (mes1 == meses[i]) dia1 = {i, d1};
        if (mes2 == meses[i]) dia2 = {i, d2};
    }

    int res = 0;
    res -= d1;
    while (dia1.first != dia2.first) {
        res += dias[dia1.first++];
    }
    res += d2;

    cout << res;

    return 0;
}