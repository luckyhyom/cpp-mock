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