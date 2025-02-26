#include "Cat.h"
#include "iot.h"

/**
 * 직접 호출하는 외부 라이브러리 Mocking하기
 */
void Cat::eat() {
  bool isHealth = iot::chain::checkHealth(fullness);
  if(isHealth) { return; }
  fullness += 10;
}

std::string Cat::say() {
  if(fullness < 10) return "Meow!!";
  return "Meow~";
}

int Cat::call() {
  iot::Doctor doctor;
  int money = 100;
  int surgery_cost = 100;

  bool ok = doctor.checkHealth(money);
  if(ok) {
    return money;
  }
  
  return money + surgery_cost;
}
