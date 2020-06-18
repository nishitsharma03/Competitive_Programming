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
ll dp[1000000][11];

/*ll recurse(int pos,int tot)
{
	if(tot>10)
		return 0;
	if(dp[pos][tot]!=-1)
		return dp[pos][tot];

	fab(0,tot,i)
	dp[pos][tot]+=recurse(pos-1,tot-i);

}*/

ll power(ll x, ll y) 
{ 
    ll res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll k;
	cin>>k;

	//cout<<"rep:"<<rep<<" "<<cnt<<endl;
	string s="codeforces";
	ll v[10];
	fab(0,10,i)
	v[i]=1;
	ll prod=1;
	ll tim=0,i=0;
	while(prod<k)
	{
		v[i]++;
		i++;
		i%=10;
		prod=1;
		fab(0,10,j)
		prod*=v[j];
	}
	fab(0,10,i)
	{
		fab(0,v[i],j)
		cout<<s[i];


	}


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}