#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	scanf("%d",&n);
	vector<int> nums;
	nums.resize(n);

	for(int i=0 ; i<n; i++){
		scanf("%d",&nums[i]);
		printf("%d ",nums[i] );
	}

	//obtener el tamaño de la LIS
	multiset<int> ms;
	multiset<int>::iterator it;
	vector<int> lis;

	for(int i=0 ; i<n; i++){
		int aux = nums[i];
		ms.insert(aux);
		it = ms.find(aux);
		it++;
		if(it!=ms.end())
			ms.erase(it);
		else
			lis.push_back(aux);
	}	

	printf("\n");
	for(int i=0 ; i<lis.size(); i++){
		printf("%d ",lis[i]);
	}
	printf("\n");

	printf("\nLis tam: %d\n", ms.size());

}