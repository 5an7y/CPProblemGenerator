#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N, T;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    ordered_set<pair<int, int>> S;
    
    int a; cin >> a;
    for (int i = 1; i < n; i++) {ll a; cin >> a; agrega(a);}
cout << ans() << '\n';
offset++;
multitest() {
    ll a, b;
    cin >> a >> b;
    if (a == -1) borra(b - offset);
    else agrega(b - offset);
    cout << ans() << '\n';
    offset++;
}
return 0;
}