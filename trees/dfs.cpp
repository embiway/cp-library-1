/*
    Depth first search is a very important algorithm for graphs and trees
*/

#include <bits/stdc++.h>
const int max_n = 1e5 + 9;
std::vector<std::vector<int>> adj;

//for graphs we maintain a visited array for dfs
int visited[max_n];

void depth_first_search(int source){
    
    for(int i = 0 ; i < adj[source].size() ; i++){
        if(!visited[adj[source][i]]){
            depth_first_search(adj[source][i]);
        }
    }
}


//for trees
void depth_first_search(int source , int parent){
    for(int i = 0 ; i < adj[source].size() ; i++){
        if(adj[source][i] != parent){
            depth_first_search(adj[source][i] , parent);
        }
    }
}