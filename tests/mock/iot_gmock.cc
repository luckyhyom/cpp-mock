/**
 * 헤더 파일을 포함하면, 함수뿐만 아니라 관련 클래스, 네임스페이스, 타입 등에 대한 정확한 정보를 제공받아 컴파일러가 올바르게 타입 검사를 수행할 수 있습니다.
 */
#include "iot.h"
#include "iot_gmock.h"

/**
 * 💯
 * 전역 포인터 gHealthCheckerMock가 설정되어 있으면 그 객체를 통해 gmock의 동작(예: EXPECT_CALL)을 수행하도록 합니다.
 * -> 전역 변수를 사용해 함수의 반환 값을 조작했던 것과 비슷하게 여기서는 전역 gmock 객체를 사용한다.!
 * 
 * GMock같은 라이브러리는 왜 사용할까❓
 * 직접 Mock class를 만들수도 있지만 GMock에는 좀 더 상세한 조작을 위한
 * (인자 값, 호출 여부, 등 검증) 메서드들이 구현되어있다.
 * -> 
 */
HealthCheckerMock* gHealthCheckerMock = nullptr;

namespace iot {
  namespace chain {
    // production에서는 항상 true를 반환하지만, 테스트에서는 gmock 객체를 통해 제어합니다.
    bool checkHealth(int fullness) {
      if (gHealthCheckerMock) {
        return gHealthCheckerMock->checkHealth(fullness);
      }
      return true; // 기본값 (모의 객체가 없으면 production과 동일하게 true)
    }
  }
}
