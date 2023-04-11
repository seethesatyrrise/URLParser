#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::vector;
using std::map;

enum class Method {GET, POST, PUT, DELETE};

class URLParser {
    std::string url;
    Method method;
    vector<std::string> paths;
    map<std::string, vector<std::string>> params;
    bool isValid = true;
    void ParseString(const char*);
    void ParseMethod(std::string);
    void ParsePaths(std::string);
    void ParseParams(std::string);

public:
    URLParser(const char* URL) {
        ParseString(URL);
    }
    std::string GetURL();
    Method GetMethod();
    std::string GetPath(int);
    map<std::string, vector<std::string>> URLParser::GetParams();
    operator bool() const;
};

#include "URLParser.cpp"