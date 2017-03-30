#include <bits/stdc++.h>

using namespace std;


class uf
{
    public:
    //int papas[1000005], sizes[1000005], niv[1000005], cant_conjuntos;
    vector<int> papas, sizes, niv;
    int cant_conjuntos;
    uf(int n)
    {
        // printf("entre\n");
        papas.resize(1000005);
        sizes.resize(1000005);
        niv.resize(1000005);
        cant_conjuntos = n;
        for(int i=0; i<n; i++)
        {
           sizes[i] = 1;
           papas[i] = i;
           niv[i] = 0;
        }
        // printf("sali\n");
    }

    int papa(int a)
    {
        if(papas[a] != a)
            papas[a] = papa(papas[a]);
        return papas[a];
    }

    void une(int a, int b)
    {
        int pa = papa(a);
        int pb = papa(b);

        if(pa != pb)
        {
            if(niv[pa] < niv[pb])
            {
                papas[pa] = pb;
            }
            else if (niv[pa] > niv[pb])
            {
                papas[pb] = pa;
            }
            else
            {
                papas[pa] = pb;
                niv[pb]++;
            }
            int tam = sizes[pa] + sizes[pb];

            sizes[pa] = tam;
            sizes[pb] = tam;
            cant_conjuntos--;
        }
    }

    bool mismo(int a, int b)
    {
        int pa = papa(a);
        int pb = papa(b);
        return pa == pb;
    }

    //regresa el taño del conjunto al que pertenece a
    int tam(int a)
    {
        int pa = papa(a);
        return sizes[pa];
    }

    int cant_sets()
    {
        return cant_conjuntos;
    }

};



int main()
{
    int N,I, q, a, b;


    scanf("%d%d", &N, &I);

    uf u = uf(3);

    for(int i=1; i<=I; i++)
    {
        scanf("%d", &q);
        if(q == 1)
        {
            scanf("%d%d", &a, &b);
            u.une(a,b);
        }
        else if(q == 2)
        {
            scanf("%d", &a);
            printf("%d\n", u.tam(a));

        }
        else
        {
            printf("%d\n", u.cant_sets());
        }
    }

    return 0;
}
