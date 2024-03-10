#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10; 
vector<int> graph[N]; 
vector<vector<int>> components; 
vector<int> current; 
int visited[N]; 

void dfs(int vertex){    
  if(visited[vertex]) 
    return; 

  current.push_back(vertex); 
  visited[vertex] = true; 

  for(auto child: graph[vertex]){ 
    dfs(child); 
  } 
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

    int count = 0; 
    for(int i=1; i<=n ; i++){ 
      if(visited[i]) 
        continue; 
      else{ 
        current.clear(); 
        dfs(i); 
        components.push_back(current); 
        count++; 
      } 
    } 

    cout << "total connected components: " << count << endl;
    
    for(auto it: components){ 
      for(auto iitt: it){ 
          cout << iitt << " "; 
      } 
      cout << endl; 
    } 
} 