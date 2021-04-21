//重点是在查找root的时候，把查找路径上所有的结点的父节点递归设置为root！！！！！压缩了树的深度


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector <int> in,level;
void levelout(int start,int end,int index);

int main(){
    int n;
    cin>>n;
    in.resize(n);
    level.resize(n);
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    sort(in.begin(),in.end());
    levelout(0,n-1,0);
    printf("%d",level[0]);
    for(int i=1;i<n;i++)
        printf(" %d",level[i]);
    return 0;
}

void levelout(int start,int end,int index){
    if(start>end) return;
    int n=end-start+1;
    int l=log(n+1)/log(2);
    int leave=n-(pow(2,l)-1);
    int root=start+(pow(2,l-1)-1)+min(leave,(int)(pow(2,l-1)));
    level[index]=in[root];
    levelout(start,root-1,2*index+1);
    levelout(root+1,end,2*index+2);
}
