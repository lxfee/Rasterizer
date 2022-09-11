#ifndef RASTERIZER_SHADER_H_
#define RASTERIZER_SHADER_H_

#include "maths.h"

class shader_t {
public:
    shader_t(int sizeof_uniforms, int sizeof_varyings);
    virtual ~shader_t();

    virtual const vec4 vertex_shader(const void *attribs, void *varyings) = 0;
    virtual const vec4 fragment_shader(const void *varyings, bool& discard) = 0;

    int get_sizeof_uniforms() const ;
    int get_sizeof_varyings() const ;

    void set_uniform(void *uniform_data);

    shader_t(const shader_t&) = delete;
    shader_t &operator = (const shader_t&) = delete;
    
protected:
    char *uniforms;
    bool enable_blend;
private:
    int sizeof_uniforms;
    int sizeof_varyings;
};
#endif // RASTERIZER_SHADER_H_