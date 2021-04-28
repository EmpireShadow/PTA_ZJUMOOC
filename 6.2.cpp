#include <iostream>
using namespace std;

int flag=0;

void getout(int x,int y);
int distance(int i,int j,int m,int n);
void DFS(int (*crocodile)[3],int i,int n,int d);

int main(){
    //初始化，录入
    int n,d;
    cin>>n>>d;
    int crocodile[n][3];
    for(int i=0;i<n;i++){
        cin>>crocodile[i][0]>>crocodile[i][1];
        crocodile[i][2]=0;
    }
    //开始深度遍历
    for(int i=0;i<n;i++){
        int x=crocodile[i][0];
        int y=crocodile[i][1];
        if(crocodile[i][2]==0&&distance(x,y,0,0)<=(7.5+d)*(7.5+d))
                DFS(crocodile,i,n,d);
    }
    if(flag==1) cout<<"Yes";
    else cout<<"No";
}

int distance(int i,int j,int m,int n){
    return (i-m)*(i-m)+(j-n)*(j-n);
}

void getout(int x,int y,int d){
    if(x<0) x=-x;
    if(y<0) y=-y;
    if((x+d>=50)||(y+d)>=50) flag=1;
}

void DFS(int (*crocodile)[3],int i,int n,int d){
    crocodile[i][2]=1;
    int x=crocodile[i][0];
    int y=crocodile[i][1];
    getout(x,y,d);
    for(int m=0;m<n;m++){
        int q=crocodile[m][0];
        int p=crocodile[m][1];
        if(distance(x,y,q,p)<=d*d&&crocodile[m][2]==0)
            DFS(crocodile,m,n,d);
    }
}
