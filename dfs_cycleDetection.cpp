#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 10; 
vector<int> graph[N]; 
bool visited[N]; 
int rootNode[N];
int cycleState[N];
int cycle=0;

void dfs(int vertex,int parent){ 

  if(visited[vertex]) 
    return; 

  cout << "vertex: " << vertex << endl;   
  visited[vertex] = true;  
  cycleState[vertex] = 0;

  for(auto child : graph[vertex]){ 
    

    if(child != parent){
      cout << "par: " << vertex << " child: " << child << endl;
      if(cycleState[child] == 0)
        cycle = 1;
      
      dfs(child, vertex);
    }
  }    

  cycleState[vertex] = 1;
} 

int main() { 
   int n,m; 
   cin >> n >> m; 

   for(int i=0 ; i<m ; i++){ 
     int v1,v2; 
     cin >> v1 >> v2; 

     graph[v1].push_back(v2); 
     graph[v2].push_back(v1); 
   } 

   for (int i=1; i<=n; i++){
      cycleState[i] = -1;
   }
   
   dfs(1,1); 

   cout << "cycle's existence: " << cycle << endl;

   // for (int i=1; i<=n; i++){
   //    cout << endl << cycleState[i] << endl;
   // }

} 

/*
8 10
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
7 8  //island
*/