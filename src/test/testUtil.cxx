/// @file testUtil.cxx
#include <string>
#include <iostream>
#include "facilities/Util.h"
/** Miniscule program to test a couple modes of Util::expandEnvVar
 *  Caller should have an environment variable SRC with some
 *  sensible definition.
 */
int main(int, char**) {
  std::string name = std::string("{FACILITIESROOT}/src");
  std::string oDelim = std::string ("{");
  std::string cDelim = std::string ("}");
  int ntrans;

  try {
    ntrans = facilities::Util::expandEnvVar(&name, oDelim, cDelim);
    std::cout << "Translated name is " << name << std::endl;  }
  catch (facilities::Untranslatable err) {
    std::cout << "Failed to completely translate " << name << std::endl;
  }



  // Process running this must have environment variable SRC
  std::string multi = std::string("$(FACILITIESROOT)/$(SRC)");

  try {
    ntrans = facilities::Util::expandEnvVar(&multi);

    std::cout << "Translated name is " << multi << std::endl;
    std::cout << ntrans << " variables were translated." << std::endl;
  }
  catch (facilities::Untranslatable err) {
    std::cout << "Failed to completely translate " << multi << std::endl;
  }

  // Test the new itoa routine
  std::string intStr;
  facilities::Util::itoa(12, intStr);
  std::cout << "My String is " << intStr << std::endl;

  // Test stringTokenize and basename
  std::string unixname("/a/path/myUnixFile.txt");
  std::string wname("C:\\a\\longer\\path\\myWindowsFile.txt");

  std::vector<std::string> tokens;
  unsigned int i;

  facilities::Util::stringTokenize(unixname, "/", tokens);

  std::cout << "Processing string " << unixname << std::endl;
  for (i = 0; i < tokens.size(); i++) {
    std::cout << "Token " << i << " is: " << tokens[i] << std::endl;
  }

  std::cout << "basename is " << facilities::Util::basename(unixname) << std::endl;

  facilities::Util::stringTokenize(wname, "\\", tokens);

  std::cout << "Processing string " << wname << std::endl;
  for (i = 0; i < tokens.size(); i++) {
    std::cout << "Token " << i << " is: " << tokens[i] << std::endl;
  }

  std::cout << "basename is " << facilities::Util::basename(wname) << std::endl;


  // Test stringToDouble routine
  std::string okDouble("3.14159");
  std::string badDouble("3.garbage56");

  double result = -1;

  try {
    result = facilities::Util::stringToDouble(okDouble);
    std::cout << "Converted (string) " << okDouble << " to (double) " 
              << result << std::endl;
  }
  catch (facilities::WrongType ex) {
    std::cout << "Failed with exception WrongType:  " << ex.getMsg() 
              << std::endl;
  }

  try {
    result = facilities::Util::stringToDouble(badDouble);
    std::cout << "Converted (string) " << badDouble << " to (double) " 
              << result << std::endl;
  }
  catch (facilities::WrongType ex) {
    std::cout << "Failed with exception WrongType: " << ex.getMsg() 
              << std::endl;
  }

  // Test stringToInt routine
  std::string okInt("33550");
  std::string badInt1("3garbage56");
  std::string badInt2("garbage356");

  int intResult = -1;

  try {
    intResult = facilities::Util::stringToInt(okInt);
    std::cout << "Converted (string) " << okInt << " to (int) " 
              << intResult << std::endl;
  }
  catch (facilities::WrongType ex) {
    std::cout << "Failed with exception WrongType:  " << ex.getMsg() 
              << std::endl;
  }

  try {
    intResult = facilities::Util::stringToInt(badInt1);
    std::cout << "Converted (string) " << badInt1 << " to (int) " 
              << intResult << std::endl;
  }
  catch (facilities::WrongType ex) {
    std::cout << "Failed with exception WrongType: " << ex.getMsg() 
              << std::endl;
  }

  try {
    intResult = facilities::Util::stringToInt(badInt2);
    std::cout << "Converted (string) " << badInt2 << " to (int) " 
              << intResult << std::endl;
  }
  catch (facilities::WrongType ex) {
    std::cout << "Failed with exception WrongType: " << ex.getMsg() 
              << std::endl;
  }

  return 0;
}

  
