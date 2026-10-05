#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void main()
{
    int n = 8;
    int capacity = 20;

    int weight[] = {2, 3, 4, 5, 6, 7, 8, 9};
    int value[]  = {3, 4, 5, 8, 9, 10, 11, 13};

    int dp[9][21];

    int i, w;

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i - 1][w],
                    value[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("DP Table:\n\n");

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= capacity; w++)
        {
            printf("%3d ", dp[i][w]);
        }
        printf("\n");
    }

    printf("\nMaximum value = %d\n", dp[n][capacity]);

    w = capacity;

    printf("Selected items: ");

    for (i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            printf("%d ", i);
            w = w - weight[i - 1];
        }
    }

    printf("\n");
}