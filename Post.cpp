#pragma once
#include<iostream>
#include "Media.h"
#include "Post.h"
std::string Post::getText() {
	return _text;
}
Media* Post::getMedia() {
	return _media;
}
//TODO: Verify those functions.
Post::Post(const std::string str) {
	_text = str;
}
Post::Post(const std::string str, Media* media) {
	_text = str;
	_media = media;
}

