# OpenGL Model Viewer

This project is a real-time renderer for .stl format files, built using the OpenGL graphics API. I primarily used Joey de Vries' tutorials at [learnopengl.com](www.learnopengl.com) to teach myself OpenGL, and they inspired much of this design. 

## Features
Fully adjustable ambient, diffuse and specular (Phong) lighting

![Alien](https://media.giphy.com/media/hs7beqrv6l2AaaAhk5/giphy.gif)

Mouse, scroll and keyboard controls for oribiting and zooming around the model

![Bust](https://media.giphy.com/media/VIo4oot5YSDh5GgCgU/giphy.gif)

Explode effect on start

![Elephant](https://media.giphy.com/media/eg4eVV5r2tysDBi38g/giphy.gif)

Ability to load high-detail (> 1 million polygons) models

![Head](https://media.giphy.com/media/W5rCkFi3NH4JljDw92/giphy.gif)

Adjustable FOV

![Rat](https://media.giphy.com/media/Yq8YbmwlsXJ7BIf6YM/giphy.gif)

_Sample models retrieved from turbosquid.com:_
- [Alien](https://www.turbosquid.com/3d-models/free-printable-aline-animal-3d-model/1030948)
- [Bust](https://www.turbosquid.com/3d-models/free-indian-woman-3d-model/1128457)
- [Elephant](https://www.turbosquid.com/FullPreview/Index.cfm/ID/1369839)
- [Head](https://www.turbosquid.com/3d-models/free-zbrush-man-head-3d-model/696839)
- [Rat](https://www.turbosquid.com/3d-models/sculpture-rat-3ds-free/1127738)


## Files
| File | Contents |
|:-:|:-:|
| main.cpp | config.ini file parsing, GLFW setup, OpenGL setup, input processing functions and main rendering loop |
| camera.hpp/cpp | Camera class: stores camera position and angle state, handles camera movement and FOV adjustment, calculates view and projection matrices |
| mesh.hpp/cpp | Mesh class: loads and stores mesh vertices and indices, draws meshes |
| model.hpp/cpp | Model class: recursively processes, loads and stores meshes, iteratively draws those meshes |
| shader.hpp/cpp | Shader class: loads, compiles, links and binds shaders, updates shader uniforms |
| shaders/model/*.glsl | GLSL shaders for the model. geometry.glsl only exists for explode effect |
| config.ini | Configuration file for changing any model, material, lighting, graphical or window properties that may need to be customized. I have future plans to move this configuration to a GUI |

## Dependencies
|Library|Description|Link|
|:-:|:-:|:-:|
| OpenGL | Open-source graphics API, written by graphics hardware manufacturers. This project uses version 4.1 as it is pre-installed on all modern MacOS devices | [Website](https://www.opengl.org) |
| GLFW | Cross-platform library used for window management, OpenGL context management, and user input processing | [Website](https://www.glfw.org) |
| Assimp | Library for importing 3D models | [Website](https://www.assimp.org) |
| GLM | Math library for OpenGL programming, designed with GLSL in mind. Used for vector and matrix operations | [Website](https://www.glm.g-truc.net) |
|inih| .ini file parsing library. Used to parse config.ini | [Original Library](https://www.github.com/benhoyt/inih) <br> [Header-only version used](https://www.github.com/jtilly/inih) |

## Build
_This project has not been tested on any platforms other than my development machine (2018 MBP). I may look into improving this in the future._

opengl-model-viewer is expected to work on all MacOS machines, but this is unverified. It will not work on Windows or Linux machines without modifcation to the OpenGL importing process (this project uses the preinstalled OpenGL found on MacOS, and therefore does not use a extension loading library such as GLEW). The GLFW installation should also be modified as it is now using a MacOS-only pre-compiled binary. Assimp, GLM, and inih should not need modification for building on other systems.
