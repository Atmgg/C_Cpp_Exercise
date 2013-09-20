#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <limits.h>

#define SENTRY INT_MAX

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __cplusplus
typedef enum bool{false=0,true=!false}bool;
#endif
typedef int Type;
typedef struct Lnode{
        Type data;
        struct Lnode* next;
        }Lnode;
typedef Lnode* LinkList;
typedef void (*pFunc)(Lnode *node);


void CreatLinkList(LinkList *L);
void CreatLinkListByArr(LinkList *L,Type *Arr,int len);
void DestroyList(LinkList *L);
void ListInsert(LinkList *L,Lnode *Node);
Lnode *ListFind(LinkList *L,Type type);
void ListDelete(LinkList *L,Lnode *pToDelete);
void DisplayNode(Lnode *node);
void TranverseList(LinkList *L,pFunc fun);
bool ListEmpty(LinkList *L);
void ListClear(LinkList *L);
int ListLength(LinkList *L);

#ifdef __cplusplus
}
#endif

#endif
