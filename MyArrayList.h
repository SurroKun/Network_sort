#ifndef LAB1_MYARRAYLIST_H
#define LAB1_MYARRAYLIST_H
#pragma once
#include "MyList.h"
#include <bitset>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
class Address;
bool operator== (Address& address1, Address& address2)
{
    if (address1.bits().size() != address2.bits().size())  	return false;
    size_t i = 0;
    for (;;) {
        if (address1.bits()[i] != address2.bits()[i])    	return false;
        if (++i == address1.bits().size())          		return true;
    }
}
std::ostream& operator << (std::ostream& out, const Address& address)
{
    for (auto bit : address.bits()) out << bit << " ";
    return out;
}
template <typename E>

class MyArrayList: public MyList<E> {
private:
    E *arr;
    size_t capacity;
    size_t size;

    void grow() {
        size_t newCap = capacity + 16;
        E *newArr = new E[newCap];
        if (arr != NULL) {
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete arr;
        }
        capacity = newCap;
        arr = newArr;
    }

    int partition(int lo, int hi) {
        E pivot = arr[hi];
        for (int j = lo; j < hi; j++) {
            if (MyList<E>::cmp(arr[j], pivot) < 0) {
                std::swap(arr[lo++], arr[j]);
            }
        }
        std::swap(arr[lo], arr[hi]);
        return lo;
    }

    void quickSort(int lo, int hi) {
        if (lo >= hi) return;
        int p = partition(lo, hi);
        quickSort(lo, p - 1);
        quickSort(p + 1, hi);
    }


    void merge(int lt, int m, int rt) {
        int n1 = m - lt + 1;
        int n2 = rt - m;

        E *L = new E[n1];
        E *R = new E[n2];

        for (int i = 0; i < n1; i++) {
            L[i] = arr[lt + i];
        }

        for (int j = 0; j < n2; j++) {
            R[j] = arr[m + j + 1];
        }

        int i = 0, j = 0;
        int k;

        for (k = lt; i < n1 && j < n2; k++) {
            if (MyList<E>::cmp(L[i], R[j]) <= 0) {
                arr[k] = L[i++];
            } else {
                arr[k] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++];
        }

        while (j < n2) {
            arr[k++] = R[j++];
        }

        delete[] L;
        delete[] R;
    }

    void mergeSort(int lt, int rt) {
        if (lt >= rt) return;
        int m = lt + (rt - lt) / 2;
        mergeSort(lt, m);
        mergeSort(m + 1, rt);
        merge(lt, m, rt);
    }

public:
    MyArrayList() : MyList<E>() {
        arr = NULL;
        size = capacity = 0;
        grow();
    }

    void add(E element) {
        if (size == capacity) grow();
        arr[size++] = element;
    }

    E get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("index");
        }
        return arr[index];
    }

    E remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("index");
        }
        E ret = arr[index];
        size--;
        for (int i = 0; i < (size - index); i++) {
            arr[index + i] = arr[index + i + 1];
        }
        return ret;
    }

    size_t getSize() {
        return size;
    }

    int indexOf(E element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    std::string toString() {
        std::stringstream ret;
        for (int i = 0; i < size; i++) {
            ret << arr[i];
            if (i != size - 1) {
                ret << ", ";
            }
        }
        return ret.str();
    };

    void forEach(void (*b)(E)) {
        for (int i = 0; i < size; i++) {
            b(arr[i]);
        }
    }

    void insertionSort() {
        for (int i = 1; i < size; i++) {
            E key = arr[i];
            int j;
            for (j = i - 1; j >= 0 && MyList<E>::cmp(arr[j], key) > 0; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = key;
        }
    }

    void quickSort() {
        quickSort(0, size - 1);
    }

    void mergeSort() {
        mergeSort(0, size - 1);
    }
};


#endif //LAB1_MYARRAYLIST_H
