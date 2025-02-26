#include "iot.h"
#include "iot_gmock_class.h"

// 📌 전역 변수 정의 시 MockDoctor*와 같이 타입을 명시해주어야 컴파일러가 올바르게 인식합니다.
MockDoctor* mockDoctor = nullptr;
namespace iot {
  namespace chain {
    bool checkHealth(int fullness) {
      return true;
    }
  }

  bool Doctor::checkHealth(int money) {
    if(mockDoctor) {
      return mockDoctor->checkHealth(money);
    }
    return false;
  }
}