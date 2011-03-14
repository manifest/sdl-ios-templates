#include <iostream>
#include <string>
#include <cstdlib>
#include "SDL.h"

const unsigned Width = 256;
const unsigned Height = 256;

Uint16 CreateHicolorPixel(SDL_PixelFormat *fmt, Uint8 red, Uint8 green, Uint8 blue) {
	Uint16 value = 
		((red >> fmt->Rloss) << fmt->Rshift) + 
		((green >> fmt->Gloss) << fmt->Gshift) +
		((blue >> fmt->Bloss) << fmt->Bshift);
	
	return value;
}

void error(const std::string &msg) {	
	std::cerr<<msg<<": "<<SDL_GetError()<<std::endl;
	exit(1);
}

int main(int argc, char **argv) {
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		error("Unable to initialize SDL");
	atexit(SDL_Quit);
	
	SDL_Surface *screen = SDL_SetVideoMode(Width, Height, 16, 0 /* SDL_FULLSCREEN */);
	if(!screen)
		error("Unable to set video mode");
	
	SDL_LockSurface(screen);
	Uint16 *raw_pixels = static_cast<Uint16 *>(screen->pixels);
	for(int x = 0; x < Width; x++) {
		for(int y = 0; y < Height; y++) {
			Uint16 pixel_color = CreateHicolorPixel(screen->format, x, 0, y); 
			int offset = (screen->pitch / 2 * y + x);
			raw_pixels[offset] = pixel_color;
		}
	}
	SDL_UnlockSurface(screen);
	SDL_UpdateRect(screen, 0, 0, 0, 0);
	SDL_Delay(3000);
	
	return 0;
}
