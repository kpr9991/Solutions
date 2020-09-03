//Journey to the moon 
1.Idea:-->Components kanukkuni each component lo unna nodes ni kanuukoo.
2.Aa nodes yokka pairs of combinations kanukko.
3.Return 
Common sense -> x->y edge undi ante y->x kuuda undela rasko.Because graph is undirected.
Ee point change testhundi ani yela cheptav : -->  
1.Simple suppose 1->2 edge mark chesav anuko and 2->1 mark cheskoledhu anuko.Now suppose 2 daggara start chesav anuko,
1 ni reach avvalev dfs traversal lo , but 1 and 2 connected and not direct kadha ! Thus conclusion is 1->2 edge undi and graph undirected ante,
adjacency list chesetappudu just add 2->1 also.

void dfs(vector<int> adj[],int node,vector<bool> &visited,int &nodecount){
    cout<<node<<" ";
visited[node]=true;
nodecount++;
for(auto i:adj[node]){
if(visited[i]==false)
    dfs(adj,i,visited,nodecount);
}
return ;
}
long journeyToMoon(int n, vector<vector<int>> astronaut) {
    if(n==0)
    return 0;
    vector<int> adj[n];
    for(auto i:astronaut){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }


vector<bool> visited(n,false);
long ans=0;
long long sum=0;
vector<long> nodebucket;
for(int i=0;i<n;i++){
    if(visited[i]==false)
    {
    int nodecount=0;
    dfs(adj,i,visited,nodecount);
    nodebucket.push_back(nodecount);
    }
}
for(int i=0;i<nodebucket.size();i++){     //Idhi konchem think chey pairs yela form cheyali ani.
    for(int j=i+1;j<nodebucket.size();j++){
        ans+=nodebucket[i]*nodebucket[j];
    }
}
return ans;
}
