#pragma once

#include "with_name.hpp"
#include <cstdint>
#include "check_error_macro.hpp"

namespace al {

namespace internal {
    void gen_buffers(uint n, uint* buffers);
	void delete_buffers(uint n, uint* buffers);
	void buffer_data(uint buffer, uint format, void*data, uint size, uint freq);
}

class buffer : public with_name {
	inline static uint gen() {
		uint name;
		internal::gen_buffers(1, &name);
		AL_CHECK_FOR_ERROR_FN
		return name;
	}
    
	inline void data(uint format, void* data, uint size, uint frequency) {
		internal::buffer_data(name, format, data, size, frequency);
		AL_CHECK_FOR_ERROR_FN
	}
public:
    enum class format {
		mono8 = 0x1100,
		mono16,
		stereo8,
		stereo16
	};

	buffer(buffer&& r) = default;
	buffer():with_name(gen()) {}
	buffer& operator=(buffer&& b) = default;
	~buffer() {
		if(name != invalid_name) {
			internal::delete_buffers(1, &name);
			AL_CHECK_FOR_ERROR_FN
			invalidate_name();
		}
	}

	template<class RAI>
	void data(format fmt, RAI begin, unsigned size, unsigned frequency) {
		data(static_cast<unsigned>(fmt), &*begin, size, frequency);
	}

	template<class RAI>
	void data(uint8_t channels, uint8_t bits, RAI begin, unsigned size, unsigned frequency) {
		data(static_cast<al::buffer::format>
			(0x1100 + (channels - 1) * 2 + bits / 8 - 1), begin, size, frequency);
	}

	template<class Container>
	void data(uint8_t channels, uint8_t bits, Container c, unsigned frequency) {
		data(channels, bits, c.begin(), c.size()*sizeof(typename Container::value_type), frequency);
	}
};

}