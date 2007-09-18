#include "commonUtilities/commonUtilities.h"
#include <iostream>
using namespace std;

int main(){
  int errors = 0;
  string dataPath = commonUtilities::getDataPath("commonUtilities");
  if(dataPath == ""){
    cerr<<"Unable to get data path"<<endl;
    errors++;
  }
  string home = commonUtilities::getEnvironment("HOME");
  cout<<"$HOME is set to "<<home<<endl;
  commonUtilities::setEnvironment("COMMONUTILITIESTESTENV","test123");
  string testSet = commonUtilities::getEnvironment("COMMONUTILITIESTESTENV");
  if(testSet != "test123"){
    cerr<<"$COMMONUTILITIESTESTENV doesn't match test123"<<endl;
    errors++;
  }
  commonUtilities::setEnvironment("COMMONUTILITIESTESTENV","noOverwrite");
  testSet = commonUtilities::getEnvironment("COMMONUTILITIESTESTENV");
  if(testSet == "noOverwrite"){
    cerr<<"$COMMONUTILITIES incorrectly overwritten"<<endl;
    errors++;
  }
  commonUtilities::setEnvironment("COMMONUTILITIESTESTENV","overwrite",true);
  testSet = commonUtilities::getEnvironment("COMMONUTILITIESTESTENV");
  if(testSet != "overwrite"){
    cerr<<"$COMMONUTILITIES incorrectly not overwritten"<<endl;
    errors++;
  }
  return errors;
}
