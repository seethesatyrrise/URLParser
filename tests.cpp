

void DoTests() {
    const char* request1 = new char[100]{"GET http://abc.ru/main/test/test1/test2"};
    const char* request2 = new char[100]{"POST http://abc.ru/main/test"};
    const char* request3 = new char[100]{"DELETE http://abc.ru/main/part2?param=3&param=4"};
    const char* request4 = new char[100]{"PUT http://abc.ru/main/test/test1?id=1&value=10"};

    TestGetMethod(request1, Method::GET);
    TestGetMethod(request2, Method::POST);
    TestGetMethod(request3, Method::DELETE);
    TestGetMethod(request4, Method::PUT);

    std::cout << "\n";

    TestGetPath(request1, 0, "main");
    TestGetPath(request1, 2, "test1");
    TestGetPath(request1, 3, "test2");
    TestGetPath(request3, 1, "part2");
    TestGetPath(request3, 2, "");
    TestGetPath(request3, -1, "");

    std::cout << "\n";

    std::map<std::string, vector<std::string>> request3params {{"param", {"3", "4"}}};
    std::map<std::string, vector<std::string>> request4params {{"id", {"1"}}, {"value", {"10"}}};

    TestGetParams(request3, request3params);
    TestGetParams(request4, request4params);

    delete request1;
    delete request2;
    delete request3;
    delete request4;
}

void TestGetMethod(const char* url, Method expected) {
    static int testNum = 1;
    std::cout << "GetMethod Test #" << testNum++ << ": ";

    URLParser test(url);

    if (!test)          
        return;
    
    if (test.GetMethod() == expected) 
        std::cout << "passed\n";
    else
        std::cout << "failed\n";

}

void TestGetPath(const char* url, int pathNum, std::string expected) {
    static int testNum = 1;
    std::cout << "GetPath Test #" << testNum++ << ": ";

    URLParser test(url);

    if (!test)          
        return;
    
    if (test.GetPath(pathNum) == expected) 
        std::cout << "passed\n";
    else
        std::cout << "failed\n";
}

void TestGetParams(const char* url, std::map<std::string, vector<std::string>> expected) {
    static int testNum = 1;
    std::cout << "GetParams Test #" << testNum++ << ": ";

    URLParser test(url);

    if (!test)          
        return;

    if (test.GetParams() == expected) 
        std::cout << "passed\n";
    else
        std::cout << "failed\n";
}