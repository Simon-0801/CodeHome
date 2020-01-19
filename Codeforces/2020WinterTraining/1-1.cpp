#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int  num[105];
char str[105];

int main() {
    scanf("%s",str);
    int len=strlen(str);
    int cnt=0,index=1;
    for(int i=0;i<len;i++){
        if(str[i]=='Q')  cnt++;
        else if(str[i]=='A'){
            num[index++]=cnt;
        }
    }
    cnt=0;
    int tindex=index-1;
    for(int i=len-1;i>=0;i--){
        if(str[i]=='Q')  cnt++;
        else if(str[i]=='A'){
            num[tindex--]*=cnt;
        }
    }
    int sum=0;
    for(int i=1;i<=index-1;i++){
        sum+=num[i];
    }
    printf("%d\n",sum);
    return 0;
}