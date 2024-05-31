// Problem: B. Concurso de cartas
// Contest: omegaUp
// URL:
// https://omegaup.com/arena/Yuc_2023_2/#problems/Concurso-de-cartas
// Memory Limit: 32 MB
// Time Limit: 1000 ms
// Start: 16-07-2023 09:15:38
#include <bits/stdc++.h>

#include <cstdint>
using namespace std;

using uint = unsigned int;

#define gcd(x, y) __gcd(x, y)
#define mcm(x, y) abs((x) * (y)) / gcd(x, y)
#define all(x)    begin(x), end(x)
#define pb(x)     push_back(x)
#define endl      '\n'
uint64_t gauss(uint64_t n) { return (n * (n + 1)) / 2; }

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	uint64_t n, k, curr = 1;
	cin >> n >> k;

	n--;
	while (n) {
		if (curr + 1 <= k && gauss(curr + 1) <= n) {
			cout << 'S';
			n -= ++curr;
		} else if (gauss(curr) <= n) {
			cout << 'I';
			n -= curr;
		} else if (n > 1) {
			cout << 'B';
			n -= --curr;
		}
        cerr << n << ' ' << curr << '\n';
	}

	return 0;
}