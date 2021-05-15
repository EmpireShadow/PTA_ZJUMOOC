#include <iostream>
#include <algorithm>
using namespace std;
#define maxsize 1000
typedef struct{
    int head;
    int tail;
    int value;
}edges,Edge[3000];
int vertex[1001];
Edge edge;
int N,M;

bool cmp(edges a,edges b);

int main(){
    cin>>N>>M;
    int values=0;
    int count=0;
    for(int i=0;i<M;i++){
        cin>>edge[i].head>>edge[i].tail>>edge[i].value;
    }
    sort(edge,edge+M,cmp);
    for(int i=1;i<N+1;i++){
        vertex[i]=i;
    }
    for(int i=0;i<M;i++){
        int a=edge[i].head;
        int b=edge[i].tail;
        int c=vertex[a];
        int d=vertex[b];
        if(c!=d){
            values+=edge[i].value;
            count++;
            for(int j=1;j<=N;j++)
                if(vertex[j]==d)
                    vertex[j]=c;
        }
    }
    if(count!=N-1) cout<<"-1";
    else cout<<values;
    return 0;
}

bool cmp(edges a,edges b){
    if(a.value!=b.value)
        return a.value<b.value;
    else if(a.head!=b.head)
        return a.head<b.head;
    else if(a.tail!=b.tail)
        return a.tail<b.tail;
}
