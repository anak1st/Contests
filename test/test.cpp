#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
pair<int,int> p[1000010];
int fu[1000010];
int num[1000010];
int n;
vector<int> v[1000010];
int vis[1000010];
int mypow(int a,int q)
{
	int ans=1;
	int tem=a;
	while(q)
	{
		if((q&1)==1) ans=1ll*ans*tem%N;
		tem=1ll*tem*tem%N;
		q>>=1;
	}
	return ans%N;
}


int Find(int x)
{
	if(fu[x]==x) return x;
	return fu[x]=Find(fu[x]);
}
int f[1000010];
void dfs(int x)
{
	int len=v[x].size();
	for(int i=0;i<len;i++)
	{
		int son=v[x][i];
		if(vis[son]) continue;
		vis[son]=1;
		f[son]=x;
		dfs(son);
	}
}
long long ans=1;
int che()
{
	for(int i=1;i<n;i++)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vis[1]=1;
	f[1]=1;
	dfs(1);
	for(int i=1;i<n;i++) 
	{
		int a,b;
		a=p[i].first;b=p[i].second;

		int fa=Find(a),fb=Find(b);
		ans=((1ll*ans*num[fa])%N*num[fb])%N;
		if(fa==fb) return false; 
		if(Find(f[fa])==fb) fu[fa]=fb,num[fb]=(1ll*num[fb]+num[fa])%N;
		else if(Find(f[fb])==fa) fu[fb]=fa,num[fa]=(1ll*num[fa]+num[fb])%N;
		else return -1;
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) fu[i]=i,num[i]=1;
	for(int i=1;i<n;i++) 
	{
		int a,b;cin>>a>>b;
		p[i]=make_pair(a,b);

	} 
	for(int i=1;i<=n;i++) fu[i]=i;
	if(che()!=-1) cout<<mypow(ans,N-2);
	else cout<<0;
	return 0;
}