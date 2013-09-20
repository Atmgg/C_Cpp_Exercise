#include <stdio.h>
#include "BinaryTree.h"
int main()
{
        BiTree T=NULL;
        CreatBiTreeFromFile("tree2.txt",&T);
        printf("is tree empty?:%d\n",BiTreeEmpty(&T));
        printf("\nthe PreOrderTranverse is:");
        PreOrderTranverse(&T,Display);
        printf("\nthe InOrderTranverse is:");
        InOrderTranverse(&T,Display);
        printf("\nthe PostOrderTranverse is:");
        PostOrderTranverse(&T,Display);
        ClearBiTree(&T);
        printf("\nis tree empty?:%d\n",BiTreeEmpty(&T));
        
        return 0;
}
