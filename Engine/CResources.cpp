#include "CResources.h"

#include <fstream>
#include <sstream>

CMesh CResources::Loader(const std::string& path)
{
	std::ifstream file(path);
	std::string line;

	std::vector<SVector3> v;
	std::vector<SVector2> vt;
	std::vector<SVector3> vn;
	std::vector<int> indices;

	while (std::getline(file, line))
	{
		if (line.substr(0, 2) == "v ")
		{
			std::stringstream text(line.substr(2, line.size()));
			SVector3 vTemp;
			for (size_t i(0); i < 3; i++)
				text >> vTemp[i];
			v.push_back(vTemp);
		}
		else if (line.substr(0, 3) == "vt ")
		{
			std::stringstream text(line.substr(3, line.size()));
			SVector2 vtTemp;
			for (size_t i(0); i < 2; i++)
				text >> vtTemp[i];
			vt.push_back(vtTemp);
		}
		else if (line.substr(0, 3) == "vn ")
		{
			std::stringstream text(line.substr(3, line.size()));
			SVector3 vnTemp;
			for (size_t i(0); i < 3; i++)
				text >> vnTemp[i];
			vn.push_back(vnTemp);
		}
		else if (line.substr(0, 2) == "f ")
		{
			std::stringstream text(line.substr(2, line.size()));
			text = std::stringstream(parseFaces(text.str()));
			int indexTemp;
			for (size_t i(0); i < 9; i++)
			{
				text >> indexTemp;
				indices.push_back(indexTemp - 1);
			}
		}
	}

	CMesh mesh;
	std::vector<SVector3> temp;
	std::vector<SVector2> temp2;

	for (size_t i(0); i < indices.size(); i += 3)
		temp.push_back(v[indices[i]]);
	mesh.SetVertices(temp);
	temp.clear();

	for (size_t i(1); i < indices.size(); i += 3)
		temp2.push_back(vt[indices[i]]);
	mesh.SetUVS(temp2);

	for (size_t i(2); i < indices.size(); i += 3)
		temp.push_back(vn[indices[i]]);
	mesh.SetNormals(temp);

	return mesh;
}

std::string CResources::parseFaces(const std::string& text)
{
	std::string textLine(text);
	size_t i(0);
	while (textLine[i] != '\0')
	{
		if (textLine[i] == '/')
			textLine[i] = ' ';
		i++;
	}
	return textLine;
}
