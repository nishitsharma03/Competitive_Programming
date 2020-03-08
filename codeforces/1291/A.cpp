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
		string s;
		cin>>s;
		bool f=false;
		int sum=0;
	//	fab(0,n,i)
	//	sum+=s[i]-'0';
		int cnt;
		fab(0,n,i)
		{
			if((s[i]-'0')%2)
				sum++;
			if(sum==2)
			{
				cnt=i;
				f=true;
				break;
			}
		}

		if(!f)
			cout<<-1<<endl;
		else
		{
			fab(0,cnt+1,i)
			cout<<s[i];
			cout<<endl;
		}
	}
	

	return 0;
}