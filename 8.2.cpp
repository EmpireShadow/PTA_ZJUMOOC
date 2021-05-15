#include <iostream>
#include <stack>
using namespace std;
#define maxint 32767

int N,M;
int arc[100][100];
int indegree[100];
int cost[100];
int out[100];

int main(){
    int a,b;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cost[i]=0;
        indegree[i]=0;
        for(int j=0;j<N;j++){
            arc[i][j]=maxint;
        }
    }
    for(int i=0;i<M;i++){
        cin>>a>>b;
        cin>>arc[a][b];
        indegree[b]++;
    }
    stack<int> s;
    for(int i=0;i<N;i++)
        if(indegree[i]==0)
            s.push(i);
    int m=0;
    while(!s.empty()){
        out[m++]=s.top();
        int temp=s.top();
        s.pop();
        for(int j=0;j<N;j++){
            if(arc[temp][j]!=maxint){
                indegree[j]--;
                if(indegree[j]==0)
                    s.push(j);
                if(arc[temp][j]+cost[temp]>cost[j])
                    cost[j]=arc[temp][j]+cost[temp];
            }
        }
    }
    if(m<N) cout<<"Impossible";
    else{
        int max=0;
        for(int i=0;i<N;i++){
            if(cost[i]>max) max=cost[i];
        }
        cout<<max;
    }
    return 0;
}
