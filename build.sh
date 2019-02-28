cxx=$CXX
if [[ -z $cxx ]]; then
    if clang++ --version >& /dev/null; then
        cxx=clang++;
    elif g++ --version >& /dev/null; then
        cxx=g++;
    fi
fi

echo using $cxx

cxxargs=\
"-c \
--std=c++17 \
-Iinclude/openal \
-o build/bridge.o \
src/bridge.cpp"

cxxargs=$cxxargs $CXXARGS

mkdir -p build
$cxx $cxxargs