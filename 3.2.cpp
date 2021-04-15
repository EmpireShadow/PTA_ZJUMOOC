//树的层次遍历，找到叶子节点
//运用队列辅助完成
#include <iostream>
#include <queue>
using namespace std;
#define Null -1
#define Tree int
#define Maxsize 10

Tree get(struct TreeNode t[]);
void getleaves(int root);

struct TreeNode{
    Tree left;
    Tree right;
}T[Maxsize];

int main(){
    Tree root;
    root=get(T);
    getleaves(root);
    return 0;
}

Tree get(struct TreeNode t[]){
    int x;
    char temp;
    cin>>x;
    int root[x];
    for(int i=0;i<x;i++) root[i]=0;
    int r;
    if(x==0) r=-1;
    else{
        for(int i=0;i<x;i++){
            cin>>temp;
            if(temp=='-') t[i].left=-1;
            else{t[i].left=temp-'0'; root[temp-'0']=1;}
            cin>>temp;
            if(temp=='-') t[i].right=-1;
            else{t[i].right=temp-'0'; root[temp-'0']=1;}
        }
        if(r!=-1){
            for(r=0;r<x;r++){
                if(root[r]==0) break;
            }
        }
    }
    return r;
}

void getleaves(int root){
    queue<int> q;
    int flag=1;
    if(root==-1) ;
    else{
        q.push(root);
        while(!q.empty()){
            Tree s=q.front();
            q.pop();
            if(T[s].left==Null&&T[s].right==Null){
                if(flag==1){
                    flag=0;
                    cout<<s;
                }
                else cout<<" "<<s;
            } 
            else{
                if(T[s].left!=Null) q.push(T[s].left);
                if(T[s].right!=Null) q.push(T[s].right);
            }
        }
    }
}
