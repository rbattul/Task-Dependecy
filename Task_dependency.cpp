/* 

Given a set of courses dependencies find the order to take up the courses

physics depends on maths
chemistry depends on maths
maths
computer science depends on maths and physics
Accounting depdends on maths
Biology depends on chemistry and computer science

*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void populateDepedencyCount(map<int,int> &DepCount, vector<pair<int,int>> &taskDep)
{
    for(auto &obj : taskDep)
    {
        if(obj.second != 0)
        {
            DepCount[obj.first]++;
        }
        else
        {
            DepCount[obj.first] = DepCount[obj.first];
        }
    }
}

void prepareList(map<int,vector<int>> &outlist, map<int,int> &inDepMat)
{
    for (auto it = inDepMat.begin(); it != inDepMat.end(); ++it)
    {
            vector<int> temp;
            temp.reserve(6);
            temp = outlist[it->second];
            temp.push_back(it->first);
            outlist[it->second] = temp;
    }
}

int main()
{
    map<int,string> TaskRank = {            {1,"Physics"},
                                            {2,"Maths"},
                                            {3,"Chemistry"},
                                            {4,"Computer Sci"},
                                            {5,"Accounting"},
                                            {6,"Biology"}
                                        };
                                        
    vector<pair<int,int>> TaskDepedency = {
                                         {1,2},{3,2},{2,0},{5,2},{6,3},{6,4},{4,2},{4,1}
                                        // {1,2},{3,2},{5,2}
                                        // {4,2},{4,1},{6,3},{6,4}
                                    }; 
                                    
    map<int,int> DependecyCount;
    map<int,vector<int>> list;
    populateDepedencyCount(DependecyCount,TaskDepedency);
    
    cout << endl << "TaskRank Count :- "  << TaskRank.size();
    
   for (auto it = DependecyCount.begin(); it != DependecyCount.end(); ++it)
    {
            cout << endl << it->first << " :- " << it->second;
    }
    
     cout << endl << " preparing List " << endl;
     
    prepareList(list,DependecyCount);
    
    cout << endl << " prepared List " << endl;
    
    cout << endl << " Printing List " << endl;
    
     for (auto it = list.begin(); it != list.end(); ++it)
    {
            cout << endl << it->first << " :- ";
            
            vector<int> t = it->second;
            
            for(auto i = 0; i< t.size(); ++i)
            {
                cout << TaskRank[t[i]] << (i != t.size()-1? ",":"");
            }
            cout << endl;
            
    }
    
    return 0;
}