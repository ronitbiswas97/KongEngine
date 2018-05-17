#include <glad\glad.h>
#include "CVertexBuffer.h"

CVertexBuffer::CVertexBuffer(size_t size, const void* data)
{
	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void CVertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
}

void CVertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void CVertexBuffer::Update(size_t size, size_t offset, const void* data)
{
	glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}

void CVertexBuffer::Destroy()
{
	glDeleteBuffers(1, &m_vertexBuffer);
}