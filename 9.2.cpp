#include <iostream>
using namespace std;

int num;
int length1=1;
int matrix[100];
int matrix1[100];
int matrix2[100];
int tempmatrix[100];
int flag=-1;
int flag2=-1;

void copy();
bool test();
void insert(int num);
void Merge_Sort(int num);
void merge1(int matrix[],int tempmatrix[],int l,int r,int rightend);
void merge_pass(int matrix[],int tempmatrix[],int num,int length);

int main(){
    cin>>num;
    for(int i=0;i<num;i++)
        cin>>matrix[i];
    for(int i=0;i<num;i++)
        cin>>matrix2[i];
    copy();
    insert(num);
    if(flag==1) cout<<"Insertion Sort"<<endl;
    else{
        copy();
        Merge_Sort(num);
        cout<<"Merge Sort"<<endl;
    }
    cout<<matrix1[0];
    for(int i=1;i<num;i++)
        cout<<" "<<matrix1[i];
    return 0;
}

void insert(int num){
    int i;
    for(int k=1;k<num;k++){
        int temp=matrix1[k];
        for(i=k;k>0&&temp<matrix1[i-1];i--)
            matrix1[i]=matrix1[i-1];
        matrix1[i]=temp;
        if(flag==1) break;
        if(test()) flag=1;
    }
}

void copy(){
    for(int i=0;i<num;i++)
        matrix1[i]=matrix[i];
}

bool test(){
    int f=1;
    for(int i=0;i<num;i++)
        if(matrix1[i]!=matrix2[i])
            f=0;
    if(f==0) return false;
    else return true;
}

//归并 循环
void merge1(int matrix[],int tempmatrix[],int l,int r,int rightend){
    int leftend=r-1;
    int temp=l;
    int mergelength=rightend-l+1;
    while(l<=leftend&&r<=rightend){
        if(matrix[l]<=matrix[r]) tempmatrix[temp++]=matrix[l++];
        else tempmatrix[temp++]=matrix[r++];
    }
    while(l<=leftend) tempmatrix[temp++]=matrix[l++];
    while(r<=rightend) tempmatrix[temp++]=matrix[r++];
    for(int i=0;i<mergelength;i++,rightend--)
        matrix[rightend]=tempmatrix[rightend];
}

void merge_pass(int matrix[],int tempmatrix[],int num,int length){
    int i,j;
    for(i=0;i<=num-2*length;i+=2*length)
         merge1(matrix,tempmatrix,i,i+length,i+2*length-1);
     if(i+length<num) /* 归并最后2个子列*/
         merge1(matrix,tempmatrix,i,i+length,num-1);
     else/* 最后只剩1个子列*/
         for(j=i;j<num;j++) tempmatrix[j]=matrix[j];
}

void Merge_Sort(int num)
{ 
     int length=1; /* 初始化子序列长度*/
     while(length<num) {
         merge_pass(matrix1,tempmatrix,num,length);
         length*= 2;
         if(flag2==1) return;
         if(test()) flag2=1;
         merge_pass(tempmatrix,matrix1,num,length);
         length*= 2;
         if(flag2==1) return;
         if(test()) flag2=1;
     }
}
