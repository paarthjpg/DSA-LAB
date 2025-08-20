#include <iostream>
using namespace std;

class Diagonal {
    int a[3]; // only 3 diagonal elements
public:
    void set(int i,int j,int x){ if(i==j) a[i]=x; }
    int get(int i,int j){ return (i==j)?a[i]:0; }

    void display(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

int main(){
    Diagonal d;
    d.set(0,0,1); d.set(1,1,5); d.set(2,2,9);
    d.display();
}