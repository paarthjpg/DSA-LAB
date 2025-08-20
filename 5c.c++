#include <iostream>
using namespace std;

class LowerTriangular {
    int a[6]; 
public:
    void set(int i,int j,int x){ if(i>=j) a[i*(i+1)/2+j]=x; }
    int get(int i,int j){ return (i>=j)?a[i*(i+1)/2+j]:0; }

    void display(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

int main(){
    LowerTriangular l;
    l.set(0,0,1);
    l.set(1,0,2); l.set(1,1,3);
    l.set(2,0,4); l.set(2,1,5); l.set(2,2,6);
    l.display();
}