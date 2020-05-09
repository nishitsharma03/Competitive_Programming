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
		ll int a[n];
		fab(0,n,i)
		cin>>a[i];
		ll int suma=0,sumb=0,curra=0,currb=0,cnt=0;
		int i=0,j=n-1;
		while(i<=j)
		{
			if(cnt%2==0)
			{
				curra=0;
				while(i<=j and curra<=currb)
				{
					suma+=a[i];
					curra+=a[i];
					i++;
				}
			}
			else
			{
				currb=0;
				while(j>=i and currb<=curra)
				{
					sumb+=a[j];
					currb+=a[j];
					j--;
				}
			}
			cnt++;

		}
		cout<<cnt<<" "<<suma<<" "<<sumb<<endl;
	}
	

	return 0;
}