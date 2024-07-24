#pragma once
#include <SDL_ttf.h>
#include <string>
class Font
{
public:
	Font() = default;
	~Font();
	friend class Text;

	bool Load(const std::string& name, int fontSize);

private:
	_TTF_Font* m_ttfFont{ nullptr };
};