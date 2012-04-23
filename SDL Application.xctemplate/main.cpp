#include <SDL/SDL.h>
#include <stdexcept>

const int Width = 320;
const int Height = 480;

Uint16 CreateHicolorPixel(SDL_PixelFormat *fmt, Uint8 red, Uint8 green, Uint8 blue) {
	Uint16 value = 
		((red >> fmt->Rloss) << fmt->Rshift) + 
		((green >> fmt->Gloss) << fmt->Gshift) +
		((blue >> fmt->Bloss) << fmt->Bshift);
	
	return value;
}

int main(int argc, char **argv) {
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		std::runtime_error("Unable to initialize SDL");
	
    SDL_Window *window(SDL_CreateWindow(
        "SDL_Window", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        Width, 
        Height, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL
    ));
	if(!window)
		std::runtime_error("Unable to create window");
	
    SDL_Surface *surface(SDL_GetWindowSurface(window));
	SDL_LockSurface(surface);
	Uint16 *raw_pixels = static_cast<Uint16 *>(surface->pixels);
	for(int x = 0; x < 255; ++x) {
		for(int y = 0; y < 255; ++y) {
			Uint16 pixel_color = CreateHicolorPixel(surface->format, x, 0, y); 
			int offset = (surface->pitch / 2 * y + x);
			raw_pixels[offset] = pixel_color;
		}
	}
    SDL_UpdateWindowSurface(window);
    SDL_GL_SwapWindow(window);
    SDL_Delay(5000);
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
