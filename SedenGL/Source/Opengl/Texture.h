#pragma once
#include <iostream>
#include <string>
#include <glad/glad.h>


namespace Seden {
	class Texture {
	private:
		unsigned int ID;
	public:
		Texture(const std::string& path);
		~Texture();

		void Bind() const;
		void Unbind() const;
	};
}