//
// Created by Sereg on 26.11.2019.
//

#include "MyStdVectorList.h"

int MyStdVectorList::partition(int lo, int hi) {
    E pivot = arr[hi];
    for (int j = lo; j < hi; j++) {
        if (MyList<E>::cmp(arr[j], pivot) < 0) {
            std::swap(arr[lo++], arr[j]);
        }
    }
    std::swap(arr[lo], arr[hi]);
    return lo;
}
void MyStdVectorList::quickSort(int lo, int hi) {
    if (lo >= hi) return;
    int p = partition(lo, hi);
    quickSort(lo, p - 1);
    quickSort(p + 1, hi);
}
void MyStdVectorList::merge(int lt, int m, int rt) {
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
}
void MyStdVectorList::mergeSort(int lt, int rt) {
    if (lt >= rt) return;
    int m = lt + (rt - lt) / 2;
    mergeSort(lt, m);
    mergeSort(m + 1, rt);
    merge(lt, m, rt);
}