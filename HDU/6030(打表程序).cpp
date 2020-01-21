#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define sa(x) scanf("%d",&x)

const int N=10005;
int p[N],is_p[N],sum[N],a[N];
int ans=0,n;
int pcnt=0;
void init() {
    for(int i=2;i<N;++i) {
        if(!is_p[i]) {
            p[++pcnt]=i;
            for(int j=2*i;j<N;++j) is_p[j]=1;
        }
    }
}
bool judge() {
    sum[0]=0;
    for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
    for(int k=1;k<=pcnt&&p[k]<=n;++k) {
        int len=p[k];
        for(int i=1;i+len-1<=n;++i) {
            int j=i+len-1;
            int a1=sum[j]-sum[i-1];
            int a0=len-a1;
            if(a1<a0) return false;
        }
    }
    return true;
}
void dfs(int pos) {
    if(pos==n+1) {
        if(judge()) ++ans;
        return ;
    }
    a[pos]=0;
    dfs(pos+1);
    a[pos]=1;
    dfs(pos+1);
}

int main() {
    freopen("out.txt","w",stdout);
    init();
    for(int i=2;i<20;++i) {
        n=i;
        ans=0;
        dfs(1);
        printf("%d\n",ans);
    }
    fclose(stdout);
    return 0;
}

