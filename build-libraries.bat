set BUILD_EXAMPLES_FLAG=false
mkdir build

if "%1"=="--build-examples" (SET BUILD_EXAMPLES_FLAG=true)

echo BUILD_EXAMPLES_FLAG="%BUILD_EXAMPLES_FLAG%"

cmake -s . -B build -DBUILD_EXAMPLES=%BUILD_EXAMPLES_FLAG% -DCMAKE_TOOLCHAIN_FILE=%CD%\dependencies\vcpkg\scripts\buildsystems\vcpkg.cmake 

cmake --build build