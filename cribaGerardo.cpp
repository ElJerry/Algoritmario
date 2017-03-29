#include <bits/stdc++.h>

using namespace std;

int criba[10000];

bitset<10000000> bs;
vector<int> primos;

void crearCriba(){
    bs.set();
    bs[0] = 0;
    bs[1] = 0;
    for(int i=2; i<500 ; i++){
        if(bs[i]==0)
            continue;
        for(int j=i*i; j<500; j+=i){

            bs[j] = 0;
        }
        primos.push_back(i);
        cout << i << endl;
    }
    cout << "Existen " << primos.size() << " Primos" << endl;
}

int main(){

    crearCriba();

}
