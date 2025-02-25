// CatTest.cc
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Cat.h"
#include "iot_gmock.h"  // mock 객체 선언을 위해 포함

using ::testing::Return;
using ::testing::_;

TEST(CatTest, EatWhenHealthy) {
  HealthCheckerMock mock;
  // 전역 포인터에 mock 객체를 할당해, 오버라이드된 checkHealth()가 gmock을 사용하도록 함
  gHealthCheckerMock = &mock;
  EXPECT_CALL(mock, checkHealth(_))
      .WillOnce(Return(true));

  Cat cat;
  cat.eat();

  EXPECT_EQ(cat.say(), "Meow!!");

  // 테스트 후 전역 포인터 초기화
  gHealthCheckerMock = nullptr;
}

TEST(CatTest, EatWhenNotHealthy) {
  HealthCheckerMock mock;
  gHealthCheckerMock = &mock;
  EXPECT_CALL(mock, checkHealth(_))
      .WillOnce(Return(false));

  Cat cat;
  cat.eat();

  EXPECT_EQ(cat.say(), "Meow~");

  gHealthCheckerMock = nullptr;
}
