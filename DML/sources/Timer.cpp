#include "../headers/Timer.h"

Timer::Timer()
{
    setInterval(1000);
    setLoops(0);
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

void Timer::stop()
{
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
            _loopsDone = 0;
            stop();
        }
    }

    return _enabled;
}