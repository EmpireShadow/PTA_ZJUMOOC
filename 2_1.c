List Merge( List L1, List L2 ){
    typedef struct Node Lnode;
    List p=(Lnode *) malloc(sizeof(Lnode));
    List q=p;
    p->Next=NULL;
    List x=L1->Next;
    List y=L2->Next;
    while(x&&y){
        if(x->Data<y->Data){
            q->Next=x;
            q=q->Next;
            x=x->Next;
        }
        else{
            q->Next=y;
            q=q->Next;
            y=y->Next;
        }
    }
    q->Next=NULL;
    if(x){
        q->Next=x;
    }
    if(y){
        q->Next=y;
    }
    L1->Next=NULL;
    L2->Next=NULL;
    return p;
}
