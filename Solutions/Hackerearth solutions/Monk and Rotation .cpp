#include<bits/stdc++.h>
using namespace std;
int main(){
	#define int long long
	int t;
	cin>>t;
	while(t--){
		vector<int> v;
		int n;
		cin>>n;
		int k=0;
		cin>>k;
		int x=0;
		k=k%n;
		for(int i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		for(int i=n-k;i<n;i++){
			cout<<v[i]<<" ";
		}
		for(int i=0;i<n-k;i++)
		cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;

}
