# CMake

### include_directories
요약: 헤더 파일이 구현 파일과 다른 경로에 있는 경우 경로를 지정한다.

CMake 에서는 컴파일 시에 헤더 파일들을 찾을 경로의 위치를 지정할 수 있습니다. 보통 컴파일러는 #include <> 의 형태로 include 되는 헤더 파일들은 시스템 경로에서 찾고, #include "" 의 형태로 include 된 헤더 파일의 경우는 따로 지정하지 않는 이상 현재 코드의 위치를 기준으로 찾습니다.

하지만 경우에 따라서 (특히 나중에 라이브러리 만들 시에 더욱) 헤더 파일들을 다른 곳에 위치시키는 경우가 있는데 컴파일러가 해당 파일들을 찾기 위해서는 컴파일 시에 따로 경로를 지정해줘야 합니다.