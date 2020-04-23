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
		ll int a[n],pos[n+1];
		fab(0,n,i)
		{
			cin>>a[i];
			pos[a[i]]=i;

		}
		string ans="YES";
		bool term[n+1],check[n+1];
		fab(0,n,i)
		{term[i]=false;
		check[i]=false;}	
		fab(1,n+1,i)
		{
			if(check[i])
				continue;
			ll int  st=pos[i];
			ll int cnt=0;
			fab(st+1,n,j)
			{
				cnt++;
				if(term[j]==true)
					break;
				if(a[j]!=i+cnt)
				{
					ans="NO";
					break;
				}
				else
					check[a[j]]=true;



			}
			term[st]=true;
			if(ans=="NO")
				break;
		}
		cout<<ans<<endl;	

	}
	

	return 0;
}