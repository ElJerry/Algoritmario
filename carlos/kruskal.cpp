#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
int tc, M, N, papas[505], niv[505];
int arr[505], X, Y, X1, Y1, X2, Y2, dist;
pair <int, pair<int, int> > puntos[505];
pair <int, pair<int, int> > pesos[250000+5];
int papa(int a)
{
    if(a == papas[a])
        return a;
    else
        papa(papas[a]);
}
void une(int a, int b)
{
    int pa = papa(a);
    int pb = papa(b);
    if (niv[pa] > niv[pb])
        papas[pb] = pa;
    else if(niv[pa] < niv[pb])
        papas[pa] = pb;
    else
    {
        papas[pb] = pa;
        niv[pa]++;
    }
}
int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        for(int i=0; i<=501; i++)
        {
            niv[i] = 1;
            papas[i] = i;
        }

        scanf("%d%d", &M, &N);
        for(int i=0; i<N; i++)
        {
            puntos[i].first = i;
            scanf("%d%d", &puntos[i].second.first, &puntos[i].second.second);
        }
        int c = 0;
        for(int i=0; i<N; i++)
        {
            X1 = puntos[i].second.first;
            Y1 = puntos[i].second.second;
            for(int j=i; j<N; j++)
            {
                if(puntos[i].first != puntos[j].first)
                {
                    X2 = puntos[j].second.first;
                    Y2 = puntos[j].second.second;
                    X = (X2 - X1) * (X2 - X1);
                    Y = (Y2 - Y1) * (Y2 - Y1);
                    dist = X + Y;
                    pesos[c].first = dist;
                    pesos[c].second.first = puntos[i].first;
                    pesos[c].second.second = puntos[j].first;
                    c++;
                }
            }
        }
        sort(pesos, pesos+c);
        int k = 0;
        for(int i=0; i<c; i++)
        {
            if(papa(pesos[i].second.first) != papa(pesos[i].second.second))
            {
                une(pesos[i].second.first, pesos[i].second.second);
                arr[k] = pesos[i].first;
                k++;
            }
        }

        double aux = sqrt(arr[k-M]);

        printf("%.2lf\n", aux);
    }
    return 0;
}
