//
// Created by Sereg on 03.12.2019.
//

#ifndef LAB1_ADDRESS_H
#define LAB1_ADDRESS_H


#include "vector"
#include <bitset>
#include <sstream>

using namespace std;
class Address {
private:
    vector<bool> arr;

public:
    Address(const string& str){
        char d;
        int n;
        if (str.find('.') != string::npos) {
            d = '.';
            n =  8;
        } else {
            d = ':';
            n = 16;
        }

        for (size_t i = 0, j = str.find(d); true; i = j + 1) {
            j = str.find(d, i);

            string s;
            if (j != string::npos) {
                s = str.substr(i, j - i);
            } else {
                s = str.substr(i);
            }

            stringstream t;
            if (d == ':') t << hex;
            t << s;

            unsigned short c;
            t >> c;

            bitset<16> b(c);
            for (int k = n - 1; k >= 0; k--) {
                arr.push_back(b[k]);
            }

            if (j == string::npos) break;
        }
    }
    Address(){}
    vector<bool> bits() const {
        return arr;
    }
    string toString() {
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
};


#endif //LAB1_ADDRESS_H
