#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii; // <peso,nodo>

int main(){
	int s = 0; // NODO ORIGEN!

	//Dijkstra!
	priority_queue<ii, vector<ii>, greater<ii> pq;
	pq.push(ii(0,s));

	while(!pq.empty()){
		ii front = pq.top(); pq.pop();

		int d = front.first; // peso
		int u = front.second; // nodo

		if(d > dist[u]) continue;

		for(int j=0 ; j < AdjList[u].size(); j++){
			ii v = AdjList[u][j]; // todas las salidas del nodo u

			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

