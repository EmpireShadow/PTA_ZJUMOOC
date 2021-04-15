#include <iostream>
using namespace std;
#define Maxsize 10
#define Null -1
#define Tree int
#define Elemtype char

struct TreeNode{
    Elemtype value;
    Tree left;
    Tree right;
}T1[Maxsize],T2[Maxsize];

Tree BuiltTree(struct TreeNode T[]);
bool fuc(int r1,int r2);

int main(){
    Tree r1,r2;
    r1=BuiltTree(T1);
    r2=BuiltTree(T2);
    if(fuc(r1,r2)) printf("Yes\n");
    else printf("No\n");
    return 0;
}

Tree BuiltTree(struct TreeNode T[]){
    int x;
    cin>>x;
    int root[x]={0};
    for(int i=0;i<x;i++){
        char temp;
        cin>>T[i].value>>temp;
        if(temp=='-') T[i].left=Null;
        else { T[i].left=temp-'0'; root[T[i].left]=-1;}
        cin>>temp;
        if(temp=='-') T[i].right=Null;
        else {T[i].right=temp-'0'; root[T[i].right]=-1;}
    }
    int r1;
    for(r1=0;r1<x;r1++){
        if(root[r1]!=-1) break;
    }
    if(x==0) r1=Null;
    return r1;
}

bool fuc(int r1,int r2){
    if(r1==r2&&r1==Null) return true;
    else if(((r1!=Null)&&(r2==Null))||((r1==Null)&&(r2!=Null))) return false;
    else if(T1[r1].value!=T2[r2].value) return false;
    else if(T1[r1].left==Null&&T2[r2].left==Null) return fuc(T1[r1].right,T2[r2].right);
    else if(T1[r1].left!=Null&&T2[r2].left!=Null&&T1[T1[r1].left].value==T2[T2[r2].left].value) return fuc(T1[r1].right,T2[r2].right)&&fuc(T1[r1].left,T2[r2].left);
    else return fuc(T1[r1].right,T2[r2].left)&&fuc(T1[r1].left,T2[r2].right);
}
