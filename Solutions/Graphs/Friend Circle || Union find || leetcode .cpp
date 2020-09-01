//Adjacency matrix ichchad ikkada,and most important point usual ga nodes ichchinte vaatini kaluputham union find algorithm lo but ikkada nodes ,
//yevi ante matrix ante indices eh nodes ani kadha . Adhi common sense.
//so thus,union(i,j) ante two nodes (Two friends) ni merge chestunnam ani.
//2.Ala one ani kanipiste matrix lo aa i,j ki edge unnattu so aa edges ni connect chey.Ila graph form chey.
//3.Anni edges connect cheste final ga form ayye dsfu vector lo yenni -1's unte anni components unnattu.

class Solution {
public:
    vector<int> dsfu;
    void union_op(int node1,int node2){
        int absroot1=findabs(node1);
        int absroot2=findabs(node2);
        if(absroot1!=absroot2)                 //Same set lo unnay ante union cheyalsina avasram ledu.
        dsfu[absroot1]=absroot2;              //Idhi okka fuckingly important point, rendu nodes same set lo lekunte,absolute roots ni union cheyali and vaati nodes ni kaadhu.
    }
    int findabs(int node1)
    {
        if(dsfu[node1]==-1)
            return node1;
        return findabs(dsfu[node1]);
    }
    int findCircleNum(vector<vector<int>>& M) {
        dsfu.clear();
        int rows=M.size();
        if(rows==0)
            return 0;
        dsfu.resize(rows,-1);
        
        int cols=M[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(M[i][j]==1){      
                    union_op(i,j);                       //1's ni union cheyatam yendi.
                }
            }
        }
        int count=0;
        for(auto i:dsfu){
            if(i==-1)
                count++;
        }
        return count;
    }
};
