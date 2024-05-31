#include "FindShip.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matriz;
int N, M, X;
int tries;
bool termino = false;

int Conocer(int x, int y) {
	if (!(0 <= x && x <= N - 1 && 0 <= y && y <= M - 1)) {
		cerr << "Preguntaste por una posicion invalida y se te devolvio -1\n";
		return -1;
	}
	tries++;
	if (tries > N * M) {
		cerr << "Te pasaste del limite de preguntas\n";
		exit(0);
	}
	cerr << "Intento #" << tries << ": Preguntaste por (" << x << ", " << y << ") y regreso " << matriz[x][y] << '\n'; 
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

	tries = 0;
	Encontrar(N, M, X);
	if (termino) {
		cerr << "Felicidades! Encontraste la nave.\n";
	} else {
		cerr << "Tu programa no fue capaz de encontrar la nave :(\n";
	}
	return 0;
}
