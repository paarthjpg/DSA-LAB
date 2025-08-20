#include<iostream>
using namespace std;
int linearsearch(int arr[], int n){
    for(int i=0 ;i< n-1; i++){
        if(arr[i] != i+1){
            return i+1;
        }
    }
    return n;
}
int main() {
    int arr[6] = {1,2,3,4,5,7};
    int result = linearsearch(arr, 6);
    cout << "The missing number is " << result;
    return 0;
}