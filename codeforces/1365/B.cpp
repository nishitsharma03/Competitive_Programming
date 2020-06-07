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
		int n;
		cin>>n;

		bool ok=true;
		ll a[n],b[n];
		fab(0,n,i)
		cin>>a[i];
		fab(0,n,i)
		cin>>b[i];
		fab(1,n,i)
		{
			if(a[i]<a[i-1])
				{ok=false;
			break;}

		}
		if(ok or n==1)
			{
				cout<<"Yes\n";
				continue;
			}
			int cnt1=0,cnt2=0;
		fab(0,n,i)
		{
			if(b[i]==0)
				cnt1++;
			else
				cnt2++;
			/*ll small=1e9;
			int ind=i;
			fab(i,n,j)
			{
				if(small>a[j])
				{
					small=a[j];
					ind=j;
				}

			}
			if(ind==i)
				{continue;
					ok=true;
				}
			int tp=b[ind];
			 ok=false;
			fab(i,n,j)
			{

				if(b[j]!=tp)
				{
					swap(b[j],b[ind]);
					swap(a[j],a[ind]);
					ok=true;
					break;
				}
			}
			if(!ok)
				break;*/

		}
		
		if(cnt1>0 and cnt2>0)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}