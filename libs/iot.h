// ❓ 5번 테스트를 추가하면서 필요해졌다. 왜지?
#ifndef IOT_H
#define IOT_H
namespace iot {
  namespace chain {
    bool checkHealth(int fullness);
  }
  class Doctor {
    public:
      bool checkHealth(int money);
  };
}
#endif // IOT_H