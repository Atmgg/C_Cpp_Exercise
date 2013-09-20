#include <iostream>
#include <stack>
#include "LinkList.h"
using namespace std;

// 将单链表反转
void ReverseList(LinkList *L)
{
        if(ListEmpty(L) || !(*L)->next->next ) // 空表或者只有一个节点的链表直接返回
                return;

        Lnode *pCruuent = (*L)->next; // 链表第一个节点
        Lnode *pTemp=NULL;
        (*L)->next=NULL;
        while(pCruuent)
        {
                pTemp=pCruuent;
                pCruuent=pCruuent->next;
                pTemp->next=(*L)->next;
                (*L)->next=pTemp;
        }
}

// 查找单链表中的倒数第K个结点（k > 0）
Lnode *FindKstNode(LinkList L,int k)
{
        if(ListEmpty(&L))
                return NULL;
        Lnode *pFirst=L->next;
        Lnode *pSecond=L->next;

        int i=1;
        while(i<=k && pFirst)
        {
                pFirst=pFirst->next;
                i++;
        }

        if(i<k)
                return NULL;
        else if(i==k)
                return pSecond;
        while(pFirst)
        {
                pFirst=pFirst->next;
                pSecond=pSecond->next;
        }

        return pSecond;
}

// 查找单链表的中间结点
Lnode *FindMidNode(LinkList L)
{
        if(ListEmpty(&L))
                return NULL;
        Lnode *pFirst=L->next;
        Lnode *pSecond=L->next;
        while(pFirst && pFirst->next)
        {
                pFirst=pFirst->next->next;
                pSecond=pSecond->next;
        }
        
        return pSecond;
}

// 从尾到头打印单链表
void PrintListFromTailToHead(LinkList L)
{
        /*****递归版本，存在缺陷，将把头节点处的数据也打印出来
        if(!L)
                return;
        else PrintListFromTailToHead(L->next);
        cout<<L->data<<'\t';
        *********/

        /****非递归版本******/
        if(ListEmpty(&L))
                return;
        Lnode *pTmp=L->next;
        stack<Lnode *> stk;
        while(pTmp)
        {
                stk.push(pTmp);
                pTmp=pTmp->next;
        }

        while(!stk.empty())
        {
                pTmp=stk.top();
                cout<<pTmp->data<<'\t';
                stk.pop();
        }
}

 // 已知两个单链表pHead1 和pHead2 各自有序，把它们合并成一个链表依然有序
 LinkList MergeTwoList(LinkList L1,LinkList L2)
{
        if (!L1 && !L2)
                return NULL;
        else if(!L1)
                return L2;
        else if(!L2)
                return L1;

        LinkList Lmerge=L1;
        Lnode *pL1=L1->next;
        Lnode *pL2=L2->next;
        Lnode *pL=L1;

        while(pL1 && pL2)
        {
                if(pL1->data<pL2->data)
                {
                        pL->next=pL1;
                        pL=pL1;
                        pL1=pL1->next;
                }
                else
                {
                        pL->next=pL2;
                        pL=pL2;
                        pL2=pL2->next;
                }

        }
        if(pL2)
                pL1=pL2;

        pL->next=pL1;

        return Lmerge;
}

int main()
{
        Type Arr[]={1,2,3,6,34,63,756,234,21,4};
        Type Arr2[]={43,23,56,75,72,82,234,901};
        LinkList list1=NULL;
        LinkList list2=NULL;
        CreatLinkListByArr(&list1,Arr,sizeof(Arr)/sizeof(Type));
        CreatLinkListByArr(&list2,Arr2,sizeof(Arr2)/sizeof(Type));
        cout<<"Length of list1 is:"<<ListLength(&list1)<<endl;
        TranverseList(&list1,DisplayNode);
        cout<<endl;
        // ReverseList(&list1);
        // TranverseList(&list1,DisplayNode);
        //
        // cout<<"now find the last k node"<<endl;
        // Lnode *Kst=FindKstNode(list1,3);
        // cout<<Kst->data<<endl;
        //
        // cout<<"The Mid Node is:";
        // Lnode *pMid=FindMidNode(list1);
        // if(pMid)
                // cout<<pMid->data<<endl;

        // PrintListFromTailToHead(list1);
        //
        LinkList ListMerge=MergeTwoList(list1,list2);
        TranverseList(&ListMerge,DisplayNode);

        DestroyList(&list1);
        DestroyList(&list2);
        return 0;
}
