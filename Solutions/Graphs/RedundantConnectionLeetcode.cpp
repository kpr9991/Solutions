//Just common sense.
//Union find algorithm use chesi chaala cheyachchu.
// 2.Cycle detection in un-directed  graph ki use avuthundi.(Not for directed)
// 3.Edges lo unna nodes ni one by one teesukuni aa nodes same set lo unnaya different set lo unnaya ani kanukkuntam.
// 4.Yela ante aa two nodes ki absroots kanukkuntam and absroots same vaste aa two nodes okkate set lo unnattu.
// 5.So if aa two nodes okkate set lo unnay anuko , aa two nodes already some way or the other connected ani ala vunte,
// Ee koththa edge inkoti add chesam ante cycle form avuthundi kadha.So 
// 6.Thus aa edge yedhi aa edge lo unna nodes yevi anedi kanukkovali adhe question.

//Union find Time Complexity O(V+E)    ("Tech dose channel Youtube lo chuudu if any doubts")
class Solution {
public:
    vector<int> dsuf;                                       //Disjoint set union find ane peru ni short form lo raasa.Prathi node ki absoulute root kanukkovali       
                                                            //ee vector ni use chestam.
   int findabs(int node){                                    
        if(dsuf[node]==-1)   
            return node;
        return findabs(dsuf[node]);                            //Idhi usual findabs ante absolute root of node kanukkuntundi.
    }
    void union_op(int node1,int node2)                          //Two nodes ni union cheyatam ante vaati absolute roots ni union cheyatam, ikkada absolute roots ne pass
        dsuf[node1]=node2;                                      //chesa arguments ni, okavela normal ga two nodes ni pass cheste, x=findabs(node1) y=findabs(node2) ila chesi
                                                                //absroots kanukkoni dsfu[x]=y ani join cheyali or else just dsfu[node1]=node2;
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsuf.clear();
        int rows=edges.size();
        vector<int> final;
        if(rows==0)
            return final;
       dsuf.resize(rows+1,-1);                                   //Idhi first time chustunna.Ila chesi kuuda vector ni initialize cheyachchu.Deeni size
                                                                  //Question lo yenni nodes ichcharo anni nodes tho initialize cheyali.Ikkada +1 because 1 based indexing.
        
        for(int i=0;i<rows;i++){
            int node1=edges[i][0];
            int node2=edges[i][1];
            int absroot1=findabs(node1);
            int absroot2=findabs(node2);
            if(absroot1==absroot2){                                    //Idhi normal same absroots ayithe cycle cause chese edge adhe ani.
                final.push_back(node1);                        
                final.push_back(node2);
                return final;
            }
            union_op(absroot1,absroot2);                               //Absroots ni union cheyali yendukante akkada manam nodes ni join chesi graph build chestunnatuu.Oka node
                                                                        //Two nodes ki same absroots ante rendu already vere node tho connected ani.Alantappudu ee koththa edge vesthe 
                                                                          //cycle form avuthundi ga.Thats  it.
              
        }
        return final;
        
    }
};
