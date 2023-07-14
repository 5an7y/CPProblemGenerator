#include <bits/stdc++.h>
using namespace std;

namespace Validator {
    std::ifstream case_in, case_out;
    void init_validator() {
        std::string case_in_name("data.in"), case_out_name("data.out");
        case_in.open(case_in_name.c_str());
        case_out.open(case_out_name.c_str());

        if (!case_in) {
            throw std::runtime_error("Error al abrir " + case_in_name + "\n");
            exit(EXIT_FAILURE);
        }
        if (!case_out) {
            throw std::runtime_error("Error al abrir " + case_out_name + "\n");
            exit(EXIT_FAILURE);
        }
        return;
    }
}

int main() {
    Validator::init_validator();
    
    return 0;
}