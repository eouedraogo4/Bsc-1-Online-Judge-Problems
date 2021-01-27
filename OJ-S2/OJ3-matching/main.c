#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct MyStruct
{
    int pos;
    int end;
    unsigned short word_found;
    unsigned short shap_found;
    unsigned short change_pos;
};
typedef struct MyStruct INFO;
INFO Infos;

void Compare_word(char* l_word, int l_size,
                  char* s_word, int s_size, int start_point)
{
    int j=0;
    for(int i=start_point;i<l_size;i++)
    {
        if(s_word[j]==l_word[i])
        {
            j++;
        }
        else
        {
            if(s_word[j]=='?' && l_word[i]!='$')
                j++;
            else if(s_word[j]=='#')
            {
                Infos.shap_found=1;
                Infos.pos=start_point;
                Infos.end=j;
                return;
            }
            else
            {
                Infos.change_pos=1;
                return;
            }
        }

        if(j>=s_size)
        {
            Infos.pos=start_point;
            Infos.end=i;
            Infos.word_found=1;
            return;
        }
    }
    Infos.change_pos=1;
    return;
}

void simple_search(char *l_word_tmp, char *s_word_tmp,
                   int l_size, int s_size)
{
    while(!Infos.word_found && !Infos.shap_found && Infos.pos<l_size)
    {
        if(!Infos.change_pos)
            Compare_word(l_word_tmp,l_size,s_word_tmp,s_size,Infos.pos);
        else if(Infos.change_pos)
        {
            Infos.pos++;
            Infos.change_pos=1;
            Compare_word(l_word_tmp,l_size,s_word_tmp,s_size,Infos.pos);
        }
    }
    if(Infos.word_found)
        for(int i=Infos.pos;i<Infos.end+1;i++)
            l_word_tmp[i]='$';
    return;
}

int main()
{
    char l_word[101], s_word[100];
    gets(l_word); gets(s_word);

    int l_size=strlen(l_word);
    int s_size=strlen(s_word);
    char l_word_tmp[101], s_word_tmp[100];
    for(int i=0;i<l_size;i++)
    {
        l_word_tmp[i]=toupper(l_word[i]);
        if(i<s_size)
        {
            s_word[i]=toupper(s_word[i]);
            s_word_tmp[i]=s_word[i];
        }

    }

    Infos.pos=0;
    Infos.change_pos=0;
    Infos.shap_found=0;
    Infos.word_found=0;
    while(Infos.pos<l_size && !Infos.shap_found)
    {
        simple_search(l_word_tmp,s_word_tmp,l_size,s_size);
        if(Infos.word_found)
        {
            printf("%d ",Infos.pos);
            for(int i=Infos.pos;i<Infos.end+1;i++)
            {
                printf("%c",l_word[i]);
            }
            printf("\n");
            Infos.word_found=0;
        }
    }

    if(Infos.shap_found)
    {
        int shap_pos=Infos.end;
        if(shap_pos==0 || shap_pos==s_size-1)
        {
            int position[100];
            int count=0;
            Infos.shap_found=0;
            if(shap_pos!=0)
            {
                s_word_tmp[s_size-1]='\0';
                position[count]=Infos.pos;
                Infos.pos++;
                count++;
            }
            while(Infos.pos<l_size)
            {
                if(shap_pos==0)
                {
                    simple_search(l_word_tmp,&s_word_tmp[1],l_size,s_size-1);
                    if(Infos.word_found)
                    {
                        position[count]=Infos.end;
                        count++;
                        Infos.word_found=0;
                    }
                }

                else
                {
                    simple_search(l_word_tmp,s_word_tmp,l_size,s_size-1);
                    if(Infos.word_found)
                    {
                        position[count]=Infos.pos;
                        count++;
                        Infos.word_found=0;
                    }
                }
            }
            if(shap_pos==0)
            {
                for(int i=0;i<l_size;i++)
                {
                    for(int j=0;j<count;j++)
                    {
                        if(position[j]-i>s_size-3)
                        {
                            printf("%d ",i);
                            for(int k=i;k<position[j]+1;k++)
                                printf("%c",l_word[k]);
                            printf("\n");
                        }
                    }
                }
            }
            else
            {
                for(int i=0;i<count;i++)
                {
                    for(int size=position[i]+s_size;size<l_size+2;size++)
                    {
                        printf("%d ",position[i]);
                        for(int j=position[i];j<size-1;j++)
                            printf("%c",l_word[j]);
                        printf("\n");
                    }
                }
            }
        }
        else
        {
            Infos.shap_found=0;
            int size_a=Infos.end;
            int size_b=s_size-size_a-1;
            int start=Infos.pos, end=-1;
            s_word_tmp[shap_pos]='\0';
            while(Infos.pos<l_size)
            {
                if(start>=0)
                {
                    Infos.change_pos=0;
                    Infos.pos=start+size_a;
                    while(Infos.pos<l_size)
                    {

                        simple_search(l_word_tmp,&s_word[shap_pos+1],l_size,size_b);
                        if(Infos.word_found)
                        {
                            end=Infos.end;
                            Infos.word_found=0;
                        }
                        if(end>=0)
                        {
                            printf("%d ",start);
                            for(int i=start;i<end+1;i++)
                                printf("%c",l_word[i]);
                            printf("\n");
                        }
                        end=-1;
                    }
                    Infos.change_pos=0;
                    Infos.pos=start+1;
                    for(int i=start;i<l_size;i++)
                        l_word_tmp[i]=toupper(l_word[i]);
                }
                start=-1;
                simple_search(l_word_tmp,s_word_tmp,l_size,size_a);
                if(Infos.word_found)
                {
                    start=Infos.pos;
                    Infos.word_found=0;
                }
            }
        }
    }

    return 0;
}
