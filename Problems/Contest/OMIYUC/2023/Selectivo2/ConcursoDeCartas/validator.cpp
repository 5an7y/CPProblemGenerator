#include <bits/stdc++.h>
using namespace std;

namespace Validator {
    std::ifstream case_in, case_out;
    void init_validator() {
        std::string case_in_name("data.in"), case_out_name("data.out");
        case_in.open(case_in_name.c_str());
        case_out.open(case_out_name.c_str());

        if (!case_in) {
            throw runtime_error("Error al abrir " + case_in_name + "\n");
            exit(EXIT_FAILURE);
        }
        if (!case_out) {
            throw runtime_error("Error al abrir " + case_out_name + "\n");
            exit(EXIT_FAILURE);
        }
        return;
    }
}

int main() {
    Validator::init_validator();
    long long N, K;
    string ans, s;

    Validator::case_in >> N >> K;
    Validator::case_out >> ans;

    if (!(cin >> s)) {
        cerr << "Error leyendo la salida del concursante\n";
        cout << 0.0 << '\n';
        return 0;
    }
    if (s.size() != ans.size()) {
        cerr << "Las respuesta no tiene la longitud deseada\n";
        cout << 0.0 << '\n';
        return 0;
    }

    long long suma = 1;
    long long act = 1;
    for (auto& ins : s) {
        if (ins == 'S') {
            act++;
        } else if (ins == 'B') {
            act--;
        } else if (ins != 'I') {
            cerr << "Se dio un caracter invalido\n";
            cout << 0.0 << '\n';
            return 0;
        }

        if (!(0 <= act && act <= K)) {
            cerr << "El valor de la carta se salio del rango\n";
            cout << 0.0 << '\n';
            return 0;
        }

        suma += act;
        if (suma > N) {
            cerr << "La suma se paso del objetivo\n";
            cout << 0.0 << '\n';
            return 0;
        }
    }

    if (act != 1) {
        cerr << "El valor final de la carta no fue 1\n";
        cout << 0.0 << '\n';
        return 0;
    }

    if (suma != N) {
        cerr << "No se consiguio el valor objetivo\n";
        cout << 0.0 << '\n';
        return 0;
    }

    cout << 1.0 << '\n';

    return 0;
}