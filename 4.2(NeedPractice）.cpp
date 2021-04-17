// cout<<a sad day..........
//sad
//sad

#include <iostream>
using namespace std;


typedef struct AVLNode{
    int data;
    AVLNode *left,*right;
    int height;
}AVLNode,*AVLTree;

int GetHeight(AVLTree T);
AVLTree SingleLeftRotation ( AVLTree A );
AVLTree DoubleLeftRightRotation ( AVLTree A );
AVLTree SingleRightRotation ( AVLTree A );
AVLTree DoubleRightLeftRotation ( AVLTree A );
AVLTree Insert( AVLTree T, int X );
int Max(int i1,int i2);

int main(){
    int n;
    cin>>n;
    AVLTree a=NULL;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        a=Insert(a,temp);
    }
    if(a)
        cout<<a->data<<endl;
    else cout<<"loser";
}

AVLTree LL(AVLTree A){
    AVLTree B=A->left;
    A->left=B->right;
    B->right=A;
    A->height=Max(GetHeight(A->left),GetHeight(A->right))+1;
    B->height=Max(GetHeight(B->left),GetHeight(B->right))+1;
    return B;
}

AVLTree RR(AVLTree A){
    AVLTree B=A->right;
    A->right=B->left;
    B->left=A;
    A->height=Max(GetHeight(A->left),GetHeight(A->right))+1;
    B->height=Max(GetHeight(B->left),GetHeight(B->right))+1;
    return B;
}

AVLTree RL(AVLTree A){
    A->right=LL(A->right);
    return RR(A);
}

AVLTree LR(AVLTree A){
    A->left=RR(A->left);
    return LL(A);
}

AVLTree Insert(AVLTree A,int x){
    if(!A){
        A=(AVLTree)malloc(sizeof(AVLNode));
        A->data=x;
        A->left=NULL;
        A->right=NULL;
        A->height=0;
    }
    else{
        if(A->data>x){
            A->left=Insert(A->left,x);
            if(GetHeight(A->left)-GetHeight(A->right)==2){
                if(x>A->left->data) A=LR(A);
                else if(x<A->left->data) A=LL(A);
            }
        }
        else if(A->data<x){
            A->right=Insert(A->right,x);
            if(GetHeight(A->right)-GetHeight(A->left)==2){
                if(x<A->right->data) A=RL(A);
                else if(x>A->right->data) A=RR(A);
            }
        }
    }
    A->height=Max(GetHeight(A->left),GetHeight(A->right))+1;
    return A;
}

int Max(int i1,int i2){
    return i1>i2?i1:i2;
}

int GetHeight(AVLTree T){
    if(!T) return -1;
    return T->height;
}
