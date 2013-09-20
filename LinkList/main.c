#include <stdlib.h>
#include <stdio.h>
#include "LinkList.h"


int main()
{
        LinkList list1=NULL;
        pFunc fun=DisplayNode;
        CreatLinkList(&list1);
        TranverseList(&list1,fun);
        printf("list length is:%d\n",ListLength(&list1));
        while(1)
        {
                printf("\nwhich node do you want to add? :");
                Type Tmp;
                scanf("%d",&Tmp);
                Lnode *p=ListFind(&list1,Tmp);
                if(p)
                        printf("the number %d is in the linklist\n",Tmp);
                else
                {
                        printf("the number %d is not in the linklist\n",Tmp);
                        printf("now insert the number into list\n");
                        Lnode *q=(Lnode*)malloc(sizeof(Lnode));
                        q->data=Tmp;
                        q->next=NULL;
                        ListInsert(&list1,q);
                        printf("the list is now becoming :\n");
                        TranverseList(&list1,fun);
                }

                printf("\nwhich node do you want to remove? :");
                scanf("%d",&Tmp);
                p=ListFind(&list1,Tmp);
                if(p)
                {
                        ListDelete(&list1,p);
                        printf("the list is now becoming :\n");
                        TranverseList(&list1,fun);
                }
                else
                {
                        printf("there is no number valuing %d\n",Tmp);
                }
                getchar();
                if(getchar()==EOF)
                        break;
        }
        printf("\nis List empty? %d\n",ListEmpty(&list1));
        ListClear(&list1);
        printf("is List empty? %d\n",ListEmpty(&list1));
        
        DestroyList(&list1);
        return 0;

}
