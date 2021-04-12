
int main(){
    int q,left,right;
    int l=0;
    scanf("%d",&q);
    int x[q];
    for(int i=0;i<q;i++){
        scanf("%d",&x[i]);
    }
    int thisMax=0,Max=-1000;
    for(int i=0;i<q;i++){
        thisMax+=x[i];
        if(thisMax<0) {
            thisMax=0;
            l=i+1;
        }
        else if(thisMax>Max){
            left=l; right=i; Max=thisMax;
        }
        
    }
    if(Max<0)
        printf("0 %d %d",x[0],x[q-1]);
    else
        printf("%d %d %d",Max,x[left],x[right]);
}
