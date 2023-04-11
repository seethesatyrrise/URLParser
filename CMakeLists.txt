cmake_minimum_required(VERSION 3.16)     

project(URLParser)                      

add_executable(                          
  ${PROJECT_NAME}                       
  main.cpp                               
)   

add_executable(                          
  tests                      
  main.cpp                               
) 

target_compile_definitions(
  tests PUBLIC TESTING
)

install(                                 
  TARGETS ${PROJECT_NAME} tests                
  RUNTIME DESTINATION bin                
)     