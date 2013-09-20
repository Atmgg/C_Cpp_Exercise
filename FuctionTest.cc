#include <stdio.h>


int main(){
	int max(int,int);
	int (*p)(int,int);
	p = &max;
	int a = 0;
       	int b = 0;
	unsigned int addr = 0x10203040;
	char *p1 = (char*)addr;
	p1 =(char*)(&a);

	//scanf("%d,%d",&a,&b);
	//int c = (*p)(a,b);
	//printf("max is %d\n",c);
	return 0;
}

int printmax(void){
	int a = 0;
       	int b = 0;
	scanf("%d,%d",&a,&b);
	int max(int,int);
	int c = max(a,b);
	printf("max is %d\n",c);
}

int max(int x, int y){
	return x>y?x:y;
}

