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
		 ll int ans=(n*(n-1)/2);
		 //cout<<ans<<" ";
		 k=ans+1-k;
		string s="";
		ll int ind,sum=0,cnt=0;	
		//cout<<k<<" ";
		for( ind=n-1;ind>=0;ind--)
		{
			sum+=ind;
			//cout<<"ind="<<ind<<" ";
			
			if(sum>=k)
			break;
			cnt++;
		}
		//cout<<sum<<endl<<cnt<<endl<<ind<<endl;
		fab(0,cnt,i)
		s+='a';
		s+='b';
		sum-=ind;
		fab(0,k-sum-1,i)
		s+='a';
		s+='b';
		while(s.size()<n)
			s+='a';
		cout<<s<<endl;
	}
	

	return 0;
}