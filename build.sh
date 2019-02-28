if [[ -z $CXX ]]; then
    echo you must specify CXX variable;
    exit
fi

cxxargs=\
"-c \
--std=c++17 \
../src/internal.cpp \
../src/device.cpp \
../src/buffer.cpp \
../src/source.cpp \
-I../include/openal"

cxxargs=$cxxargs $CXXARGS

mkdir -p build
cd build
$CXX $cxxargs