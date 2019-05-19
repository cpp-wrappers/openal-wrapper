mkdir -p build
cd build
rm *

$CXX $CXXFLAGS -c -std=c++17 \
-I../src \
../src/al/internal.cpp \
../src/al/buffer.cpp \
../src/al/source.cpp \
../src/alc/device.cpp

ar -rs libopenal-wrapper.a internal.o buffer.o source.o device.o