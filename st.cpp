#include <bits/stdc++.h>

using namespace std;


class segmentTree{
    public:
        //int arr[1000000+5], tree[5000000+5];
        vector<int> arr, tree, lazy;
        int  N;

    void build(int node, int ss, int se)
    {
        int mid;
        if(ss == se)
            scanf("%d", &tree[node]);
        else
        {
            mid = (ss + se) / 2;
            build(2*node, ss, mid);
            build(2*node+1, mid+1, se);
            tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
        }
    }

    void update(int node, int ss,int se, int index, int val)
    {
        int mid;
        if(ss == se)
            tree[node] = val;
        else
        {
            mid = (ss + se) / 2;
            if(index <= mid)
                update(node * 2, ss, mid, index, val);
            else
                update(node*2+1, mid + 1, se, index, val);

            tree[node] = (tree[node * 2] + tree[node * 2 + 1]);
        }
    }

    void update_range(int node, int ss, int se, int qs, int qe, int val)
    {
        int mid = (ss+se)/2;
        if(lazy[node]!=0)
        {
            tree[node] = lazy[node];///for RANGESUM use = (se-ss+1)*lazy[node]
            if(ss != se)
            {
                lazy[node*2] = lazy[node];
                lazy[node*2+1] = lazy[node];
            }
            lazy[node] = 0;
        }

        if(ss>se || ss>qe || se<qs)
            return;

        if(qs <= ss && se <= qe)
        {
            tree[node] = val;///for RANGESUM use = (se-ss+1)*val
            if(ss != se)
            {
                lazy[node*2] = val;
                lazy[node*2+1] = val;
            }
        }
        else
        {
            update_range(node*2, ss, mid, qs, qe, val);
            update_range(node*2+1, mid+1, se, qs, qe, val);

            tree[node] = max(tree[node*2] , tree[node*2+1]);
        }
    }

    long long query(int node, int ss, int se, int qs, int qe)
    {
        // if(lazy[node])
        // {
        //     tree[node] = lazy[node];///for RANGESUM use = (se-ss+1)*lazy[node]
        //     if(ss != se)
        //     {
        //         lazy[node*2] = lazy[node];
        //         lazy[node*2+1] =lazy[node];
        //     }
        //     lazy[node] = 0;
        // }
        int mid;
        if(qe < ss || qs > se)
            return -100000000000; /// for RANGESUM return 0, rangeProduct 1, RangeMin return max
        if(qs <= ss && se <= qe)
          return tree[node];
        else
        {
            mid = (ss + se) / 2;
            return max(query(node*2, ss, mid, qs, qe) , query(node*2+1, mid+1, se, qs, qe));
        }
    }



    void build(int n){
        arr.resize(n+5);
        lazy.resize(5*n+5);
        tree.resize(5*n+5);
        build(1,1,n);
        N = n;
    }
    long long query(int qs,int qe)
    {
        return query(1, 1, N, qs, qe);
    }
};



int main()
{
    int tc, N, K;
    scanf("%d", &tc);
    while(tc--)
    {
        segmentTree st;
        scanf("%d%d", &N, &K);
        st.build(N);
        for(int i=1; i<=N-K+1; i++)
        {
            printf("%lld ", st.query(i, i+K-1));
        }
        printf("\n");
    }

    return 0;
}
