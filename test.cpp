#include <fstream>
#include "SortTester/SortTester.h"

#define MIN_SIZE 500
#define MAX_SIZE 100000
#define STEP 100

using namespace std;

int main() {
    SortTester tester;

    ofstream out("tests.csv");

    // Writing header
    out << "size,"
        << "merge_random,hybrid_random,"
        << "merge_reverse,hybrid_reverse,"
        << "merge_almost,hybrid_almost\n";

    for (int size = MIN_SIZE; size <= MAX_SIZE; size += STEP) {

        // Initializing tests
        const long long mr = tester.runMergeRegularTests(size);
        const long long hr = tester.runHybridMergeRegularTests(size);

        const long long mrev = tester.runMergeSortedBackwardsTests(size);
        const long long hrev = tester.runHybridMergeSortedBackwardsTests(size);

        const long long mal = tester.runMergeAlmostSortedTests(size);
        const long long hal = tester.runHybridMergeAlmostSortedTests(size);

        // Writing row
        out << size << ","
            << mr << "," << hr << ","
            << mrev << "," << hrev << ","
            << mal << "," << hal << "\n";
    }
    out.close();
}
