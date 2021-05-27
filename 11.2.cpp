#include <iostream>
using namespace std;

int nextPrime(int n);

int main(){
    int n,m,temp;
    cin>>n>>m;
    n=nextPrime(n);
    int matrix[n];
    for(int i=0;i<n;i++)
        matrix[i]=-1;
    for(int i=0;i<m;i++){
        if(i!=0) cout<<" ";
        cin>>temp;
        int t=temp%n;
        if(matrix[t]==-1){
            cout<<t;
            matrix[t]=temp;
        }
        else{
            int flag=-1;
            for(int j=1;j<=n;j++){
                int s=(t+j*j)%n;
                if(matrix[s]==-1)
                    {flag=1;matrix[s]=temp;cout<<s;break;}
            }
            if(flag==-1) cout<<"-";
        }
    }
}

int nextPrime(int n){
    if(n==1) return 2;
    int flag;
    n=(n%2==0)?n+1:n+2;
    for(;flag!=1;n+=2){
        flag=1;
        for(int i=3;i*i<=n;i+=2)
            if(n%i==0){
                flag=0;
                break;
            }
    }
    return n-2;
}
