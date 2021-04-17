BinTree Insert( BinTree BST, ElementType X ){
    if(!BST){
        BST=(BinTree)malloc(sizeof(Position));
        BST->Data=X;
        BST->Left=NULL;
        BST->Right=NULL;
    }
    else{
        if(X>BST->Data) BST->Right=Insert(BST->Right,X);
        else BST->Left=Insert(BST->Left,X);
    }
    return BST;
}
BinTree Delete( BinTree BST, ElementType X ){
    if(!BST) printf("Not Found\n");
    else{
        if(BST->Data>X) BST->Left=Delete(BST->Left,X);
        else if(BST->Data<X) BST->Right=Delete(BST->Right,X);
        else{
            if(BST->Left&&BST->Right){
                BinTree min=FindMax(BST->Left);
                BST->Data=min->Data;
                BST->Left=Delete(BST->Left,BST->Data);
            }
            else{
                BinTree Tmp = BST; 
                if( !BST->Left )
                    BST = BST->Right; 
                else
                    BST = BST->Left;
                free( Tmp );
            }
        }
    }
    return BST;
}
Position Find( BinTree BST, ElementType X ){
    while(BST){
        if(BST->Data>X) BST=BST->Left;
        else if(BST->Data<X) BST=BST->Right;
        else return BST;
    }
    return NULL;
}
Position FindMin( BinTree BST ){
    if(BST)
        while(BST->Left) BST=BST->Left;
    return BST;
}
Position FindMax( BinTree BST ){
    if(BST)
        while(BST->Right) BST=BST->Right;
    return BST;
}
