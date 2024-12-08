#include <iostream>
using namespace std;
int main()
{
    int arr[6];
    for(int i=0;i<6;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<6;i++){
        int minIndex=i;
        for(int j=i+1;j<6;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
        
    }
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}