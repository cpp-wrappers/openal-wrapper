#include "AL/al.h"
#include "openal/internal.hpp"

inline uint al::internal::get_error() {
    return alGetError();
}

