#include <iostream>
using namespace std;
#define maxsize 101

int N,M;
int vertix[maxsize][maxsize];
int vertix2[maxsize][maxsize];

void Floyd();

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
    //Floyd算法
    Floyd();
    return 0;
}

void Floyd(){
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(vertix[i][j]>vertix[i][k]+vertix[k][j]&&j!=i&&k!=i)
                    vertix[i][j]=vertix[i][k]+vertix[k][j];
    int animal;
    int fv=maxsize;
    for(int i=1;i<=N;i++){
        int max=0;
        for(int j=1;j<=N;j++){
            if(vertix[i][j]>max&&i!=j)
                max=vertix[i][j];
        }
        if(max<fv){
            fv=max;
            animal=i;
        }
        if(fv==maxsize) {cout<<"0"<<endl; return;}
    }
    cout<<animal<<" "<<fv<<endl;
}

