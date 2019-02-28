#pragma once

#include <string>
#include "context.hpp"

namespace alc {
namespace internal {
    inline void* open_device(const char* str);
    inline void close_device(void* device_ptr);
    inline void* create_context(void* device_ptr, int* attribs);
    inline void make_context_current(void* context);
}

class device;

class device {
    friend device open_device(std::string name);
    friend device open_default_device();
    void* device_ptr;
    device(void* device_ptr): device_ptr{ device_ptr } {}
public:
    ~device() {
        internal::close_device(device_ptr);
    }

    context create_context() {
        return internal::create_context(device_ptr, nullptr);
    }
};

inline device open_default_device() {
    return device(internal::open_device(nullptr));
}

inline device open_device(std::string name) {
    return device(internal::open_device(name.data()));
}

inline void make_context_current(context& c) {
    internal::make_context_current(c);
}

}

#ifdef AL_INCLUDE
#include "../../src/device.cpp"
#endif