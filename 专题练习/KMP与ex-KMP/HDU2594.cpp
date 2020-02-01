#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 50000 + 5;

char a[maxn],b[maxn];
int nxt[maxn],extend[maxn],match[maxn];
int n,m;

void cal_nxt(){
    nxt[1]=0;
    for(int i=2,j=0;i<=n;i++){
        while(j>0&&a[i]!=a[j+1])  j=nxt[j];
        if(a[i]==a[j+1])  j++;
        nxt[i]=j;
    }
}

void cal_extend(){
    int p=1;
    extend[1]=0;
    while(extend[1]<n&&extend[1]<m&&b[extend[1]+1]==a[extend[1]+1])  ++extend[1];
    for(int i=2;i<=m;++i){
        if(i+nxt[i-p+1]<p+extend[p])  extend[i]=nxt[i-p+1];
        else{
            int j=extend[p]+p-i;
            if(j<0)j=0;
            while(i+j<=m&&j<n&&b[i+j]==a[j+1])  ++j;
            extend[i]=j;
            p=i;
        }
    }
}

int main() {
    while(~scanf("%s%s",a+1,b+1)){
        n=strlen(a+1);
        m=strlen(b+1);
        cal_nxt();
        cal_extend();
        int ans=0,ansi=0;
        for(int i=1,j=0;i<=m;i++){
            while(j>0&&(j==n||b[i]!=a[j+1]))  j=nxt[j];
            if(b[i]==a[j+1])  j++;
            match[i]=j;
        }
        // for(int i=1;i<=m;i++){
        //     if(extend[i]>ans&&i+extend[i]-1==m){
        //         ans=extend[i];
        //         ansi=i;
        //         // break;
        //     }
        // }
        if(match[m]){
            // for(int i=1;i<=ans;i++){
            //     printf("%c",a[i]);
            // }
            printf("%s %d\n",b+m-match[m]+1,match[m]);
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}