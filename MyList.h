#ifndef TESTIK_MYLIST_H
#define TESTIK_MYLIST_H
#pragma once
#include <string>
#include <cstdlib>
#include "Address.h"
class Address;

bool operator< (Address& address1, Address& address2)
{
    if (address1.bits().size() != address2.bits().size())  	return address1.bits().size() < address2.bits().size();
    size_t i = 0;
    for (;;) {
        if (address1.bits()[i] != address2.bits()[i])    	return address1.bits()[i] < address2.bits()[i];
        if (++i == address1.bits().size())          		return false;
    }
}

bool operator> (Address& address1, Address& address2) {
    if (address1.bits().size() != address2.bits().size()) return address1.bits().size() > address2.bits().size();
    size_t i = 0;
    for (;;) {
        if (address1.bits()[i] != address2.bits()[i]) return address1.bits()[i] > address2.bits()[i];
        if (++i == address1.bits().size()) return false;
    }
}

template <typename E>
class MyList {
protected:
    int (*cmp)(E, E);

public:
    MyList() {
        this->cmp = [](E a, E b)
        {
            return a < b ? -1 : (a > b ? 1 : 0);
        };
    }

    virtual void add(E element) = 0;

    virtual E get(int index) = 0;

    virtual E remove(int index) = 0;

    virtual size_t getSize() = 0;

    virtual int indexOf(E element) = 0;

    virtual std::string toString() = 0;

    virtual void insertionSort() = 0;

    virtual void quickSort() = 0;

    virtual void mergeSort() = 0;

    virtual void forEach(void (*b)(E)) = 0;

    void fill(int n, E (*g)()) {
        for (int i = 0; i < n; i++) {
            this->add(g());
        }
    }

    void setComparator(int (*c)(E, E)) {
        this->cmp = c;
    }
};


#endif //TESTIK_MYLIST_H
