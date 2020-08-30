#include<bits/stdc++.h>
using namespace std;
void checkOnlineJudge()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output1.txt","w",stdout);
 #endif
}
int main()
{
	checkOnlineJudge();
    int numberofDays=0;
    int clusterCount=0;
    unordered_map<string,pair<int,int> > cluster;
    for(int i=0;i<clusterCount;i++)
    {
    	string str;
    	cin>>str;
    	int maxCapacity=0;
    	int perday=0;
    	cin>>perday>>maxCapacity;
    	cluster[str]={perday,maxCapacity};
    }
    int linkscount=0;
    cin>>linkscount;
    unordered_map<string,vector<string> > connect;
    for(int i=0;i<linkscount;i++)
    {
    	string str;
    	cin>>str;
    	if(str[0]=='F')
    	connect["F"].push_back(str.substr(2,2));
    	else
    		connect[str.substr(0,2)].push_back(str.substr(3,2));
    }
    for(auto i:connect){
    	for(auto j:i.second){
    		cout<<j<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}