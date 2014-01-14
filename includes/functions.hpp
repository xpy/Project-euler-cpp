#include <iostream>
#include <vector>
#include <math.h>
//#include <gmp.h>
#include <algorithm>
using namespace std;

vector<int> primesTo(int to){
	vector<int> odds;
	int cur = 3;
	bool flag = true;
	int numOfOdds = 0;
	int prek = 0;
	bool sqrtFlag;
	double sqrtCur;
	int k;
	while(cur<to){
		if(flag){
			sqrtFlag= true;
			sqrtCur = sqrt(cur);
			if((sqrtCur) == floor(sqrtCur)){flag = false;}
			for(k = prek; sqrtFlag && k<numOfOdds; k++ )
			{
			 		if(odds[k]>= sqrtCur){ sqrtFlag = false; prek = k; }
			}
 		} else { flag = true;}

 		for(int i = 0; flag && i < k ; i++)
 		{
		 		if(cur%odds[i] == 0){flag = false;}
 		}
 		if (flag) {odds.push_back(cur); numOfOdds++; }
 		cur+=2;
	}
	vector<int>::iterator  it = odds.begin();
	odds.insert(it,2);
	return odds;
}


int isPrime(int num ){
    double sqr = sqrt(num);
    double rem;
    if(modf(sqr,&rem) == 0.0 ){return false;}
    sqr = (int) floor(sqr);
   for(int i = 3 ; i <= sqr; i+=2){
        if((num % i) == 0){return false;}
    }
    return !(num%2 == 0);
}


int nextPrime(int num){
    if(num%2 == 0){num+=1;}
    else if(isPrime(num)){num+=2;}
    while(!isPrime(num)){num+=2;}
    return num;
}


int isPalindrome( int num){
	int factor = 1;
	int factor2 = 10;
	while(factor<=num){factor*=10;}
	factor*=0.1;
	bool flag = true;
	while(factor >= factor2)
	{
	 flag = floor(num/factor) == (num%factor2);
	 if(!flag){return flag;}
	 num=floor((num%factor)*0.1); factor*=0.01;
	}
	return flag;
}


int sumOfDigits(int num){
    int sum = 0;
    int guard =num*10;
    for(int i =10 ;i<= guard; i*=10){
        sum += floor((num%i)/(i*0.1));
    }
    return sum;
}

bool hasZero(int num)
{
    int guard =num*10;
    for(int i =10 ;i<= guard; i*=10){
        if(floor((num%i)/(i*0.1)) == 0 ){return true;}
    }
    return false;
}

int factorial(int num)
{
    if(num >0 ){  return num * factorial(num-1); }
    return 1;
}

vector<int> divisors(int num)
{
 		vector<int> divisors;
    if(isPrime(num)){ divisors.push_back(1); divisors.push_back(num);return divisors;}
    int border = num;
    int step = num%2+1;

    for(int i = 1 ;  i <=  border;  i+= step){
        if(!(num%i)){ divisors.push_back(i); border = (num/i); divisors.push_back(border); }
    }
   if(num!=1){ divisors.push_back(num);}
   sort(divisors.begin(),divisors.end());
   vector<int>::iterator it;
   it = unique(divisors.begin(),divisors.end());
   divisors.resize(it-divisors.begin());
    return divisors;
}

vector<int> properDivisors(int num)
{   vector<int> divs = divisors(num);
    divs.pop_back();
    return(divs);
}

vector<int> addArrays(vector<int> array1, vector<int> array2){
    int len = min(array1.size(),array2.size());

    vector<int> ret;
    for(int i=0;i<len;i++){

        ret.push_back(array1[i] + array2[i]);

    }
    return ret;
}

int array_sum(vector<int> arr)
{int sum = 0;
	for(int i =arr.size()-1;i>0;sum+=arr[i--]){}
	return sum;
}
bool isPerfect(int num)
{
    return (array_sum(properDivisors(num))== num);
}

bool isDeficient(int num)
{
    return (array_sum(properDivisors(num)) < num);
}

bool isAbundant(int num)
{
    return (array_sum(properDivisors(num)) > num);
}

int array_search (int needle,vector<int> haystack)
{
  vector<int>::iterator it;
	it = search_n (haystack.begin(),haystack.end(), 1, needle);
	return int(it-haystack.begin());
	}

	int rotlNumber(int num)
	{
		int factor = 1;
		while(factor<=num){factor*=10;}factor*=0.1;
		return (((num%factor)*10)+floor(num/factor));
	}
/*  ----------------- */
void printVec(vector<int> vec)
{
   int length = vec.size();
   for(int i = 0; i< length; i++)
   { cout<< vec[i] << '\n';}
}

int getDigit(int number,int digit){
	int i  = 1;
	for(i = 0;pow(10,i)<=number;i++);
	return (int)(number/pow(10,i-1-digit))%10;
}

double isTriangle(long num){

//    $delta = 1 - 4*2*$num*-1;
//    long delta = 1 + 8*num;
//		cout<<"+++"<<2*num<<"\n";
//		cout<<"+++"<<delta<<"\n";
    double x1 = (-1 + sqrt(1 + 8*num))/2;
  //  $x2 = (-1 - sqrt($delta))/2;

//    return [$x1,$x2];
    return x1;

}

double isPentagonal(long num){

//    $delta = 1 - 4*3*2*$num*-1;
   // long delta = 1 + 24*num;
//    $x1 = (1 + sqrt($delta))/(2*3);
    double x1 = (1 + sqrt(1 + 24*num))/6;
    //  $x2 = (-1 - sqrt($delta))/2;

//    return [$x1,$x2];
    return x1;

}
double isHexagonal(long num){

//    $delta =1 - 4*2*$num*-1;
   // long delta = 1 + 8*num;
   // $x1 = (1 + sqrt($delta))/(2*2);
    double x1 = (1 + sqrt(1 + 8*num))/4;
    //  $x2 = (-1 - sqrt($delta))/2;

//    return [$x1,$x2];
    return  x1;

}
