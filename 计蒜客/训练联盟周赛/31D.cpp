#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+5;
ll a[1005],b[1005];
ll dp[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    while(cin>>n>>m&&n+m)
    {
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            a[i]=(b[i]-a[i]+m)%m;
        }
        memset(dp,0x3f,sizeof dp);
        for(int i=0;i<n;i++) dp[1][i]=a[1]+i*m;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j]+max(0ll,a[i]-a[i-1]));
                if(j>0) dp[i][j]=min(dp[i-1][j-1]+m+a[i]-a[i-1],dp[i][j]);
                dp[i][j]=min(dp[i-1][j+1],dp[i][j]);
            }
 
        }
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<n;i++) ans=min(ans,dp[n][i]);
        cout<<ans<<endl;
    }
 
 
    return 0;
}
