#include<iostream>
#include "linkedList.cpp"
using namespace std;

int main(){
    List list;
    list.add(5);
    list.add(13);
    list.add(4);
    list.add(8);
    list.add(24);
    list.add(48);
    list.add(12);
    list.start();
    while(list.next()){
        cout<<"List Element: " << list.get() << endl;
    }
}