#include "al/buffer.hpp"
#include "AL/al.h"

void al::internal::gen_buffers(uint n, uint* buffers) {
    alGenBuffers(n, buffers);
}

void al::internal::delete_buffers(uint n, uint* buffers) {
    alDeleteBuffers(n, buffers);
}

void al::internal::get_buffer(uint buffer, uint pname, int* value) {
    alGetBufferi(buffer, pname, value);
}

void al::internal::buffer_data(uint buffer, uint format, void*data, uint size, uint freq) {
    alBufferData(buffer, format, data, size, freq);
}