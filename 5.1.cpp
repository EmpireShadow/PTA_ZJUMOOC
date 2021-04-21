#include <iostream>
using namespace std;
#define Mindata -10000
#define Maxsize 1000

int flag=1;
typedef struct Heap{
    int *data;
    int size;
    int capacity;
}Heap,*MinHeap;

MinHeap insert(MinHeap heap,int x);
void research(MinHeap heap,int x);

int main(){
    int n,m,x;
    cin>>n>>m;
    MinHeap heap=(MinHeap)malloc(sizeof(Heap));
    heap->data=(int*)malloc(sizeof(int)*(n+1));
    heap->capacity=n;
    heap->size=0;
    heap->data[0]=Mindata;
    for(int i=0;i<n;i++){
        cin>>x;
        heap=insert(heap,x);
    }
    for(int i=0;i<m;i++){
        flag=1;
        cin>>x;
        research(heap,x);
        cout<<endl;
    }
    return 0;
}


MinHeap insert(MinHeap heap,int x){
    int i;
    if(heap->size==heap->capacity) ;
    else{
        i=++heap->size;
        for(;heap->data[i/2]>x;i/=2){
            heap->data[i]=heap->data[i/2];
        }
        heap->data[i]=x;
    }
    return heap;
}

void research(MinHeap heap,int x){
    for(int j=x;j>0;j/=2){
        if(flag==1) {cout<<heap->data[j];flag=0;}
        else cout<<" "<<heap->data[j];
    }
}
