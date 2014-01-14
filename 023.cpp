#include <iostream>
#include <math.h>
#include <time.h>
#include "includes/functions.hpp"

int main(){

int megaSum = 0;
int largestAbudant = 28123;
	while(!isAbundant(--largestAbudant) && largestAbudant>0){ }
vector<int> abudants;
for (int i = 12; i<=largestAbudant;i++)
{
    if(isAbundant(i)){abudants.push_back(i);}
}
int numOfAbudants = abudants.size();
int k = 0;
int preAbu;
int preAbuIndex;
int sum; bool flag;
for(int i = 0; i<=28123; i++)
{
   /*  preAbu = i;
   while(!isAbundant(--preAbu) && preAbu>0){ }
    preAbuIndex = array_search(preAbu,abudants);
*/
    sum = 0;flag = true;int k ;
    for(k= 0 ; abudants[k]<i && flag; k++){
					flag = !isAbundant(i-abudants[k]);
    }
    if(flag){megaSum+=i;
  //  cout<< i<<"-"<<k<<"- sum:"<<sum<<"- SUM:"<<megaSum<<" === "<<preAbuIndex <<"\n";
	}
	if(i%100==0){	cout<<i<<"  "<<preAbuIndex<<" "<<preAbu<<"\n"; }
}

cout<<"\n--"<<megaSum<<"--\n";

int t = clock();
cout<<"\n"<< ((float)(t))/1000<<"sec";
	}
