#include <bits/stdc++.h>

using namespace std;

int findSubsequenceCount(string S, string T)
{
    int m = T.length(), n = S.length();

    // T can't appear as a subsequence in S
    if (m > n)
        return 0;
 
    // mat[i][j] stores the count of occurrences of
    // T(1..i) in S(1..j).
    int mat[m + 10][n + 10];
 
    // Initializing first column with all 0s. An empty
    // string can't have another string as suhsequence
    for (int i = 1; i <= m; i++)
        mat[i][0] = 0;
 
    // Initializing first row with all 1s. An empty
    // string is subsequence of all.
    for (int j = 0; j <= n; j++)
        mat[0][j] = 1;
 
    // Fill mat[][] in bottom up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // If last characters don't match, then value
            // is same as the value without last character
            // in S.
            if (T[i - 1] != S[j - 1])
                mat[i][j] = mat[i][j - 1];
 
            // Else value is obtained considering two cases.
            // a) All substrings without last character in S
            // b) All substrings without last characters in
            //    both.
            else
                mat[i][j] = (mat[i][j - 1] + mat[i - 1][j - 1])%1000000007;
        }
    }
 
     // uncomment this to print matrix mat
    // for (int i = 1; i <= m; i++, cout << endl)
    //     for (int j = 1; j <= n; j++)
    //         cout << mat[i][j] << " ";  
    return mat[m][n] ;
}

int main(){

	int m, n;

	scanf("%lli %lli",&m,&n);

	string s1, s2;

	cin >> s1 >> s2;
	// cout << s1 << " " << s2 << endl;
	int res = findSubsequenceCount(s2,s1);
	printf("%d\n", res);

}