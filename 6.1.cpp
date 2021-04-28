//邻接矩阵表示
#include <iostream>
using namespace std;
#define maxedge 11
#include <queue>

int visited[maxedge];
typedef struct graphmatrix{
    int vertexnum,edgenum;
    int matrix[maxedge][maxedge];
}graphmatrix;

void DFSgraph(graphmatrix g);
void BFSgraph(graphmatrix g);
void DFS(graphmatrix g,int i);
void BFS(graphmatrix g,int i);

int main(){
    //构建邻接矩阵
    graphmatrix g;
    cin>>g.vertexnum>>g.edgenum;
    for(int i=0;i<g.vertexnum;i++)
        for(int j=0;j<g.vertexnum;j++)
            g.matrix[i][j]=0;
    for(int i=0;i<g.edgenum;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        g.matrix[temp1][temp2]=1;
        g.matrix[temp2][temp1]=1;
    }
    DFSgraph(g);
    BFSgraph(g);
    return 0;
}

void DFSgraph(graphmatrix g){
    for(int i=0;i<g.vertexnum;i++)
        visited[i]=0;
    for(int i=0;i<g.vertexnum;i++){
        if(visited[i]!=1)
            {cout<<"{ ";
            DFS(g,i);
            cout<<"}\n";}
    }
}

void DFS(graphmatrix g,int i){
    cout<<i<<" ";
    visited[i]=1;
    for(int j=0;j<g.vertexnum;j++){
        if(visited[j]==0&&g.matrix[i][j]==1){
            DFS(g,j);
        }
    }
}

void BFSgraph(graphmatrix g){
    for(int i=0;i<g.vertexnum;i++)
        visited[i]=0;
    for(int i=0;i<g.vertexnum;i++){
        if(visited[i]!=1)
            {cout<<"{ ";
            BFS(g,i);
            cout<<"}\n";}
    }
}

void BFS(graphmatrix g,int i){
    cout<<i<<" ";
    visited[i]=1;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        if(visited[s]==0){
            cout<<s<<" ";
            visited[s]=1;
        }
        for(int j=0;j<g.vertexnum;j++){
            if(visited[j]==0&&g.matrix[s][j]==1){
                q.push(j);
            }
        }
    }
}
