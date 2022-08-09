# CMakeList.txt: Spring 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

include_directories(./http)
include_directories(./http/msg)
include_directories(./utils)
include_directories(./socket)


# 将源代码添加到此项目的可执行文件。
add_executable (Spring 
				Spring.cpp
				Spring.h 

				socket/Address.cpp
				socket/Address.h 
				socket/CLSocket.h 
				socket/CLSocket.cpp
				socket/ServerSocket.h 
				socket/ServerSocket.cpp
				socket/ClientSocket.h 
				socket/ClientSocket.cpp

				utils/StringUtils.cpp
				utils/StringUtils.h
				utils/TimeUtils.cpp
				utils/TimeUtils.h

				http/msg/DefaultResponseMessage.cpp
				http/msg/DefaultResponseMessage.h
				http/msg/ResponseMessage.cpp
				http/msg/ResponseMessage.h

				
				http/HttpInfo.cpp
				http/HttpInfo.h
				http/RequstProxy.cpp
				http/RequstProxy.h
				http/Control.cpp
				http/Control.h
				http/HttpClient.cpp
				http/HttpClient.h
				http/HttpServer.cpp
				http/HttpServer.h
				http/HttpResponse.cpp
				http/HttpResponse.h
				http/HttpRequest.cpp
				http/HttpRequest.h
				http/Http.cpp
				http/Http.h

				rapidjson
				)

# TODO: 如有需要，请添加测试并安装目标。
