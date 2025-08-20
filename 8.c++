#include<iostream>
using namespace std;
int countDistinct(int arr[], int n){
    int count =0;
     for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

      
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            count++;
        }
    }

    return count;
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Total distinct elements: " << countDistinct(arr, n) << endl;

    return 0;
}