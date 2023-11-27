#include <bits/stdc++.h>

using namespace std;
const int N=1e3+10;
const int mod=1e9+7;
const int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,mp[N][N],p;
int cnt[N*N][5];
long long ans=0;
struct node{
    int val,x,y,z;
}nd[N*N];

bool cmp(node a,node b){
    return a.val<b.val;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        int v;
        cin>>v;
        mp[i][j]=v;
        nd[++p].val=v;
        nd[p].x=i;
        nd[p].y=j;
        nd[p].z=(i-1)*m+j;
    }
    for(int i=1;i<=p;i++)
    {
        bool f=0;
        for(int j=0;j<4;j++)
        {
            int nx=nd[i].x+mv[j][0],ny=nd[i].y+mv[j][1];
            if(nx<=0||nx>n||ny<=0||ny>m||mp[nx][ny]!=nd[i].val-1) continue;
            f=1;
        }
        if(f==0) cnt[nd[i].z][1]=1;
    }
    sort(nd+1,nd+1+p,cmp);
    for(int i=1;i<=p;i++)
    {
        bool f=0;
        for(int j=0;j<4;j++)
        {
            int nx=nd[i].x+mv[j][0],ny=nd[i].y+mv[j][1];
            if(nx<=0||nx>n||ny<=0||ny>m||mp[nx][ny]!=nd[i].val+1) continue;
            int nz=(nx-1)*m+ny;
            f=1;
            for(int k=2;k<5;k++)
                cnt[nz][k]=(cnt[nz][k]+cnt[nd[i].z][k-1])%mod;
            cnt[nz][4]=(cnt[nz][4]+cnt[nd[i].z][4])%mod;
        }
        if(f==0) ans=(ans+cnt[nd[i].z][4])%mod;
    }
    cout<<ans<<endl;
    return 0;
}