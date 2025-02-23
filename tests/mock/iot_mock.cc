#include "iot.h"

namespace iot {
  namespace chain {
    bool checkHealth(int fullness) {
      return false;
    }
  }

  bool Doctor::checkHealth(int fullness) {
    return chain::checkHealth(fullness);
  }
}