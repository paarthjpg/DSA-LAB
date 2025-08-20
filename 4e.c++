#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; // ASCII conversion
        cout << "Lowercase character: " << ch << endl;
    } else {
        cout << "Not an uppercase character!" << endl;
    }
    return 0;
}
