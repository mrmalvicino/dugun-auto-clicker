#ifdef __linux__
    #include <X11/Xlib.h>
    #include <X11/extensions/XTest.h>
    #include <unistd.h> // usleep
#endif

class LinuxController
{
    public:

    void leftClick();

    void rightClick();
};