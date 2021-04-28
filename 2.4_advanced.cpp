#include <iostream>
#include <stack>
using namespace std;

int main(){
    int m,n,k;
    cin>>m>>n>>k;
    for(int i=0;i<k;i++){
        int seq[n];
        bool flag=false;
        for(int j=0;j<n;j++){
            cin>>seq[j];
        }    
        stack<int> s;
        int count=1;
        for(int j=0;j<n;j++){
            s.push(j+1);
            if(s.size()>m) break;
            while(!s.empty()&&s.top()==seq[count-1]){
                s.pop();
                count++;
            }
        }
        if(count==n+1) flag=true;
        if(flag){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
