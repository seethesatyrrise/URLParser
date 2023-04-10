#include <iostream>
#include <string>

enum class Method {GET, POST, PUT, DELETE};

class URLParser {
    std::string url;
    Method method;
    bool isValid = true;
    void ParseMethodAndURL(const char*);

public:
    URLParser(const char* URL) {
        ParseMethodAndURL(URL);
    }
    std::string GetURL();
    Method GetMethod();
    operator bool() const;
};

#include "URLParser.cpp"