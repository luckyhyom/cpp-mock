#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Cat.h"

/**
 * 📌 의존성 주입(DI)이 불가능한 상태임을 가정한다.
 */
TEST(CatTest, Eat) {
  Cat cat;
  cat.eat();

  /**
   * ❌ 결과값이 랜덤해서 테스트할 수 없다.
   * 테스트 파일을 실행시키면 매번 결과가 다르다.
   */
  EXPECT_EQ(cat.say(), "Meow~");
}