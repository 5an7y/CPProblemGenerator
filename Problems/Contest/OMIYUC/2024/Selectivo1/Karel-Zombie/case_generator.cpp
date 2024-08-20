#include <iostream>
#include "Generator.hpp"
#include "Random.hpp"

using std::max;
using std::min;

int64_t gauss(int64_t N) {
    return (N) * (N + 1) / 2;
}

int64_t calc_infectados(
    int64_t N, 
    int64_t x,
    int64_t y,
    int64_t D
) { 
    int64_t infectados = D * D + (D-1) * (D-1);
    int64_t off_side_north = max((int64_t)0, y + D - 1 - N),
            off_side_south = max((int64_t)0, D - y),
            off_side_east  = max((int64_t)0, x + D - 1 - N),
            off_side_west  = max((int64_t)0, D - x);

    infectados -= off_side_north * off_side_north
                + off_side_south * off_side_south
                + off_side_east  * off_side_east
                + off_side_west  * off_side_west;

    int64_t overlap_nw = max((int64_t)0, min(off_side_north - x,  off_side_west - (N - y + 1) )),
            overlap_ne = max((int64_t)0, min(off_side_north - (N - x + 1),  off_side_east - (N - y + 1) )),
            overlap_sw = max((int64_t)0, min(off_side_south - x,  off_side_west - y)),
            overlap_se = max((int64_t)0, min(off_side_south - (N - x + 1),  off_side_east - y));
    
    infectados += gauss(overlap_ne) 
                + gauss(overlap_nw) 
                + gauss(overlap_se) 
                + gauss(overlap_sw);

    return infectados;
}


int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    std::int64_t N, K, x, y;
    std::string k_arg, coords_args;
    Generator::arguments >> N >> k_arg >> coords_args;

    if (coords_args == "ESQUINA") {
        int typ; Generator::arguments >> typ;
        switch (typ)
        {
        case 1:
            x = y = 1;
            break;
        case 2:
            x = 1;
            y = 2;
            break;
        case 3:
            x = 2;
            y = 1;
            break;
        case 4:
            x = N;
            y = 1;
            break;
        case 5:
            x = N - 1;
            y = 1;
            break;
        case 6:
            x = N;
            y = 2;
            break;
        case 7:
            y = N;
            x = 1;
            break;
        case 8:
            y = N - 1;
            x = 1;
            break;
        case 9:
            y = N;
            x = 2;
            break;
        case 10:
            y = N;
            x = N;
            break;
        case 11:
            y = N - 1;
            x = N;
            break;
        case 12:
            y = N;
            x = N-1;
            break;

        default:
            break;
        }
    } else if (coords_args == "CENTER") {
        x = y = (N + 1) / 2;
    } else {
        x = Random::rnd<int64_t>(1, N);
        y = Random::rnd<int64_t>(1, N);
    }

    if (k_arg == "MAXED") {
        K = N * N;
    } else if (k_arg == "EQ") {
        auto D = Random::rnd<int64_t>(1, 2 * N);
        K = calc_infectados(N, x, y, D);
    } else if (k_arg == "ANT") {
        auto D = Random::rnd<int64_t>(1, N);
        K = calc_infectados(N, x, y, D) + 1;
    } else if (k_arg == "IN_LIMIT") {
        auto D = min({x, N - x + 1, y, N - y + 1});
        K = Random::rnd<int64_t>(1, calc_infectados(N, x, y, D));
    } else if (k_arg == "OFF_LIMIT") {
        auto D = min({x, N - x + 1, y, N - y + 1});
        K = Random::rnd<int64_t>(calc_infectados(N, x, y, D) + 1, N * N);
    } else {
        K = Random::rnd<int64_t>(1, N * N);
    }

    Generator::case_in << N << ' ' << K << ' ' << x << ' ' << y;

    return 0;
}