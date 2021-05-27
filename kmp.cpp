#include <iostream>
#include <cstring>
using namespace std;

#define STRINGLENGTH 1000000
#define PATTERNLENGTH 100000

int KMP(char *string,char *pattern);
void Buildnext(char* pattern,int *next);

int main(){
    char str[1000001];
    char pattern[100001];
    int n;
    cin>>str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>pattern;
        int j=KMP(str,pattern);
        if(j==-1) cout<<"Not Found\n";
        else printf("%s\n",str+j);
    }
}

void Buildnext(char* pattern,int* next){
    int i,j;
    int m=strlen(pattern);
    next[0]=-1;
    for(j=1;j<m;j++){
        i=next[j-1];
        while((i>=0)&&(pattern[i+1]!=pattern[j]))
            i=next[i];
        if(pattern[i+1]==pattern[j])
            next[j]=i+1;
        else next[j]=-1;
    }
}

int KMP(char *str,char *pattern){
    int n=strlen(str);
    int m=strlen(pattern);
    int s=0,p=0,*next;
    if(n<m) return -1;
    next=(int*)malloc(sizeof(int)*m);
    Buildnext(pattern,next);
    while(s<n&&p<m){
        if(str[s]==pattern[p]){s++;p++;}
        else if(p>0) p=next[p-1]+1;
        else s++;
    }
    return (p==m)?(s-m):-1;
}
