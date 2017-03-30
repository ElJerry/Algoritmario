#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

struct point{
    long double x, y;
    point(){};
    point(double a, double b)
    {
        x = a;
        y = b;
    }
};

struct vec
{
    ///Parece lo mismo que un punto, pero es un vector
    double x, y;
    vec(){};
    vec(point a, point b)
    {
        x = b.x-a.x;
        y = b.y-a.y;
    }
};

struct line{
    point p1, p2;
    long double a,b,c;
    line(){};
    line(point ini, point fin)
    {
        ///De dos puntos lo llevo a la forma ax+by+c = 0
        a = ini.y-fin.y;
        b = fin.x-ini.x;
        c = (ini.x*fin.y) - (ini.y*fin.x);
        ///Guardo esos dos puntos en caso de requerir un "segmento"
        p1.x = ini.x;
        p1.y = ini.y;
        p2.x = fin.x;
        p2.y = fin.y;
    }
};

bool lineVsline(line l, line s)
{
    double det = l.a*s.b - l.a*s.b;
    return det!=0;
}

bool lineVSsegment(line l, line s)
{
    int v1, v2;
    v1 = l.a*s.p1.x + l.b*s.p1.y + l.c;
    v2 = l.a*s.p2.x + l.b*s.p2.y + l.c;
    if(v1*v2 <= 0)
    {
        return true;
    }
    return false;
}

bool segmentvssegment(line a, line b)
{
    ///Los primeros dos ifs "grandes" se pueden cambiar por "si somos colineales (El area formada por los 4 puntos es 0)
    ///y los segmentos no se traslapan(como en el if de adentro) return false;
    if(a.p1.x==a.p2.x && a.p2.x == b.p1.x && b.p1.x==b.p2.x)
    {
        if(max(a.p1.y,a.p2.y) < min(b.p1.y, b.p2.y) || min(a.p1.y,a.p2.y) > max(b.p1.y, b.p2.y))
            return false;
    }

    if(a.p1.y==a.p2.y && a.p2.y == b.p1.y && b.p1.y==b.p2.y)
    {
        if(max(a.p1.x,a.p2.x) < min(b.p1.x, b.p2.x) || min(a.p1.x,a.p2.x) > max(b.p1.x, b.p2.x))
            return false;
    }

    int v1, v2;
    v1 = a.a*b.p1.x + a.b*b.p1.y + a.c;
    v2 = a.a*b.p2.x + a.b*b.p2.y + a.c;
    if(v1*v2 <= 0)
    {
        v1 = b.a*a.p1.x + b.b*a.p1.y + b.c;
        v2 = b.a*a.p2.x + b.b*a.p2.y + b.c;
        if(v1*v2 <= 0)
            return true;
    }
    return false;
}

point intersection(line line1, line line2)
{
    ///La llamo sí y solo sí se intersectan
    long double det, detx, dety;
    point ans;

    det = line1.a*line2.b - line2.a*line1.b;
    detx = line1.c*line2.b - line2.c*line1.b;
    dety = line1.a*line2.c - line2.a*line1.c;

    ans = point(-1*detx/det, -1*dety/det);
    return ans;
}

double angle(point a, point b, point p)
{
    ///Regresa el ángulo apb ( vertice en "p")
    vec pa = vec(p,a),pb = vec(p,b);
    double dot = pa.x*pb.x + pa.y*pb.y;

    double norm_pa = pa.x*pa.x + pa.y*pa.y;
    double norm_pb = pb.x*pb.x + pb.y*pb.y;
    return acos(dot/sqrt(norm_pa*norm_pb));
}

bool leftturn(point a, point b, point c)
{
    ///Me regresa si el giro de los puntos fue hacia la izquierda o hacia la derecha
    double ans = a.x*b.y;
    ans+=b.x*c.y;
    ans+=c.x*a.y;
    ans-= a.y*b.x;
    ans-=b.y*c.x;
    ans-=c.y*a.x;

    return ans > 0;
}

long double area(vector<point> pp)
{
    ///Si no funciona es muy probable que ea por los arreglos
    pp.push_back(pp[0]);
    long double a = 0;
    for(int i=0; i<pp.size(); i++)
    {
        a += pp[i].x*pp[i+1].y;
        a -= pp[i].y*pp[i+1].x;
    }
    return a/2.0;
}

bool pInPolygon( point p, vector<point> pp)
{
    pp.push_back(pp[0]);
    double suma = 0, pi = acos(-1);
    bool a;

    for(int i=0; i<pp.size()-1; i++)/**El "-1" es una conjetura,se usa porque al meter el primero el tamaño aumenta
                                    Si no funciona usar arrays**/
    {
        a = leftturn(pp[i], pp[i+1], p);
        if(a == false)
            suma -= angle(pp[i], pp[i+1], p);
        else
            suma += angle(pp[i], pp[i+1], p);
    }
    if(abs(abs(suma) - (2.0)*pi) < 0.0000001) return true;
    else return false;
}

bool isConvex(vector<point> pp)
{
    pp.push_back(pp[0]);
    bool dir = leftturn(pp[0], pp[1], pp[2]), actual;
    for(int i=0; i<pp.size()-1; i++)
    {
        actual =leftturn(pp[i], pp[i+1], pp[i+2]);
        if( actual != dir) return false;
    }
    return true;
}

int main()
{
    return 0;
}
