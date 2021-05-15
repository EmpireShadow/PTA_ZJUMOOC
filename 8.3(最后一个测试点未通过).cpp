#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define maxint 32767
#define maxsize 110

int indegree[maxsize];
int outdegree[maxsize];
int arc[maxsize][maxsize];
int outlist[maxsize];
int m,n,number=0;
int ve[maxsize];
int vl[maxsize];


queue<int> q1,q2;
void initialize();
void criticalpath();
void topologicalorder();

int main(){
    //初始化
    initialize();
    //拓扑排序,同时计算ve
    topologicalorder();
    //判断是否可行，可行则开始计算关键路径
    if(number>=n)
        criticalpath();
    else cout<<"0";
    return 0;
}

void initialize(){
    int a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ve[i]=0;
        indegree[i]=0;
        outdegree[i]=0;
        for(int j=0;j<n;j++){
            arc[i][j]=maxint;
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        cin>>arc[a-1][b-1];
        indegree[b-1]++;
        outdegree[a-1]++;
    }
}

void topologicalorder(){
    stack<int> s;
    for(int i=0;i<n;i++)
        if(indegree[i]==0)
            s.push(i);
    while(!s.empty()){
        int t=s.top();
        outlist[number++]=t;
        s.pop();
        for(int j=0;j<n;j++){
            if(arc[t][j]!=maxint){
                indegree[j]--;
                if(indegree[j]==0)
                    s.push(j);
            }
        }
    }
    for(int i=0;i<n;i++){
        int l=outlist[i];
        for(int j=0;j<n;j++){
            if(arc[l][j]!=maxint&&arc[l][j]+ve[l]>ve[j])
                ve[j]=arc[l][j]+ve[l];
        }
    }
}

void criticalpath(){
    for(int i=0;i<n;i++)
        {vl[i]=ve[n-1]; }
    for(int i=n-1;i>=0;i--){
        int t=outlist[i];
        for(int j=0;j<n;j++){
            if(arc[t][j]!=maxint&&vl[j]-arc[t][j]<vl[t])
                vl[t]=vl[j]-arc[t][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(arc[i][j]!=maxint&&i!=j){
                int e=ve[i];
                int l=vl[j]-arc[i][j];
                if(e==l){
                    q1.push(i);
                    q2.push(j);
                }
            }
        }
    }
    
    //测试部分
    //for(int i=1;i<=n;i++){
    //    cout<<i<<" "<<ve[i-1]<<" "<<vl[i-1]<<endl;
    //}
    cout<<ve[n-1];
    while(!q1.empty()){
        int a=q1.front()+1;
        int b=q2.front()+1;
        q1.pop();
        q2.pop();
        cout<<endl<<a<<"->"<<b;
    }
}
