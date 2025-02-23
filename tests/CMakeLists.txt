cmake_minimum_required(VERSION 3.31)
project(CatTests)

# ======================
# CTest 명령어로 여러개의 테스트 파일을 한번에 실행할 수 있다.
enable_testing()


# ======================
# GoogleTest 폴더 추가 🎉
add_subdirectory(googletest)


# ======================
# 헤더 파일 기본 검색 경로
include_directories(${CMAKE_SOURCE_DIR}/../include)
# ✅ iot.cc, Cat.cc, 등 여러곳에서 쓰이므로 기본 검색 경로로 설정한다.
include_directories(${CMAKE_SOURCE_DIR}/../libs)


# ======================
# 라이브러리 만들기
# 최상단 CMakeLists.txt와는 별개의 파일이므로 라이브러리를 다시 정의한다.
add_library(iot_lib ${CMAKE_SOURCE_DIR}/../libs/iot.cc)
# 테스트 코드 입장에서는 테스트하려는 구현체 코드도 결국 import해오는 라이브러리다.
add_library(cat_module ${CMAKE_SOURCE_DIR}/../src/Cat.cc)


# ======================
# 테스트 파일 생성 📁
add_executable(CatTest CatTest.cc)


# ======================
# GoogleTest 및 GoogleMock 라이브러리 링크
target_link_libraries(CatTest PRIVATE gtest_main gmock_main cat_module iot_lib)

# ======================
# CTest 명령어로 여러개의 테스트 파일을 한번에 실행할 수 있다.
add_test(NAME CatTest COMMAND CatTest)