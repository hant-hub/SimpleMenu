#pragma once
#include <../../lib/stbimage/stb_image.h>

namespace Render {

    namespace Image {

        struct image {
            unsigned char* data;
            int width, height, nrChannels;
        };

        struct texture {
            GLuint id;
        };

        texture downloadImage(const std::string filepath);

    }

}