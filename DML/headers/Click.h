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

    Click();

    void left();

    void right();

    private:

    #ifdef _WIN64

    #endif

    #ifdef __linux__
        
    #endif

    #ifdef __APPLE__
        
    #endif
};