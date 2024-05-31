#include <bits/stdc++.h>
using namespace std;

bool match(string& a, string& regex) {
    if (a.size() != regex.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (regex[i] == 'X') continue;
        else if (regex[i] != a[i]) return false;
    }
    return true;
}

int main() {
    // Cambiamos el nombre
    ifstream file("1.in");
    ofstream salida("1.out");

    vector<string> vec;
    int word_index = 1000;
    for (int i = 0; i < 11; i++) {
        string a;
        getline(file, a);
        vec.push_back(a);
        word_index = min(word_index, (int) a.size());
    }
    string regex_word = "";
    for (auto& p : vec)
        regex_word += p[word_index - 1];

    ifstream diccionario_file("Santysccionario.txt");
    string aux;
    int ans = 0;
    while (getline(diccionario_file, aux)) {
        if (match(aux, regex_word)) ans++;
    }

    salida << ans << '\n';
    return 0;
}