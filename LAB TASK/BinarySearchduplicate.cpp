#include<iostream>
using namespace std;
int main(){
    int arr[10]={23,36,45,45,56,67,86,88,88,90};
    int target;
    bool flag=false;
    int l=0;
    int r=9;
    int mid;
    int count=0;
    cout<<"Enter a target:  ";
    cin>>target;
    while(l<=r){
    mid=(l+r)/2;
    if(target==arr[mid]){
        flag=true;
        int i=mid;
        while(i>=0 && arr[i]==target){
        cout<<"Element found at index: "<< i <<endl;
        count++;
        i--;
        }
        i=mid+1;
        while(i<=10 && arr[i]==target){
            cout<<"Element found at index: "<< i <<endl;
            count++;
            i++;
        }
        break;
      }
      if(target>arr[mid]){
        l=mid+1;
      }else{
        r=mid-1;   
      }  
    }
    if(flag==false){
        cout<<"Not found";
    }
   cout<<"Count: "<<count;
      return 0;
}
    