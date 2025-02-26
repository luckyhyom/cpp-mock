cmake_minimum_required(VERSION 3.31)
project(CatTests)

# 전체 프로젝트에 컴파일 옵션 추가
add_compile_options(-Wall -Wextra)

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


# ======================
# Mocking 첫번째 예제 - 파일을 교체하기
add_executable(CatTest2_Mock CatTest2_Mock.cc)
add_library(mock_iot_lib ${CMAKE_SOURCE_DIR}/mock/iot_mock.cc)
target_link_libraries(CatTest2_Mock PRIVATE gtest_main gmock_main cat_module mock_iot_lib)

add_test(NAME CatTest2_Mock COMMAND CatTest2_Mock)


# ======================
# Mocking 두번째 예제 - 값을 조작하기 (구현 파일 교체 및 전역 변수 활용)
add_library(mock_dyn_iot_lib ${CMAKE_SOURCE_DIR}/mock/iot_mock_dynamic.cc)
include_directories(mock_dyn_iot_lib PUBLIC ${CMAKE_SOURCE_DIR}/mock/)
add_executable(CatTest3_Mock_Dynamic CatTest3_Mock_Dynamic.cc)
target_link_libraries(CatTest3_Mock_Dynamic PRIVATE gtest_main gmock_main cat_module mock_dyn_iot_lib)

add_test(NAME CatTest3_Mock_Dynamic COMMAND CatTest3_Mock_Dynamic)

# ======================
# Mocking 세번째 예제 - 값을 조작하기 (구현 파일 교체 및 전역 변수 활용) (GMock을 사용한 함수 오버라이딩)
add_library(iot_gmock_lib ${CMAKE_SOURCE_DIR}/mock/iot_gmock.cc)
include_directories(iot_gmock_lib PUBLIC ${CMAKE_SOURCE_DIR}/mock/)
target_link_libraries(iot_gmock_lib PRIVATE gmock_main)
add_executable(CatTest4_GMock CatTest4_GMock.cc)
target_link_libraries(CatTest4_GMock PRIVATE gtest_main gmock_main cat_module iot_gmock_lib)

add_test(NAME CatTest4_GMock COMMAND CatTest4_GMock)

# ======================
# Mocking 세번째 예제 - 값을 조작하기 (구현 파일 교체 및 전역 변수 활용) (GMock을 사용한 클래스 오버라이딩)
add_library(iot_gmock_class_lib ${CMAKE_SOURCE_DIR}/mock/iot_gmock_class.cc)
include_directories(iot_gmock_class_lib PUBLIC ${CMAKE_SOURCE_DIR}/mock/)
target_link_libraries(iot_gmock_class_lib PRIVATE gmock_main)
add_executable(CatTest5_GMock_Class CatTest5_GMock_Class.cc)
target_link_libraries(CatTest5_GMock_Class PRIVATE gtest_main gmock_main cat_module iot_gmock_class_lib)

add_test(NAME CatTest5_GMock_Class COMMAND CatTest5_GMock_Class)