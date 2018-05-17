#ifndef CVERTEXBUFFER_H
#define CVERTEXBUFFER_H

class CVertexBuffer
{
private:
	unsigned int m_vertexBuffer;
public:
	CVertexBuffer(size_t size, const void* data);
	void Bind();
	void Unbind();
	void Update(size_t size, size_t offset, const void* data);
	void Destroy();
};

#endif