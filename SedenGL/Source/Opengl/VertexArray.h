#pragma once
#include <glad/glad.h>
#include "Buffer.h"

namespace Seden {
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();
		void AddBuffer(const VertexBuffer& vb, int size, int stride, int offset);
		inline unsigned int getId() const { return ID; }
		void Bind()const;
		void Unbind()const;
	private:
		unsigned int ID;
		unsigned int pos;
	};
}