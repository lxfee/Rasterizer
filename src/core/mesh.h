#ifndef RASTERIZER_MESH_H_
#define RASTERIZER_MESH_H_

#include <string>
#include <vector>

#include "graphics.h"
#include "maths.h"

struct vertex_t {
    vec3 position;
    vec3 normal;
    vec2 texcoord;
    vec3 tangent;
};

class mesh_t {
   public:
    mesh_t(const std::string& filename);
    mesh_t(const std::vector<vertex_t>& vertexes);
    ~mesh_t();

    mesh_t(const mesh_t&) = delete;
    mesh_t& operator=(const mesh_t&) = delete;

    const vbo_t* get_vbo() const;

   private:
    vbo_t* vbo;
};

#endif  // RASTERIZER_MESH_H_