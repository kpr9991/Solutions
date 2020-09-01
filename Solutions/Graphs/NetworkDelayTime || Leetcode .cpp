//Idhi direct Dijkstra's , just anni nodes ki source nundi distance kanukkovali and return the maximum distance.Because maximum time adigad kabatti.
//Now adjacency matrix prepare chesko first weights tho.
//2.Ee matrix lo weight okavela zero ayina consider cheyali adhe magicccu.
//3.Because zero seconds lo kuuda signal transmit avvagaladhu.
//4.Inka normal logic.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(times.size()==0)
            return -1;
        
        int src=K;
        vector<int> dis(N+1,INT_MAX);
        dis[src]=0;
        
        set<pair<int,int> > s;
        s.insert({0,src});
        pair<int,int> minpair;
        
        vector<vector<int> > adjmatrix(N+1);
       for(int i=0;i<=N;i++){
           vector<int> temp(N+1,INT_MAX);
           adjmatrix[i]=temp;
       }
        
        for(auto i:times)
            adjmatrix[i[0]][i[1]]=i[2];       //Filling adjacency matrix.
        
        
        
        while(!s.empty()){
            minpair=*(s.begin());
            s.erase(minpair);
            int node=minpair.second;
            int curdis=minpair.first;
            for(int i=1;i<=N;i++){
                if(adjmatrix[node][i]!=INT_MAX)
                {
                    int predis=dis[i];
                    if(curdis+adjmatrix[node][i]<dis[i]){
                        dis[i]=curdis+adjmatrix[node][i];
                        s.erase({predis,i});
                        s.insert({dis[i],i});
                    }
                }
            }
        }
        dis.erase(dis.begin());
        auto max=max_element(dis.begin(),dis.end());
        if(*max==INT_MAX)
            return -1;
        else
        return *max;
        
        
        
        
    }
};
