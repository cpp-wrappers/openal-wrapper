#include "alc/device.hpp"
#include "AL/alc.h"

void* alc::internal::open_device(const char* str) {
    return alcOpenDevice(str);
}

void alc::internal::close_device(void* device_ptr) {
    alcCloseDevice((ALCdevice*)device_ptr);
}

void* alc::internal::create_context(void* device_ptr, int* attribs) {
    return alcCreateContext((ALCdevice*)device_ptr, attribs);
}

void alc::internal::make_context_current(void* context) {
    alcMakeContextCurrent((ALCcontext*)context);
}

uint alc::internal::get_error(void* device) {
    return alcGetError((ALCdevice*)device);
}