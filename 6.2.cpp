#include <iostream>
using namespace std;

int flag=0;
int visited[101][101];
int lake[101][101];

void getout(int x,int y);
int distance(int i,int j,int m,int n);
void DFS(int i,int j,int d);

int main(){
    //初始化，录入
    int n,d;
    cin>>n>>d;
    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++){
            visited[i][j]=0;
            lake[i][j]=0;
        }
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        lake[x+50][y+50]=1;
    }
    //开始深度遍历
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(lake[i][j]==1&&visited[i][j]==0&&distance(i,j,50,50)<=(7.5+d)*(7.5+d))
                DFS(i,j,d);
        }
    }
    if(flag==1) cout<<"Yes";
    else cout<<"No";
}

int distance(int i,int j,int m,int n){
    return (i-m)*(i-m)+(j-n)*(j-n);
}

void getout(int x,int y,int d){
    if(x>50) x=100-x;
    if(y>50) y=100-y;
    if((x-d<=0)||(y-d)<=0) flag=1;
}

void DFS(int i,int j,int d){
    visited[i][j]=1;
    getout(i,j,d);
    for(int m=0;m<101;m++){
        for(int n=0;n<101;n++){
            if(distance(i,j,m,n)<=distance(0,0,d,0)&&visited[m][n]==0&&lake[m][n]==1){
                DFS(m,n,d);
            }
        }
    }
}
