#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int n;
int m;

typedef struct Node
{
    int data;
    struct Node *next;
} ListNode;

ListNode *Init(void)
{
    ListNode *head = NULL;
    head = (ListNode *)malloc(sizeof(ListNode));
    /*
    if (head==NULL)
        return NULL;
    */
    head->next = NULL;
    return head;
}

void CreatList(ListNode *listhead)
{
    int x;
    ListNode *p = NULL;
    ListNode *r = NULL;
    if (!listhead)
        return;
    r = listhead;
    //p = listhead->next;
    for (int i=0; i<n; i++)
    {
        p = (ListNode*)malloc(sizeof(ListNode));
        scanf("%d", &x);
        p->data = x;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

void DeletElem(ListNode *listhead)
{
    int i = 0;
    ListNode *p = NULL;
    ListNode *q = NULL;
    if (!listhead)
        return;
    p = listhead;
    for (i=0; i<n; i++)
        {
            while (p->next && p->next->data!=m)
                p = p->next;
            if (p->next)
            {
                q = p->next;
                p->next = q->next;
                free(q);
                n--;
            }
            else
                return;
        }
}

void TravList(ListNode *listhead)
{
    ListNode *p = NULL;
    if (!listhead)
        return;
    p = listhead->next;
    while (p)
    {
        if (p->next!=NULL)
            printf("%d ",p->data);
        else
            printf("%d\n", p->data);
        p = p->next;
    }
}

void DestoryList(ListNode *listhead)
{
    ListNode *p = NULL;
    ListNode *s = NULL;
    if (!listhead)
        return;
    p = listhead;
    while (p)
    {
        s = p->next;
        free(p);
        p = s;
    }
}

int main(void)
{
    //int n, m;
    while (scanf("%d", &n)!= EOF)
    {
        int k = n;
        ListNode *head = NULL;
        head = Init();
        CreatList(head);
        //TravlList(head);
        scanf("%d", &m);
        printf("%d\n", k);
        TravList(head);
        DeletElem(head);
        printf("%d\n", n);
        TravList(head);
        DestoryList(head);
    }
    return 0;
}

