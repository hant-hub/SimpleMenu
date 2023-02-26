#include "image.h"



namespace Render {

    namespace Image {


        texture downloadImage(const std::string filepath) {
            image i;
            stbi_set_flip_vertically_on_load(true);

            i.data = stbi_load(filepath.c_str(), &i.width, &i.height, &i.nrChannels, 4);

            if (!i.data) {
                std::cout << "Failed to Load Image" << std::endl;
            }

            
            GLuint id;

            glGenTextures(1, &id);
            glBindTexture(GL_TEXTURE_2D, id);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, i.width, i.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, i.data);

            glGenerateMipmap(GL_TEXTURE_2D);

            glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // repeat texture if larger than image
            glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // if magnified linearly interpolate
            glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // if shrunk linearly interpolate between mipmaps and texels

            

            glBindTexture(GL_TEXTURE_2D, 0);


            stbi_image_free(i.data);

            return {id};
        }




    }
}