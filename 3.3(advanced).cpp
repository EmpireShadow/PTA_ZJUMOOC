//不建树
#include <iostream>
using namespace std;
#include <stack>
#include <cstring>
#define maxsize 31

int pre[maxsize];
int in[maxsize];
int post[maxsize];

void makepost(int prel,int inl,int postl,int n);

int main(){
    int n,a=1,b=1;
    string s;
    stack<int> st;
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>s;
        if(s=="Push"){
            cin>>pre[a];
            st.push(pre[a]);
            a++;
        }
        else{
            in[b]=st.top();
            st.pop();
            b++;
        }
    }
    makepost(1,1,1,n);
    cout<<post[1];
    for(int i=2;i<=n;i++)
        cout<<" "<<post[i];
}

void makepost(int prel,int inl,int postl,int n){
    int i;
    if(n==0) return;
    if(n==1){
        post[postl]=pre[prel];
        return;
    }
    post[postl+n-1]=pre[prel];
    for(i=1;i<n+1;i++)
        if(in[inl+i-1]==pre[prel])
            break;
    makepost(prel+1,inl,postl,i-1);
    makepost(prel+i,inl+i,postl+i-1,n-i);
}
