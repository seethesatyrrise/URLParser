#include "main.h"

int main() {

#ifndef TESTING
    while (1) {
        std::cout << "Input string:\n";
        std::string input;
        std::getline(std::cin, input);
        URLParser parsedString(input.c_str());
        if (!parsedString) {
            continue;
        }
        PrintMethod(parsedString);
        PrintPaths(parsedString);
        PrintParams(parsedString);
        std::cout << "\n";
    }
#else
    DoTests();
#endif
    std::cin.get();
}

void PrintMethod(URLParser parsedString) {
    std::cout << "Method: ";
    Method method = parsedString.GetMethod();
    switch (method) {
        case Method::GET:
        std::cout << "GET\n";
        break;
        case Method::POST:
        std::cout << "POST\n";
        break;
        case Method::PUT:
        std::cout << "PUT\n";
        break;
        case Method::DELETE:
        std::cout << "DELETE\n";
        break;
    }
}

void PrintPaths(URLParser parsedString) {
    std::cout << "\nPaths:\n";
    for (int i = 0; ; i++) {
        std::string path = parsedString.GetPath(i);
        if (path.size() > 0) {
            std::cout << "Path #" << i << ": " << path << "\n"; 
        } else {
            return;
        }
    }
}

void PrintParams(URLParser parsedString) {
    std::cout << "\nParameters:\n";
    map<std::string, vector<std::string>> params = parsedString.GetParams();
    for (auto item : params) {
        for (auto value : item.second) {
            std::cout << "\"" << item.first << "\" = \"" << value << "\"\n";
        }
    }
}