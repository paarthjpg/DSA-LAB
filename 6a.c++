#include <iostream>
using namespace std;

int main() {
   
    int A[4][3] = { {3,3,3}, {0,2,5}, {1,1,8}, {2,2,3} };
    int B[4][3]; 

    B[0][0] = A[0][1]; 
    B[0][1] = A[0][0]; 
    B[0][2] = A[0][2]; 

    int k = 1;
    for(int col=0; col<A[0][1]; col++) {
        for(int i=1; i<=A[0][2]; i++) {
            if(A[i][1] == col) {
                B[k][0] = A[i][1];
                B[k][1] = A[i][0];
                B[k][2] = A[i][2];
                k++;
            }
        }
    }

    cout << "Transpose in triplet form:\n";
    for(int i=0; i<=B[0][2]; i++)
        cout << B[i][0] << " " << B[i][1] << " " << B[i][2] << endl;
}