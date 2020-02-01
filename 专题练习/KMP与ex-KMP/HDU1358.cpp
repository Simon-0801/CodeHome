#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 5;

char a[maxn];
int nxt[maxn];
int n;

//KMP计算字符串自身的next数组
void cal_nxt(){
    nxt[1]=0;
    for(int i=2,j=0;i<=n;i++){
        while(j>0&&a[i]!=a[j+1])  j=nxt[j];
        if(a[i]==a[j+1])  j++;
        nxt[i]=j;
    }
}

int main() {
    int cas=0;
    while(scanf("%d",&n)&&n){
        cas++;
        scanf("%s",a+1);
        cal_nxt();
        printf("Test case #%d\n",cas);
        int len;
        for(int i=2;i<=n;i++){
            len=i-nxt[i];//最小循环节长度
            if(i%len==0&&i/len>1){
                printf("%d %d\n",i,i/len);
            }
        }
        printf("\n");
    }
    return 0;
}