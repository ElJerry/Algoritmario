#include <cstdio>

using namespace std;

int papas[1000005], sizes[1000005], niv[1000005];
char ins[10];

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
    }
}

int main()
{
    int N, I, a, b;

    scanf("%d%d", &N, &I);

    for(int i=0; i<=N; i++)
    {
       sizes[i] = 1;
       papas[i] = i;
       niv[i] = 0;
    }

    for(int i=1; i<=I; i++)
    {
        scanf("%s", ins);

        if(ins[0] == 'A')
        {
            scanf("%d%d", &a, &b);
            une(a,b);
        }
        else
        {
            scanf("%d", &a);
            printf("%d\n", sizes[papa(a)]);
        }

    }

    return 0;
}
