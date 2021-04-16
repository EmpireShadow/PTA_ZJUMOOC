#include <iostream>
using namespace std;

typedef struct TreeNode{
    int data;
    TreeNode *left,*right;
}TreeNode,*Tree;

Tree createTree(int n);
bool Compare(Tree T,Tree T1);
Tree insert(Tree t,int x);

int main(){
    int n,l,flag=1;
    cin>>n;
    while(n!=0){
        cin>>l;
        Tree T=createTree(n);
        for(int i=0;i<l;i++){
            Tree T1=createTree(n);
            if(flag==1){
                flag=0;
                if(Compare(T,T1)) printf("Yes");
                else printf("No");
            }
            else{
                if(Compare(T,T1)) printf("\nYes");
                else printf("\nNo");
            }
            free(T1);
        }
        free(T);
        cin>>n;
    }
    return 0;
}

Tree createTree(int n){
    int x;
    if(n==0) return NULL;
    Tree t=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        t=insert(t,x);
    }
    return t;
}

bool Compare(Tree T,Tree T1){
    if(T==NULL&&T1==NULL) return true;
    if((T==NULL&&T1!=NULL)||(T!=NULL&&T1==NULL)) return false;
    if(T->data!=T1->data) return false;
    else return Compare(T->right,T1->right)&&Compare(T->left,T1->left);
}

Tree insert(Tree t,int x){
    if(!t){
        t=(Tree)malloc(sizeof(TreeNode));
        t->data=x;
        t->left=NULL;
        t->right=NULL;
    }
    else{
        if(x>t->data) t->right=insert(t->right,x);
        else t->left=insert(t->left,x);
    }
    return t;
}
