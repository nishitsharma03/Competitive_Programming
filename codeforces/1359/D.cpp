//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
//#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
const int INF=1e8+3;
ll n;
int a[100005];
pair<int,int> seg1[4*100005],seg2[4*100005],seg3[4*100005];
pair<int,int> maxi(pair<int,int> a,pair<int,int> b)
{
	if(a.f>b.f)
		return a;
	else
		return b;
}
pair<int,int> mini(pair<int,int> a,pair<int,int> b)
{
	if(a.f<b.f)
		return a;
	else
		return b;
}
void build(int node,int s,int e,int arr[],pair<int,int> seg[])
{
	if(s==e)
		{seg[node].f=arr[s];
		seg[node].se=s;}
	else
	{
		int mid=(s+(e-s)/2);
		build(2*node,s,mid,arr,seg);
		build(2*node+1,mid+1,e,arr,seg);
		seg[node]=maxi(seg[2*node],seg[2*node+1]);
	}

}
pair<int,int> query(int node,int s,int e,int l,int r,pair<int,int> seg[])
{
	if(s>r or e<l)
		return mp(-INF,-INF);
	if(l<=s and e<=r)
		return seg[node];
	int mid=(s+(e-s)/2);
	return maxi(query(2*node,s,mid,l,r,seg),query(2*node+1,mid+1,e,l,r,seg));
}
void build2(int node,int s,int e,int arr[],pair<int,int> seg[])
{
	if(s==e)
		{seg[node].f=arr[s];
			seg[node].se=s;}
	else
	{
		int mid=(s+(e-s)/2);
		build2(2*node,s,mid,arr,seg);
		build2(2*node+1,mid+1,e,arr,seg);
		seg[node]=mini(seg[2*node],seg[2*node+1]);
	}

}

pair<int,int> query2(int node,int s,int e,int l,int r,pair<int,int> seg[])
{
	//cout<<"dd:"<<endl;
	if(s>r or e<l)
		{return mp(INF,INF);
		//	cout<<"der";
		}
	if(l<=s and e<=r)
		{return seg[node];
			//cout<<"hti:";
		}
	int mid=(s+(e-s)/2);
	//cout<<"dddfgdf";
	return mini(query2(2*node,s,mid,l,r,seg),query2(2*node+1,mid+1,e,l,r,seg));
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>n;
    fab(0,n,i)
	cin>>a[i];

	build(1,0,n-1,a,seg1);
	int pref[n+1],suff[n+1];
	int sum=0;
	pref[0]=0;
	fab(0,n+1,i)
	{
		sum+=a[i];
		pref[i+1]=sum;
		//cout<<pref[i]<<" ";
	}
	sum=0;
	for(int i=n-1;i>=0;i--)
	{
		sum+=a[i];
		suff[i]=sum;
	}
	int final=0;
	build2(1,0,n,pref,seg2);
	build(1,0,n,pref,seg3);
	fab(0,n,i)
	{
		int j=i;
		int low=0,high=i;
		int ans=i;
		while(low<=high)
		{
			int mid=(low+high)/2;
			if(query(1,0,n-1,mid,i,seg1).f==a[i])
			{
				ans=min(ans,mid);
				high=mid-1;
			}
			else
				low=mid+1;
		}
		int lef=query2(1,0,n,ans,i,seg2).se;
		//int lef=0;
		int sumrange=0;
		if(lef>0)
			sumrange-=pref[lef];
		//cout<<"ans:"<<ans<<" "<<sumrange<<" ";
		ans=i;
		low=i;
		high=n-1;
		while(low<=high)
		{
			int mid=(low+high)/2;
			if(query(1,0,n-1,i,mid,seg1).f==a[i])
			{
				ans=max(ans,mid);
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}

		}
		int ref=query(1,0,n,i+1,ans+1,seg3).se;
		//sumrange-=2*a[i];
		sumrange+=pref[ref];
		sumrange-=a[i];
		//cout<<sumrange<<" "<<ref<<" "<<i<<endl;
		final=max(final,sumrange);
	}
	cout<<final<<endl;
	//fab(0,4*n,i)
	//cout<<seg2[i].f<< " ";
	//cout<<"query check:"<<query2(1,0,n,0,1,seg2).se<<endl;




	return 0;
}