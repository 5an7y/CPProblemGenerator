#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> bucket;
set<char> diff;

int N;
string S;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        diff.insert(S[i]);
    
    int l = 0,
        r = 0,
        act_dif = 0,
        goal_dif = diff.size(),
        ans = N;
    while (l < N) {
        while (r < N && goal_dif != act_dif)
            if ( (++bucket[S[r++]]) == 1)
                act_dif++;
        if (act_dif == goal_dif)
            ans = min(r - l, ans);
        if ((--bucket[S[l++]]) == 0)
            act_dif--;
    }
    cout << ans << '\n';

    return 0;
}