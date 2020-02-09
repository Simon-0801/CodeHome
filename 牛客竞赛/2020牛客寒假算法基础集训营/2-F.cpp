#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

struct node
{
    int a,b,index;
    bool operator<(const node& nn)const{
        return a+b<nn.a+nn.b;
    }
};


node p[maxn];
priority_queue<node> pq;
vector<ll>  va,vb;

int main() {
    ll n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&p[i].a);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&p[i].b);
        p[i].index=i;
        pq.push(p[i]);
    }
    int flag=0;
    while(!pq.empty()){
        node tmp=pq.top();
        pq.pop();
        if(flag==0){
            va.push_back(tmp.index);
        }
        else{
            vb.push_back(tmp.index);
        }
        flag=flag^1;
    }
    // memset(vis,0,sizeof vis);
    // for(int i=1;i<=n;i++){
    //     node tmp;
    //     if(i&1){
    //         while(!pq.empty()){
    //             tmp=pq.top();
    //             pq.pop();
    //             if(vis[tmp.index])  continue;
    //             else  break;
    //         }
    //         va.push_back(tmp.index);
    //     }
    //     else{
    //         while(!qb.empty()){
    //             tmp=qb.top();
    //             qb.pop();
    //             if(vis[tmp.index])  continue;
    //             else  break;
    //         }
    //         vb.push_back(tmp.index);
    //     }
    //     vis[tmp.index]=1;
    // }
    for(int i=0;i<va.size();i++){
        printf("%lld%c",va[i],i==va.size()-1?'\n':' ');
    }
    for(int i=0;i<vb.size();i++){
        printf("%lld%c",vb[i],i==vb.size()-1?'\n':' ');
    }
    return 0;
}