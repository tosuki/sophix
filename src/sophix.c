#include "window_manager.h"

int main() {
    WindowManager* wm = create_window_manager();
    window_manager_run(wm); 
    destroy_window_manager(wm);
    return 0;
}
