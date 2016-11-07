#include <iostream>
#include <string.h>

using std::string;
using std::cout;
using std::endl;    

#include "Model.h"
#include "Camera.h"
#include "Scene.h"
#include "Linear.h"

int main(int argc, char* argv[]) {
    if(argc < 4) {
        cout << "Usage: raytracer <CAMERA_MODEL> <PLY_MODEL(S)> <OUTFILE_NAME>" << endl;
        return 0;
    }
    
    int numModels = argc - 3;
    Model* models = new Model [numModels];
    for(int i = 2; i < argc-1; i++)
        models [i - 2].init(argv[i]);

    Linear* linear = new Linear();
    Scene scene = Scene(argv[1], linear, models, numModels);
    scene.genDistances();
    // cout << "Finished generating distances" << endl;
    scene.depthWrite(argv[argc - 1]);
    // cout << "Finished writing file" << endl;

    delete [] models;
    delete linear;
	return 0;
}

