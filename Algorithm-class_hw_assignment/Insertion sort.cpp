#include <bits/stdc++.h>

using namespace std;

void printArray(int A[], int length);
void generateArray(int A[], int length);
void insertionSort(int A[], int length);

int main() {

    int n = 10000;
    int array[n];

    // generating array
    generateArray(array,n);

    cout << "Before sorting: ";
    printArray(array, n);

    // insertion sort
   
    cout<< "Insertion Sort:\n";
    clock_t start = clock();
    insertionSort(array, n);
    clock_t stop = clock();

    long long clockdif = stop-start;
    double timeTaken = (double)clockdif / CLOCKS_PER_SEC;
    cout<<(fixed)<<setprecision(8)<<"Time taken = "<< timeTaken <<endl<<endl;

    cout << "After sorting:  ";
    printArray(array, n);

    return 0;
}

void printArray(int A[], int length) {
    for (int i = 0; i < length; i++) {
        if (i != 0)
            cout << ", ";
        cout << A[i];
    }
    cout << endl;
}

void generateArray(int A[], int length) {
    for(int i=0; i<length; i++)
        A[i]=rand();
}

void insertionSort(int A[], int length) {
    for (int j = 1; j < length; j++) {
        int key = A[j];
        int i = j - 1;
        while (i > -1 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}
