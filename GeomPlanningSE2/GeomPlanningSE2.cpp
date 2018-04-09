#include <ompl/geometric/SimpleSetup.h>
#include <ompl/base/spaces/SE2StateSpace.h>
#include <cmath>
#include <ompl/base/SpaceInformation.h>
#include <ompl/geometric/planners/rrt/RRT.h>
#include <iostream>
#include <fstream>
#include<cstdlib>
#include <string>
#include<stdlib.h>
#include "boost/bind.hpp"
#include <vector>

namespace ob = ompl::base;
namespace og = ompl::geometric;

// Return true if the state is valid, false if the state is invalid
bool isStateValid(const ob::State *state)
{
  const ob::SE2StateSpace::StateType *state_2d = state->as<ob::SE2StateSpace::StateType>();
  const double &x(state_2d->getX()), &y(state_2d->getY());
  int grid[200][200];
  std::ifstream infile;
   infile.open("/home/ljq/ompl_tutorial/OMPL_Sample/GeomPlanningSE2/33.txt");
   //infile.open("/home/ljq/ompl_tutorial/OMPL_Sample/GeomPlanningSE2/plot/22.txt");
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


  if((grid[int(x)][int(y)]==0.0)||(grid[int(x)+1][int(y)]==0.0)||(grid[int(x)-1][int(y)]==0.0)||(grid[int(x)][int(y)+1]==0.0)||(grid[int(x)][int(y)-1]==0.0))
  {
 // if((x>50)&&(x<100)&&(y>50)&&(y<100))
       return false;       
  }
  else
  {
        return true;
  }
}
void planWithSimpleSetup(void)
{

  ob::StateSpacePtr space(new ob::SE2StateSpace());
  ob::RealVectorBounds bounds(2);
  bounds.setLow(0);
  bounds.setHigh(200);
  space->as<ob::SE2StateSpace>()->setBounds(bounds);

  // Instantiate SimpleSetup
  og::SimpleSetup ss(space);

  // Setup the StateValidityChecker

    ss.setStateValidityChecker(boost::bind(&isStateValid, _1));
  // Setup Start and Goal
  ob::ScopedState<ob::SE2StateSpace> start(space);
  start->setXY(20,20);
  //std::cout << "start: "; start.print(std::cout);

  ob::ScopedState<ob::SE2StateSpace> goal(space);
  goal->setXY(150,50);
  //std::cout << "goal: "; goal.print(std::cout);

  ss.setStartAndGoalStates(start, goal);

  ob::PlannerPtr planner(new og::RRT(ss.getSpaceInformation()));

  ss.setPlanner(planner);

  std::cout << "----------------" << std::endl;

  // Execute the planning algorithm
  ob::PlannerStatus solved = ss.solve(30.0);

  // If we have a solution,
  if (solved)
  {
    std::cout << "----------------" << std::endl;
    std::cout << "Found solution:" << std::endl;
    ss.getSolutionPath().print(std::cout);
    std::ofstream ofs("/home/ljq/ompl_tutorial/OMPL_Sample/GeomPlanningSE2/plot/path.dat");
    ss.getSolutionPath().printAsMatrix(ofs);
  }
  else
    std::cout << "No solution found" << std::endl;
}


int main()
{
  planWithSimpleSetup();
  return 0;
}
