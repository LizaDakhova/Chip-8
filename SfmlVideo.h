#ifndef SFML_VID_H
#define SFML_VID_H

#include "Base_Video.h"
#include "Base_Audio.h"
#include "Base_Keyboard.h"


class SfmlAudio : public BaseAudio {
public:
	~SfmlAudio() {}
};
class SfmlVideo : public BaseVideo {
public:
	~SfmlVideo() {}
};
class SfmlKeyboard : public BaseKeyboard {
public:
	~SfmlKeyboard() {}
};

#endif