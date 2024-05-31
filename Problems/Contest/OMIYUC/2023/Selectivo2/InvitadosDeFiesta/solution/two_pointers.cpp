#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<int, int>> nums(N);
    vector<int> blacklist(M);
    for (int i = 0; i < N; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }
    for(auto& it: blacklist) cin >> it;
    sort(nums.begin(), nums.end());
    sort(blacklist.begin(), blacklist.end());
    vector<pair<int, int>> ans;

    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j < M && nums[i].first > blacklist[j]) j++;
        if (j < M && nums[i].first == blacklist[j]) continue;
        ans.push_back({nums[i].second, nums[i].first});
    }
    if (ans.size() == 0) {
        cout << "-1";
        return 0;
    }
    sort(ans.begin(), ans.end());
    K = min(K, (int) ans.size());
    for (int i = 0; i < K; i++)
        cout << ans[i].second << ' ';

    return 0;
}