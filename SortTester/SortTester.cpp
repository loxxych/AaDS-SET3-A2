//
// Created by loxxy on 15.11.2025.
//

#include <chrono>
#include "SortTester.h"

#define MAX_SIZE 100000
#define ITERATIONS 5

SortTester::SortTester() {
    _sorter = new Sorter();
    _generator = new ArrayGenerator();

    _generator->generateBaseArrays(MAX_SIZE);
}

// Time measuring functions
long long SortTester::measureMergeTime(vector<int> &arr) {
    auto start = std::chrono::high_resolution_clock::now();

    _sorter->mergeSort(arr, 0, arr.size() - 1);

    const auto elapsed = std::chrono::high_resolution_clock::now() - start;
    const long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();

    return msec;
}

long long SortTester::measureHybridMergeTime(vector<int>& arr) {
    const auto start = std::chrono::high_resolution_clock::now();

    _sorter->hybridMergeSort(arr, 0, arr.size() - 1);

    const auto elapsed = std::chrono::high_resolution_clock::now() - start;
    const long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();

    return msec;
}

// Utility functions
long long SortTester::averageMergeSortingTime(vector<int>& arr) {
    long long total = 0;

    for (size_t i = 0; i < ITERATIONS; i++) {
        total += measureMergeTime(arr);
    }

    // Average time
    return total / ITERATIONS;
}

long long SortTester::averageHybridMergeSortingTime(vector<int>& arr) {
    long long total = 0;

    for (size_t i = 0; i < ITERATIONS; i++) {
        total += measureHybridMergeTime(arr);
    }

    // Average time
    return total / ITERATIONS;
}

// Merge tests
long long SortTester::runMergeRegularTests(int n) {
    auto array = _generator->generateRandomArray(n);
    return averageMergeSortingTime(array);
}

long long SortTester::runMergeSortedBackwardsTests(int n) {
    auto array = _generator->generateBackwardsArray(n);
    return averageMergeSortingTime(array);
}

long long SortTester::runMergeAlmostSortedTests(int n) {
    auto array = _generator->generateAlmostSortedArray(n);
    return averageMergeSortingTime(array);
}

// Hybrid merge tests
long long SortTester::runHybridMergeRegularTests(int n) {
    auto array = _generator->generateRandomArray(n);
    return averageHybridMergeSortingTime(array);
}

long long SortTester::runHybridMergeSortedBackwardsTests(int n) {
    auto array = _generator->generateBackwardsArray(n);
    return averageHybridMergeSortingTime(array);
}

long long SortTester::runHybridMergeAlmostSortedTests(int n) {
    auto array = _generator->generateAlmostSortedArray(n);
    return averageHybridMergeSortingTime(array);
}