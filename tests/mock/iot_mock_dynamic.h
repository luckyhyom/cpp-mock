// 이 헤더는 없어도 된다, 그냥 전역변수 선언용 헤더임!!!!!!
namespace iot {
  namespace chain {
    inline bool checkHealthReturn = false;
    bool checkHealth(int fullness);
  }
  class Doctor {
    public:
      bool checkHealth(int fullness);
  };
}