#pragma once

#include <stdexcept>
#include <string>
#include <sstream>

using uint = unsigned;

namespace al {

struct error : public std::runtime_error {
    error(std::string what) : std::runtime_error(what) {}
};

namespace internal {
    inline uint get_error();

    inline void check_for_error() {
        using namespace std;
        int error = get_error();
        if(error) {
            ostringstream what;
            what << hex << showbase << uppercase << error;
            throw al::error(what.str());
        }
    }
}
}

#ifdef AL_INCLUDE
#include "../../al/src/internal.cpp"
#endif
