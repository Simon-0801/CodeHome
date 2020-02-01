#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 5;
const int maxm = 10000+5;

char a[maxn],b[maxm];
int nxt[maxm],match[maxn];
int n,m;

void cal_nxt(){
    nxt[1]=0;
    for(int i=2,j=0;i<=m;i++){
        while(j>0&&b[i]!=b[j+1])  j=nxt[j];
        if(b[i]==b[j+1])  j++;
        nxt[i]=j;
    }
}


int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",b+1);
        scanf("%s",a+1);
        n=strlen(a+1);
        m=strlen(b+1);
        cal_nxt();
        int ans=0;
        for(int i=1,j=0;i<=n;i++){
            while(j>0&&a[i]!=b[j+1])  j=nxt[j];
            if(a[i]==b[j+1])  j++;
            match[i]=j;
            if(match[i]==m){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}