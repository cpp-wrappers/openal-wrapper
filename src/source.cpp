#include "al/source.hpp"
#include "AL/al.h"

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