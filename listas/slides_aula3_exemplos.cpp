#include <iostream>
using namespace std;

struct Node2 {
    int id;
    Node2(){
    id=0;
    }
    
    void setNode2(int i){
    id = i;
    }
 
    int getNode2(){
    return id;
    }
};

/*
main(){
    struct Node2 y1;
    struct Node2 y2;
    y1.setNode2(3);
    y2 = y1;
    y2.setNode2(4);
    cout<<"(VALUE)y1.getNode2():"<<y1.getNode2()<<endl;
    cout<<"(VALUE)y2.getNode2():"<<y2.getNode2()<<endl;
    cout<<"---------------"<<endl;
};
*/

int main(){
    struct Node2 *x=new Node2();
    struct Node2 *x2=new Node2();
    x2 = x;
    cout<<"x2->getNode2():"<<x2->getNode2()<<endl;
    x2->setNode2(4);  
    cout<<"x2->getNode2():"<<x2->getNode2()<<endl;
    cout<<"x->getNode2():"<<x->getNode2()<<endl;
    cout<<"---------------"<<endl;
}