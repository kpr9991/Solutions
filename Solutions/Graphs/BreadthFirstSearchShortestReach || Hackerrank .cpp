
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    queue<int> q;
    q.push(s);
    vector<bool> visited(n+1,false);     //1 numbered.
    visited[s]=true;
    map<int,int> dist;
    vector<int> adj[n+1];
    for(auto i:edges)           //preparing adjacency list.
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);   
    }


    int level=0;
    while(!q.empty()){  
        int k=q.size();
        level++;
        while(k--){
            int front1=q.front();
             q.pop();
             for(auto i:adj[front1])
            {
                if(visited[i]==false)
                {
                visited[i]=true;
                dist[i]=level;
                q.push(i);
                }
            }


        }
    }
    vector<int> final;
    for(int i=1;i<=n;i++){
        if(visited[i]==false)
        dist[i]=-1;
    }
    for(auto i:dist)
        if(i.second!=-1)
        final.push_back(i.second*6);
        else
        final.push_back(-1);
        return final;


}

