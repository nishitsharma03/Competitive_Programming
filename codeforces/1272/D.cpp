//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
ll int dp[200005][2];
ll int n,a[200005]; 
int recur(int pos,bool isremoved)
{
	int p=1,q=1;
	if(dp[pos][isremoved]!=-1)
		return dp[pos][isremoved];
	if(pos==n-1)
		return dp[pos][isremoved]=1;

	if(a[pos+1]>a[pos])
		p=1+recur(pos+1,isremoved);
	if( pos+2<n and a[pos+2]>a[pos] and isremoved==false)
		q= 1+recur(pos+2,true);
		//cout<<"pos:"<<pos<<" "<<p<<" "<<q<<endl;
	return	dp[pos][isremoved]=max(p,q);

}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
	cin>>n;
	
	fab(0,n,i)
	cin>>a[i];
	fab(0,2,j)
	fab(0,n,i)
	dp[i][j]=-1;
	ll int ans=recur(0,false);
	fab(0,n,i)
	{
		ll int d=recur(i,0);
		//cout<<"dp[i]:"<<i<<" "<<dp[i]<<endl;
		ans=max(ans,d);
	}
	cout<<ans<<endl;


	return 0;
}