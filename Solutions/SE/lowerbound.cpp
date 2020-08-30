#include<bits/stdc++.h>
using namespace std;
 void checkOnlineJudge()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output1.txt","w",stdout);
 #endif
}
int main(){
	checkOnlineJudge();
	int arr[]={1,2,3};
	auto itr=lower_bound(arr,arr+3,-4);
	if(itr==arr+3
		cout<<*itr<<endl;
	else 
		cout<<*itr;
	return 0;
}