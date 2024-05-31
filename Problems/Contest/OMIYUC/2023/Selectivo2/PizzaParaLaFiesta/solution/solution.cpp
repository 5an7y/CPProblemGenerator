
#include <bits/stdc++.h>
using namespace std;
 
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define MOD(n, k) ( ( ((n) % k) + k ) % k )
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vp;
 
const ll LN = (ll)(1e5 +5),
         LM = (ll)(1e2),
         MOD = 0;
 
void Solve() {
    int N, K, F;
 
    cin >> N >> F >> K;
    vector<int> ingridients(N);
    for (auto& it : ingridients) cin >> it;

    sort(all(ingridients));
    unordered_map<int, int> mapping;
    for (int i = 0; i < N; i++)
        mapping[ingridients[i]] = i;
 
    vector<vector<int>> dislikes(F);
    for (int i = 0; i < F; i++)
    {
        int M, disk;
        cin >> M;
        while(M--)
            cin >> disk, dislikes[i].push_back(mapping[disk]);
    }
 
    int ans = 0;
    for (int i = 0; i < (1<<F); i++)
    {
        vector < bool > ingredients(N,true);
        int cont = N, inv = 0;
        for (int j = 0; j < F; j++)
        {
            if(!(i & (1<<j)))
                continue;
            inv++;
            for (auto &&del : dislikes[j])
            {
                if (!ingredients[del])
                    continue;
                cont--;
                ingredients[del] = false;
            }
        }
        if (cont >= K)
            ans = max(ans, inv);
    }
    cout << ans;
    
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int tc = 1;
    //cin >> tc;
    forn(i, tc)
        Solve();
 
 
    return 0;
}