//
// Created by Sereg on 02.12.2019.
//

#ifndef TESTIK_NETWORK_H
#define TESTIK_NETWORK_H

class Network {
private:
    Address addr;
    int mask;
public:
    Network(const string &cidr): addr(Address(cidr.substr(0, cidr.find('/')))) {
        stringstream s;
        s << cidr.substr(cidr.find('/') + 1);
        s >> mask;
    };

    bool test(const Address &bddr) {
        vector<bool> a = addr.bits();
        vector<bool> b = bddr.bits();

        if (a.size() != b.size()) return false;

        for (int i = 0; i < mask; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
    }
};

#endif //TESTIK_NETWORK_H
