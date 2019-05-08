#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int _n,*n=&_n,*p,_num=0,*num=&_num;
long timef;
float _time;

int check(int j){
	for(int i=1;j-i>=0;i++){
		if((*(p+j)>>i)==*(p+j-i)||(*(p+j)<<i)==*(p+j-i)||*(p+j)==*(p+j-i)) return 1;
	}
	return 0;
}

void loop(int j){
	for(int i=0;i<*n;i++){
		*(p+j)=1<<i;
		if(check(j)==0){
			if(j==*n-1) *num+=1;
			else loop(j+1);
		}
	}
}

void main(){
	printf("Input the amount of the queen:");
	scanf("%d",n);
	p=(int*)malloc(_n*sizeof(int));
	timef=clock();
	loop(0);
	_time=(float)(clock()-timef)/1000;
	printf("There are %d solutions of this question.\nTime used %.3fs.\n",_num,_time);
	getch();
}