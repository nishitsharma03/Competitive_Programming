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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		ll int n;
		cin>>n;
		ll int k=n/2,ans=0,cnt=n-1;
		/*while(k>0)
		{
			//cout<<((n-1)*k+1)<<"fg\n";
			ans+=(cnt*4*k);
			k--;
			cnt--;

		}*/
		ll int p=n;
		fab(0,n/2,i)
		{
			ans+=((p+p-1+p-1+p-2)*(n/2-i));
			//cout<<"ans:"<<ans<<endl;
			p-=2;
		}
		cout<<ans<<endl;
	}
	

	return 0;
}