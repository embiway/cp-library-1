/*
    Binary lifting is a very important tree technique which is mostly used for LCA problems but can also serve other important purposes
*/

#include <bits/stdc++.h>
using namespace std;

const int l = 32;       //maximum height that tree can take

int timer;      //timer variable . Maintains the current time
vector<int> tin , tout;         //tin -> stores the time at which a node enters the dfs     tout -> time at which node exits dfs
vector<vector<int>> up;         //used for binary lifting  up[node][height] stores the (2 ^ height)th ancestor of node
vector<vector<int>> adj;          //adjacency list of tree

void dfs(int u , int v){
    tin[u] = ++timer;
    up[u][0] = v;       //immediated ancestor of u is its parent
    for(int i = 1 ; i < l ; i++){
        up[u][i] = up[up[u][i-1]][i-1];         //binary lifting
    }

    for(auto it : adj[u]){
        if(it != v){
            dfs(it , u);
        }
    }

    tout[u] = ++timer;
}

bool is_ancestor(int u , int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
    //fundamental condition to check if u is an ancestor of v;
}

int lca(int u , int v){
    if(is_ancestor(u , v))return u;
    if(is_ancestor(v , u))return v;

    for(int i = l - 1 ; i >= 0 ; i--){
        if(!is_ancestor(up[u][i] , v)){
            u = up[u][i];
            //we're trying to find the highest element which is an ancestor of u but not v
            //the parent of this node would be our required lca
        }
    }

    return up[u][0];
}

void preprocess(int n , int root){
    tin.resize(n+1);
    tout.resize(n+1);
    up.resize(n+1 , vector<int>(l , 0));
    timer = 0;
    dfs(root , root);
}