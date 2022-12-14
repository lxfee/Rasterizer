#ifndef RASTERIZER_CAMERA_H_
#define RASTERIZER_CAMERA_H_

#include "maths.h"

typedef enum {
    PROJECTION_MODE_ORTHO,
    PROJECTION_MODE_PERSPECTIVE
} projection_mode_t;

class camera_t {
   public:
    camera_t(float _aspect, projection_mode_t _mode);
    virtual ~camera_t();

    const mat4 get_projection_matrix() const;
    virtual const mat4 get_view_matrix() const = 0;

    /** setter **/
    void set_near(float _n);
    void set_far(float _f);
    void set_zoom(float _zoom);
    void set_aspect(float _aspect);
    void set_mode(projection_mode_t _mode);

    /** getter **/
    float get_near() const;
    float get_far() const;
    float get_zoom() const;
    float get_aspect() const;
    projection_mode_t get_mode() const;

   private:
    float n, f;
    float zoom, aspect;
    projection_mode_t mode;
};

#endif  // RASTERIZER_CAMERA_H_