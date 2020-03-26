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
		ll int t[n];
		fab(0,n,i)
		cin>>t[i];
		bool chk=true;
		fab(0,n,i)
		{
			if(t[i]!=t[0])
		{	chk=false;
			break;
		}


		}
		if(chk)
		{
			cout<<1<<"\n";
			fab(0,n,i)
			cout<<1<<" ";
			cout<<endl;
			continue;
		}
		if(n%2==0||t[0]==t[n-1])
		{
			cout<<2<<"\n";
			fab(0,n,i)
			{
				if(i&1)
					cout<<1<<" ";
				else
					cout<<2<<" ";
			}
			cout<<endl;
			continue;
		}
		ll int saath=-1;
		fab(1,n,i)
		{
			if(t[i]==t[i-1])
			{
				saath=i-1;
				break;

			}
		}
		if(saath!=-1)
		{
			cout<<2<<"\n";
			fab(0,saath,i)
			{
				if(i&1)
					cout<<"1 ";
				else
					cout<<"2 ";

			}
			if(saath&1)
				cout<<"1 1 ";
			else
				cout<<"2 2 ";
			fab(saath+2,n,i)
			{
				if(i&1)
					cout<<"2 ";
				else
					cout<<"1 ";

			}
			continue;
		}
		cout<<3<<"\n";
		fab(0,n-1,i)
		{
			if(i&1)
					cout<<"1 ";
				else
					cout<<"2 ";

		}
		cout<<3<<endl;


		}

	return 0;
}