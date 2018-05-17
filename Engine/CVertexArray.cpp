#include <glad\glad.h>
#include "CVertexArray.h"
void CVertexArray::AddAttribute(int index, int size, size_t stride, const void* offset)
{
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, offset);
}
void CVertexArray::Bind()
{
	glGenVertexArrays(1, &m_vertexArray);
	glBindVertexArray(m_vertexArray);
}
void CVertexArray::Unbind() 
{
	glBindVertexArray(0);
}
void CVertexArray::Destroy() 
{
	glDeleteVertexArrays(1, &m_vertexArray);
}



