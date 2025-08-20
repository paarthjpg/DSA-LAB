#include <iostream>
using namespace std;

int main() {
    
    int A[4][3] = { {3,3,3}, {0,0,5}, {1,1,8}, {2,2,3} };
    int B[4][3] = { {3,3,3}, {0,0,4}, {1,2,6}, {2,2,7} };
    int C[10][3];

    if(A[0][0]!=B[0][0] || A[0][1]!=B[0][1]) {
        cout << "Dimension mismatch!";
        return 0;
    }

    C[0][0]=A[0][0]; C[0][1]=A[0][1];
    int i=1,j=1,k=1;

    while(i<=A[0][2] && j<=B[0][2]) {
        if(A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1]))
            C[k][0]=A[i][0], C[k][1]=A[i][1], C[k][2]=A[i][2], i++, k++;
        else if(B[j][0]<A[i][0] || (B[j][0]==A[i][0] && B[j][1]<A[i][1]))
            C[k][0]=B[j][0], C[k][1]=B[j][1], C[k][2]=B[j][2], j++, k++;
        else
            C[k][0]=A[i][0], C[k][1]=A[i][1], C[k][2]=A[i][2]+B[j][2], i++, j++, k++;
    }
    while(i<=A[0][2]) C[k][0]=A[i][0],C[k][1]=A[i][1],C[k][2]=A[i][2],i++,k++;
    while(j<=B[0][2]) C[k][0]=B[j][0],C[k][1]=B[j][1],C[k][2]=B[j][2],j++,k++;

    C[0][2]=k-1;

    cout<<"Addition result in triplet form:\n";
    for(int x=0;x<=C[0][2];x++)
        cout<<C[x][0]<<" "<<C[x][1]<<" "<<C[x][2]<<endl;
}