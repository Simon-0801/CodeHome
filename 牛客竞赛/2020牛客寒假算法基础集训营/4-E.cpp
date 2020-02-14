#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;

char str[maxn];
int num[maxn],ans[maxn];

int cmp(int a,int b){
    return a>b;
}

int main() {
    scanf("%s",str+1);
    int addcnt=0,len=strlen(str+1),cnt=0;
    for(int i=1;i<=len;i++){
        if(str[i]=='+')  addcnt++;
        else{
            num[++cnt]=str[i]-'0';
        }
    }
    addcnt++;
    sort(num+1,num+cnt+1,cmp);
    int index=0,tmp=0,jin=0,j=1;
    for(int i=1;i<=cnt;i++){
        if(j<addcnt){
            j++;
            tmp+=num[i];
        }
        else{
            tmp+=num[i];
            tmp+=jin;
            ans[++index]=tmp%10;
            jin=tmp/10;
            j=1;
            tmp=0;
        }
    }
    tmp+=jin;
    if(tmp){
        // tmp+=jin;
        while(tmp){
            ans[++index]=tmp%10;
            tmp/=10;
        }
    }
    for(int i=index;i>=1;i--){
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}