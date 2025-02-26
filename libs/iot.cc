#include <random>
#include <iostream>
#include "iot.h"

int real_time_data();

namespace iot {
  namespace chain {
    bool checkHealth(int fullness) {
      /**
      * 온라인에서 실시간으로 업데이트 되는 랜덤한 값에 따라 결과가 달라진다.
      * -> 테스트를 위해서는 고정된 값을 반환하도록 mocking 해야함
      */
      std::cout << "Real" << std::endl;
      return fullness + real_time_data() > 10;
    }
  }

  bool Doctor::checkHealth(int money) {
    return chain::checkHealth(money);
  }
}

int real_time_data() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(10, 11);  // 10~11 사이 정수 난수
  return dis(gen);
}