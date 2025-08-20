#include<iostream>
#include<string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    str1 += str2; // Concatenate str2 to str1
    cout << "Concatenated string: " << str1 << endl;
    return 0;
}