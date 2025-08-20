#include<iostream>
using namespace std;
int binarysearch(int arr[], int size , int n){
    int start =0;
    int end = size -1;
        while(start <= end){
        int mid = start + (end - start) /2;
        if(arr[mid] == n){
            return mid;
        }
        else if(arr[mid] < n){  //go to the right side
            start = mid + 1;
        }
        else{ // go to the left side
            end = mid - 1;
        }
    }return -1; // Element not found
    
}
int main() {
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n;
    cout << "Enter the number to search: ";
    cin >> n;
    int result = binarysearch(arr, size, n);
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}