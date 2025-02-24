#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Cat.h"

#include "iot_mock_dynamic.h"

/**
 * 📌 의존성 주입(DI)이 불가능한 상태임을 가정한다.
 */
TEST(CatTest, Eat) {
  /**
   * iot::chain::checkHealth의 반환 값을 Mocking한다. ✅
   */
  iot::chain::checkHealthReturn = false;

  Cat cat;
  cat.eat();

  EXPECT_EQ(cat.say(), "Meow~");
}

/**
 * 💯
 * 1. Cat.cc는 컴파일 시 헤더 파일은 /lib/iot.h를 사용한다.
 * 2. Cat.cc는 링킹 시 구현 파일은 /tests/mock/iot_mock_dynamic.cc를 사용한다.
 * 
 * How?✅
 * 1. iot_mock_dynamic.cc를 CTest3_Mock_Dynamic.cc(현재 파일)의 라이브러리로 설정
 * 2. iot_mock_dynamic.cc의 함수가 iot.cc의 함수와 동일한 심볼을 가졌기 때문에 링킹이 가능
 */
TEST(CatTest, EatFail) {
  // 전역 변수 값을 설정한다. (iot_mock_dynamic.cc는 해당 전역 변수를 사용한다.)
  iot::chain::checkHealthReturn = true;

  Cat cat;
  cat.eat();

  EXPECT_EQ(cat.say(), "Meow!!");
}