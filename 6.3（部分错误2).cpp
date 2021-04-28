#include <iostream>
#include <queue>
using namespace std;
#define maxsize 1005

typedef struct edge{
    int data;
    edge* next;
}edge;

typedef struct vertix{
    edge* firstedge;
}vertix;

typedef struct graph{
    int vertexnum,edgenum;
    vertix vertixs[maxsize];
}graph;

void SixDegree_BFS(graph g,int start);

int main(){
    //初始化
    graph g;
    cin>>g.vertexnum>>g.edgenum;
    for(int i=0;i<g.vertexnum;i++)
        g.vertixs[i].firstedge=NULL;
    for(int i=0;i<g.edgenum;i++){
        int x,y;
        cin>>x>>y;
        edge* s=(edge*)malloc(sizeof(edge));
        s->data=y-1;
        s->next=g.vertixs[x-1].firstedge;
        g.vertixs[x-1].firstedge=s;;
        edge* t=(edge*)malloc(sizeof(edge));
        t->data=x-1;
        t->next=g.vertixs[y-1].firstedge;
        g.vertixs[y-1].firstedge=t;
    }
    //开始计算
    for(int i=0;i<g.vertexnum;i++){
        SixDegree_BFS(g,i);
    }
    return 0;
}

void SixDegree_BFS(graph g,int start){
    //初始化
    int visitnum=1;
    int visited[g.vertexnum];
    for(int i=0;i<g.vertexnum;i++)
        visited[i]=0;
    visited[start]=1;
    int level=0;
    int tail=start;
    int last=start;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        edge* m=g.vertixs[s].firstedge;
        while(m){
            if(visited[m->data]==0){
                visited[m->data]=1;
                visitnum++;
                tail=m->data;
                q.push(m->data);
            }
            m=m->next;
        }
        if(s==last){
            level++;
            last=tail;
        }
        if(level==6) break;
    }
    float percent=100*visitnum/g.vertexnum;
    printf("%d: %.2f\%\n",start+1,percent);
}
