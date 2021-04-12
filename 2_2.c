#include <stdlib.h>
#include <stdio.h>
#define Maxsize 100

typedef struct Number{
    int num;
    int a[Maxsize];
    int x[Maxsize];
}Number,*Numberlist;

void insert(Numberlist L,int x,int y);
Numberlist read();
Numberlist mul(Numberlist L1,Numberlist L2);
Numberlist add(Numberlist L1,Numberlist L2);
void putout(Numberlist list);
int Research(Numberlist L,int i);
void delete(Numberlist L,int z);
    
main(){
    Numberlist N1,N2,N;
    N1=read();
    N2=read();
    N=mul(N1,N2);
    putout(N);
    printf("\n");
    N=add(N1,N2);
    putout(N);
    return 0;
}

Numberlist read(){
    int q,k,l;
    scanf("%d",&q);
    Numberlist re=(Numberlist)malloc(sizeof(Number));
    re->num=q;
    for(int i=0;i<q;i++){
        scanf(" %d %d",&k,&l);
        re->a[i]=k;
        re->x[i]=l;
    }
    return re;
}

void insert(Numberlist L,int s,int d){
    int k=0;
    int q=L->num;
    if(L->x[0]<d) k=0;
    else if(L->x[q]>d) k=q;
    else{
        for(int i=0;i<L->num;i++){
            if(L->x[i]>d&&L->x[i+1]<d) {k=i+1; break;} 
        }
    }
    for(int i=L->num;i>k;i--){
        L->x[i]=L->x[i-1];
        L->a[i]=L->a[i-1];
    }
    L->x[k]=d;
    L->a[k]=s;
    L->num++;
}

Numberlist mul(Numberlist L1,Numberlist L2){
    Numberlist L3=(Numberlist)malloc(sizeof(Number));
    Numberlist L4=(Numberlist)malloc(sizeof(Number));
    L3->num=L2->num;
    L4->num=0;
    for(int i=0;i<L1->num;i++){
        //L3->num=L2->num;
        for(int j=0;j<L2->num;j++){
            int s=L1->a[i]*L2->a[j];
            int d=L1->x[i]+L2->x[j];
            //if(s==0) L3->num--;
            //else{
                L3->a[j]=s;
                L3->x[j]=d;
            //}
        }
        L4=add(L4,L3);
    }
    return L4;
}

int Research(Numberlist L,int i){
    for(int k=0;k<=L->num;k++){
        if(L->x[k]==i) return k;
    }
    return -1;
}

void delete(Numberlist L,int z){
    for(int i=z;i<L->num-1;i++){
        L->x[i]=L->x[i+1];
        L->a[i]=L->a[i+1];
    }
    L->num--;
}
    
Numberlist add(Numberlist L1,Numberlist L2){
    Numberlist s=(Numberlist)malloc(sizeof(Number));
    s->num=0;
    int l1=0,l2=0,l=0;
    while(l1<L1->num&&l2<L2->num){
        if(L1->x[l1]==L2->x[l2]){
            if(L1->a[l1]+L2->a[l2]==0) l--;
            else {
                s->x[l]=L1->x[l1];
                s->a[l]=L1->a[l1]+L2->a[l2];
            }
            l1++;
            l2++;
        }
        else if(L1->x[l1]>L2->x[l2]){
            s->x[l]=L1->x[l1];
            s->a[l]=L1->a[l1];
            l1++;
        }
        else if(L1->x[l1]<L2->x[l2]){
            s->x[l]=L2->x[l2];
            s->a[l]=L2->a[l2];
            l2++;
        }
        l++;
    }
    while(l1<L1->num){
        s->x[l]=L1->x[l1];
        s->a[l]=L1->a[l1];
        l1++;
        l++;
    }
    while(l2<L2->num){
        s->x[l]=L2->x[l2];
        s->a[l]=L2->a[l2];
        l2++;
        l++;
    }
    s->num=l;
    //s=deletezero(s);
    return s;
}

void putout(Numberlist list){
    int nu=list->num;
    if(nu==0){
        printf("0 0");
    }
    else{
        for(int i=0;i<nu-1;i++){
            if(list->a[i]!=0){
                printf("%d %d ",list->a[i],list->x[i]);
            }
        }
        if(list->a[nu-1]!=0){
            printf("%d %d",list->a[nu-1],list->x[nu-1]);
        }
    }
}
