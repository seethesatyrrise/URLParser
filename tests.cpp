

void DoTests() {
    const char* request1 = new char[100]{"GET http://abc.ru/main/test/test1/test2"};
    const char* request2 = new char[100]{"POST http://abc.ru/main/test"};
    const char* request3 = new char[100]{"DELETE http://abc.ru/main/part2?param=3&param=4"};
    const char* request4 = new char[100]{"PUT http://abc.ru/main/test/test1"};
    const char* request5 = new char[100]{"ABC http://abc.ru/main/test/test1"};

    TestGetMethod(request1, Method::GET);
    TestGetMethod(request2, Method::POST);
    TestGetMethod(request3, Method::DELETE);
    TestGetMethod(request4, Method::PUT);
    TestGetMethod(request5, Method::GET);
}

void TestGetMethod(const char* url, Method method) {
    static int TestNum = 1;
    std::cout << "Test #" << TestNum++ << ": ";

    URLParser test(url);

    if (!test)          
        return;
    
    if (test.GetMethod() == method) 
        std::cout << "passed\n";
    else
        std::cout << "failed\n";

}