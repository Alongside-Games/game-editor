#include "frames_counter.hpp"

namespace core
{
    auto FramesCounter::init() -> void
    {
        current_time = Time::now_time();
    }

    auto FramesCounter::update() -> void
    {
            counter++;

            const auto current = Time::now_time();

        if (const auto elapsed  = seconds(current - current_time).count();
                       elapsed >= 1.0f)
        {
            _frames  = static_cast<int32_t>(static_cast<float>(counter) / elapsed);
             counter = 0;

             current_time = current;

            if (on_update)
            {
                on_update();
            }
        }
    }

    auto FramesCounter::frames() -> int32_t
    {
        return _frames;
    }
}