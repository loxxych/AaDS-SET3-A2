//
// Created by loxxy on 15.11.2025.
//

#ifndef SET3_SORTTESTER_H
#define SET3_SORTTESTER_H

#include <vector>
#include "../Sorter/Sorter.h"
#include "../ArrayGenerator/ArrayGenerator.h"

using namespace std;

class SortTester {
private:
    Sorter* _sorter;
    ArrayGenerator* _generator;
    vector<int> _randomArray;
    vector<int> _generatorReverse;
    vector<int> _generatorAlmost;

public:
    SortTester();

    long long measureMergeTime(vector<int> &arr);
    long long measureHybridMergeTime(vector<int>& arr);

    //long long measureSort(vector<int>& arr) const;
    long long averageMergeSortingTime(vector<int>& array);
    long long averageHybridMergeSortingTime(vector<int>& array);

    long long runMergeRegularTests(int n);
    long long runMergeSortedBackwardsTests(int n);
    long long runMergeAlmostSortedTests(int n);

    long long runHybridMergeRegularTests(int n);
    long long runHybridMergeSortedBackwardsTests(int n);
    long long runHybridMergeAlmostSortedTests(int n);
};


#endif //SET3_SORTTESTER_H