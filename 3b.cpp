#include<iostream>
using namespace std;
int binarysearch(int arr[], int n)
    {
       int start =0 , end = n-2;
         while(start <= end) {
              int mid = start + (end - start) / 2;
              if(arr[mid] == mid +1) {
                start = mid+ 1; 
              
              } else {
                end = mid - 1; 
              }
         }
         return start + 1;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarysearch(arr, n);
    cout<< "The missing number is : " << result << endl;
   
    return 0;
}