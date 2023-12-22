cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(WebServer CXX)

set(SourceFiles
    "./src/Main.cpp"
    "./src/HTTP/HTTPMessage.cpp"
    "./src/HTTP/HTTPRequest.cpp"
    "./src/HTTP/HTTPResponse.cpp"
)

add_executable(${PROJECT_NAME} ${SourceFiles})