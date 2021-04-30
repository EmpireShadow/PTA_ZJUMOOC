#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int dist(int x,int y,int i,int j);
void Dijkstras(int v0);
bool getout(int x,int y);
bool closetoisland(int x,int y);
int firstJump(int v);
bool cmp(int x,int y);

int crocodiles[100][2];
int N,jump;
int D[100];
int path[100];
queue<int> q;
int canjump[100];

int start=-1;
int finally=-1;
int countss=100;

int main(){
    cin>>N>>jump;
    for(int i=0;i<N;i++)
        cin>>crocodiles[i][0]>>crocodiles[i][1];
    if(jump+7.5>=50){cout<<"1"; return 0;}
    for (int i = 0; i < N; i++) 
        canjump[i] = i;
    sort(canjump, canjump + N, cmp);
    for(int i=0;i<N;i++){
        if(firstJump(canjump[i])!=0)
            Dijkstras(canjump[i]);
    }
    if(start==-1) cout<<"0";
    else{
        cout<<countss<<endl;
        Dijkstras(start);
        stack<int> s;
        int temp=finally;
        s.push(finally);
        while(path[temp]!=-1){
            s.push(path[temp]);
            temp=path[temp];
        }
        for(int i=0;i<countss-1;i++){
            int m=s.top();
            s.pop();
            cout<<crocodiles[m][0]<<" "<<crocodiles[m][1]<<endl;
        }
    }
    return 0;
}

void Dijkstras(int v0){
    for(int i=0;i<N;i++){
        D[i]=-1;
        path[i]=-1;
    }
    D[v0]=1;
    q.push(v0);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(int i=0;i<N;i++){
            if(D[i]==-1&&dist(crocodiles[i][0],crocodiles[i][1],crocodiles[s][0],crocodiles[s][1])<=jump*jump){
                D[i]=D[s]+1;
                path[i]=s;
                if(getout(crocodiles[i][0],crocodiles[i][1])&&D[i]+1<countss)
                    {countss=D[i]+1;
                    start=v0;
                    finally=i;}
                q.push(i);
            }
        }
    }
}

int dist(int x,int y,int i,int j){
    return (x-i)*(x-i)+(y-j)*(y-j);
}

bool getout(int x,int y){
    if(x<0) x=-x;
    if(y<0) y=-y;
    if(x+jump>=50||y+jump>=50) return true;
    else return false;
}

bool closetoisland(int x,int y){
    if(dist(x,y,0,0)<=(7.5+jump)*(7.5+jump))
        return true;
    else return false;
}

int firstJump(int v){
    int d=dist(crocodiles[v][0],crocodiles[v][1],0,0);
    int r = (jump+7.5)*(jump+7.5);
    if(r >= d) return d;
    else return 0;
}

bool cmp(int x,int y){
    return firstJump(x) < firstJump(y);
}
