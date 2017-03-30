#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "ufds.h"

using namespace std;

struct arista{
	int peso;
	int a, b;

	arista(int a, int b, int c){
		this->a = a;
		this->b = b;
		this->peso = c;
	}
};


bool funcionOrden(arista a, arista b){
	return a.peso < b.peso;
}

void leerGrafo(vector<arista> &l){

	int a, b, c;
	cout << "\n---Aristas leidas---\n";
	while(!cin.eof()){
		cin >> a >> b >> c;
		l.push_back(*new arista(a-1,b-1,c));
		cout << a << "->" << b << " " << c << endl;
	}
	cout << endl;
}

vector<arista> kruskal(vector<arista> &lista, disjointSet &ds){
	// Ordenamos la lista de mayor a menor
	sort(lista.begin(),lista.end(),funcionOrden);
	
	//Creamos una lista para agregar los resultados
	vector<arista> result;

	// greedy!!
	int sz = lista.size();

	for(int i=0 ; i<sz; i++){
		arista aux = lista[i];
		if(!ds.isSameSet(aux.a,aux.b)){
			cout << "Seleccionado: ";
			ds.joinSet(aux.a,aux.b);
			result.push_back(aux);
		}
		else
			cout << "Ignorando: ";

		cout << aux.a<<"->"<<aux.b << endl;
	}

	return result;
}

int calcularPeso(vector<arista> v){
	int x = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		x+=v[i].peso;
	}
	return x;
}

int main(){	
	ios::sync_with_stdio(0);
	vector<arista> lista;
	
	// Leemos la cantidad de nodos
	int nodos;
	cin >> nodos;
	cout << "Nodos Leidos: " << nodos << endl;

	//Creamos el grafo y lo leemos
	leerGrafo(lista);

	//Creamos el ufds con la cantidad de aristas
	disjointSet ds(nodos);

	//Imprimiendo informacion de lista
	cout << "Tamano de la lista: " << lista.size() << endl << endl;

	//Aplicamos el algoritmo de Kruskal
	vector<arista> res = kruskal(lista,ds);

	// Imprimimos peso;
	cout << "\nPeso min/max: " << calcularPeso(res);
	cout << "\n\n--- Fin del Algoritmo ---\n";
	// system("pause");

	ds.mostrarSet();
}