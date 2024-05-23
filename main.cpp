#include <iostream>
#include "UI/headers/Menu.h"
#include "DML/headers/Sequence.h"
#include "BLL/headers/AutoClicker.h"

int main()
{
    /*
    Menu menu;
    menu.display();
    */
    int actionsAmount = 3;
    MouseAction * mouseActions = new MouseAction[actionsAmount];

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
    event3.setName("Wait");
    action3.setCursorEvent(event3);
    action3.setTime(6000);

    mouseActions[0] = action1;
    mouseActions[1] = action2;
    mouseActions[2] = action3;

    Sequence sequence;
    sequence.setMouseActions(mouseActions, actionsAmount);
    sequence.setLoopsAmount(1);

    AutoClicker autoClicker;
    autoClicker.setSequence(sequence);
    autoClicker.runSequence();

    return 0;
}