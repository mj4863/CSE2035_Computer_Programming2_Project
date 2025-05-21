#include <png.h>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>
using namespace std;

// read png_file
void read_png_file(const char* file_name, vector<png_bytep>& row_pointers, int& width, int& height, png_byte& color_type) {
    FILE *fp = fopen(file_name, "rb");
    if (!fp) throw runtime_error("File cannot be opened for reading!");

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) throw runtime_error("png_create_read_struct failed!");

    png_infop info = png_create_info_struct(png);
    if (!info) throw runtime_error("png_create_info_struct failed!");

    if (setjmp(png_jmpbuf(png))) throw runtime_error("Error during initializing input and output!");

    png_init_io(png, fp);
    png_read_info(png, info);

    width = png_get_image_width(png, info);
    height = png_get_image_height(png, info);
    color_type = png_get_color_type(png, info);

    png_read_update_info(png, info);

    row_pointers.resize(height);

    for (int i = 0; i < height; i++) {
        row_pointers[i] = (png_byte*)malloc(png_get_rowbytes(png, info));
    }

    png_read_image(png, row_pointers.data());

    fclose(fp);
}

// write png_file
void write_png_file(const char* file_name, vector<png_bytep>& row_pointers, int width, int height, png_byte color_type) {
    FILE *fp = fopen(file_name, "wb");
    if (!fp) throw runtime_error("File cannot be opened for writing!");

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) throw runtime_error("png_create_write_struct failed!");

    png_infop info = png_create_info_struct(png);
    if (!info) throw runtime_error("png_create_info_struct failed!");

    if (setjmp(png_jmpbuf(png))) throw runtime_error("Error during initializing input and output");

    png_init_io(png, fp);

    png_set_IHDR(png, info, width, height,
                 8, color_type, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(png, info);

    png_write_image(png, row_pointers.data());
    png_write_end(png, NULL);

    fclose(fp);
}

// flip png_file vertically
void flip_image(vector<png_bytep>& row_pointers, int width, int height, png_byte color_type) {
    int row_bytes = width * 4; // 4 bytes per pixel for RGBA
    if (color_type == PNG_COLOR_TYPE_RGB) row_bytes = width * 3; // 3 bytes per pixel for RGB
    vector<png_byte> temp_row(row_bytes); // Temporary storage for a row

    for (int i = 0; i < height / 2; i++) {
        memcpy(temp_row.data(), row_pointers[i], row_bytes);
        memcpy(row_pointers[i], row_pointers[height - 1 - i], row_bytes);
        memcpy(row_pointers[height - 1 - i], temp_row.data(), row_bytes);
    }
}

int main() {
    const char* file_in = "input.png";
    const char* file_out = "output.png";

    vector<png_bytep> row_pointers;
    int width, height;
    png_byte color_type;

    try {
		// read png_file
        read_png_file(file_in, row_pointers, width, height, color_type);

		// flip png_file vertically
        flip_image(row_pointers, width, height, color_type);

		// write png_file
        write_png_file(file_out, row_pointers, width, height, color_type);

		// release allocated memory
        for (int i = 0; i < height; i++)
            free(row_pointers[i]);
    } 
	catch (const runtime_error& e) {
        cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}