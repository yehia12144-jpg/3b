#include <iostream>

using namespace std;

class Sorter {
public:
    void mergeSort(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    void quickSort(int arr[], int low, int high, long long &comps) {
        if (low < high) {
            int pi = partition(arr, low, high, comps);
            quickSort(arr, low, pi - 1, comps);
            quickSort(arr, pi + 1, high, comps);
        }
    }

    void quickSortM3(int arr[], int low, int high, long long &comps) {
        if (low < high) {
            int pi = partitionM3(arr, low, high, comps);
            quickSortM3(arr, low, pi - 1, comps);
            quickSortM3(arr, pi + 1, high, comps);
        }
    }

    void quickSort(int arr[], int low, int high) {
        long long dummy = 0;
        quickSort(arr, low, high, dummy);
    }

    void quickSortM3(int arr[], int low, int high) {
        long long dummy = 0;
        quickSortM3(arr, low, high, dummy);
    }

private:
    void swapVal(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }

    void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        delete[] L;
        delete[] R;
    }

    int partition(int arr[], int low, int high, long long &comps) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            comps++;
            if (arr[j] <= pivot) {
                i++;
                swapVal(arr[i], arr[j]);
            }
        }
        swapVal(arr[i + 1], arr[high]);
        return i + 1;
    }

    int medianOfThree(int arr[], int low, int high) {
        int mid = low + (high - low) / 2;
        int a = arr[low], b = arr[mid], c = arr[high];
        int medianIdx = low;

        if ((a <= b && b <= c) || (c <= b && b <= a)) {
            medianIdx = mid;
        } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
            medianIdx = low;
        } else {
            medianIdx = high;
        }

        swapVal(arr[medianIdx], arr[high]);
        return high;
    }

    int partitionM3(int arr[], int low, int high, long long &comps) {
        medianOfThree(arr, low, high);
        return partition(arr, low, high, comps);
    }
};

int main() {
    Sorter s;
    int tmp[8];
    int a[] = {64, 25, 12, 22, 11, 90, 45, 34};
    int n = 8;

    for (int i = 0; i < n; i++) tmp[i] = a[i];
    s.mergeSort(tmp, 0, n - 1);
    cout << "MS: ";
    for (int i = 0; i < n; i++) cout << tmp[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++) tmp[i] = a[i];
    s.quickSort(tmp, 0, n - 1);
    cout << "QS: ";
    for (int i = 0; i < n; i++) cout << tmp[i] << " ";
    cout << endl;

    int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 0; i < n; i++) tmp[i] = sorted[i];
    s.quickSort(tmp, 0, n - 1);
    cout << "QS sorted: ";
    for (int i = 0; i < n; i++) cout << tmp[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++) tmp[i] = sorted[i];
    s.quickSortM3(tmp, 0, n - 1);
    cout << "QSM3 sorted: ";
    for (int i = 0; i < n; i++) cout << tmp[i] << " ";
    cout << endl;

    return 0;
}