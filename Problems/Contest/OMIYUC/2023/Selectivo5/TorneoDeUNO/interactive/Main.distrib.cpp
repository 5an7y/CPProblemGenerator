#include "TorneoUNO.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> Elementos;
int N, sz, max_tries, tries;

int Mejor(int x, int y) {
	tries++;
	if (tries > sz) {
        puts("Te pasaste del limite de preguntas");
		exit(0);
	}

	if (!(1 <= x && x <= sz && 1 <= y && y <= sz)) {
        printf("Preguntaste por (%d, %d) y no esta en los limites\n", x, y);
        fflush(stdout);
		return -1;
	}


	if (Elementos[x-1] == Elementos[y-1]) {
        printf("Preguntaste por (%d, %d) y quedo en empate\n", x, y);
        fflush(stdout);
		return 0;
	} else if (Elementos[x-1] < Elementos[y-1]) {
		printf("Preguntaste por (%d, %d) y (%d) obtuvo mas victorias\n", x, y, y);
        fflush(stdout);
		return 2;
	} else {
		printf("Preguntaste por (%d, %d) y (%d) obtuvo mas victorias\n", x, y, x);
        fflush(stdout);
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
		printf("%d No es una respuesta valida", ganador);
        fflush(stdout);
		return 0;
	}

	bool correcto = true;
	for (auto& it : Elementos) {
		if (it > Elementos[ganador-1]) {
			correcto = false;
		}
	}

	if (!correcto) {
		cerr << "El elemento que adivinaste no es el ganador" << std::endl;
		return 0;
	}

	cerr << "Felicidades, encontraste el ganador!" << std::endl;
	return 0;
}
