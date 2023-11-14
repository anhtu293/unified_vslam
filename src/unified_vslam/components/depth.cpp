#include "depth.hpp"
#include <png.h>
#include <vector>
#include <fstream>
#include <memory>

namespace unified_slam::components{
    Depth::Depth(const std::string& path){
        FILE *fp = fopen(path.c_str(), "rb");

        // create png and info pointers
        png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        if (!png) abort();
        png_infop info = png_create_info_struct(png);
        if (!info) abort();

        // set jump in case of failure
        if (setjmp(png_jmpbuf(png))) abort();
        png_init_io(png, fp);
        png_read_info(png, info);

        // get info: width, height, type and bit_depth
        int width = png_get_image_width(png, info);
        int height = png_get_image_height(png, info);
        png_byte color_type = png_get_color_type(png, info);
        png_byte bit_depth = png_get_bit_depth(png, info);

        std::vector<std::unique_ptr<png_byte[]>> row_pointers(height);
        for (int y = 0; y < height; y++){
            row_pointers[y] = std::make_unique<png_byte[]>(png_get_rowbytes(png, info));
        }

        png_read_image(png, reinterpret_cast<png_bytep*>(row_pointers.data()));

        fclose(fp);

        Eigen::MatrixXd data(width, height);

        for (int row = 0; row < width; ++row){
            for (int col = 0; col < height; ++col){
                data(row, col) = row_pointers[row][col];
            }
        }
        this->depth_ = data;
    }
} // namespace unified_slam::components
