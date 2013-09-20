#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

bool CreatBiTree(BiTree *T,Type *PreOrderArr,Type *InOrder,int Arrlen)
{
        if (*T)  // Check if the tree is not an empty tree
                return false;
        if(!Arrlen) return true; // this situation maybe because one subtree is empty

        (*T) = (BiTree)malloc(sizeof(BiNode));
        if(!(*T)) // check if malloc is succeed
                return false;
        (*T)->data=PreOrderArr[0];
        (*T)->left=NULL;
        (*T)->right=NULL;

        if(Arrlen == 1)  // Only have one node ,then the recusison are not needed yet.
                return true;

        int i=0;
        while(!Compare(PreOrderArr[0],InOrder[i])) ++i;

        
        CreatBiTree(&((*T)->left),PreOrderArr+1,InOrder,i);
        CreatBiTree(&((*T)->right),PreOrderArr+i+1,InOrder+i+1,Arrlen-i-1);

        return  true;
}

void ClearBiTree(BiTree *T)
{
        if(!(*T)) return;
        ClearBiTree( &((*T)->left) );
        ClearBiTree( &((*T)->right) );
        free(*T);
        (*T)=NULL;
        
}

void DestoryBiTree(BiTree *T)
{
        ClearBiTree(T);
}

bool BiTreeEmpty(BiTree *T)
{
        return (*T)?false:true;
}

bool Compare(Type data1,Type data2)
{
        return (data1 == data2 ? true : false);
}

bool CreatBiTreeFromFile(const char *filename,BiTree *T)
{
        FILE *fd=NULL;
        if(!(fd=fopen(filename,"r")) )
                return false;
        char buf[255];
        fgets(buf,255,fd);
        int i=0 ,j=0;
        while(buf[i]!=':')i++;
        int NodeNum = atoi(buf+i+1);
        Type *PreOrderArr = (Type*)malloc(sizeof(Type)*NodeNum);
        Type *InOrderArr = (Type*)malloc(sizeof(Type)*NodeNum);

        for(i=0;i<NodeNum;++i)
                fscanf(fd,"%d",&(PreOrderArr[i]));

        for(i=0;i<NodeNum;++i)
                fscanf(fd,"%d",&(InOrderArr[i]));
        if (!CreatBiTree(T,PreOrderArr,InOrderArr,NodeNum))
                return false;

        free(PreOrderArr);PreOrderArr=NULL;
        free(InOrderArr);InOrderArr=NULL;
        return true;
}

void PreOrderTranverse(BiTree *T,pFunc Visit)
{
        if(!(*T)) // NULL Node,return directly
                return;
        Visit(*T);
        PreOrderTranverse(&(*T)->left,Visit);
        PreOrderTranverse(&(*T)->right,Visit);

        return;
}

void InOrderTranverse(BiTree *T,pFunc Visit)
{
        if(!(*T)) // NULL Node,return directly
                return;
        InOrderTranverse(&(*T)->left,Visit);
        Visit(*T);
        InOrderTranverse(&(*T)->right,Visit);

        return;
}

void PostOrderTranverse(BiTree *T,pFunc Visit)
{
        if(!(*T)) // NULL Node,return directly
                return;
        PostOrderTranverse(&(*T)->left,Visit);
        PostOrderTranverse(&(*T)->right,Visit);
        Visit(*T);

        return;
}

void Display(BiNode *p)
{
        printf("%d\t",p->data);
}

