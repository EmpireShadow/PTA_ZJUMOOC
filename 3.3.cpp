//借用栈实现中序遍历建树
//然后递归后序遍历输出

#include <iostream>
using namespace std;
#include <stack>
#include <cstring>

typedef struct TreeNode{
    int data;
    TreeNode *left,*right;
}TreeNode,*Tree;

Tree create(Tree t,int n);
void post1(Tree t);
int flag=1;

int main(){
    int n;
    cin>>n;
    if(n==0) ;
    else{
        Tree t;
        t=create(t,n);
        if(t==NULL) ;
        else if(t->left==NULL&&t->right==NULL) cout<<t->data;
        else{
            post1(t);
        }
    }
    return 0;
}

Tree create(Tree t,int n){
    string temp1;
    int temp2,flag=1;
    stack<Tree> s;
    cin>>temp1>>temp2;
    t=(Tree)malloc(sizeof(TreeNode));
    t->data=temp2;
    t->left=NULL;
    t->right=NULL;
    Tree t1=t;
    s.push(t1);
    for(int i=0;i<2*n-1;i++){
        cin>>temp1;
        if(temp1=="Push"){
            cin>>temp2;
            TreeNode *ts=(Tree)malloc(sizeof(TreeNode));
            ts->data=temp2;
            ts->left=NULL;
            ts->right=NULL;
            if(flag==1){
                t1->left=ts;
            }
            else t1->right=ts;
            t1=ts;
            s.push(t1);
            flag=1;
        }
        if(temp1=="Pop"){
            t1=s.top();
            s.pop();
            flag=0;
        }
    }
    return t;
}

void post1(Tree t){
    if(t==NULL) ;
    else{
        post1(t->left);
        post1(t->right);
        if(flag==1){
            flag=0;
            cout<<t->data;
        } 
        else cout<<" "<<t->data;
    }
}
