// CatTest.cc
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Cat.h"
#include "iot_gmock_class.h" 

using ::testing::Return;
using ::testing::_;

TEST(CatTest, CatDoctor) {
  MockDoctor mock;
  mockDoctor = &mock; // 전역 변수에 새로운 객체 포인터 대입

  // 새로운 객체를 모의한다.
  EXPECT_CALL(mock, checkHealth(_)) // "_": 검증 안함, 인자 값을 넣으면 검증 함.
      .WillOnce(Return(true));

  Cat cat;
  int cost = cat.call();

  EXPECT_EQ(cost, 100);

  // 테스트 후 전역 포인터 초기화
  mockDoctor = nullptr;
}

TEST(CatTest, CatDoctorMoney) {
  MockDoctor mock;
  mockDoctor = &mock;
  EXPECT_CALL(mock, checkHealth(100)) // 인자 값에 100이 입력되었는지 검증한다. 다른 값이 입력되었으면 Fail!
      .WillOnce(Return(false));

  Cat cat;
  int cost = cat.call();

  EXPECT_EQ(cost, 200);

  mockDoctor = nullptr;
}
