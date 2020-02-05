#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 200 + 5;

char a[4005][maxn];
int nxt[maxn],match[maxn];

void cal_nxt(int l,int r){
    nxt[1]=0;
    for(int i=2,j=0;i<=r-l+1;i++){
        while(j>0&&a[1][i+l-1]!=a[1][l-1+j+1])  j=nxt[j];
        if(a[1][i+l-1]==a[1][l-1+j+1])  j++;
        nxt[i]=j;
    }
}

bool cal_match(int index,int l,int r){
    int len=strlen(a[index]+1);
    for(int i=1,j=0;i<=len;i++){
        while(j>0&&(j==r-l+1||a[index][i]!=a[1][l-1+j+1]))  j=nxt[j];
        if(a[index][i]==a[1][l-1+j+1])  j++;
        match[i]=j;
        if(match[i]==r-l+1){
            return true;
        }
    }
    return false;
}

int main() {
    int t,m;
    // scanf("%d",&t);
    while(scanf("%d",&m)&&m){
        for(int i=1;i<=m;i++){
            scanf("%s",a[i]+1);
        }
        int ansl=0,ansr=0;
        string s=a[1]+1,ans;
        int alen=strlen(a[1]+1);
        for(int len=alen;len>0;len--){
            for(int l=1;l<=alen+1-len;l++){
                int r=l+len-1;
                cal_nxt(l,r);
                int flag=1;
                for(int i=2;i<=m;i++){
                    if(!cal_match(i,l,r)){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    string tmp=s.substr(l-1,r-l+1);
                    if(ansl==0){
                        ans=tmp;
                        ansl=l;
                        ansr=r;
                    }
                    else{
                        if(ans>tmp){
                            ans=tmp;
                            ansl=l;
                            ansr=r;
                        }
                    }
                }
            }
            if(ansl){
                break;
            }
        }
        if(ansl){
            for(int i=ansl;i<=ansr;i++){
                printf("%c",a[1][i]);
            }
            printf("\n");
        }
        else{
            printf("IDENTITY LOST\n");
        }
    }
    return 0;
}