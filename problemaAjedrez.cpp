#include <bits/stdc++.h>

using namespace std;

int grundy[15][15];
vector<vector<bool> > asignados;

int mov[4][2] = {{-2,1},{-2,-1},{1,-2},{-1,-2}};

int Mex(set<int> s){
	int n=0;
	while(s.find(n)!=s.end()){
		n++;
	}
	return n;
}

bool dentro(int x, int y){

	return (x>=0 && x<15 && y>=0 && y<15 );
}

int grund(int x,int y){
	//ya esta calculado
	if(asignados[x][y])
		return grundy[x][y];

	//no se ha calculado
	set<int> v;

	for(int i=0 ; i<4; i++){ // revisar cada movimiento
		int xx, yy;
		xx = x + mov[i][0];
		yy = y + mov[i][1];
		if(dentro(xx,yy)){
			int aux = grund(xx,yy);
			v.insert(aux);
		}
	}

	int res = Mex(v);
	grundy[x][y] = res;
	asignados[x][y] = 1;
	return res;
	// printf("%d\n",v.size());
}

void printG(){
	for(int i=0 ; i<15; i++){
		for(int j=0 ; j<15; j++){
			cout << grundy[i][j] << " ";
		}
		printf("\n");
	}
}

int main(){

	asignados.assign(15,vector<bool>(15,false));

	//solo los primeros 4 cuadros son 0
	asignados[0][0] = 1;
	asignados[0][1] = 1;
	asignados[1][0] = 1;
	asignados[1][1] = 1;

	// grund(5,5);
	

	int tc;

	scanf("%d",&tc);

	while(tc--){

		int m;
		scanf("%d",&m);

		int xxor = 0;
		while(m--){
			int x, y;
			scanf("%d %d",&x,&y);
			int res = grund(x-1,y-1);
			xxor ^= res;
		}

		

		// printG();

		if(xxor==0)
			printf("Second\n");
		else
			printf("First\n");
	}
}