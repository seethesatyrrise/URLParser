#include <iostream>
#include <string>
#include <vector>

using std::vector;

enum class Method {GET, POST, PUT, DELETE};

class URLParser {
    std::string url;
    Method method;
    vector<std::string> paths;
    bool isValid = true;
    void ParseString(const char*);
    void ParseMethod(std::string);
    void ParsePaths(std::string);

public:
    URLParser(const char* URL) {
        ParseString(URL);
    }
    std::string GetURL();
    Method GetMethod();
    std::string GetPath(int);
    operator bool() const;
};

#include "URLParser.cpp"