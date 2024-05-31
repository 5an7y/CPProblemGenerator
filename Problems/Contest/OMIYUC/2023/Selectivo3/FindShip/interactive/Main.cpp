#include "FindShip.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matriz;
int N, M, X;
int tries;
bool termino = false;

int Conocer(int x, int y) {
	if (!(0 <= x && x <= N - 1 && 0 <= y && y <= M - 1)) {
		return -1;
	}
	tries++;
	if (tries > N * M) {
		cerr << "Te pasaste del limite de preguntas\n";
		cout << 0.0 << '\n';
		exit(0);
	}
	termino = (matriz[x][y] == X);
	return matriz[x][y];
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> X;
	matriz.resize(N, vector<int>(M));
	
	for (auto& vec : matriz)
		for (auto& it : vec)
			cin >> it;
// Problems\OMIYUC\2023\Selectivo4\DungeonsAndDragons
	tries = 0;
	Encontrar(N, M, X);
	if (!termino) {
		cout << 0.0 << '\n';
		return 0;
	} 

	if (tries <= N + M + 1) {
		cout << 1.0 << '\n';
		return 0;
	}
	if (tries <= min(N * (log2(M) + 1), M * (log2(N) + 1))) {
		cout << 0.6 << '\n';
		return 0;
	}
	cout << 0.3 << '\n';
	return 0;
}
