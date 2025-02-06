#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <X11/Xutil.h>

#include <stdio.h>
#include <stdlib.h>

#include "./wm.h"

#include "./cursor.h"
#include "./keyboard.h"

int main() {
    WindowManager* windowManager = createWindowManager();

    XSelectInput(windowManager->display, windowManager->rootWindow, SubstructureNotifyMask | SubstructureRedirectMask);

    createCursor(windowManager);
    dispatchKeyboardEvents(windowManager);
    XSync(windowManager->display, False);

    XEvent event;

    for(;;) {
        XNextEvent(windowManager->display, &event);
        
        switch (event.type) {
            case KeyPress:
                puts("key pressed");
                break;

            case ButtonPress:
                XAllowEvents(windowManager->display, ReplayPointer, CurrentTime);
                XSync(windowManager->display, 0);
                puts("Button pressed");
                break;
            default:
                puts("Unexpected event");
                break;
        }
        XSync(windowManager->display, False);
    }    

    closeWindowManager(windowManager);

    return 0;
}
