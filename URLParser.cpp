const int DOMAIN_MIN_LENGTH = 9;

void URLParser::ParseString(const char* URL) {                  // Separates input into url-string and method-string
    std::string str = std::string(URL);                         // (is it's impossible, marks object as invalid and returns)
    int separator = str.find(" ");                              // then defines Method value for method-string
    if (separator == -1) {                                      // (if method-string is not in Method values, marks 
        std::cout << "invalid string\n";                        // object as invalid and returns), fills vector Paths
        isValid = false;                                        // and map Params
        return;
    }

    url = str.substr(separator + 1);                                      
    ParseMethod(str.substr(0, separator));

    int pathsSeparator = url.find("/", DOMAIN_MIN_LENGTH);
    int paramsSeparator = url.find("?");
    std::string paramsStr = url.substr(paramsSeparator == -1 ? url.size() : paramsSeparator);
    std::string pathsStr = url.substr(pathsSeparator + 1, url.size() - paramsStr.size() - pathsSeparator - 1);
    if (isValid){
        ParsePaths(pathsStr);
        if (paramsStr.size() > 0) {
            ParseParams(paramsStr.substr(1));
        }
    }
}

void URLParser::ParseMethod(std::string methodStr) {
    if (methodStr == "GET") method = Method::GET;               
    else if (methodStr == "POST") method = Method::POST;
    else if (methodStr == "PUT") method = Method::PUT;
    else if (methodStr == "DELETE") method = Method::DELETE;
    else {
        std::cout << "invalid method\n";
        isValid = false;                                        
    };
}

void URLParser::ParsePaths(std::string pathsStr) {
    for (; pathsStr.size() > 0;) {
        int separator = pathsStr.find("/");
        if (separator != -1) {
            paths.push_back(pathsStr.substr(0, separator));
            pathsStr = pathsStr.substr(separator + 1);
        } else {
            paths.push_back(pathsStr);
            pathsStr = "";
        }
    }
}

void URLParser::ParseParams(std::string paramsStr) {
    for (; paramsStr.size() > 0;) {
        std::string param = paramsStr;
        int separator = paramsStr.find("&");
        if (separator != -1) {
            param = paramsStr.substr(0, separator);
            paramsStr = paramsStr.substr(separator + 1);
        } else {
            paramsStr = "";
        }
        int valueSeparator = param.find("=");
        if (valueSeparator < 0) {
            std::cout << "invalid param; ";
            continue;
        }
        params[param.substr(0, valueSeparator)].push_back(param.substr(valueSeparator + 1));
    }
}

Method URLParser::GetMethod() {                                 
    return method;
}

std::string URLParser::GetPath(int pathNum) {
    if (pathNum >= 0 && paths.size() > pathNum)
        return paths[pathNum];
    else {
#ifdef TESTING
        std::cout << "no path for this num; ";
#endif
        return "";
    }
}

map<std::string, vector<std::string>> URLParser::GetParams() {
    return params;
}

URLParser::operator bool() const {                             
    return isValid;
}