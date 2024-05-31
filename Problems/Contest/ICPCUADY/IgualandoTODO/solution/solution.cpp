#include <bits/stdc++.h>
using namespace std;

int N, Q, sz, t = 0;
vector<int> vec;
multiset<int> fpart, spart;
int64_t fsum = 0, ssum = 0;

void printAns() {
    if (sz % 2 == 1) {
        cout << ( (int64_t)(*spart.begin()) * fpart.size() - fsum ) +
                ( ssum -  (int64_t)(*spart.begin()) * spart.size()) << '\n';
    } else {
        int64_t a = *spart.begin(),
                b = *fpart.rbegin();
        cout << min(
            ( a * fpart.size() - fsum ) + ( ssum -  a * spart.size()),
            ( b * fpart.size() - fsum ) + ( ssum -  b * spart.size())
        ) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vec.resize(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        fpart.insert(x);
        vec[i] = x;
        fsum += x;
    }

    while (fpart.size() > spart.size()) {
        auto it = fpart.end();
        it--;
        fsum -= *it;
        ssum += *it;
        spart.insert(*it);
        fpart.erase(it);
    }

    sz = N;
    cin >> Q;
    while (Q--) {
        int pos, ai; 
        cin >> pos >> ai;

        int last_num = vec[pos-1];
        vec[pos-1] = ai;

        if (fpart.size() > 0 && last_num <= *fpart.rbegin()) {
            fpart.erase(fpart.find(last_num));
            fsum -= last_num;
            fsum += *spart.begin();
            ssum -= *spart.begin();
            fpart.insert(*spart.begin());
            spart.erase(spart.begin());
        } else {
            ssum -= last_num;
            spart.erase(spart.find(last_num));
        }

        if (fpart.size() > 0 && ai <= *fpart.rbegin()) {
            fpart.insert(ai);
            fsum += ai;
        } else {
            spart.insert(ai);
            fpart.insert(*spart.begin());
            ssum += ai;
            fsum += *spart.begin();
            ssum -= *spart.begin();
            spart.erase(spart.begin());
        }

        while (fpart.size() > spart.size()) {
            auto it = fpart.end();
            it--;
            fsum -= *it;
            ssum += *it;
            spart.insert(*it);
            fpart.erase(it);
        }
        printAns();
    }

    return 0;
}