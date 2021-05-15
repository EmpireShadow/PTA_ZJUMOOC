#include <iostream>
using namespace std;

long int matrix[100000];
long int tempmatrix[100000];
int Sedgewick[12] = {8929,3905,2161,929, 505, 209, 109, 41, 19, 5, 1, 0};

void sort1(int num);        //冒泡排序
void sort2(int num);        //插入排序
void sort3(int num);        //希尔排序
void sort4(int num);        //选择排序
int findmin(int l,int r);   //找到最小数

void HeapSort(int num);        //堆排序
void PercDown(int p,int num);

void msort0(int l,int rightend);        //归并排序 递归
void merge0(int l,int r,int rightend);   //merge0
void swap(int a,int b);     //交换



int main(){
    //初始化
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
        cin>>matrix[i];
    
    //选择排序方式
    //sort4(num);
    //msort0(0,num-1);
    HeapSort(num);
    
    //输出
    cout<<matrix[0];
    for(int i=1;i<num;i++)
        cout<<" "<<matrix[i];
}

void swap(int a,int b){
    int temp=matrix[a];
    matrix[a]=matrix[b];
    matrix[b]=temp;
}

//冒泡
void sort1(int num){
    if(num==1) return;
    for(int i=num-1;i>0;i--){
        int flag=0;
        for(int j=0;j<i;j++){
            if(matrix[j]>matrix[j+1]){
                swap(j,j+1);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}

//插入
void sort2(int num){
    if(num==1) return;
    int i;
    for(int n=1;n<num;n++){
        long int temp=matrix[n];         //保存未排序的第一个数
        for(i=n;i>0&&temp<matrix[i-1];i--)
                matrix[i]=matrix[i-1];
        matrix[i]=temp;
    }
}

//希尔
void sort3(int num){
    if(num==1) return;
    int i,j;
    for(i=0;Sedgewick[i]>=num;i++);
    for(int p=Sedgewick[i];Sedgewick[i]>0;p=Sedgewick[++i]){
        for(int k=p;k<num;k++){
            long int temp=matrix[k];
            for(j=k;j>=p&&temp<matrix[j-p];j-=p)
                matrix[j]=matrix[j-p];
            matrix[j]=temp;
        }
    }
}

//选择
void sort4(int num){
    for(int i=0;i<num;i++){
        int temp=findmin(i,num-1);
        swap(i,temp);
    }
}

int findmin(int l,int r){
    if(l==r) return l;
    int i,min=2147483647;
    for(int j=l;j<=r;j++){
        if(matrix[j]<min){
            min=matrix[j];
            i=j;
        }
    }
    return i;
}

//归并 递归

void msort0(int l,int rightend){
    int mid;
    if(l<rightend){
        mid=(l+rightend)/2;
        msort0(l,mid);
        msort0(mid+1,rightend);
        merge0(l,mid+1,rightend);
    }
}

void merge0(int l,int r,int rightend){
    int leftend=r-1;
    int temp=l;
    int length=rightend-l+1;
    while(l<=leftend&&r<=rightend){
        if(matrix[l]<=matrix[r]) tempmatrix[temp++]=matrix[l++];
        else tempmatrix[temp++]=matrix[r++];
    }
    while(l<=leftend) tempmatrix[temp++]=matrix[l++];
    while(r<=rightend) tempmatrix[temp++]=matrix[r++];
    for(int i=0;i<length;i++,rightend--)
        matrix[rightend]=tempmatrix[rightend];
}


//堆排序
void PercDown(int p,int num)
{/* 将num个元素的数组中以matrix[p]为根的子堆调整为最大堆 */
    int Parent,Child;
    long int X;

    X=matrix[p]; /* 取出根结点存放的值 */
    for(Parent=p; (Parent*2+1)<num; Parent=Child){
        Child=Parent*2+1;
        if((Child!=num-1)&&(matrix[Child]<matrix[Child+1]))
            Child++;  /* Child指向左右子结点的较大者 */
        if(X>= matrix[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            matrix[Parent] = matrix[Child];
    }
    matrix[Parent] = X;
}

void HeapSort(int num) 
{ /* 堆排序 */
     int i;
     for (i=num/2-1;i>=0;i--)/* 建立最大堆 */
         PercDown(i,num);
     for (i=num-1;i>0;i-- ) {
         /* 删除最大堆顶 */
         swap(0,i); 
         PercDown(0,i);
     }
}
