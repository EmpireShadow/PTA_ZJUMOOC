#include <iostream>
using namespace std;

int bucket[51];
int n;

int main(){
    int temp,flag=1;
    for(int i=0;i<51;i++)
        bucket[i]=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        bucket[temp]++;
    }
    for(int i=0;i<51;i++)
        if(bucket[i]!=0&&flag==1){
            cout<<i<<":"<<bucket[i];
            flag=0;
        }
        else if(bucket[i]!=0)
            cout<<endl<<i<<":"<<bucket[i];
    return 0;
}
