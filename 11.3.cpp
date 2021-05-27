#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string,string> mymap;
    string s1,s2;
    char c;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        if(i!=0) cout<<endl;
        cin>>c;
        cin>>s1;
        cin>>s2;
        if(c=='N'){
            auto it=mymap.find(s1);
            if(it==mymap.end()){
                mymap[s1]=s2;
                cout<<"New: OK";
            }
            else
                cout<<"ERROR: Exist";
        }
        if(c=='L'){
            auto it=mymap.find(s1);
            if(it!=mymap.end())
                if(it->second==s2)
                    cout<<"Login: OK";
                else
                    cout<<"ERROR: Wrong PW";
            else
                cout<<"ERROR: Not Exist";
        }
    }
    return 0;
}
