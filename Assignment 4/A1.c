#include <stdio.h>
#include <string.h>

# define MAX 100

void main()
{
    char a[MAX], b[MAX], lcs[MAX];
    int dp[MAX][MAX];
    int i, j, m, n, k;

    printf("Enter first string: ");
    scanf("%s", a);

    printf("Enter second string: ");
    scanf("%s", b);

    m = strlen(a);
    n = strlen(b);

    if (m < 10 || n < 10)
    {
        printf("Error: Both strings must have at least 10 characters.\n");
        return;
    }

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else if (dp[i - 1][j] > dp[i][j - 1])
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    printf("\nLength of LCS = %d\n", dp[m][n]);

    i = m;
    j = n;
    k = dp[m][n];

    lcs[k] = '\0';

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs[k - 1] = a[i - 1];
            i--;
            j--;
            k--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("Longest Common Subsequence = %s\n", lcs);
}