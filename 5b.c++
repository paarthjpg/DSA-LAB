#include <iostream>
using namespace std;

class TriDiagonal {
    int a[7]; // 3n - 2 = 7
public:
    void set(int i,int j,int x){
        if(i-j==1) a[i-1]=x;
        else if(i==j) a[2+i]=x;
        else if(j-i==1) a[5+i]=x;
    }

    int get(int i,int j){
        if(i-j==1) return a[i-1];
        else if(i==j) return a[2+i];
        else if(j-i==1) return a[5+i];
        else return 0;
    }

    void display(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

int main(){
    TriDiagonal t;
    t.set(0,0,1); t.set(1,1,5); t.set(2,2,9);
    t.set(0,1,2); t.set(1,2,6);
    t.set(1,0,3); t.set(2,1,7);
    t.display();
}