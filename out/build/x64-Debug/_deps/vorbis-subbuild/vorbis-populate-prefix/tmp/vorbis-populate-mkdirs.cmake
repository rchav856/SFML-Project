# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/vorbis-src"
  "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/vorbis-build"
  "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/vorbis-subbuild/vorbis-populate-prefix"
  "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/vorbis-subbuild/vorbis-populate-prefix/tmp"
  "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp"
  "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/vorbis-subbuild/vorbis-populate-prefix/src"
  "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()