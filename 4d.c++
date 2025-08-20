#include<iostream>
#include<string>
#include<algorithm> // For sort function
using namespace std;

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading n
      
    string arr[100];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, arr[i]);   
    }
    
    sort(arr, arr + n); // Sort the array of strings
    cout << "Sorted strings: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}