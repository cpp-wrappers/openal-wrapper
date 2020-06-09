#pragma once

#include "al/with_name.hpp"
#include "al/check_error_macro.hpp"
#include "al/buffer.hpp"

namespace al {
namespace internal {
    void gen_sources(uint n, uint* sources);
    void delete_sources(uint n, uint* sources);
    void source(uint source, uint pname, float value);
    void source(uint source, uint pname, int value);
    void get_source(uint source, uint pname, float* value);
    void get_source(uint source, uint pname, int* value);
	void source_queue_buffers(uint source, uint n, uint* buffers);
	void source_unqueue_buffers(uint source, uint n, uint* buffers);
    void source_play(uint source);
    void source_stop(uint source);
}

class source : public with_name {
    enum class param_name {
        source_relative = 0x202,
		cone_inner_angle = 0x1001,
		cone_outer_angle = 0x1002,
		looping = 0x1007,
		buffer = 0x1009,
		source_state = 0x1010,
        buffers_queued = 0x1015,
        buffers_processed = 0x1016
    };

	inline static uint gen() {
        uint name;
		internal::gen_sources(1, &name);
		AL_CHECK_FOR_ERROR_FN
        return name;
	}

	void i(param_name param, int value) {
		internal::source(name, (uint)param, value);
		AL_CHECK_FOR_ERROR_FN
	}
    int get_i(param_name param) {
        int v;
		internal::get_source(name, (uint)param, &v);
		AL_CHECK_FOR_ERROR_FN
        return v;
	}
public:
	enum class state {
		initial = 0x1011,
		playing,
		paused,
		stopped
	};

	source() :with_name{ gen() } {}
	~source() {
		if(name != invalid_name) {
			internal::delete_sources(1, &name);
			AL_CHECK_FOR_ERROR_FN
			invalidate_name();
		}
	}

	void buffer(al::buffer& buf) {
		i(param_name::buffer, buf.name);
	}

	void buffer(al::buffer* buf) {
		i(
			param_name::buffer,
			buf == nullptr ? 0 : (*buf).name
        );
	}

	void queue_buffer(al::buffer& buff) {
		internal::source_queue_buffers(name, 1, &buff.name);
		AL_CHECK_FOR_ERROR_FN
	}

	void unqueue_buffer(al::buffer& buff) {
		internal::source_unqueue_buffers(name, 1, &buff.name);
		AL_CHECK_FOR_ERROR_FN
	}

	state get_state() {
		return (state) get_i(param_name::source_state);
	}

	bool stopped() {
		return get_state() == state::stopped;
	}

    bool playing() {
        return get_state() == state::playing;
    }

	unsigned get_buffers_processed() {
		return get_i(param_name::buffers_processed);
	}

	unsigned get_buffers_queued() {
		return get_i(param_name::buffers_queued);
	}

	void play() { internal::source_play(name); AL_CHECK_FOR_ERROR_FN }
	void stop() { internal::source_stop(name); AL_CHECK_FOR_ERROR_FN }
};

}