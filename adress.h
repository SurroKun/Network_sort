//
// Created by Sereg on 29.10.2019.
//

#ifndef NETWORK_SORT_ADRESS_H
#define NETWORK_SORT_ADRESS_H
#include <iostream>
#include <vector>
#include <sstream>
#include <bitset>
using namespace std;

class Address {
private:
    vector<bool> arr;

public:
    Address(const string& str) {}

    vector<bool> bits() const {
        return arr;
    }

    string toString() {};


#endif //NETWORK_SORT_ADRESS_H
