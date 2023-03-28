// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <vector>
#include <random>

using namespace std::chrono;

using namespace std;


int partition(vector<int> arr, int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(vector<int> arr, int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}
void swap_address(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort_NonRecursive(vector<int> arr, int low, int high) {
    stack<int> stk;
    stk.push(low);
    stk.push(high);

    while (!stk.empty()) {
        int h = stk.top();
        stk.pop();
        int l = stk.top();
        stk.pop();

        int pivot = arr[h];
        int i = l - 1;
        for (int j = l; j < h; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap_address(&arr[i], &arr[j]);
            }
        }
        swap_address(&arr[i+1], &arr[h]);
        int p = i + 1;

        if (p - 1 > l) {
            stk.push(l);
            stk.push(p - 1);
        }
        if (p + 1 < h) {
            stk.push(p + 1);
            stk.push(h);
        }
    }
}

int main() {
    const int n = 500;
    cout << "array size: " << n << endl;
    vector<int> arr1(n);
    vector<int> arr2(n);
    
    // seed the random number generator
    random_device rd;
    mt19937 gen(rd());    
    // generate random numbers between 1 and 100 and fill the vector
    uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < n; i++) {
        arr1[i] = dist(gen);
        arr2[i] = dist(gen);
    }
    
    auto start = high_resolution_clock::now();
    quickSort(arr1, 0, n - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds with recursive method" << endl;
    
    
    auto start1 = high_resolution_clock::now();
    quickSort_NonRecursive(arr2, 0, n - 1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<chrono::microseconds>(end1 - start1);
    cout << "Time taken: " << duration1.count() << " microseconds with non - recursive method" << endl;
    
    return 0;
}
