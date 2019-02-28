#include "AL/al.h"
#include "AL/alc.h"
#include "internal.hpp"
#include "buffer.hpp"
#include "source.hpp"
#include "device.hpp"

uint al::internal::get_error() {
    return alGetError();
}

void al::internal::gen_buffers(uint n, uint* buffers) {
    alGenBuffers(n, buffers);
}

void al::internal::delete_buffers(uint n, uint* buffers) {
    alDeleteBuffers(n, buffers);
}

void al::internal::buffer_data(uint buffer, uint format, void*data, uint size, uint freq) {
    alBufferData(buffer, format, data, size, freq);
}

void al::internal::gen_sources(uint n, uint* sources) {
    alGenSources(n, sources);
}

void al::internal::delete_sources(uint n, uint* sources) {
    alDeleteSources(n, sources);
}

void al::internal::source(uint source, uint pname, float value) {
    alSourcef(source, pname, value);
}

void al::internal::source(uint source, uint pname, int value) {
    alSourcei(source, pname, value);
}

void al::internal::get_source(uint source, uint pname, float* value) {
    alGetSourcef(source, pname, value);
}

void al::internal::get_source(uint source, uint pname, int* value) {
    alGetSourcei(source, pname, value);
}

void al::internal::source_queue_buffers(uint source, uint n, uint* buffers) {
    alSourceQueueBuffers(source, n, buffers);
}

void al::internal::source_unqueue_buffers(uint source, uint n, uint* buffers) {
    alSourceUnqueueBuffers(source, n, buffers);
}

void al::internal::source_play(uint source) {
    alSourcePlay(source);
}

void al::internal::source_stop(uint source) {
    alSourceStop(source);
}

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