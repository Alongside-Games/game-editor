#pragma once

#include "core/time.hpp"

namespace core
{
    class FramesCounter
    {
    public:
        auto init()   -> void;
        auto update() -> void;

        static auto frames() -> int32_t;

        std::function<void()> on_update { };

    private:
        inline static int32_t _frames   { };
                      int32_t _counter  { };

        time_point _current_time { };
    };
}