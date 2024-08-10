// 牛客网：https://www.nowcoder.com/practice/bc62febdd1034a73a62224affe8bddf2?tpId=182&tqId=34304&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3DSQL%25E7%25AF%2587%26topicId%3D182&difficulty=undefined&judgeStatus=undefined&tags=&title=

#include <iostream>
using namespace std;

int rev(int x){
    int rev = 0;
    while(x){
        rev =  rev * 10 + x % 10;
        x = x / 10;
    }
    return rev;
}

int main(){
    int a, b;
    while(cin >> a >> b){
        cout << rev(rev(a)+rev(b)) << endl;
    }
    return 0;
}