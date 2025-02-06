#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <X11/Xutil.h>

#include <stdio.h>
#include <stdlib.h>

#include "./wm.h"
#include "./lib/utils.h"

#include "./cursor.h"
#include "./keyboard.h"

int main() {
    WindowManager* windowManager = createWindowManager();

    setupWindowManager(windowManager);
    closeWindowManager(windowManager);

    return 0;
}
