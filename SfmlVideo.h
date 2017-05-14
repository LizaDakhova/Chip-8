#ifndef SFML_VID_H
#define SFML_VID_H

#include <SFML/Graphics.hpp>
#include "Base_Video.h"
#include "SfmlMemory.h"

class SfmlVideo : public BaseVideo {
public:
	SfmlVideo(byte pixelsize, const std::string& inputfile, SfmlMemory* const memory) :
		BaseVideo(pixelsize), 
		screen(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), inputfile), 
		VideoMemory(memory) {

	}
	~SfmlVideo() {}
	void draw(two_byte start_corner, two_byte end_corner) {}
private:
	bool videoMemoryAccessId = true;
	SfmlMemory* const VideoMemory;
	sf::RenderWindow screen;
};

#endif