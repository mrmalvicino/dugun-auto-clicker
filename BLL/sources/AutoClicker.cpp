#include "../headers/AutoClicker.h"

Sequence AutoClicker::getSequence() const
{
    return _sequence;
}

void AutoClicker::setSequence(const Sequence & sequence)
{
    _sequence = sequence;
}

void AutoClicker::runSequence()
{
    MouseAction * mouseActions = _sequence.getMouseActions();
    int actionsAmount = _sequence.getActionsAmount();
    int loopsAmount = _sequence.getLoopsAmount();

    if (0 < loopsAmount)
    {
        _timer.setLoopsAmount(actionsAmount * loopsAmount);
    }

    _timer.setInterval(mouseActions[0].getTime());
    _timer.start();
    int i = 0;

    while (_timer.enabled())
    {
        _controller.move(mouseActions[i].getCursorPosition());

        if (mouseActions[i].getCursorEvent().getName() == "Left click")
        {
            _controller.leftClick();
        }
        else if (mouseActions[i].getCursorEvent().getName() == "Right click")
        {
            _controller.rightClick();
        }

        if (i + 1 < actionsAmount)
        {
            _timer.setInterval(mouseActions[i+1].getTime());
            i ++;
        }
        else
        {
            i = 0;
        }
    }
}