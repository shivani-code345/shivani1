#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    cout << "Bubble Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
}
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;
    int swaps = 0;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
}
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        swaps++;
    }
    cout << "Selection Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    bubbleSort(arr);
    insertionSort(arr);
    selectionSort(arr);

    return 0;
}
