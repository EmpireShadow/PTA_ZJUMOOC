#include <iostream>
using namespace std;
#define maxsize 501

int N,M,S,D;
int road[maxsize][maxsize];
int fee[maxsize][maxsize];
int s[maxsize];
int d[maxsize];
int f[maxsize];

void Dijkstra(int v0);

int main(){
    cin>>N>>M>>S>>D;
    int x,y;
    for(int i=0;i<N;i++){
        s[i]=0;
        for(int j=0;j<N;j++){
            road[i][j]=maxsize;
            fee[i][j]=maxsize;
        }
    }
    for(int i=0;i<M;i++){
        cin>>x>>y;
        cin>>road[x][y]>>fee[x][y];
        road[y][x]=road[x][y];
        fee[y][x]=fee[x][y];
    }
    Dijkstra(S);
    cout<<d[D]<<" "<<f[D];
    return 0;
}

void Dijkstra(int v0){
    for(int i=0;i<N;i++){
        d[i]=road[v0][i];
        f[i]=fee[v0][i];
    }
    d[v0]=0;
    f[v0]=0;
    s[v0]=1;
    for(int i=1;i<N;i++){
        int min=maxsize;
        int v;
        for(int w=0;w<N;w++){
            if(road[v0][w]<min&&s[w]!=1){
                min=road[v0][w];
                v=w;
            }
        }
        s[v]=1;
        for(int w=0;w<N;w++){
            if(s[w]!=1&&road[v][w]<maxsize){
                if(road[v][w]+d[v]<d[w]){
                    d[w]=road[v][w]+d[v];
                    f[w]=f[v]+fee[v][w];
                }
                if(road[v][w]+d[v]==d[w]&&f[w]>f[v]+fee[v][w]){
                    f[w]=f[v]+fee[v][w];
                }
            }
        }
    }
}
