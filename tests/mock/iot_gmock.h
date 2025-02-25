#ifndef IOT_MOCK_H
#define IOT_MOCK_H

#include <gmock/gmock.h>

/**
 * gmock 기반의 모의 객체를 선언하고, 테스트 중에 해당 모의 객체를 참조할 수 있도록 전역 포인터를 제공합니다.
 */
class HealthCheckerMock {
public:
  MOCK_METHOD(bool, checkHealth, (int fullness));
};

/**
 * 📌 extern
 * 여러 소스 파일에서 같은 전역 변수를 참조할 때, 변수의 중복 정의를 피하고, 하나의 전역 변수에 여러 곳에서 접근할 수 있게 됩니다.
 */
extern HealthCheckerMock* gHealthCheckerMock;

#endif // IOT_MOCK_H