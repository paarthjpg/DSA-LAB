#include<iostream>
using namespace std;
 
int countInversion(int arr[], int n){
    int count =0;
    for( int i=0 ; i< n-1; i++){
        for (int j = i; j < n; j++)
        {
            if(arr[i] > arr[j]){
                count++;
            }
        }
        
    }
    return count;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
    cin >> arr[i];
}

    cout << "Number of inversions: " << countInversion(arr, n) << endl;
    return 0;
}