#include "../headers/Timer.h"

Timer::Timer()
{
    _interval = 1000;
    _loopsAmount = 0;
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

int Timer::getLoopsAmount()
{
    return _loopsAmount;
}

void Timer::setLoopsAmount(int loopsAmount)
{
    _loopsAmount = loopsAmount;
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

void Timer::tick()
{
    std::this_thread::sleep_for(_interval * _millisecond);
}

bool Timer::enabled(bool isDoWhileCondition)
{
    if (0 < _loopsAmount)
    {
        _loopsDone ++;

        if (_loopsDone == _loopsAmount + 1 - isDoWhileCondition)
        {
            stop();
            return _enabled;
        }
    }

    tick();

    return _enabled;
}