#ifndef GRID_H
#define GRID_H

#include <glm/glm.hpp>
/*
constexpr glm::vec3 substraction(glm::dvec3& vec1, glm::dvec3& vec2)
{
    glm::dvec3 result = vec1 - vec2;
    return const_cast<const glm::dvec3&>(result);
}
*/
class Grid3D
{
public:
    Grid3D(const glm::dvec3& min_bound, const glm::dvec3& max_bound, size_t num_x_voxels, size_t num_y_voxels, size_t num_z_voxels) : 
            min_bound{min_bound},
            max_bound{max_bound},
            grid_size{max_bound - min_bound},
            num_x_voxels{num_x_voxels},
            num_y_voxels{num_y_voxels},
            num_z_voxels{num_z_voxels},
            voxel_size_x{grid_size.x / num_x_voxels},
            voxel_size_y{grid_size.y / num_y_voxels},
            voxel_size_z{grid_size.z / num_z_voxels} {}

    size_t numberOfXVoxels() const { return num_x_voxels;}
    size_t numberOfYVoxels() const { return num_y_voxels;}
    size_t numberOfZVoxels() const { return num_z_voxels;}
    glm::vec3 minBound() const { return min_bound;}
    glm::vec3 maxBound() const { return max_bound;}
    glm::vec3 gridSize() const { return grid_size;}
    double voxelSizeX() const { return voxel_size_x;}
    double voxelSizeY() const { return voxel_size_y;}
    double voxelSizeZ() const { return voxel_size_z;}

private:
    // the minimum bound vector of the voxel grid
    const glm::dvec3 min_bound;
    // the maximum bound vector of the voxel grid
    const glm::dvec3 max_bound;
    // the grid size, determined by (Max_bound - Min_bound)
    const glm::dvec3 grid_size;
    // the number of voxel in each of the x, y, z directions
    const size_t num_x_voxels, num_y_voxels, num_z_voxels;
    // the size of the voxel's x dimension 
    const double voxel_size_x;
    // the size of the voxel's y dimension 
    const double voxel_size_y;
    // the size of the voxel's z dimension 
    const double voxel_size_z;

};

#endif