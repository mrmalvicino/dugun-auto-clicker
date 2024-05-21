#ifdef __APPLE__
    #include <ApplicationServices/ApplicationServices.h>
#endif

#include "../../DML/headers/CursorPosition.h"

class MacOSController
{
    public:

    void leftClick();

    void rightClick();

    void move(CursorPosition cursorPosition);

    CursorPosition getPosition();

    private:

    #ifdef __APPLE__
        CGPoint _CGPosition;
        CGEventRef _CGEvent;
    #endif
};