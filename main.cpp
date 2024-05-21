#include <iostream>
#include "UI/headers/Menu.h"
#include "DML/headers/Sequence.h"
#include "DML/headers/MouseAction.h"
#include "DML/headers/Timer.h"
#include "API/headers/MacOSController.h"

int main()
{
    int actionsAmount = 3;
    MouseAction * mouseActions = new MouseAction[actionsAmount];

    //Sequence sequence;
    //sequence.setMouseActions(mouseActions, actionsAmount);

    MacOSController controller;

    MouseAction action1;
    CursorPosition position1;
    position1.setX(118);
    position1.setY(151);
    action1.setCursorPosition(position1);
    CursorEvent event1;
    event1.setName("Right click");
    action1.setCursorEvent(event1);
    action1.setTime(2000);

    MouseAction action2;
    CursorPosition position2;
    position2.setX(228);
    position2.setY(292);
    action2.setCursorPosition(position2);
    CursorEvent event2;
    event2.setName("Wait");
    action2.setCursorEvent(event2);
    action2.setTime(4000);

    MouseAction action3;
    CursorPosition position3;
    position3.setX(331);
    position3.setY(343);
    action3.setCursorPosition(position3);
    CursorEvent event3;
    event3.setName("Left click");
    action3.setCursorEvent(event3);
    action3.setTime(6000);

    mouseActions[0] = action1;
    mouseActions[1] = action2;
    mouseActions[2] = action3;

    Timer timer;
    timer.setLoops(actionsAmount);
    timer.setInterval(mouseActions[0].getTime());
    timer.start();

    int i = 0;

    while (timer.enabled())
    {
        std::cout << mouseActions[i].toString() << "\n";

        controller.move(mouseActions[i].getCursorPosition());

        if (mouseActions[i].getCursorEvent().getName() == "Left click")
        {
            controller.leftClick();
        }
        else if (mouseActions[i].getCursorEvent().getName() == "Right click")
        {
            controller.rightClick();
        }

        if (i + 1 < timer.getLoops())
        {
            timer.setInterval(mouseActions[i+1].getTime());
        }

        i++;
    }

    return 0;
}