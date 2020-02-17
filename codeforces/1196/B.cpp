#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
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
		int n,k;
		cin>>n>>k;
		ll int a[n],sum=0,cnto=0,cnte=0;
		fab(0,n,i)
		{
			cin>>a[i];
			sum+=a[i];
			if(a[i]%2)
				cnto++;
			else
				cnte++;
		}
		if((sum%2==0&&k%2==1)||(sum%2==1&&k%2==0))
		{
			cout<<"NO\n";
		continue;

		}
		if(cnto<k)
		{
			cout<<"NO\n";
			continue;	
		}
		else
		{
			//cout<<"YES\n";
			vector<int> v;
			int odds=0,cnt=0;
			fab(0,n,i)
			{	
				if(cnt==k-1)
					break;

				if(a[i]%2)
				{
					v.pb(i+1);
					cnt++;
					
				}
				
			}
			v.pb(n);
			cout<<"YES\n";
			fab(0,k,i)
			cout<<v[i]<<" ";
			cout<<endl;
		}
	}

	return 0;
}