Position BinarySearch( List L, ElementType X ){
    Position l=0;
    Position r=L->Last;
    Position m;
    while(l<=r){
        m=(l+r)/2;
        if(L->Data[m]==X) return m;
        if(L->Data[m]<X) l=m+1;
        else r=m-1;
    }
    return NotFound;
}
