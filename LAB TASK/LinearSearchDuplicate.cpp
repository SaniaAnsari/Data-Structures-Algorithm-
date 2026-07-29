#include<iostream>
using namespace std;
int main(){
    int arr[10]={23,33,33,56,67,77,83,88,99,65};
    int target;
    bool flag =false;
    int count=0;
    cout<<"enter a target: ";
    cin>> target;
    for(int i=0;i<10;i++){
        if(target==arr[i]){
            flag=true;
            cout<<"Element found at index: "<< i <<endl;
             count++;
        }
        
    }if(flag==false){
        cout<< "Not found";
    }
    cout<<"Count: "<<count;

    return 0;
}