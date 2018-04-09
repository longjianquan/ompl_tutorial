#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  double grid[200][200];

  ifstream infile("/home/ljq/python test/111.txt");
  
  while (infile.good()&& !infile.eof())
  {
     for(int i=0;i<200;i++)
     {

         for(int j=0;j<200;j++)
         {             
             infile>>grid[i][j];                   
         }
     }
  }
  infile.close();
  
  ofstream outfile("/home/ljq/ompl_tutorial/OMPL_Sample/GeomPlanningSE2/33.txt");
       for(int i=0;i<200;i++)
     {

         for(int j=0;j<200;j++)
         {      
                outfile<<grid[i][j]<<" ";      
         
         }
         outfile<<"\n";
         
     }
  outfile.close();




        return 0;
}
