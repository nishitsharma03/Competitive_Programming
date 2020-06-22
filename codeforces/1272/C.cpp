//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
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

void numberofsubstrings(ll n,ll k,bool available[],string s)
{
	ll lastpos=-1;
	ll ans=n*(n+1);
	ans/=2;
	fab(0,n,i)
	{
		if(available[s[i]-'a']==0)
		{
			ll k=(i-lastpos);
			ans-=(k*(n-i));
			lastpos=i;
		}
	}
	cout<<ans<<endl;
	
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif	
    string s;
   	ll n,k;
   	cin>>n>>k>>s;
   	bool available[26]={0};
   	 fab(0,k,i)
   	 {
   	 	char a;
   	 	cin>>a;
   	 	available[a-'a']=1;
   	 }
   	 numberofsubstrings(n,k,available,s);

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}