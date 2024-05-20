#include "../headers/Timer.h"

Timer::Timer()
{
    _interval = 1000;
    _loops = 0;
    _loopsDone = 0;
    _enabled = false;
    _millisecond = std::chrono::milliseconds(1);
}

int Timer::getInterval()
{
    return _interval;
}

void Timer::setInterval(int interval)
{
    _interval = interval;
}

int Timer::getLoops()
{
    return _loops;
}

void Timer::setLoops(int loops)
{
    _loops = loops;
}

void Timer::start()
{
    _enabled = true;
}

void Timer::pause()
{
    _enabled = false;
}

void Timer::stop()
{
    _loopsDone = 0;
    _enabled = false;
}

bool Timer::enabled()
{
    std::this_thread::sleep_for(_interval * _millisecond);

    if (0 < _loops)
    {
        _loopsDone ++;

        if (_loopsDone == _loops + 1)
        {
            stop();
        }
    }

    return _enabled;
}