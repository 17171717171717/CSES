// https://codeforces.com/contest/2107/submission/318485890

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define LL0 (ll)0
int t,n;
ll a,k;
char rem[2001000];
ll dt[200100],l[200100],r[200100],best;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k>>(rem+1);
		l[0]=r[n+1]=0;
		for(int i=1;i<=n;i++){
			cin>>dt[i];
			if(rem[i]=='0'){
				dt[i]=-1e18;
			}
			l[i] = max(l[i-1]+dt[i],dt[i]);
		}
		for(int i=n;i>=1;i--){
			r[i] = max(r[i+1]+dt[i],dt[i]);
		}
		for(int i=1;i<=n;i++){
			if(rem[i]=='0'){
				dt[i] = k-max(LL0,l[i-1])-max(LL0,r[i+1]);
				break;
			}
		}
		best = dt[1];
		for(int i=n;i>=1;i--){
			r[i] = max(r[i+1]+dt[i],dt[i]);
			best = max(best, r[i]);
		}
		if(best==k){
			cout<<"Yes"<<endl;
			for(int i=1;i<=n;i++)cout<<dt[i]<<" ";
			cout<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
} 