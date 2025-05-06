#pragma once

#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
namespace GRAPHT {
	class Shader {
	public:
		unsigned int ID;
		const char* vShaderCode;
		const char* fShaderCode;
		const char* gShaderCode;

		Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);

		virtual void  generate() = 0;

		virtual void use() = 0;
		

	};


	class GLShader : public Shader {
	public:
		GLShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr) :Shader(vertexPath,fragmentPath,geometryPath) {
			generate();
		}
		void checkCompileErrors(unsigned int shader, std::string type);

		virtual void  generate();

		virtual void use();

		void setMat4(const std::string& name, const glm::mat4& mat) const;

		void setMat3(const std::string& name, const glm::mat3& mat) const;

		void setMat2(const std::string& name, const glm::mat2& mat) const;

		void setVec4(const std::string& name, float x, float y, float z, float w);

		void setVec4(const std::string& name, const glm::vec4& value) const;

		void setVec3(const std::string& name, float x, float y, float z) const;

		void setVec3(const std::string& name, const glm::vec3& value) const;

		void setVec2(const std::string& name, const glm::vec2& value) const;

		void setVec2(const std::string& name, float x, float y) const;

		void setFloat(const std::string& name, float value) const;

		void setInt(const std::string& name, int value) const;

		void setBool(const std::string& name, bool value) const;


	};


	class TShader {

	public:
		unsigned int ID;
		TShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);

		void checkCompileErrors(unsigned int shader, std::string type);


		 void use();

		void setMat4(const std::string& name, const glm::mat4& mat) const;

		void setMat3(const std::string& name, const glm::mat3& mat) const;

		void setMat2(const std::string& name, const glm::mat2& mat) const;

		void setVec4(const std::string& name, float x, float y, float z, float w);

		void setVec4(const std::string& name, const glm::vec4& value) const;

		void setVec3(const std::string& name, float x, float y, float z) const;

		void setVec3(const std::string& name, const glm::vec3& value) const;

		void setVec2(const std::string& name, const glm::vec2& value) const;

		void setVec2(const std::string& name, float x, float y) const;

		void setFloat(const std::string& name, float value) const;

		void setInt(const std::string& name, int value) const;

		void setBool(const std::string& name, bool value) const;

	};
}