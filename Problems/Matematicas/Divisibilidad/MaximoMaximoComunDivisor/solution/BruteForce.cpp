#include <bits/stdc++.h>
using namespace std;

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);

    vector<int> nums;

    int N; cin >> N;
    nums.resize(N);
    int maxi = 1;
    for (auto& it : nums) cin >> it;
    
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            maxi = max(maxi, __gcd(nums[i], nums[j]));

    cout << maxi;
    return 0;
}