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
		ll int n,k;
		cin>>n>>k;
		ll int a[n];
		fab(0,n,i)
		cin>>a[i];
		pair<ll int,ll int> las[n];
		las[0]=mp(0,0);

		vector<ll int> v; 
		ll int cnt=0,lat=0;;
		fab(1,n,i)
		{
			if(a[i]>a[i-1] and a[i]>a[i+1])
				{
					cnt++;
					lat=i;
				}
				las[i]=mp(lat,cnt);
		}
		/*fab(0,n,i)
		{
			cout<<"las:"<<las[i].f<<" "<<las[i].se<<endl;
		}*/
		ll int maxi=0,st=0;
		fab(1,n-k+2,i)
		{
			ll int tot=las[i+k-3].se-las[i-1].se;
			if(tot>maxi)
			{
				maxi=tot;
				//cout<<"check:"<<i+k-2<<endl;
				st=las[i+k-3].f;
			}
			//cout<<"maxi::"<<maxi<<" "<<st<<endl;
		}
		st=max((ll int)0,st+1-(k-1));
		cout<<maxi+1<<" "<<st+1<<endl;
	}
	

	return 0;
}