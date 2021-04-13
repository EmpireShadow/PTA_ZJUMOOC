//第一版 勉强运行通过了！！
#include <iostream>
#include <cstring>
using namespace std;

bool judge(char tree1[],char tree2[],int landr1[][3],int landr2[][3],int root1,int root2);

int main(){
    int x,y,root1,root2,n;
    cin>>x;
    char tree1[x];
    char tree2[x];
    int landr1[x][3];
    int landr2[x][3];
    int root[x]={0};
    char temp;
    if(x!=0){
    for(int i=0;i<x;i++){
        cin>>tree1[i]>>temp;
        temp=='-'?landr1[i][1]=-1:landr1[i][1]=temp-48;
        if(landr1[i][1]!=-1){n=landr1[i][1]; root[n]=-1;}
        cin>>temp;
        temp=='-'?landr1[i][2]=-1:landr1[i][2]=temp-48;
        if(landr1[i][2]!=-1){n=landr1[i][2]; root[n]=-1;}
    }
    for(int i=0;i<x;i++){
        if(root[i]!=-1) root1=i;
        root[i]=0;
    }
    }
    cin>>y;
    bool flag=true;
    if(y!=x) flag=false;
    else if(x==0&&y!=0||x!=0&&y==0) flag=false;
    else if(x==0&&y==0) flag=true;
    else{
        for(int i=0;i<x;i++){
            cin>>tree2[i]>>temp;
            temp=='-'?landr2[i][1]=-1:landr2[i][1]=temp-48;
            if(landr2[i][1]!=-1){n=landr2[i][1]; root[n]=-1;}
            cin>>temp;
            temp=='-'?landr2[i][2]=-1:landr2[i][2]=temp-48;
            if(landr2[i][2]!=-1){n=landr2[i][2]; root[n]=-1;}
        }
        for(int i=0;i<x;i++){
            if(root[i]!=-1) root2=i;
        }
        //初始化完成
        
        //检测开始
        flag=judge(tree1,tree2,landr1,landr2,root1,root2);
    }
    if(flag==false) cout<<"No";
    else cout<<"Yes";
    return 0;
}

bool judge(char tree1[],char tree2[],int landr1[][3],int landr2[][3],int root1,int root2){
    if(root1==root2&&root1==-1) return true;
    else if(root1==-1||root2==-1) return false;
    else if(tree1[root1]!=tree2[root2]) return false;
    else{
        int i=landr1[root1][1];
        int j=landr1[root1][2];
        int k=landr2[root2][1];
        int l=landr2[root2][2];
        return (judge(tree1,tree2,landr1,landr2,i,k)&&judge(tree1,tree2,landr1,landr2,j,l))||(judge(tree1,tree2,landr1,landr2,j,k)&&judge(tree1,tree2,landr1,landr2,i,l));
    }
}
