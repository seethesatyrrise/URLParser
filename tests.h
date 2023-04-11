#include <iostream>
#include "URLParser.h"
#include <string>

void DoTests();

void TestGetMethod(const char*, Method);

void TestGetPath(const char*, int, std::string); 

void TestGetParams(const char*, std::map<std::string, vector<std::string>>);

#include "tests.cpp"