// 卡码网58.区间和
#include "head.h"

 void method_violent(){
    int n, a, b;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    while(cin >> a >> b){
        int sum = 0;
        for(int i=a; i<=b; i++){
            sum += vec[i];
        }
        cout << sum << endl;
    }
 }

 int main(){
    method_violent();
 }