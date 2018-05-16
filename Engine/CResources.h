#ifndef CRESOURCES_H
#define CRESOURCES_H

#include "CMesh.h"
#include <string>

class CResources
{
public:
	static CMesh Loader(const std::string& path);
private:
	static std::string parseFaces(const std::string& text);
};

#endif