#include <iostream>
using namespace std;
#define maxsize 32767

typedef struct phone *Phone;
typedef struct phone{
    long int mobile;
    int callnum=0;
    Phone next;
}phone;

typedef struct book{
    int phonenumber;
    Phone head;
}book,*Book;

int nextprime(int n);
Book createTable(int n);
int Hash(long int key,int p);
Phone Find(Book B,long int key);
bool Insert(Book B,long int key);
void scanandoutput(Book B);

int main(){
    Book H;
    int n;
    cin>>n;
    long int s;
    H=createTable(n*2);
    for(int i=0;i<n;i++){
        cin>>s;
        Insert(H,s);
        cin>>s;
        Insert(H,s);
    }
    scanandoutput(H);
    return 0;
}

Book createTable(int n){
    Book B;
    B=(Book)malloc(sizeof(book));
    B->phonenumber=nextprime(n);
    B->head=(Phone)malloc(B->phonenumber*sizeof(phone));
    for(int i=0;i<B->phonenumber;i++){
        B->head[i].mobile=0;
        B->head[i].next=NULL;
        B->head[i].callnum=0;
    }
    return B;
}

int nextprime(int n){
    n=(n%2==0)?n+1:n;
    for(;n<maxsize;n+=2){
        int flag=1;
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0) {flag=0;break;}
        }
        if(flag==1) break;
    }
    return n;
}

int Hash(long int key,int p){
    int s=key%10000;
    return s%p;
}

Phone Find(Book B,long int key){
    int pos=Hash(key,B->phonenumber);
    Phone p=B->head[pos].next;
    while(p&&p->mobile!=key) p=p->next;
    return p;
}

bool Insert(Book B,long int key){
    Phone p,newcell;
    int pos;
    p=Find(B,key);
    if(!p){
        newcell=(Phone)malloc(sizeof(phone));
        newcell->mobile=key;
        newcell->callnum=1;
        pos=Hash(key,B->phonenumber);
        newcell->next=B->head[pos].next;
        B->head[pos].next=newcell;
        return true;
    }
    else{
        p->callnum++;
        return false;
    }
}

void scanandoutput(Book B){
    int i,maxcnt=0,pcnt=0;
    long int minphone;
    Phone ptr;
    minphone=0;
    for(i=0;i<B->phonenumber;i++){
        ptr=B->head[i].next;
        while(ptr){
            if(ptr->callnum>maxcnt){
                maxcnt=ptr->callnum;
                minphone=ptr->mobile;
                pcnt=1;
            }
            else if(ptr->callnum==maxcnt){
                pcnt++;
                if(minphone>ptr->mobile){
                    minphone=ptr->mobile;
                }
            }
            ptr=ptr->next;
        }
    }
    cout<<minphone<<" "<<maxcnt;
    if(pcnt>1) cout<<" "<<pcnt;
}
