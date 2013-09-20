#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include "BinaryTree.h"

using namespace std;

// 获取二叉树中的节点数目
int GetBiTreeNodeNum(BiTree *T)
{
        if (BiTreeEmpty(T))
                return 0;
        return GetBiTreeNodeNum(&(*T)->left)+GetBiTreeNodeNum(&(*T)->right)+1;
}

// 获取二叉树的深度
int GetBiTreeDepth(BiTree *T)
{
        if(BiTreeEmpty(T))
                return 0;
        int DepthLeft=GetBiTreeDepth(&(*T)->left);
        int DepthRight=GetBiTreeDepth(&(*T)->right);
        return (DepthLeft>DepthRight?DepthLeft:DepthRight)+1;
}

// 层序遍历二叉树
void  LevelOrderTranverse(BiTree *T,pFunc Visit)
{
        if(!(*T))
                return;
        queue<BiNode *> que1;
        Visit(*T);
        que1.push(*T);
        BiNode *Tmp=NULL;
        while(!que1.empty())
        {
                Tmp=que1.front();
                que1.pop();
                if(Tmp->left)
                {
                        Visit(Tmp->left);
                        que1.push(Tmp->left);
                }

                if(Tmp->right)
                {
                        Visit(Tmp->right);
                        que1.push(Tmp->right);
                }
        }
        return;

}

// 统计二叉树在第Ｋ层有多少个节点
int GetCountOfLevelK(BiTree *T,int K)
{
        if(!(*T))
                return 0;
        if(1==K)
                return 1;
        else
                return GetCountOfLevelK(&(*T)->left,K-1)+GetCountOfLevelK(&(*T)->right,K-1);
}

// 统计二叉树中的叶子节点个数
int LeafCount=0;
void isTheNodeLeaf(BiNode *p)
{
        if(p && !p->left && !p->right)
                LeafCount++;
}

int GetCountOfLeaf(BiTree *T)
{
        PreOrderTranverse(T,isTheNodeLeaf);
        return LeafCount;
}

// 判断两棵二叉树的结构是否相同
bool StructCmp(BiTree T1,BiTree T2)
{
        if (!T1 && !T2)
                return true;
        else if(!T1 || !T2)
                return false;
        else
                return StructCmp(T1->left,T2->left) && StructCmp(T1->right,T2->right);
}

// 判断一棵二叉树是不是平衡二叉树
bool IsBiTreeBalance(BiTree T)
{
        if(!T)
                return true;
        int DepthLeft=GetBiTreeDepth(&(T->left));
        int DepthRight=GetBiTreeDepth(&(T->right));

        if(IsBiTreeBalance(T->left) && IsBiTreeBalance(T->right) && abs(DepthLeft-DepthRight)<=1)
                return true;
        else 
                return false;
}

// 求一棵二叉树的镜像
BiTree Mirror(BiTree T)
{
        if (!T)
                return NULL;
        BiTree Tleft=Mirror(T->left);
        BiTree Tright=Mirror(T->right);

        T->left=Tright;
        T->right=Tleft;

        return T;
}

// 求两个节点的最近公共节点
bool FindNode(BiTree T,BiNode *p)
{
        if(T == NULL || p == NULL)  
                return false;  

        if(T == p)  
                return true;  
        bool found = FindNode(T->left, p);  
        if(!found)  
                found = FindNode(T->right, p);  
        return found;  
}

BiNode* FindRecentPublic(BiTree T,BiNode *A,BiNode *B) 
{
        if(FindNode(T->left, A))  
        {  
                if(FindNode(T->right, B))  
                        return T;  
                else  
                        return FindRecentPublic(T->left, A, B);  
        }  
        else  
        {  
                if(FindNode(T->left, B))  
                        return T;  
                else  
                        return FindRecentPublic(T->right, A, B);  
        }  

}  

int main()
{
        BiTree T=NULL;
        CreatBiTreeFromFile("tree2.txt",&T);
        BiTree T2=NULL;
        CreatBiTreeFromFile("tree1.txt",&T2);
        // printf("The Number of Node in this tree is:%d\n",GetBiTreeNodeNum(&T));
        // printf("The Depth of tree2 is:%d\n",GetBiTreeDepth(&T));
        // printf("The Levelorder tranverse of tree2 is:\n");
        // LevelOrderTranverse(&T,Display);
        // printf("The Count of Level 3 for tree2 is:%d",GetCountOfLevelK(&T,3));
        // printf("The Number of Leaf in tree2 is:%d\n",GetCountOfLeaf(&T));
        // printf("If tree2 == tree2%d\n",StructCmp(T,T));
        // printf("If tree2 == tree1%d\n",StructCmp(T,T2));
        // printf("is tree 2 balanced?:%d\n",IsBiTreeBalance(T));
        // printf("The Mirror of tree2 is:\n");
        // Mirror(T);
        // InOrderTranverse(&T,Display);
        BiNode *p=FindRecentPublic(T,T->left->left->right,T->left->left);
        if(!p)
                printf("%d",p->data);

        DestoryBiTree(&T);
        DestoryBiTree(&T2);

        
        return 0;
}
