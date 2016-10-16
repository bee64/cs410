#ifndef SCENE_H_INCLUDE
#define SCENE_H_INCLUDE

#include "Camera.h"
#include <string>

class Scene{
public:
    Scene();
    ~Scene();

    void genIntersections(Camera * cam);
    void depthWrite(std::string filename);

    double* distToDepth(double d);
private:

    void allocateImage();
    // Maximum and Minimum distance in the scene
    double tmin;
    double tmax;

    double** image;
    int resX;
    int resY;
    
};

#endif