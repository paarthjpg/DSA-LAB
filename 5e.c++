#include <iostream>
using namespace std;

class Symmetric {
    int a[6]; 
public:
    void set(int i,int j,int x){
        if(i>=j) a[i*(i+1)/2+j]=x;
        else a[j*(j+1)/2+i]=x;
    }
    int get(int i,int j){
        return (i>=j)?a[i*(i+1)/2+j] : a[j*(j+1)/2+i];
    }

    void display(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

int main(){
    Symmetric s;
    s.set(0,0,1); s.set(0,1,2); s.set(0,2,3);
    s.set(1,1,4); s.set(1,2,5);
    s.set(2,2,6);
    s.display();
}