#include "frames_counter.hpp"

namespace core
{
    auto FramesCounter::init() -> void
    {
        _current_time = Time::now_time();
    }

    auto FramesCounter::update() -> void
    {
        _counter++;

        const auto current_time = Time::now_time();
        const auto elapsed_time = seconds(current_time - _current_time).count();

        if (elapsed_time >= 1.0f)
        {
            _frames  = static_cast<int32_t>(static_cast<float>(_counter) / elapsed_time);
            _counter = 0;

            _current_time = current_time;

            if (on_update)
                on_update();
        }
    }

    auto FramesCounter::frames() -> int32_t
    {
        return _frames;
    }
}