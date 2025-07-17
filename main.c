#include <stdio.h>
#include <stdlib.h>

#include <SDL3/SDL.h>

int main() {
    bool r = SDL_Init(SDL_INIT_VIDEO);
    if (!r) {
        fprintf(stderr, "Init failed: %s\n", SDL_GetError());
        exit(1);
    }

    atexit(SDL_Quit);

    int w = 256;
    int h = 256;
    SDL_Window *window = SDL_CreateWindow("sample", w, h, SDL_WINDOW_ALWAYS_ON_TOP);
    if (window == NULL) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        exit(1);
    }

    // There is no rendering, so the window content will contain garbage, but
    // we don't care for this sample

    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        switch(event.type) {
            case SDL_EVENT_QUIT:
                printf("Quit\n");
                goto end;
            case SDL_EVENT_MOUSE_MOTION:
                if (SDL_GetWindowRelativeMouseMode(window)) {
                    printf("[relative mode] mouse motion (%f, %f)\n",
                           event.motion.xrel, event.motion.yrel);
                }
                break;
            case SDL_EVENT_MOUSE_BUTTON_UP:
                if (SDL_GetWindowRelativeMouseMode(window)) {
                    printf("[relative mode] mouse button up\n");
                }
                break;
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                if (SDL_GetWindowRelativeMouseMode(window)) {
                    printf("[relative mode] mouse button down\n");
                }
                break;
            case SDL_EVENT_KEY_DOWN:
                // Toggle relative mode on Alt
                if (event.key.key == SDLK_LALT) {
                    bool new_mode = !SDL_GetWindowRelativeMouseMode(window);
                    SDL_SetWindowRelativeMouseMode(window, new_mode);
                    printf("switch relative mode to %s\n",
                           new_mode ? "true" : "false");
                }
                break;
        }
    }

end:
    SDL_DestroyWindow(window);

    return 0;
}
