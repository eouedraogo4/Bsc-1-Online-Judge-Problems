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

int main()
{
//--- get inputs
    INFO *student=NULL;
    int N;
    scanf("%d",&N); getchar();
    student=malloc(N*sizeof(INFO));
    if(!student)
    {
        fprintf(stderr,"main | Memory allocation Error !!!");
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
    qsort(student, N, sizeof(INFO),Compare);
//--- display of results
    for(int i=0; i<N; i++)
        printf("%s\n%d\n",student[i].name,student[i].mark);
    free(student);
    return EXIT_SUCCESS;
}
