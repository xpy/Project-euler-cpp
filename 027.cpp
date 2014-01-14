#include <iostream>
#include <math.h>
#include <time.h>
#include "includes/functions.hpp"

int main(){

int megaSum = 0;

bool flag = true;
int n =0;
int nsq = 0;
int nPb = 0;
int max , maxa , maxb,amul ,count= 0;


for(int b =-1000; b<=1000;b++)
{
	for(int a = -1000;a<=1000; a++)
	{
		n=0;
		amul =0;
		while(flag)
		{
			nsq  = n*n; nPb = nsq+b+amul;
			flag = isPrime(nPb) && nPb>0;
			amul+=a;
			n++;
		}

		flag  =true;
		max = ((max>=n)?max:(n-1));
		if(max == n-1){maxa = a; maxb=b;
		cout<<b<<"  "<<a<<"  "<<n<<"  "<<nPb<<"  "<<max<<"\n";}
	}
}


cout<<"\n--"<<maxa<<"   "<<maxb<<"   "<<maxa*maxb<<"  "<<max<<"--\n";

int t = clock();
cout<<"\n"<< ((float)(t))/1000<<"sec";
	}
