#include <iostream>
using namespace std;
#define maxsize 101

int S[maxsize];
int D[maxsize];
int path[maxsize];
int N,M;
int vertix[maxsize][maxsize];
int Max=maxsize;
int animal;
int flag;

void Dijkstra(int v0);

int main(){
    int x,y;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            vertix[i][j]=maxsize;
    for(int i=0;i<M;i++){
        cin>>x>>y;
        cin>>vertix[x][y];
        vertix[y][x]=vertix[x][y];
    }
    //最短路径
    animal=0;
    for(int v0=1;v0<=N;v0++){
        Dijkstra(v0);
    }
    if(animal==0) cout<<"0";
    else cout<<animal<<" "<<Max;
    return 0;
}

void Dijkstra(int v0){
    for(int i=1;i<=N;i++){
        S[i]=0;
        D[i]=vertix[v0][i];
        if(D[i]==maxsize) path[i]=-1;
        else path[i]=v0;
    }
    flag=1;
    int w=0;
    S[v0]=1;
    D[v0]=0;
    for(int q=1;q<N;q++){
        int min=maxsize;
        for(int i=1;i<=N;i++){
            if(S[i]==0&&D[i]<min){
                min=D[i];
                w=i;
            }
        }
        S[w]=1;
        for(int i=1;i<=N;i++){
            if(S[i]==0&&D[w]+vertix[w][i]<D[i]){
                D[i]=D[w]+vertix[w][i];
                path[i]=w;
            }
        }
    }
    int max=0;
    for(int i=1;i<=N;i++){
        if(D[i]==maxsize)
            flag=0;
        if(D[i]>max)
            max=D[i];
    }
    if(flag!=0&&max<Max) {animal=v0; Max=max;}
}
