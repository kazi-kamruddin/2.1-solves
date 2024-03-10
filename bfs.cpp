#include <bits/stdc++.h> 
using namespace std; 

const int N = 1e5 + 10;
vector<int> graph[N]; 
int level[N]; 
int parent[N]; 

void bfs(int source){ 
    level[source] = 0; 
    queue<int> q; 
    q.push(source); 

    while(!q.empty()){ 
        int curr = q.front(); 
        q.pop(); 

        for(auto x : graph[curr]){ 
            if(level[x] == -1){    // not visited yet 
                parent[x] = curr; 
                level[x] = level[curr]+1; 
                q.push(x); 
            } 
        } 
    } 
} 

void pathFinder(int node){ 
    if(node != parent[node]) 
      pathFinder(parent[node]); 
       
    cout << node << endl; 
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
        parent[i] = i;

    bfs(1); 

    cout << "level: ";
    for(int i=1 ; i<=node; i++)
        cout << level[i] << " "; 

    cout << endl; 

    cout << "parent: ";
    for(int i=1 ; i<=node; i++)
        cout << parent[i] << " "; 

    cout << endl << endl; 

    cout << "route from 1 to 4 : " << endl; 
    pathFinder(4); 

    return 0; 
}
