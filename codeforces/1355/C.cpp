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
ll int pref[int(1e6)+6];
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t=1;
	//cin>>t;
	while(t--)
	{
		ll int a,b,c,d;
		cin>>a>>b>>c>>d;
		//int pref[d+5]={0};
		fab(a,b+1,i)
		{
			pref[i+b]++;
			pref[c+i+1]--;

		}
		ll int ans =0;
		fab(1,1e6+2,i)
		pref[i]+=pref[i-1];
		fab(1,1e6+2,i)
		pref[i]+=pref[i-1];
		fab(c,d+1,i)
	{	ans+=pref[int(1e6+1)]-pref[i];
		
	}
		cout<<ans<<endl;
	}
	

	return 0;
}