#include <iostream>
#include <math.h>
#include <time.h>
#include "includes/functions.hpp"



int main(){

      //  536870913
long start = 10000000;
long end = start * 10;
for (long i = 40756; i < end; i++) {
		double isH = isHexagonal(i);
    if (isH == floor(isH)) {
	//		cout<<"Hexagon!:"<<isH<<"  "<<i<<"\n";
			double isP = isPentagonal(i);
      if (isP == floor(isP)) {
				cout<<"Hexagon!:"<<isP<<"  "<<i<<"\n";
        double isT = isTriangle(i);
    		if (isT == floor(isT)) {
					cout<<"Triangle!:"<<isT<<"  "<<i<<"\n";
          cout<<(isTriangle(i))<<"\n";
          cout<<(isPentagonal(i))<<"\n";
          cout<<(isHexagonal(i))<<"\n";
          cout<<i;
          break;
					}
        }
    }

  /*  if ($isT && $isP && $isH) {
        var_dump(isTriangle($i));
        var_dump(isPentagonal($i));
        var_dump(isHexagonal($i));
        var_dump($i);
        die();
    }*/
}
cout<<"\nNOP!";


}
