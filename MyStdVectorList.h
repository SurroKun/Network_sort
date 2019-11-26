//
// Created by Sereg on 26.11.2019.
//

#ifndef NETWORK_SORT_MYSTDVECTORLIST_H
#define NETWORK_SORT_MYSTDVECTORLIST_H
#pragma once
#include "MyList.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>

template <typename E>
class MyStdVectorList: public MyList<E> {
private:
    std::vector<E> arr;

    int partition(int lo, int hi);

    void quickSort(int lo, int hi);
    void merge(int lt, int m, int rt);
    void mergeSort(int lt, int rt);

public:
    MyStdVectorList() : MyList<E>() {
    }
    void add(E element) {
        arr.push_back(element);
    }
    E get(int index) {
        return arr[index];
    }
    E remove(int index) {
        E ret = arr[index];
        arr.erase(arr.begin() + index);
        return ret;
    }
    size_t getSize() {
        return arr.size();
    }
    int indexOf(E element) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }
    std::string toString() {
        std::stringstream ret;
        ret << "[";
        for (int i = 0; i < arr.size(); i++) {
            ret << arr[i];
            if (i != arr.size() - 1) {
                ret << ", ";
            }
        }
        ret << "]";
        return ret.str();
    }

    void forEach(void (*b)(E)) {
        for (int i = 0; i < arr.size(); i++) {
            b(arr[i]);
        }
    }

    void insertionSort() {
        for (int i = 1; i < arr.size(); i++) {
            E key = arr[i];
            int j;
            for (j = i - 1; j >= 0 && MyList<E>::cmp(arr[j], key) > 0; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = key;
        }
    }

    void quickSort() {
        quickSort(0, arr.size() - 1);
    }

    void mergeSort() {
        mergeSort(0, arr.size() - 1);
    }
};

#endif //NETWORK_SORT_MYSTDVECTORLIST_H
