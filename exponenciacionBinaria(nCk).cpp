#include <cstdio>

using namespace std;
long long factoriales[10000000], p = 1000000000+7;

long long exp_bin(long long a, long long n)
{
    ///a^n
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
    ///requiere inicializar arreglo de factoriales, si k> p se va a la verga.
    long long ans;
    ans = (factoriales[n] * exp_bin(factoriales[n-k], p-2)) % p;
    ans = (ans * exp_bin(factoriales[k], p-2)) % p;
    return ans;

}

int main()
{
    factoriales[0] = 1;
    for(long long i=1; i<=1000; i++)
        factoriales[i] = (i*factoriales[i-1]) % p;

    printf("%lld", nCk(10,2));
    return 0;
}
