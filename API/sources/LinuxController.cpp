#include "../headers/LinuxController.h"

void LinuxController::leftClick()
{
    #ifdef __linux__
        Display* display = XOpenDisplay(NULL);

        if (display == NULL)
        {
            fprintf(stderr, "No se puede abrir la pantalla.\n");
            return;
        }

        // Obtener la posición actual del cursor
        Window root = DefaultRootWindow(display);
        Window root_return, child_return;
        int root_x, root_y, win_x, win_y;
        unsigned int mask_return;
        XQueryPointer(display, root, &root_return, &child_return, &root_x, &root_y, &win_x, &win_y, &mask_return);

        // Simular clic izquierdo
        XTestFakeButtonEvent(display, Button1, True, CurrentTime);
        XFlush(display);
        usleep(2000); // Esperar 2 milisegundos
        XTestFakeButtonEvent(display, Button1, False, CurrentTime);
        XFlush(display);

        XCloseDisplay(display);
    #endif
}

void LinuxController::rightClick()
{
    #ifdef __linux__
        Display* display = XOpenDisplay(NULL);

        if (display == NULL)
        {
            fprintf(stderr, "No se puede abrir la pantalla.\n");
            return;
        }

        // Obtener la posición actual del cursor
        Window root = DefaultRootWindow(display);
        Window root_return, child_return;
        int root_x, root_y, win_x, win_y;
        unsigned int mask_return;
        XQueryPointer(display, root, &root_return, &child_return, &root_x, &root_y, &win_x, &win_y, &mask_return);

        // Simular clic derecho
        XTestFakeButtonEvent(display, Button3, True, CurrentTime);
        XFlush(display);
        usleep(2000); // Esperar 2 milisegundos
        XTestFakeButtonEvent(display, Button3, False, CurrentTime);
        XFlush(display);

        XCloseDisplay(display);
    #endif
}