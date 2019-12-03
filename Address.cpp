#include "Address.h"
#include <bitset>
#include <sstream>


string Address::toString() {
    stringstream ret;
    int n;

    if (arr.size() == 32) {
        n =  8;
    } else {
        n = 16;
        ret << hex;
    }

    for (int i = 0; i < (arr.size() / n); i++) {
        bitset<16> b;
        for (int j = n - 1; j >= 0; j--) {
            b[j] = arr[i * n + (n - j - 1)];
        }
        ret << b.to_ulong();
        if (i < (arr.size() / n) - 1) {
            ret << (arr.size() == 32 ? '.' : ':');
        }
    }

    return ret.str();
}