#include <bits/stdc++.h>
using namespace std;

int N, Q, sz, t = 0;
multiset<int> fpart, spart;

void printMedian() {
    if (sz % 2 == 1) {
        cout << *spart.begin() + t<< '\n';
    } else {
        int a = *spart.begin() + t,
            b = *fpart.rbegin() + t;
        cout << (a + b) / 2;
        if ((a + b) % 2 == 1) cout << ".5";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        fpart.insert(x);
    }

    while (fpart.size() > spart.size()) {
        auto it = fpart.end();
        it--;
        spart.insert(*it);
        fpart.erase(it);
    }

    sz = N;
    printMedian();

    cin >> Q;
    while (Q--) {
        t++;
        int c, xi; cin >> c >> xi;
        xi -= t;
        if (c == -1) {
            if (fpart.size() > 0 && xi <= *fpart.rbegin()) {
                fpart.erase(fpart.find(xi));
                fpart.insert(*spart.begin());
                spart.erase(spart.begin());
            } else {
                spart.erase(spart.find(xi));
            }
            sz--;
        } else if (c == 1) {
            if (fpart.size() > 0 && xi <= *fpart.rbegin()) {
                fpart.insert(xi);
            } else {
                spart.insert(xi);
                fpart.insert(*spart.begin());
                spart.erase(spart.begin());
            }
            sz++;
        }

        while (fpart.size() > spart.size()) {
            auto it = fpart.end();
            it--;
            spart.insert(*it);
            fpart.erase(it);
        }
        printMedian();
    }

    return 0;
}