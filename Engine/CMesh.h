#ifndef CMESH_H
#ifndef CMESH_H
#define CMESH_H
#include <vector>
#include <iostream>
#include "../Math/SVector3.h"
#include "../Math/SVector2.h"
class CMesh
{
    private:
    std::vector<SVector3> m_vertices;
    std::vector<SVector2> m_uvs;
    std::vector<SVector3> m_normals;
    std::vector<unsigned int> m_indices;

    public:
    CMesh();
    void SetVertices(const std::vector<SVector3>& vertices);
    void SetUVS(const std::vector <SVector2>& uv);
    void SetNormals(const std::vector<SVector3>& normals);
    void SetIndices(const std::vector<unsigned int>& indices);
    void GetVertices(std::vector<SVector3>& vertices)const;
    void GetUVS(std::vector<SVector2>& uvs)const;
    void GetNormals(std::vector<SVector3>& normals)const;
    void GetIndices(std::vector<unsigned int>& indices);
};
#endif
