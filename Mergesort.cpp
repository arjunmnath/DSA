//
// Created by Arjun Manjunath on 15/03/24.
//

#include <iostream>
#include <vector>
using namespace  std;

class Mergesort {
private:
    vector<int> array;

    void merge(int const left, int const mid , int const right) {
        int subArray1 = mid - left +1;
        int subArray2 = right - mid;
        vector<int> leftArray = vector<int>(subArray1);
        vector<int> rightArray = vector<int>(subArray2);

        for ( int i=0; i< subArray1; i++) {
            leftArray[i] = array[left + i];
        }
        for (int i=0; i<subArray2; i++) {
            rightArray[i] = array[mid + i +1];
        }

        int idxOfSA1 = 0, idxOfSA2 = 0, idxOfMA = left;

        while (idxOfSA1 < subArray1
               && idxOfSA2 < subArray2) {
            if (leftArray[idxOfSA1]
                <= rightArray[idxOfSA2]) {
                array[idxOfMA]
                        = leftArray[idxOfSA1];
                idxOfSA1++;
            }
            else {
                array[idxOfMA]
                        = rightArray[idxOfSA2];
                idxOfSA2++;
            }
            idxOfMA++;
        }

        while (idxOfSA1 < subArray1) {
            array[idxOfMA]
                    = leftArray[idxOfSA1];
            idxOfSA1++;
            idxOfMA++;
        }
        while (idxOfSA2< subArray2) {
            array[idxOfMA]
                    = rightArray[idxOfSA2];
            idxOfSA2++;
            idxOfMA++;
        }


    }
    void _sortHelper(int start, int end) {
       if (start >= end)
           return;

        int mid = start + (end-start)/2;
       _sortHelper(start, mid);
       _sortHelper(mid+1, end);
       merge(start, mid, end);
    }
public:
    Mergesort(int * arr, int n) {
        array = vector<int>(arr, arr+n);
    }
    void sort() {
        _sortHelper(0, array.size() - 1);
    };
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
    Mergesort m = Mergesort(array, n);
    m.display();
    m.sort();
    m.display();
    return 0;
}