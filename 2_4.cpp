#include <iostream>
using namespace std;

int main(){
    int m,n,k;
    cin>>m>>n>>k;
    for(int i=0;i<k;i++){
        int seq[n];
        for(int j=0;j<n;j++){
            cin>>seq[j];
        }    
        int sstack[m];
        int top=-1;
        int count=0;
        int ppop=0,ppush=0;
        while(ppop<=n&&ppush<=n&&ppop<=ppush&&top<m&&count<n){
            if(top==-1){
                top++;
                ppush++;
                sstack[top]=ppush;
            }
            if(sstack[top]==seq[count]){
                ppop++;
                top--;
                count++;
            }
            else if(sstack[top]<seq[count]){
                top++;
                ppush++;
                sstack[top]=ppush;
            }
            else {
                break;
            }
        }
        if(ppop==ppush&&ppop==n&&count==n){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
