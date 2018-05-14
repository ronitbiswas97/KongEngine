class CShader{

private:
unsigned int ID;
public:
CShader(const std::string& vertexSourceFileName, const std::string& fragmentFileName);
void operator()(const char* name, int value);
void operator()(int name, int value);
void operator()(const char* name, float value);
void operator()(int name, float value);
void operator()... // sobrecargar con todos los tipos de datos
unsigned int GetID()const;
void Use();
~CShader();

static std::string ReadFile(const std::string& fileName);

private:
unsigned int Compile(const char* shaderSource, ShaderType type);
void Errors(unsigned int shader, ShaderType type);

};
