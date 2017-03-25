#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class disjointSet{

	private:
		vector<int> v, rank;

	public:
		disjointSet(int n){
			v.resize(n);
			rank.resize(n);
			for(int i=0 ; i<n; i++){
				v[i] = i;
			}
		}

		void mostrarSet(){
			int sz = v.size();
			for(int i=0; i<sz;i++){
				cout << v[i] << " ";
			}
			cout << endl;
		}

		int findSet(int x){
			if(v[x]==x)
				return x;
			else
				return findSet(v[x]);
		}

		void joinSet(int a, int b){
			int x,y;
			x = findSet(a);
			y = findSet(b);

			v[x] = y;
		}

		bool isSameSet(int a, int b){
			int x,y;
			x = findSet(a);
			y = findSet(b);
			return x==y;
		}
};