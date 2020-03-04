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
	string s;
	cin>>s;
	int n=s.size();
	vector<int> id,jd;
	int cnt1=0,cnt2=0;
	int j=n-1;
	fab(0,n,i)
	{
		if(s[i]=='(')
			{
				while(j>i)
				{
					if(s[j]==')')
					{
						cnt2++;cnt1++;
				id.pb(i);
						jd.pb(j);
						j--;
						break;
					}
					j--;
				}
				if(j<=i)
					break;

			

			}
		
	}
	if(cnt1==0)
		cout<<0<<endl;
	else
	{
		sort(jd.begin(),jd.end());
		cout<<1<<endl;

		cout<<cnt2+cnt1<<endl;
		fab(0,cnt2,i)
		cout<<id[i]+1<<" ";
		//cout<<endl;
		fab(0,cnt2,i)
		cout<<jd[i]+1<<" ";
		cout<<endl;

	}



	return 0;
}