#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
ll mod;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n;
typedef pair<int,int> hashv;
const ll mod1=1000000007;
const ll mod2=1000000009;

hashv operator + (hashv a,hashv b) {
	int c1=a.fi+b.fi,c2=a.se+b.se;
	if (c1>=mod1) c1-=mod1;
	if (c2>=mod2) c2-=mod2;
	return mp(c1,c2);
}

hashv operator - (hashv a,hashv b) {
	int c1=a.fi-b.fi,c2=a.se-b.se;
	if (c1<0) c1+=mod1;
	if (c2<0) c2+=mod2;
	return mp(c1,c2);
}

hashv operator * (hashv a,hashv b) {
	return mp(1ll*a.fi*b.fi%mod1,1ll*a.se*b.se%mod2);
}

const int N=2010000;
hashv pw[N],s[N],t[N];
char tt[N];
int main() {
	scanf("%d", &n);
	n=n*2;
	scanf("%s",tt+1);
	hashv base=mp(13331,23333);
	pw[0]=mp(1,1);
	for (int i=1;i<=n;i++) {
		pw[i]=pw[i-1]*base,s[i]=s[i-1]*base+mp(tt[i],tt[i]);
        std::cout << pw[i].first << " " << pw[i].second << std::endl;
	}
	per(i,1,n+1) t[i]=t[i+1]*base+mp(tt[i],tt[i]);
    
	for (int i=0;i<=n/2;i++) {
		hashv s1=s[i]*pw[n/2-i]+(s[n]-s[i+n/2]*pw[n/2-i]);
		hashv s2=t[i+1]-t[i+1+n/2]*pw[n/2];
		if (s1==s2) {
			per(j,0,n/2) printf("%c",tt[i+1+j]);
			puts("");
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
}
