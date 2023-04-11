

void DoTests() {
    const char* request1 = new char[100]{"GET http://abc.ru/main/test/test1/test2"};
    const char* request2 = new char[100]{"POST http://abc.ru/main/test"};
    const char* request3 = new char[100]{"DELETE http://abc.ru/main/part2?param=3&param=4"};
    const char* request4 = new char[100]{"PUT http://abc.ru/main/test/test1"};
    const char* request5 = new char[100]{"ABC http://abc.ru/main/test/test1"};
    const char* request6 = new char[100]{"http://abc.ru/main/test/test1"};

    TestGetMethod(request1, Method::GET);
    TestGetMethod(request2, Method::POST);
    TestGetMethod(request3, Method::DELETE);
    TestGetMethod(request4, Method::PUT);
    TestGetMethod(request5, Method::GET);
    TestGetMethod(request6, Method::GET);

    std::cout << "\n";

    TestGetPath(request1, 0, "main");
    TestGetPath(request1, 2, "test1");
    TestGetPath(request1, 3, "test2");
    TestGetPath(request3, 1, "part2");
    TestGetPath(request3, 2, "");
    TestGetPath(request3, -1, "");

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