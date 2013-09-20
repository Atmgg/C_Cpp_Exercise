#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#ifdef __cplusplus
extern "C"{
#endif

typedef int Type;

typedef struct BiNode
{
        struct BiNode *left;
        struct BiNode *right;
        Type   data;
}BiNode;
typedef BiNode* BiTree;

#ifndef __cplusplus
typedef enum bool{false=0,true=!false}bool;
#endif

typedef void (*pFunc) (BiNode *p);


bool Compare(Type data1,Type data2);
bool CreatBiTree(BiTree *T,Type *PreOrderArr,Type *InOrder,int Arrlen);
void ClearBiTree(BiTree *T);
void DestoryBiTree(BiTree *T);
bool BiTreeEmpty(BiTree *T);
bool Compare(Type data1,Type data2);
bool CreatBiTreeFromFile(const char *filename,BiTree *T);
void PreOrderTranverse(BiTree *T,pFunc Visit);
void InOrderTranverse(BiTree *T,pFunc Visit);
void PostOrderTranverse(BiTree *T,pFunc Visit);
void Display(BiNode *p);

#ifdef __cplusplus
}
#endif

#endif
