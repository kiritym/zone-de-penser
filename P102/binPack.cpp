#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool pairCompare(const std::pair<std::string, int>& firstElem, const std::pair<std::string, int>& secondElem) {
      if(firstElem.second == secondElem.second)
          return firstElem.first < secondElem.first;
      else
          return firstElem.second < secondElem.second;
}

class Bin{
  public:
  int brown;
  int green;
  int clear;
  Bin(int b, int g, int c){
        brown = b;
        green = g;
        clear = c;
  }

  int keepBrown(){
    return green+clear;
  }

  int keepGreen(){
    return brown+clear;
  }

  int keepClear(){
    return green+brown;
  }

};

int main(){
    int array[9];
    cout<<"enter the 9 numbers: "<<endl;
    for(int i = 0; i < 9; ++i)
    {
        cin>>array[i];
    }
    
    Bin first(array[0], array[1], array[2]),
        second(array[3], array[4], array[5]),
        third(array[6], array[7], array[8]);
    //BGC, BCG, GCB, GBC, CGB, CBG
    //std::map<std::string, int>moveMap;
    std::vector<std::pair<std::string, int> >moveVector;
    moveVector.push_back(std::make_pair("BGC", first.keepBrown()+second.keepGreen()+third.keepClear()));
    moveVector.push_back(std::make_pair("BCG", first.keepBrown()+second.keepClear()+third.keepGreen()));
    moveVector.push_back(std::make_pair("GCB", first.keepGreen()+second.keepClear()+third.keepBrown()));
    moveVector.push_back(std::make_pair("GBC", first.keepGreen()+second.keepBrown()+third.keepClear()));
    moveVector.push_back(std::make_pair("CGB", first.keepClear()+second.keepGreen()+third.keepBrown()));
    moveVector.push_back(std::make_pair("CBG", first.keepClear()+second.keepBrown()+third.keepGreen()));

    std::vector<std::pair<std::string, int> >::iterator iter;

    for(iter=moveVector.begin(); iter!=moveVector.end(); ++iter)
    {
        std::cout<<iter->first<<"=>"<<iter->second<<std::endl;
    }

    std::cout<<"Optimized solution is: "<<std::endl;
    std::sort(moveVector.begin(), moveVector.end(), pairCompare);
    std::cout<<moveVector.begin()->first<<"=>"<<moveVector.begin()->second<<std::endl;
}

