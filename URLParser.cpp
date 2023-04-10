

void URLParser::ParseMethodAndURL(const char* URL) {            // Separates input into url-string and method-string
    std::string str = std::string(URL);                         // (is it's impossible, marks object as invalid and returns)
    int separator = str.find(" ");                              // then defines Method value for method-string
    if (separator == -1) {                                      // (if method-string is not in Method values, marks 
        std::cout << "invalid string\n";                        // object as invalid and returns)
        isValid = false; 
        return;
    }

    url = str.substr(separator + 1);                            
    std::string methodStr = str.substr(0, separator);           

    if (methodStr == "GET") method = Method::GET;               
    else if (methodStr == "POST") method = Method::POST;
    else if (methodStr == "PUT") method = Method::PUT;
    else if (methodStr == "DELETE") method = Method::DELETE;
    else {
        std::cout << "invalid method\n";
        isValid = false;                                        
    };
}

Method URLParser::GetMethod() {                                 
    return method;
}

URLParser::operator bool() const {                             
    return isValid;
}