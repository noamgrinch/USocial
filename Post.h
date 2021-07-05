#pragma once
#include<iostream>
#include "Media.h"
class Post
{
private:
	std::string _text;
	Media* _media;
public:
	std::string getText();
	Media* getMedia();
	Post(const std::string str);
	Post(const std::string str, Media* media);
};

