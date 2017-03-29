#include <cstdio>

using namespace std;
long long factoriales[10000000], inversos[100000], p = 1000000000+7;

long long exp_bin(long long a, long long n)
{
    ///a^n
    ///Exponenciación binaria
    long long k=a;
    long long r = 1;
    while(n>0)
    {
        if(n%2==1)
            r = (k*r) % p;
        k = (k*k) % p;
        n = n/2;
    }
    return r;
}

long long nCk(long long n, long long k)
{
    ///P tiene que ser primo
    ///requiere inicializar arreglo de factoriales e inversos, si k> p se va a la verga.
    ///calculamos el inverso multiplicativo mod p en lugar de dividir
    ///Surge de que a^p-1 es congruente a 1 mod p si p es primo, entonces a ^(p-2) es congruente con a^-1 mod p
    ///a^-1 es el inverso multiplicativo de a, entonces elevamos a^(p-2); pequeño teorema de Fermat.
    long long ans;
    ans = (factoriales[n] * inversos[n-k]) % p;
    ans = (ans * inversos[k]) % p;
    return ans;

}

int main()
{
    ///inveros[i] guarda el inverso multiplicativo de i! mod p
    factoriales[0] = 1;
    inversos[0] = exp_bin(factoriales[0], p-2) % p;
    for(long long i=1; i<=1000; i++)
    {
        factoriales[i] = (i*factoriales[i-1]) % p;
        inversos[i] = exp_bin(factoriales[i], p-2) % p;
    }

    printf("%lld", nCk(1,1));
    return 0;
}
