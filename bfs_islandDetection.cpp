#include <bits/stdc++.h>   
using namespace std;   
  
const int N = 1e5 + 10;  
vector<int> graph[N];   
int level[N];   
int parent[N]; 
int visited[N]; 
vector<int> island;
vector<vector<int>> islands;
  
void bfs(int source){   
    level[source] = 0;   
    visited[source] = 1;
    queue<int> q;   
    q.push(source);   
  
    while(!q.empty()){   
        int curr = q.front();  
        island.push_back(curr);
        q.pop();   
  
        for(auto x : graph[curr]){   
            if(visited[x] == -1){    // not visited yet   
                parent[x] = curr;   
                level[x] = level[curr]+1;   
                visited[x] = 1; 
                q.push(x);   
            }   
        }  
    }   
} 
  
int main(){   
   
    int node,edge,a,b;   
    cin >> node >> edge;   
   
    for(int i=0 ; i<edge ; i++){   
        cin >> a >> b;   
        graph[a].push_back(b);   
        graph[b].push_back(a);   
    }   
  

    for(int i=1 ; i<=node ; i++){   
       cout << i << " :  ";   
       for(int j=0 ; j<graph[i].size() ; j++){   
            cout << graph[i][j] << " ";   
       }   
       cout << endl;   
    }   
  
    for(int i=1 ; i<=node; i++)  
        level[i] = -1;  
         
    for(int i=1 ; i<=node; i++)  
        visited[i] = -1; 
      
    for(int i=1 ; i<=node; i++)  
        parent[i] = i;  
     
    for(int i=1; i<=node ; i++){ 
      if(parent[i] == i){ 
        bfs(i); 
        
        islands.push_back(island);
        island.clear();
      } 
    } 
     
    cout << "level: ";  
    for(int i=1 ; i<=node; i++)  
        cout << level[i] << " ";   
   
    cout << endl; 
     
    cout << "visited: ";  
    for(int i=1 ; i<=node; i++)  
        cout << visited[i] << " ";   
   
    cout << endl; 
  
    cout << "parent: ";  
    for(int i=1 ; i<=node; i++)  
        cout << parent[i] << " ";   
   
    cout << endl << endl;   

    cout << "there are " << islands.size() << " islands." << endl << endl;
    
    for(auto vec: islands){
      for(auto it: vec){
        cout << it << " ";
      }
      cout << endl;
    }
     
    for(int i=1 ; i<=node; i++)  
      visited[i] = -1;  
     
    return 0;
}  

/*
8 5
1 2 
2 3 
4 5 
6 8 
6 7
*/ 