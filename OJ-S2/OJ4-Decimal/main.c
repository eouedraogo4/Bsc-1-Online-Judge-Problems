#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *MultiString(char* string_1, char* string_2)
{
    int length_1=strlen(string_1);
    int length_2=strlen(string_2);
    int length=(length_1+length_2+1);
//--- create and initialize the result array at 0
    char *result=(char *)malloc(length*sizeof(char));
    if(!result)
    {
        fprintf(stderr,"MultiString | Memory allocation Error !!!");
        return NULL;
    }
    memset(result,'0',length);
    result[--length]='\0';
//--- return 0 when one of the strings value is 0
    if(atof(string_1)==0 || atof(string_2)==0)
    {
        return result;
    }
//---
    int found_1=0, found_2=0,deci_part=0;
    for(int i=0;i<length_1 || i<length_2;i++)
    {
        if(i<length_1)
        {
            if(found_1)
                deci_part++;
            if(string_1[i]=='.')
                found_1=1;
        }
        if(i<length_2)
        {
            if(found_2)
                deci_part++;
            if(string_2[i]=='.')
                found_2=1;
        }
    }

    for(int i=length_2-1;i>=0;i--)
    {
        int k=--length;
        int rest=0, quotient=0;
        for(int j=length_1-1;j>=0;j--)
        {
            if(string_2[i]=='.')
                i--;
            if(string_1[j]=='.')
                j--;
            if(i>=0 && j>=0)
            {
                int x=(string_1[j]-'0')*(string_2[i]-'0')+(result[k]-'0')+rest;
                if(x>9)
                {
                    quotient=x%10;
                    rest=x/10;
                }
                else
                {
                    quotient=x;
                    rest=0;
                }
                result[k]=quotient+'0';
                k--;
            }
        }
        result[k]+=rest;
    }
    int m=0;
    for(;m<length_1+length_2-1-deci_part;m++)
        result[m]=result[m+1];
    result[m]='.';
    return result;
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.ans","w",stdout);
    int i=0;
    char ch, *array=(char *)malloc(7*sizeof(char));
    memset(array,'\0',7);
    int n=0;
    while( (ch=getchar())!=EOF )
    {
        if(i<6)
        {
            array[i]=ch;
        }
        else if(i>6 && i<9)
        {
            if(ch!=' ')
                n=n*10+ch-'0';
        }

        if(ch=='\n')
        {
            i=-1;
            char *result=(char *)malloc(7*sizeof(char));
            memset(result,'\0',7);
            for(int j=0;j<7;j++)
                result[j]=array[j];
            for(int j=0;j<n-1;j++)
            {
                while(result[0]=='0')
                    result=&result[1];
                while(array[0]=='0')
                    array=&array[1];
                result=MultiString(array,result);
            }
            int lenght=strlen(result);
            int k=0;
            while(result[k]=='0')
                k++;
            switch(result[k])
            {
            default:
                for(;result[k]!='.';k++)
                    putchar(result[k]);
            case '.':
                if(k<lenght-1)
                {
                    for(;lenght>k;lenght--)
                        if(result[lenght-1]!='0')
                            break;
                    if(lenght-1>k)
                    {
                        for(int j=k;j<lenght;j++)
                        putchar(result[j]);
                    }
                }
                break;
            }
            putchar('\n');
            n=0;
            free(result);
            array=(char *)malloc(7*sizeof(char));
            memset(array,'\0',7);
        }
        i++;
    }
    free(array);
    return 0;
}
