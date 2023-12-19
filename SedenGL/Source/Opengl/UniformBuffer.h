#pragma once
#include <glad/glad.h>

class UniformBuffer {

public:
	UniformBuffer(const int size, const float data[], const unsigned int pos = 0);
	~UniformBuffer();
	inline unsigned int getId() const { return ID; }
	void Bind() const;
	void Unbind() const;
private:
	unsigned int ID;
};