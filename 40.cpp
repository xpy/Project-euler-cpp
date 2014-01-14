#include <iostream>
#include <math.h>
#include <time.h>
#include "includes/functions.hpp"


/*
1...9 n
10...29 %2==0 1 %2==1 =n%10
30...49 %2==0 2 %2==1 =n%10
50...69 %2==0 3 %2==1 =n%10

190...219 %3==0 1 %3==1 0 %3==2 n%100
100101102103104105106107108109 110
1-9
10-179
190-2699
10^(d-1)- 10^d-1
*/

int main(){


	int d = 10;
	int start = 0;
	int end = 0;
	int prej = 0;
	int numberInQuestion = 181;
	int digit = 0;
	int offset = 0;

	for(int numberInQuestion = 1;numberInQuestion <=1000000;numberInQuestion*=10){
		cout<<"The number in Question is: "<<numberInQuestion<<"\n";
		start=end=0;
		for(int j =1;j<=d;j++){
			start = end+1;
			end =start+ ((pow(10,j))*(j)-pow(10,j-1)*(j))-1;
			if(numberInQuestion>=start && numberInQuestion<= end){
				offset = (numberInQuestion-start);
				digit = ((numberInQuestion-start))%j;
				int number =(offset/j)+pow(10,j-1);
				cout<<"The number is: "<<getDigit(number,digit)<<"\n";
			}
		}
	}
}
