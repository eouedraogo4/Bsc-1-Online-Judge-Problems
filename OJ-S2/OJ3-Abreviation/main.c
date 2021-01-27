#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1000 + 5
#define N 20 + 5

/// find the abbreviation of element
char *findAbrev(char array[][N], int pos, int n)
{
    char *result = (char *)malloc(N*sizeof(char));
    memset(result, 0,N*sizeof(char));
    // check if we find a word < chosen word (comparing length) to be the abbrev
    for(int i = 0; array[pos][i] != '\0'; i++)
    {
        strncpy(result,array[pos],i+1); // copy i+1 char(prefix) of the chosen word
        // check the prefix is different of all other words prefix
        int j = 0;
        for(; j < n; j++)
        {
            char otherPrefix[N]="";
            strncpy(otherPrefix,array[j],i+1);
            if(j != pos && strcmp(result,otherPrefix) == 0)
                break;
        }
        if(j >= n) // the prefix is different of all others so return the current prefix as result
            return result;
    }
    free(result);
    // no available prefix so take the total word
    return array[pos];
}

int main()
{
    freopen("2.in","r",stdin);
    char input[M][N] = {""};
    int n = 0;
    do
    {
        scanf("%s",input[n]);
    }while(strcmp(input[n++],"#"));
    n--;

    for(int i = 0; i < n; i++)
    {
        char *result = findAbrev(input,i,n);
        printf("%s %s\n",input[i],result);
        if(result != input[i])
            free(result);
    }

    return 0;
}
