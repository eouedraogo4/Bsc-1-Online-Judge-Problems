#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStruct
{
    char name[21];
    char ID[21];
    int mark;
};
typedef struct MyStruct INFO;

int Compare(const void *p, const void *q)
{
    int a=((INFO *)p)->mark;
    int b=((INFO *)q)->mark;
    if(b!=a)
        return b-a;
    char *c=((INFO *)p)->ID;
    char *d=((INFO *)q)->ID;
    return strcmp(c,d);
}

void modulation(INFO *student, int N)
{
//--- find X
    int tmp=0, X, Y;
    for(int i=0; i<N; i++)
    {
        tmp++;
        if((double)tmp/N>0.4)
        {
            if(student[i].mark==100)
                X=101;
            else
                X=student[i].mark+1;
                break;
        }
    }
//--- find Y
    tmp=0;
    for(int i=N-1;i>=0;i--)
    {
        tmp++;
        if((double)tmp/N>0.05)
        {
            if(student[i-1].mark>=60)
                Y=59;
            else if(student[i].mark==0)
                Y=0;
            else
                Y=student[i].mark-1;
            break;
        }

    }
//--- calculate new scores
    tmp=59;
    for(int i=0; i<N; i++)
    {
        if(student[i].mark>=X)
            student[i].mark= 85+(15*(student[i].mark-X))/(100-X);
        else if(student[i].mark<X && student[i].mark>Y)
            student[i].mark=60+(24*(student[i].mark-Y-1))/(X-2-Y);
        else
        {
            if(Y==0)
                student[i].mark=59;
            else if(student[i].mark==student[i+1].mark)
                student[i].mark=tmp;
            else if(tmp>50)
                student[i].mark=tmp--;
            else if(tmp==50)
                student[i].mark=tmp;
        }
    }
}

int main()
{
//--- get inputs
    INFO *student=NULL;
    int N;
    scanf("%d",&N); getchar();
    student=malloc(N*sizeof(INFO));
    if(!student)
    {
        fprintf(stderr,"main() | Memory allocation Error !!!");
        return EXIT_FAILURE;
    }
    for(int i=0;i<N;i++)
    {
        gets(student[i].name);
        gets(student[i].ID);
        scanf("%d",&student[i].mark);
        getchar();
    }
//--- sort infos by marks
    qsort(student, N, sizeof(INFO), Compare);
//--- mark modulation
    modulation(student,N);
//--- sort new  scores
    qsort(student, N, sizeof(INFO), Compare);
//--- display of results
    for(int i=0; i<N; i++)
        printf("%s\n%d\n",student[i].name,student[i].mark);

    free(student);
    return EXIT_SUCCESS;
}
