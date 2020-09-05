REM install packages in vcpkg

pushd dependencies\vcpkg

IF NOT EXIST vcpkg.exe bootstrap-vcpkg.bat 


vcpkg.exe integrate install

vcpkg.exe install ffmpeg --triplet x64-windows

popd