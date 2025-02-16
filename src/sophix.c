#include "window_manager.h"

int main() {
    WindowManager* wm = create_window_manager();
    
    destroy_window_manager(wm);
    return 0;
}
