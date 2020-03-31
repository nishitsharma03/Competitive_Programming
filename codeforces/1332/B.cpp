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
		vector<int> prim={2,3,5,7,11,13,17,19,23,29,31};int col[n]={0};
		int cnt=1;
		fab(0,11,i)
		{
			bool flag=false;
			fab(0,n,j)
			{
				if(col[j]==0&&a[j]%prim[i]==0)
					{col[j]=cnt;
						flag=true;
					}
			}
			if(flag)
				cnt++;
		}
		cout<<*max_element(col,col+n)<<endl;
		fab(0,n,i)
		cout<<col[i]<<" ";
		cout<<endl;
	}
	

	return 0;
}