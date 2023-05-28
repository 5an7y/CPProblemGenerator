#include <bits/stdc++.h>
using namespace std;

int nums[1000000], lef[1000000], righ[1000000];
int sz = -1;
int LOGQ;

void insert_bin(int x) {
    nums[++sz] = x;
    int p = 0, h = 0;
    while (p != sz) {
        if (x < nums[p] && lef[p]  == -1) lef[p] = sz;
        if (x > nums[p] && righ[p] == -1) righ[p] = sz;
        if (x < nums[p]) p = lef[p];
        else if (x > nums[p]) p = righ[p];
        h++;
    }
    assert(h <= LOGQ);
}

bool search(int x) {
    if (sz < 0) return false;
    int p = 0;
    int h = 0;
    while (p != -1) {
        if (x == nums[p]) {return true;}
        else if (x < nums[p]) p = lef[p];
        else p = righ[p];
        h++;
    }
    assert(h <= LOGQ);
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Q; cin >> Q;
    LOGQ = log2(Q) + 1;

    for (int i = 0; i < Q; i++)
        nums[i] = lef[i] = righ[i] = -1;

    while (Q--) {
        int o, x; cin >> o >> x;
        bool is_in = search(x);
        if (o == 1 && !is_in) insert_bin(x);
        if (o == 2) {
            if (is_in) cout << "Si\n";
            else cout << "No\n";
        }
    }

    return 0;
}