//利用拓扑排序
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int list[n];
    int indegree[n];
    int matrix[n][n];
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>list[i];
        if(list[i]>=0) {cnt++;indegree[i]=0;}
        else indegree[i]=-1;
        for(int j=0;j<n;j++)
            matrix[i][j]=0;
    }
    for(int i=0;i<n;i++){
        if(list[i]<0) continue;
        int temp=list[i]%n;
        if(temp!=i)
            for(int j=temp;j!=i;j=(j+1)%n){
                matrix[j][i]=1;
                indegree[i]++;
            }
        else indegree[i]=0;
    }
    int q=0;
    for(int i=0;i<cnt;i++){
        if(i!=0) cout<<" ";
        int min=32767;
        for(int j=0;j<n;j++){
            if(indegree[j]==0&&min>list[j]){
                min=list[j];
                q=j;
            }
        }
        for(int j=0;j<n;j++){
            if(matrix[q][j]==1&&q!=j) 
                indegree[j]--;
        }
        indegree[q]=-1;
        cout<<min;
    }
}
