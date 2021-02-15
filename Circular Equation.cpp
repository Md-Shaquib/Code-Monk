#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#ifndef ONLINE_JUDGE
#define deb(x) cout<<#x<<" : "<<x<<"\n";
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
#define deb_arr(a,n) {cout<<#a<<":";for(int i=0;i<n;i++) {cout<<a[i]<<" ";} cout<<'\n';}
#define deb_mat(dist,n,m) {cout<<#dist<<"\n";for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<dist[i][j]<<" ";}cout<<'\n';}}
#else
#define deb(x) ;
#define debug(x,y) ;
#define deb_arr(a,n) ;
#define deb_mat(dist,n,m) ;
#endif
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define all(a) (a).begin(),(a).end()
#define bs binary_search
#define sz size()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double
#define clr fflush(stdout);
//#define clr cout.flush();
#define N 200001
#define fpr(i,a,b) for(int i=a;i<b;i++)
#define fdr(i,a,b) for(int i=a;i>b;i--)
#define repp(i,a,b,d) for(int i=a;i<b;i+=d)
#define repd(i,a,b,d) for(int i=a;i>b;i-=d)
#define LLMIN LLONG_MIN
#define LLMAX LLONG_MAX
#define AKASH_PATEL ios_base::sync_with_stdio(false);
#define SVNIT_SURAT cin.tie(NULL);cout.tie(NULL);
#define mset(x,a) memset(x,a,sizeof(x));
#define nl cout<<'\n';
#define print(c) cout<<c<<'\n';
#define setp(n) cout << fixed << setprecision(n)
#define take_arr(a,n) fpr(i,0,n) cin>>a[i];
#define print_arr(a,n) for(int i=0;i<n;i++) {cout<<a[i]<<" ";} cout<<'\n';
#define take_mat(mat,n,m) fpr(i,0,n) fpr(j,0,m) cin>>mat[i][j];
#define set_mat(mat,n,m,k) fpr(i,0,n) fpr(j,0,m) mat[i][j]=k;
#define print_mat(dist,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<dist[i][j]<<" ";}cout<<'\n';}
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > bool odd(T a) { return a&1; }
template< class T > bool even(T a) { return !(a&1); }
ll am(ll a,ll b)
{
    return (a+b)%mod;
}
ll sm(ll a,ll b)
{
    return (a-b+mod)%mod;
}
ll mm(ll a,ll b)
{
    return (a*b)%mod;
}
long long modpower(long long x,long long n)
{
    ll m=mod;
    long long ans=1;
    x=(x+m)%m;
    while(n>0)
    {
        if(n&1)
        {
            ans=(ans*x)%m;
        }
        n=n>>1;
        x=(x*x)%m;
    }
    return ans;
}
ll dm(ll a,ll b)
{
    return (a*modpower(b,mod-2))%mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../ip.txt", "r", stdin);
    freopen("../op.txt", "w", stdout);
#else
    AKASH_PATEL;
    SVNIT_SURAT;
#endif
#ifdef ONLINE_JUDGE
    int t;
    cin>>t;
    ll dp[19][391];
    dp[0][0]=1;
    fpr(i,1,19)
    {
        fpr(j,1,391)
        {
            fpr(k,0,10)
            {
                if(j>=k)
                {
                    dp[i][j]=am(dp[i][j],dp[i-1][j-k]);
                }
            }
        }
    }
    while(t--)
    {
#endif
        ll n;cin>>n;
        ll cnt=0;
        ll tp=n;
        while(tp)
        {
            cnt++;tp/=10;
        }
        string s="";
        ll ans=0;
        fpr(i,1,cnt+1) {
            s += '1';
            ll sum = stoll(s);
            if (n % sum) {
                continue;
            }
            tp=n/sum;
            if(tp>391) continue;
            fpr(j,1,i+1)
            {
                ans=am(ans,dp[j][tp]);
            }
        }
        print(ans)
#ifdef ONLINE_JUDGE
    }
#endif
    return 0;
}