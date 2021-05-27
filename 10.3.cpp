#include<iostream>
using namespace std;
#define MAX 100100
int a[MAX];
int main() {
    int i,num, S = 0, K = 0, flag = 0;
    cin >> num;
    for(i = 0; i < num; i++){
        cin >> a[i];
        if(a[i] == i) {
            if(i == 0) flag = 1;
            S++;
        }
    }
    for(i = 0; i < num; i++){
        if(a[i] != i){
            K++;
            while(a[i] != i){
                int temp = a[i];
                a[i] = i;
                i = temp;
            }
        }
    }
    if(flag) cout << num - S + K;
    else cout << num - S + K - 2;
}
