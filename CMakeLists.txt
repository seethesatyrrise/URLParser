cmake_minimum_required(VERSION 3.16)     

project(URLParser)                      

add_executable(                          
  ${PROJECT_NAME}                       
  main.cpp                               
)                                        

install(                                 
  TARGETS ${PROJECT_NAME}                
  RUNTIME DESTINATION bin                
)     