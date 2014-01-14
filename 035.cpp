#include <iostream>
#include <math.h>
#include <time.h>
#include "includes/functions.hpp"

int main(){

int megaSum = 0;

vector<int> primes = primesTo(1000000);
int numOfPrimes = primes.size();

for(int i=0;i<numOfPrimes;i++)
{
	int factor = 1, rotations = 0;
	int rotated = rotlNumber(primes[i]);
	bool flag = !hasZero(primes[i]);
	while(factor<=primes[i]){factor*=10; rotations++;}factor*=0.1;
	for(int j =0;j<rotations && flag && (rotated!=primes[i]) ;j++)
	{
		flag = isPrime(rotated);
		rotated = rotlNumber(rotated);
	}
	if(flag){megaSum++; cout<<primes[i]<<"  "<<rotations<<"\n";}
}



cout<<"\n--"<<megaSum<<"--\n";

int t = clock();
cout<<"\n"<< ((float)(t))/1000<<"sec";
	}
