/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXM 100000
using namespace std;

vector<int> divi[MAXM + 1];

int solve(int n, int m, vector<int> &a, vector<int> &b){
    cerr << "Hola Mundo" << endl;
    for(int i = 1; i <= MAXM; ++i)
        for(int j = i; j <= MAXM; j += i) divi[j].push_back(i);

    sort(a.begin(), a.end());
    cerr << "Hola Mundo" << endl;
    if(!a[0]) return 0;
    cerr << "Hola Mundo" << endl;
    int max_b = 0, target = 0;
    bool ap[MAXM + 1] = {};
    for(int x : b){
        if(!ap[x]) target++;
        ap[x] = true;
        max_b = max(max_b, x);
    }

    int cub[MAXM + 1] = {};
    int r = -1, ans = INT_MAX, cnt = ap[0];
    cerr << "Hola Mundo" << endl;

    for(int l = 0; l < n; ++l){
        while(r + 1 < n && cnt < target){
            r++;
            for(int d : divi[a[r]]){
                if(d > max_b) break;
                cnt += ++cub[d] == 1 && ap[d];
            }
        }

        if(cnt == target) ans = min(ans, a[r] - a[l]);

        for(int d : divi[a[l]]){
            if(d > max_b) break;
            cnt -= --cub[d] == 0 && ap[d];
        }
    }

    return (ans == INT_MAX ? -1 : ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("cases/sub2.21.in");
    cerr << "Hola Mundo" << endl;
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    cerr << "Hola Mundo" << endl;
    cout << solve(n, m, a, b) << '\n';
}