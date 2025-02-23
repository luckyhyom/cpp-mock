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
   * ✅ 제어할 수 없던 checkHealth의 결과값을 Mocking 해서 고정된 값으로 테스트가 가능하다.
   */
  EXPECT_EQ(cat.say(), "Meow~");
}

TEST(CatTest, EatFail) {
  Cat cat;
  cat.eat();

  /**
   * ❌ Mocking한 checkHealth의 결과값이 고정되어있어 다른 케이스를 테스트 할 수 없다.
   */
  EXPECT_EQ(cat.say(), "Meow!");
}