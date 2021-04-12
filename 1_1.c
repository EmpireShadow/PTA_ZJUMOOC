int main(){
    int a;
    scanf("%d",&a);
    int x[a];
    for(int i=0;i<a;i++){
        scanf("%d",&x[i]);
    }
    int thisMax=0,Max=0;
    for(int i=0;i<a;i++){
        thisMax+=x[i];
        if(thisMax>Max) Max=thisMax;
        else if(thisMax<0) thisMax=0;
    }
    printf("%d",Max);
}
