//It can also be solved using Union find algorithm.
//Number of nodes that have the value -1 in dsuf vector after doing union for all the 1's will be the answer.
//1.Union find edges or adjaceny matrix iste use chey.
//2.Adjacency list iste DFS prefer chey.
//3.Union find tho yela solve chestam ante :-
//i)Normal dfs lo ,'1's yekkada vasthayo chuskoni aa 1's ki connected '1's anni traverse chesi mark cheskuntu veltham, ila 
//traverse chesi nappudu enni connected components vasthayo adhe answer.
//ii) Now in the same way , '1' ane number kanapadagane , aa '1' ki unna x and y coordinate eh node kadha so aa nodes ni union function ki pampi
//union chey.
//iii) Now ala anni union chesav ante, dsfu vector lo prathi node ki absolute root dorukuthundi, now aa absolute roots veytiki -1 undo 
//avi vaatiki ave roots ani. Vaatikante paina inka vere levu ani.SO ala yenni -1's unte anni roots unnattu.Ante anni dfs trees unnay ani.
//Ante anni connected components unnayi ani.

//Main thing to observe : Union cheyalsindi i,j ni because ave ga nodes.So "edges" ichchina or "Adjacency matrix" ichchina union cheyachchu, adhe, adjacency 
//list iste,better dfs chey simple ga untundi connected components kanukkuneki.
//Next Friendcircles union find ani inkoti raasa chuudu.inka baaga artham avuthundi.

class Solution {
public:
    void dfs(vector<vector<int> > &graph,vector<bool> &visited,int current,int rows,int cols){
        visited[current]=true;
        for(int j=0;j<cols;j++){
            if(visited[j]==false && graph[current][j]==1){
                dfs(graph,visited,j,rows,cols);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& M) {
        int count=0;
        if(M.size()==0)
            return 0;
        int rows=M.size();
        int cols=M[0].size();
        vector<bool> visited(cols,false);
        int n=cols;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(M,visited,i,rows,cols);
                count++;
            }
            
        }
        return count;
        
    }
};
