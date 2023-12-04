cmake_minimum_required(VERSION 3.16)
project(Dodge_em LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Dodge_em src/main.cpp src/Source.cpp)
target_link_libraries(Dodge_em PRIVATE sfml-graphics)
target_compile_features(Dodge_em PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET Dodge_em
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Dodge_em>
        VERBATIM)
endif()

install(TARGETS Dodge_em)
