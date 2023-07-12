 cmake_minimum_required(VERSION 3.12)
 project(WebSocketProject)
 
 set(CMAKE_CXX_STANDARD 20)
 
 # Find Boost
 find_package(Boost 1.82.0 COMPONENTS system REQUIRED)
 #include_directories(/opt/homebrew/include)
 
 # Add the executable target
 add_executable(websocket websocket.cpp)
 
 # Link against Boost libraries
 target_link_libraries(websocket PRIVATE Boost::system)
 