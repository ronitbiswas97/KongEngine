#ifndef CVERTEXARRAY_H
#define CVERTEXARRAY_H
class CVertexArray
{
private:
	unsigned int m_vertexArray;
public:
	CVertexArray();
	void Bind();
	void Unbind();
	void AddAttribute(int index, int size, size_t stride, const void* offset);
	void Destroy();
};
#endif
