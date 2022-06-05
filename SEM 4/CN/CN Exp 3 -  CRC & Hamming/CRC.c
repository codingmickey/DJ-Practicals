
#include <stdio.h>

void crcProcess(int n, int l, int g[], int d[], int codeword[])
{

    int key[n + 1], m, k;

    for (int i = 0; i <= n; i++)
    {
        key[i] = d[i];
    }

    for (int i = 0; i < l; i++)
    {
        m = 0;
        k = key[0];

        for (int j = 1; j <= n; j++)
        {
            if (k == 0)
            {
                if (key[j] == 0)
                {
                    key[m] = 0;
                }
                else
                {
                    key[m] = 1;
                }
            }
            else
            {
                if (key[j] == g[j])
                {
                    key[m] = 0;
                }
                else
                {
                    key[m] = 1;
                }
            }
            m++;
        }
        key[m] = d[i + n + 1];
        codeword[i] = d[i];
    }

    for (int i = 0; i < n; i++)
    {
        codeword[l + i] = key[i];
    }
}

int main()
{
    int n;
    printf("Enter the highest degree of G(x) : ");
    scanf("%d", &n);

    int g[n];
    for (int i = 0; i <= n; i++)
    {
        printf("Enter the coefficient of x^%d : ", n - i);
        scanf("%d", &g[i]);
    }

    int l;
    printf("\nEnter the length of original data : ");
    scanf("%d", &l);
    int d[l + n];

    printf("Enter the original data: \n");
    for (int i = 0; i < l; i++)
    {
        printf("Enter the bit %d: ", i + 1);
        scanf("%d", &d[i]);
    }
    for (int i = 0; i < n; i++)
    {
        d[l + i] = 0;
    }

    int codeword[l + n];

    crcProcess(n, l, g, d, codeword);

    printf("\nGenerator : ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d", g[i]);
    }

    printf("\n\nData : ");
    for (int i = 0; i < l; i++)
    {
        printf("%d", d[i]);
    }

    printf("\n\nRemainder : ");
    for (int i = l; i < l + n; i++)
    {
        printf("%d", codeword[i]);
    }

    printf("\n\nCodeword : ");
    for (int i = 0; i < l + n; i++)
    {
        printf("%d", codeword[i]);
    }

    // crcProcess(n,l,g,codeword,codeword);

    // for(int i=l;i<l+n;i++){
    //     if(!codeword[i]==0){
    //        error=1;
    //     }
    // }

    // if(error){
    //     printf("\nError!");
    // }
    // else{
    //       printf("\nRemainder at receiving side : ");
    //       for(int i=l;i<l+n;i++){
    //       printf("%d",codeword[i]);
    //       }
    //       printf("\n");
    //       printf("\nReceived successfully");
    //  }

    return 0;
}
