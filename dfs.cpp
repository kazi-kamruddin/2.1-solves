#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 10; 
vector<int> graph[N]; 
bool visited[N]; 
int rootNode[N];

void dfs(int vertex){ 

  //after entering the vertex

  if(visited[vertex]) 
    return; 

  cout << "vertex: " << vertex << endl;   
  visited[vertex] = true;  

  for(auto child : graph[vertex]){ 
    cout << "par: " << vertex << " child: " << child << endl;

    //before entering the child

    dfs(child); 

    //after exiting the child
  }    

  //before exiting the vertex
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
   
   dfs(1); 

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