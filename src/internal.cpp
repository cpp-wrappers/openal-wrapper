#include "AL/al.h"
#include "al/internal.hpp"

uint al::internal::get_error() {
    return alGetError();
}

