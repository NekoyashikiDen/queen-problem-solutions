#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int check(int *p,int n,int j);
void loop(int *p,int n,int j,int *num);

void main(){
	int n,*p,_num=0,*num=&_num;
	long timef;
	float _time;
	printf("Input the amount of the queen:");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	timef=clock();
	loop(p,n,0,num);
	_time=(float)(clock()-timef)/1000;
	printf("There are %d solutions of this question.\nTime used %.3fs.\n",_num,_time);
	getch();
}

int check(int *p,int n,int j){
	for(int i=1;j-i>=0;i++){
		if((*p>>i)==*(p-i)||(*p<<i)==*(p-i)||*p==*(p-i)) return 1;
	}
	return 0;
}

void loop(int *p,int n,int j,int *num){
	if(j==n-1){
		for(int i=0;i<n;i++){
			*p=1<<i;
			if(check(p,n,j)==0) *num+=1;
		}
	}
	else{
		for(int i=0;i<n;i++){
			*p=1<<i;
			if(check(p,n,j)==1) continue;
			loop(p+1,n,j+1,num);
		}
	}
}