#include <stdlib.h>
#include <stdio.h>
#include "LinkList.h"
/***********************************************/
//      本实现中的链表结构为带头节点的单链表
/***********************************************/

void CreatLinkList(LinkList *L)
{
        (*L)=(Lnode*)malloc(sizeof(Lnode));
        (*L)->data=SENTRY;
        (*L)->next=NULL;
        int Tmp=0;
        Lnode *p=NULL;
        while(printf("please input the data:") && scanf("%d",&Tmp) != EOF)
        {
                p=(Lnode*)malloc(sizeof(Lnode));
                p->data=Tmp;
                ListInsert(L,p);
        }
}

void CreatLinkListByArr(LinkList *L,Type *Arr,int len)
{
        (*L)=(Lnode*)malloc(sizeof(Lnode));
        (*L)->next=NULL;
        (*L)->data=SENTRY;

        if(!Arr)
                return;
        int i=0;
        Lnode *pNode=NULL;
        while(i<len)
        {
                pNode=(Lnode*)malloc(sizeof(Lnode));
                pNode->data=Arr[i++];
                pNode->next=NULL;
                ListInsert(L,pNode);
        }
}

void DestroyList(LinkList *L)
{
        if(!(*L)) // List is not built
                return;
        Lnode *p=(*L)->next;
        Lnode *q=NULL;
        while(p)
        {
                q=p;
                free(q);
                p=p->next;
        }
        p=q=0;
        free(*L); // free head node
        (*L)=NULL;
}

void ListInsert(LinkList *L,Lnode *Node)
{
        if(!(*L)) // List is not built
                return;
        Lnode *p=(*L);
        Lnode *q=(*L)->next;
        while(q && q->data<=Node->data)
        {
                p=q;
                q=q->next;
        }
        Node->next=p->next;
        p->next=Node;
}

Lnode *ListFind(LinkList *L,Type type)
{
        if(!(*L)) // List is not built
                return;

        Lnode *p=(*L)->next;
        if(!p)
                return NULL;

        while(p)
        {
                if (p->data == type)
                        break;
                p=p->next;
        }

        return p;
}

void ListDelete(LinkList *L,Lnode *pToDelete)
{
         if(!(*L) || !pToDelete) // List is not built
                return;

        if(!pToDelete->next)
        {
                free(pToDelete);
                pToDelete=NULL;
        }
        else
        {
                Lnode *q = pToDelete->next;
                pToDelete->data=q->data;
                pToDelete->next=q->next;
                free(q);q=NULL;
        }
}

void DisplayNode(Lnode *node)
{
        printf("%d\t",node->data);
}

void TranverseList(LinkList *L,pFunc fun)
{
        if(!(*L)) // List is not built
                return;
        Lnode *p=NULL;
        for(p=(*L)->next;p;p=p->next)
        {
                (*fun)(p);
        }
}


bool ListEmpty(LinkList *L)
{
        if(!(*L))  // List is not built
                return;
        return (*L)->next?false:true;
}

void ListClear(LinkList *L)
{
        if(!(*L))  // List is not built
                return;
        Lnode *p=(*L)->next;
        while(p)
        {
                ListDelete(L,p);
                p=p->next;
        }
        (*L)->next=NULL;
                
}

int ListLength(LinkList *L)
{
        if(!(*L))   // list is not built
                return;
        Lnode *p=(*L)->next;

        int len=0;
        while(p)
        {
                len++;
                p=p->next;
        }

        return len;
}
