
/**
 *    author        : Saurav Paul 
 *    created       : August 28, 2020 8:57 AM
 *    Problem Name  : Articulation Points
 *    Problem Limit : O(N+M)
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

/*
   Articulation point (or cut vertex) is defined as a vertex which,
   when removed along with associated edges, makes the graph disconnected (or more precisely,
   increases the number of connected components in the graph).
   The task is to find all articulation points in the given graph.
*/

const int INF = 1e9 + 90 ;
int N , M ;
vector<vector<int>> graph ;

vector<bool> vis ;
int timer = 0 ;
vector<int> low , tin ;
set<int> cut_vertex ;

void dfs(int node, int par = -1){
    low[node]=tin[node]=timer++ ;
    vis[node] = true ;
    
    int child = 0 ;
    for(auto nxt : graph[node]){
        if(nxt == par) continue ;
        if(vis[nxt]){
            low[node] = min(tin[node],low[nxt]) ;
        }
        else{
            ++ child ;
            dfs(nxt,node) ;
            low[node] = min(low[node], low[nxt]) ;

            if(tin[node] <= low[nxt] && par != -1){
                cut_vertex.insert(node) ;
            }
        }
    }

    if(par == -1 && child > 1) cut_vertex.insert(node) ;
}

void find_cutpoints(){
    timer = 0 ;
    low.assign(N+1,-1) ;
    tin.assign(N+1,-1) ;
    vis.assign(N+1,false) ;

    for(int i = 1; i <= N ; i++){
        if(!vis[i]){
            dfs(i) ;
        }
    }

    cout << "Articulation points : ";
    for(auto point : cut_vertex) cout << point << " " ;
    cout << endl ;
}


void solve(){
    cin >> N >> M ;

    graph = vector<vector<int>>(N+1) ;

    for(int i = 0 ; i < M ; i++){
        int u , v ;
        cin >> u >> v ;

        graph[u].emplace_back(v) ;
        graph[v].emplace_back(u) ;
    }

    find_cutpoints() ;

}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
