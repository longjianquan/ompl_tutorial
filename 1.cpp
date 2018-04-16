#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
#include<fstream>
#include<stdlib.h>
#include<memory>
#include<cmath>
#include<string>
#include "boost/bind.hpp"

using namespace std;

int f(int a,int b)
{
        return a+b;
}
int main()
{
       
        cout<<boost::bind(f,_1,_2)(1,2)<<endl;
}
