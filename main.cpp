#include <iostream>
#include "mgl.h"
using namespace std;

int main(int argc, char* argv[]) {
    mgl_init("hello", 800, 600);
    int k = 0;
    int d = 1;
    int uptime = 0;
    while(1) {
        k += d;
        if(k == 255) d = -1;
        if(k == 0) d = 1;
        mgl_setinitcol(vec4(1.0f, 1.0f, k / 255.0f));
        mgl_clear(MGL_COLOR);
        mgl_update();
        SDL_Event e;
        if (SDL_PollEvent(&e) & e.type == SDL_QUIT) {
            break;
        }
        int cur = SDL_GetTicks();
        cout << cur - uptime << endl;
        uptime = cur;
    }
    mgl_quit();
    return 0;
}