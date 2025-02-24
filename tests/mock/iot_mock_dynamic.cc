#include "iot_mock_dynamic.h"

namespace iot {
  namespace chain {
    bool checkHealth(int fullness) {
      return checkHealthReturn;
    }
  }

  bool Doctor::checkHealth(int fullness) {
    return chain::checkHealth(fullness);
  }
}