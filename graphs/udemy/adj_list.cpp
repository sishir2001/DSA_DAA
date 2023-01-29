// #include<iostream>
// #include<list>
#include<bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	list<int> *l;
public:
	Graph(int v){
		this->V = v;
		this->l = new list<int>[this->V];
	}

	void add_edge(int i,int j,bool undir = true){
		// @param i : from node 
		// @param j : to node 
		// @param undir : is it undirected

		// adding edge from i to j , outgoing
		this->l[i].push_back(j);
		if(undir)
			this->l[j].push_back(i);
	}

	void bfs(int source){
		// graph stored in array of lists
		// !T(N) = O(V+E)
		vector<bool> visited(this->V,false);
		queue<int> q;
		q.push(source);
		visited[source] = true;
		while(!q.empty()){
			int u = q.front();q.pop();
			for(auto v : this->l[u]){
				// doubly linked list in STL
				if(!visited[v]){
					visited[v] = true;
					q.push(v);
				}
			}
			cout << u << " ";
		}
		cout << "\n";
	}

	void dfs_recursion(vector<int> &visited,int i ){
		if(i >= this->V)
			return;
		visited[i] = 1;
		cout << i << " ";
		for(auto v : this->l[i]){
			if(!visited[v]){
				dfs_recursion(visited,v);
			}
		}
		return;
	}

	void dfs(){
		vector<int> visited(this->V,0);
		for(int i = 0;i < this->V;i++){
			if(!visited[i]){
				dfs_recursion(visited,i);
			}
		}
		return;
	}

	void shortest_dist_from_source(int source){
		// similar to bfs
		// !T(N) = O(V+E)
		// !S(N) = O(V)
		vector<int> distance(this->V,0);
		vector<bool> visited(this->V,false);
		queue<int> q;
		q.push(source);
		visited[source] = true;
		while(!q.empty()){
			int f = q.front();q.pop();
			for(auto v : this->l[f]){
				// list
				if(!visited[v]){
					visited[v] = true;
					q.push(v);
					distance[v] = distance[f]+1;
				}
			}
		}

		// printing the shortest distance from source
		for(int i = 0;i < this->V;i++){
			cout << i << " : " << distance[i] <<"\n";
		}
		return;
	}

	void shortes_path_from_source(int source){
		// !T(N) = O(V+E)
		// !S(N) = O(V)
		vector<string> path(this->V,""+to_string(source));
		vector<bool> visited(this->V,false);
		queue<int> q;
		q.push(source);
		visited[source] = true;
		while(!q.empty()){
			int f = q.front();q.pop();
			for(auto v : this->l[f]){
				if(!visited[v]){
					visited[v] = true;
					q.push(v);
					path[v] = path[f]+to_string(v);
				}
			}
		}
		// print the path from source
		for(int i = 0;i < this->V;i++){
			cout << i << " : " <<path[i] << "\n";
		}
		return;
	}

	void print_adj_list(){
		for(int i = 0;i < this->V;i++){
			cout << i << " -> ";
			for(auto node : this->l[i])
				cout << node << ",";
			cout << "\n";
		}
	}
};


int main(){
	#ifndef ONLINE_JUDGE
	  freopen("input.txt","r",stdin);
	  freopen("output.txt","w",stdout);
	#endif
	Graph g(7);
	g.add_edge(0,1);
	g.add_edge(0,4);
	g.add_edge(2,1);
	g.add_edge(3,4);
	g.add_edge(4,5);
	g.add_edge(2,3);
	g.add_edge(3,5);
	g.add_edge(5,6);

	g.print_adj_list();
	// g.bfs(1);
	// cout << "\n";
	// g.shortest_dist_from_source(1);
	// cout << "\n";
	// g.shortes_path_from_source(1);
	g.dfs();
}

