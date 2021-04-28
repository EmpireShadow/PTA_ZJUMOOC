#include <iostream>
#include <queue>
using namespace std;
#define maxsize 1000

typedef struct edge{
    int data;
    edge* next;
}edge;

typedef struct vertix{
    edge* firstedge;
}vertix;

typedef struct graph{
    int vertexnum,edgenum;
    vertix vertixs[maxsize] ;
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
    int level[7]={0,0,0,0,0,0,0};
    level[0]=1;
    queue<int> q;
    q.push(start);
    for(int len=1;len<=6&&!q.empty();len++){
        for(int i=0;i<level[len-1];i++){
            int s=q.front();
            q.pop();
            for(edge* m=g.vertixs[s].firstedge;m!=NULL;m=m->next){
                if(visited[m->data]==0){
                    visited[m->data]=1;
                    visitnum++;
                    level[len]++;
                    q.push(m->data);
                }
            }
        }
    }
    float percent=100*visitnum/g.vertexnum;
    printf("%d: %.2f\%\n",start+1,percent);
}
