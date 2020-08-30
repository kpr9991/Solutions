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
    #define int long long
    checkOnlineJudge();
    int no, add=0;
    cin>>no;
    int var;
    cin>>var;
    map<string, int> d, h;
    h["F"] = 0;
    while(var--){
        string naam;
        int a, b;
        cin>>naam>>a>>b;
        d[naam] = b/a;
        h[naam] = b;
        add+=b;
    }
    cin>>var;
    while(var--){
        string naam, c1="", c2="";
        cin>>naam;
        int meflux=0;
        while(meflux<naam.length()){
            if(naam[meflux]=='_'){
                c1 = c2;
                c2 = "";
                meflux++;
                continue;
            }
            c2+=naam[meflux++];
        }
        h[c2]+= h[c1];
    }
    map<string, int>::reverse_iterator a= d.rbegin();
    int multiply = 1;
    for(; a!=d.rend(); a++ ){
        int temperature = a->second*multiply;
        if(temperature<no){
            add+=(h[a->first]*(no-temperature));
            multiply++;
        }
    }
    cout<<add;
}