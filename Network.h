//
// Created by Sereg on 26.11.2019.
//

#ifndef NETWORK_SORT_NETWORK_H
#define NETWORK_SORT_NETWORK_H


class Network {
private:
    Address addr;
    int mask;

public:
         Network(const string& cidr) : addr(Address(cidr.substr(0, cidr.find('/')))) {
        stringstream s;
        s << cidr.substr(cidr.find('/') + 1);
        s >> mask;
    }
    bool test(const Address& bddr);
};



#endif //NETWORK_SORT_NETWORK_H
