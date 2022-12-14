#include "image.h"
#include <stbimage/stb_image.h>


namespace Render {

    namespace Image {


        texture downloadImage(const std::string filepath) {
            image i;

            i.data = stbi_load(filepath.c_str(), &i.width, &i.height, &i.nrChannels, 0);
            stbi_set_flip_vertically_on_load(true);
            GLuint id;

            glGenTextures(1, &id);
            glBindTexture(GL_TEXTURE_2D, id);
            glGenerateMipmap(GL_TEXTURE_2D);

            glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // repeat texture if larger than image
            glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // if magnified linearly interpolate
            glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // if shrunk linearly interpolate between mipmaps and texels

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, i.width, i.height, 0, GL_RGB, GL_UNSIGNED_BYTE, i.data);

            glBindTexture(GL_TEXTURE_2D, 0);


            stbi_image_free(i.data);

            return {id};
        }




    }
}