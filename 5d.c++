#include <iostream>
using namespace std;

class UpperTriangular {
    int a[6];
public:
    void set(int i,int j,int x){ if(i<=j) a[(i*3 - i*(i-1)/2) + (j-i)] = x; }
    int get(int i,int j){ return (i<=j)?a[(i*3 - i*(i-1)/2)+(j-i)]:0; }

    void display(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

int main(){
    UpperTriangular u;
    u.set(0,0,1); u.set(0,1,2); u.set(0,2,3);
    u.set(1,1,4); u.set(1,2,5);
    u.set(2,2,6);
    u.display();
}