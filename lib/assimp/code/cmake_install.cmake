# Install script for directory: /Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/lib/libassimp.4.1.0.dylib"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/lib/libassimp.4.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.4.1.0.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.4.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      execute_process(COMMAND "/usr/bin/install_name_tool"
        -id "/usr/local/lib/libassimp.4.dylib"
        "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/lib/libassimp.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.dylib")
    execute_process(COMMAND "/usr/bin/install_name_tool"
      -id "/usr/local/lib/libassimp.4.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.dylib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/anim.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/ai_assert.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/camera.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/color4.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/color4.inl"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/config.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/defs.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/Defines.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/cfileio.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/light.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/material.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/material.inl"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/matrix3x3.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/matrix3x3.inl"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/matrix4x4.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/matrix4x4.inl"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/mesh.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/postprocess.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/quaternion.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/quaternion.inl"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/scene.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/metadata.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/texture.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/types.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/vector2.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/vector2.inl"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/vector3.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/vector3.inl"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/version.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/cimport.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/importerdesc.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/Importer.hpp"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/DefaultLogger.hpp"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/ProgressHandler.hpp"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/IOStream.hpp"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/IOSystem.hpp"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/Logger.hpp"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/LogStream.hpp"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/NullLogger.hpp"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/cexport.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/Exporter.hpp"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/DefaultIOStream.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/DefaultIOSystem.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/SceneCombiner.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/Compiler/pushpack1.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/Compiler/poppack1.h"
    "/Users/shane/Desktop/OpenGL-Project/lib/assimp-4.1.0/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

