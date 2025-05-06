#pragma once
#include <common/core.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
namespace GRAPHT {

	class Texture {
	public :

		int id;

		string path;

		string type;

		bool gama = false;
		
		Texture() {
		
		}

		Texture(string direct):path(direct) {
		
		}

		Texture(string direct,bool gam) :path(direct),gama(gam) {

		}

		Texture(string direct, bool gam,string ty) :path(direct), gama(gam),type(type) {

		}
		virtual ~Texture() {
		
		}
		virtual unsigned int loadTextureFromePath() {
			return -1;
		};
	};


	class GLTexture :public Texture {
	public:
		GLTexture(string direct) : Texture(direct) {
		
		}

		GLTexture(Texture texture)  {
			this->gama = texture.gama;
			this->path = texture.path;
			this->type = texture.type;
			loadTextureFromePath();
		}

		GLTexture(string direct,bool gam) : Texture(direct,gam) {
			
		}

		GLTexture(string direct, bool gam,string type) : Texture(direct, gam,type) {
			
		}

		~GLTexture() {
		
		}
		virtual unsigned int loadTextureFromePath();


	};

};