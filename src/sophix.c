#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <X11/Xutil.h>

#include "./wm.h"

int main() {
    WindowManager* windowManager = createWindowManager();

    setupWindowManager(windowManager);
    closeWindowManager(windowManager);

    return 0;
}
