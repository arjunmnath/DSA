//
// Created by Arjun Manjunath on 15/03/24.
//
#include <iostream>
#include <vector>
using namespace  std;

class Quicksort {
private:
    vector<int> array;
    void swap(int i, int j ) {
        int a = array[i];
        array[i] = array[j];
        array[j] = a;
    }
    int partition(int start, int end) {
       int pivot = array[end];
       int i = start - 1;
       for (int j=start; j<=end;j++) {
           if (array[j] < pivot) {
              i++;
              swap(i,j);
           }
       }
       swap(i+1, end);
       return i+1;
    }
    void _sortHelper(int start, int end) {
        if (start < end) {
            int p = partition(start, end);
            _sortHelper(start, p - 1);
            _sortHelper(p + 1, end);
        }
    }
public:
   Quicksort(int *arr, int n) {
        array = vector<int>(arr, arr + n);
   }

    void sort() {
        _sortHelper(0, array.size() - 1 );
    }
   void display() {
        for (auto i : array) {
            cout<< i << " ";
        }
        cout << endl;
    }
};


int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    Quicksort q = Quicksort(array, n);
    q.sort();
    q.display();
    return 0;
}