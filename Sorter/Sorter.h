//
// Created by loxxy on 15.11.2025.
//

#ifndef SET3_SORTER_H
#define SET3_SORTER_H

#include <algorithm>
#include <vector>

using namespace std;

class Sorter {
public:
    void insertionSort(vector<int>& arr, int left, int right);
    void merge(vector<int>& arr, int left, int mid, int right);
    void mergeSort(vector<int>& arr, int left, int right);
    void hybridMergeSort(vector<int>& array, int left, int right);
};


#endif //SET3_SORTER_H