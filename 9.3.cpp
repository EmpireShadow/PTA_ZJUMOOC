#include <iostream>
using namespace std;

int matrix[100];
int matrix1[100];
int matrix2[100];
int num;
int flag1=-1;
int flag2=-1;

bool test();
void copy();
void swap(int a,int b);
void insertion();
void Heapsort();
void PercDown(int p,int num);

int main(){
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>matrix[i];
        matrix1[i]=matrix[i];
    }
    for(int i=0;i<num;i++)
        cin>>matrix2[i];
    
    //test
    insertion();
    if(flag1==1) cout<<"Insertion Sort"<<endl;
    else{
        copy();
        cout<<"Heap Sort"<<endl;
        Heapsort();
    }
    cout<<matrix1[0];
    for(int i=1;i<num;i++)
        cout<<" "<<matrix1[i];
    return 0;
}

void insertion(){
    int i;
    for(int k=1;k<num;k++){
        int temp=matrix1[k];
        for(i=k;i>0&&temp<matrix1[i-1];i--)
            matrix1[i]=matrix1[i-1];
        matrix1[i]=temp;
        if(flag1==1) return;
        if(test()) flag1=1;
    }
}

void Heapsort(){
    for(int i=num/2-1;i>=0;i--)
        PercDown(i,num);
    for(int i=num-1;i>0;i--){
        swap(0,i);
        PercDown(0,i);
        if(flag2==1) break;
        if(test()) flag2=1;
    }
}

void PercDown(int p,int num){
    int parent,child;
    int x=matrix1[p];
    for(parent=p;parent*2+1<num;parent=child){
        child=parent*2+1;
        if(child!=num-1&&matrix1[child]<matrix1[child+1])
            child++;
        if(x>matrix1[child]) break;
        else matrix1[parent]=matrix1[child];
    }
    matrix1[parent]=x;
}

void swap(int a,int b){
    int temp=matrix1[a];
    matrix1[a]=matrix1[b];
    matrix1[b]=temp;
}

bool test(){
    for(int i=0;i<num;i++)
        if(matrix1[i]!=matrix2[i])
            return false;
    return true;
}

void copy(){
    for(int i=0;i<num;i++)
        matrix1[i]=matrix[i];
}
