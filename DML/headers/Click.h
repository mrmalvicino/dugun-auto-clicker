#ifdef _WIN64
    #include <Windows.h>
#endif

#ifdef __linux__
    system("clear");
#endif

#ifdef __APPLE__
    #include <ApplicationServices/ApplicationServices.h>
#endif

class Click
{
    public:

    void left();

    void right();
};