#include "TorneoUNO.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> Elementos;
int N, sz, max_tries, tries;

int Mejor(int x, int y) {
	tries++;
	if (tries > sz) {
		cerr << "Te pasaste del limite de preguntas\n";
		cout << 0.0 << '\n';
		exit(0);
	}

	if (!(1 <= x && x <= sz && 1 <= y && y <= sz))
		return -1;
	
	
	if (Elementos[x-1] == Elementos[y-1]) {
		return 0;
	} else if (Elementos[x-1] < Elementos[y-1]) {
		return 2;
	} else {
		return 1;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	sz = 1 << N;
	Elementos.resize(sz);

	for (auto& it : Elementos)
		cin >> it;

	tries = 0;
	int ganador = EncontrarGanador(N);
	if (ganador <= 0 || sz + 1 <= ganador) {
		cout << 0.0 << '\n';
		return 0;
	}

	bool correcto = true;
	for (auto& it : Elementos) {
		if (it > Elementos[ganador-1]) {
			correcto = false;
		}
	}

	if (!correcto) {
		cout << 0.0 << '\n';
		return 0;
	}

	max_tries = (2 * sz + 2) / 3;
	if (tries <= max_tries) {
		cout << 1.0 << '\n';
		return 0;
	}
	
	cout << 0.4 << '\n';
	return 0;
}
