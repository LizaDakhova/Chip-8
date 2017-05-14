#ifndef BASE_VID_H
#define BASE_VID_H

#include "Def_types.h"

class BaseVideo {
public:
	BaseVideo(byte pixelsize) :
		WINDOW_WIDTH(64 * pixelsize), WINDOW_HEIGHT(32 * pixelsize) {}
	virtual ~BaseVideo() {}
	virtual void draw(two_byte start_corner, two_byte end_corner) = 0;

protected:
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
};

#endif