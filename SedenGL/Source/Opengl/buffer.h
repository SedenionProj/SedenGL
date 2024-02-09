#pragma once
#include <glad/glad.h>
#include "glm/glm.hpp"
#include <vector>

namespace Seden {
	class VertexBuffer {
	private:
		unsigned int ID;
	public:
		VertexBuffer(const int size, const float data[]);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;

		inline unsigned int getId() const { return ID; }
	};

	class IndexBuffer {
	private:
		unsigned int ID;
		unsigned int count;
	public:
		IndexBuffer(const int size, const unsigned int data[]);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		inline unsigned int GetCount() const { return count; }
		inline unsigned int getId() const { return ID; }

	};

	class UniformBuffer {
	private:
		unsigned int ID;
		unsigned int _binding;
	public:
		UniformBuffer(const int size, const void* data, const unsigned int binding = 0);
		UniformBuffer(const int size);
		~UniformBuffer();
		void data(const int offset, const void* data, const int size, const unsigned int binding = 0);
		inline unsigned int getId() const { return ID; }
		void Bind() const;
		void Unbind() const;
	};

	class ShaderStorageBuffer {
	private:
		unsigned int ID;
		unsigned int _binding;
	public:
		ShaderStorageBuffer(const int size, const void* data, const unsigned int binding = 0);
		ShaderStorageBuffer(const int size);
		~ShaderStorageBuffer();
		inline unsigned int getId() const { return ID; }
		void data(const int offset, const void* data, const int size, const unsigned int binding = 0);
		void Bind() const;
		void Unbind() const;
	};
}