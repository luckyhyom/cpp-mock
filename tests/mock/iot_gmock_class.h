#ifndef IOT_GMOCK_H
#define IOT_GMOCK_H
#include <gmock/gmock.h>
#include "iot.h"

/**
 * production의 메서드와 동일한 시그니처여야 합니다.
 * production 코드가 virtual이 아니더라도, 여기서는 테스트용으로 gmock을 사용하기 위해 함수를 오버라이딩합니다.
 * (링크 타임 대체 방식에서는 Doctor::checkHealth()의 심볼 자체를 테스트용으로 대체하므로, 여기서 반드시 virtual일 필요는 없습니다.)
 */
class MockDoctor : public iot::Doctor { // 상속해야 메서드 사용 가능
  public:
    MOCK_METHOD(bool, checkHealth, (int money), ());
};

extern MockDoctor* mockDoctor;

#endif // IOT_GMOCK_H