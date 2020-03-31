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
		string s;
		cin>>s;
		//ll int cnt=0;
		string c="",c1="";
		ll int cnt[k][26]={0};
		ll int ma[k]={0};
		char ind[k];
		fab(0,k,i)
		{
			for(int j=i;j<n;j+=k)
			{
				//cout<<"j="<<j<<" ";
				cnt[i][s[j]-'a']++;
				if(cnt[i][s[j]-'a']>ma[i])
				{
					ma[i]=cnt[i][s[j]-'a'];
					ind[i]=s[j];
				}

			}
		}
		ll int ans=0;
	/*	fab(0,k,i)
		cout<<ma[i]<<endl;
		fab(k-2,k,i)
		//cout<<ind[i]<< " ";
		{
			fab(0,26,j)
			cout<<cnt[i][j]<<" ";
			cout<<"\n";
		}*/

		fab(0,k/2,i)
		{
			ll int cc=92345678;
			fab(0,26,j)
			
				cc=min(cc,(2*(n/k)-cnt[i][j]-cnt[k-i-1][j]));
				//ans+=2*(n/k)-ma[i]-cnt[k-i-1][ind[i]-'a'];
				//ans=ans;
				//cout<<ma[i]+cnt[k-i-1][ind[i]-'a']<<" o";
				
			
			
			ans+=cc;
		//	ans+=(n/k)-ma[i];

		}
		//cout<<ans<<endl;
		if(k%2)
			ans+=((n/k)-ma[k/2]);
		//cout<<"k&1:"<<ma[k/2]<<endl;
		cout<<ans<<endl;
		//ll int ma[k];
	
		/*for(int i=0,j=k-1;i<k;j--,i++)
		{
			if(s[i]!=s[j])
			{
				fab(0,26,j)
				{
					if(s[i][j]>max)
					{
						max=s[i][j];
						ind=j;
					}
				}
				if(s[i]!='a'+ind)
				{
					s[i]='a'+ind;
					cnt++;
				}
				if(s[j]!='a'+ind)
				{
					s[j]='a'+ind;
					cnt++;
				}
				
			}
			else
			{
				c+=s[i];
				c1+=s[j];
			}
		}
		string cp=s.substr(0,k);
		cout<<cp<<endl;
		fab(k,n,i)
		{
			if(s[i]!=c[i%k])
				{cnt++;
					//cout<<"i="<<i<<" ";

				}
		}
		cout<<cnt<<endl;*/
	}
	

	return 0;
}