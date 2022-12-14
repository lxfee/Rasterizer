#ifndef RASTERIZER_TEXTURE_H_
#define RASTERIZER_TEXTURE_H_

#include <string>

#include "graphics.h"
#include "image.h"
#include "maths.h"

typedef enum { USAGE_SRGB_COLOR, USAGE_RAW_DATA, USAGE_LINEAR_COLOR } usage_t;

typedef enum {
    SAMPLE_INTERP_MODE_NEAREST,
    SAMPLE_INTERP_MODE_BILINEAR
} sample_interp_mode_t;

typedef enum {
    SAMPLE_SURROUND_MODE_CLAMP,
    SAMPLE_SURROUND_MODE_REPEAT,
    SAMPLE_SURROUND_MODE_BORDER
} sample_surround_mode_t;

class texture_t {
   public:
    texture_t(int w, int h);
    texture_t(const std::string& filename, usage_t usage);
    ~texture_t();

    void set_interp_mode(sample_interp_mode_t _interp_mode);
    void set_surround_mode(sample_surround_mode_t _surround_mode);
    void set_border_color(vec4 _color);

    void load_from_colorbuffer(framebuffer_t* framebuffer);
    void load_from_depthbuffer(framebuffer_t* framebuffer);
    void load_from_file(const std::string& filename, usage_t usage);
    void load_from_image(image_t* image, usage_t usage);

    vec4 sample(vec2 uv);

   private:
    void ldr_image_to_texture(image_t* image);
    void hdr_image_to_texture(image_t* image);
    void srgb_to_linear();
    void linear_to_srgb();
    sample_interp_mode_t interp_mode = SAMPLE_INTERP_MODE_BILINEAR;
    sample_surround_mode_t surround_mode = SAMPLE_SURROUND_MODE_REPEAT;
    vec4 border_color;
    int width, height;
    vec4* buffer;
};

// class cube_texture_t {
// public:
//     cube_texture_t( const std::string& positive_x, const std::string&
//     negative_x,
//                     const std::string& positive_y, const std::string&
//                     negative_y, const std::string& positive_z, const
//                     std::string& negative_z, usage_t usage);
//     ~cube_texture_t();

//     void sample(vec3 direction,
//                 sample_interp_mode_t interp_mode =
//                 SAMPLE_INTERP_MODE_BILINEAR, sample_surround_mode_t
//                 surround_mode = SAMPLE_SURROUND_MODE_REPEAT);
// private:
//     texture_t* faces[6];
// };

#endif  // RASTERIZER_TEXTURE_H_