#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

#define f first
#define s second
#define pb push_back
#define multitest() ll _; cin>>_; while(_--)
#define pq_min(a) priority_queue<a, vector<a>, greater<a>>
#define pq_max(a) priority_queue<a>

//checa que tus constantes coincidan con el problema
const ll MAXN = 1e6+5;
const ll INF = 1e9+5;
const ll MOD = 998244353;
const ll SQ = 320;
mt19937_64 rnd(98275314);

ll n, q, offset;
multiset <ll> st;
std::multiset<ll>::iterator it;

void agrega(ll a) {
    st.insert(a);
    if (st.size()%2 == 0 && a < *it) it = prev(it);
    if (st.size()%2 == 1 && a >= *it) it = next(it);
    return;
}

void borra(ll a) {
    if (a == *it) {
        if (it != st.begin()) {
            it = prev(it);
            st.erase(next(it));
            if (st.size()%2 == 1) it = next(it);
        }
        else {
            it = next(it);
            st.erase(prev(it));
            if (st.size()%2 == 0) it = prev(it);
        }
        return;
    }
    st.erase(st.find(a));
    if (st.size()%2 == 0 && a > *it) it = prev(it);
    if (st.size()%2 == 1 && a < *it) it = next(it);
    return;
}

double ans() {
double a, b;
a = b = *it;
if (st.size()%2 == 0) b = *next(it);
return (a + b)/2 + offset;
}

int main() {
ios_base::sync_with_stdio(0);cin.tie(0);
cin >> n;
ll a; cin >> a; st.insert(a); it = st.begin();
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