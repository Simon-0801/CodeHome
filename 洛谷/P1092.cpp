#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define INF 0x3f3f3f3f
#define mst(a,num) memset(a,num,sizeof a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 30 + 5;

int n,cnt=0;
char add1[maxn],add2[maxn],sum[maxn];
int num[maxn],vis[maxn],nxt[maxn];

bool CanPrune() {//prune: 剪枝—百度翻译。
    if(num[add1[1]-'A'+1]+num[add2[1]-'A'+1]>=n)
        return true;
    for(int i=n;i>0;i--) {
        int A=num[add1[i]-'A'+1],B=num[add2[i]-'A'+1],C=num[sum[i]-'A'+1];
        if(A==-1||B==-1||C==-1) continue;
        if((A+B)%n!=C&&(A+B+1)%n!=C)
            return true;
    }
    return false;
}

bool Judge() {
    for(int i=n,x=0;i>0;i--) {
        int A=num[add1[i]-'A'+1],B=num[add2[i]-'A'+1],C=num[sum[i]-'A'+1];
        if((A+B+x)%n!=C) return false;
        x=(A+B+x)/n;
    }
    return true;
}

bool dfs(int index){
    if(CanPrune())   return false;
    if(index>n&&Judge()){
        rep(i,1,n){
            printf("%d ",num[i]);
        }
        printf("\n");
        return true;
    }
    repd(i,n-1,0){
        if(vis[i])  continue;
        vis[i]=1;
        num[nxt[index]]=i;
        // int tmp=now,tmpjin=jin;
        // int tadd1=num[add1[tmp]-'A'+1],tadd2=num[add2[tmp]-'A'+1],tsum=num[sum[tmp]-'A'+1];
        // int flag=1;
        // while(tmp<=n&&tadd1!=-1&&tadd2!=-1&&tsum!=-1){
        //     if((tadd1+tadd2+tmpjin)%n==tsum){
        //         tmpjin=(tadd1+tadd2+tmpjin)/n;
        //         tmp++;
        //         tadd1=num[add1[tmp]-'A'+1],tadd2=num[add2[tmp]-'A'+1],tsum=num[sum[tmp]-'A'+1];
        //     }
        //     else{
        //         flag=0;
        //         break;
        //     }
        // }
        // if(flag==0){
        //     vis[i]=0;
        //     num[nxt[index]]=-1;
        //     continue;
        // }
        if(dfs(index+1))   return true;
        vis[i]=0;
        num[nxt[index]]=-1;
    }
    return false;
}

void GetNext(int x) {
    if(vis[x]==false) {
        vis[x]=true;
        nxt[++cnt]=x;
    }
    return;
}

int main() {
    scanf("%d",&n);
    scanf("%s",add1+1);
    scanf("%s",add2+1);
    scanf("%s",sum+1);
    // reverse(add1+1,add1+n+1);
    // reverse(add2+1,add2+n+1);
    // reverse(sum+1,sum+n+1);
    repd(i,n,1){
        GetNext(add1[i]-'A'+1);
        GetNext(add2[i]-'A'+1);
        GetNext(sum[i]-'A'+1);
    }
    mst(num,-1);
    mst(vis,0);
    dfs(1);
    return 0;
}