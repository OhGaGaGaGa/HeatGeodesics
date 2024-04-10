CPMAddPackage(
    NAME "Eigen3"
    GIT_REPOSITORY "https://github.com/hexagon-geo-surv/eigen.git"
    GIT_TAG "3.4.0"
    OPTIONS
    "BUILD_TESTING OFF"
    "EIGEN_BUILD_DOC OFF"
    "EIGEN_LEAVE_TEST_IN_ALL_TARGET OFF"
    "EIGEN_BUILD_PKGCONFIG OFF"
)

CPMAddPackage(
    NAME "libigl"

    GIT_REPOSITORY "https://github.com/libigl/libigl.git"
    GIT_TAG "v2.5.0"
    OPTIONS
    "LIBIGL_SKIP_DOWNLOAD ON"
    "LIBIGL_USE_STATIC_LIBRARY OFF"
    "LIBIGL_WITH_COMISO OFF"
    "LIBIGL_WITH_EMBREE OFF"
    "LIBIGL_WITH_OPENGL OFF"
    "LIBIGL_WITH_OPENGL_GLFW OFF"
    "LIBIGL_WITH_OPENGL_GLFW_IMGUI OFF"
    "LIBIGL_WITH_PNG OFF"
    "LIBIGL_WITH_TRIANGLE OFF"
    "LIBIGL_WITH_PREDICATES OFF"
    "LIBIGL_WITH_TETGEN OFF"
    "LIBIGL_WITH_XML OFF"
    "LIBIGL_WITH_PYTHON OFF"
)

CPMAddPackage(
    NAME "fmt"

    GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
    GIT_TAG "10.2.1"
)

CPMAddPackage(
    NAME "spdlog"

    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_TAG "v1.13.0"
    OPTIONS "SPDLOG_FMT_EXTERNAL 1"
)

CPMAddPackage(
    NAME "cli11"
    GIT_REPOSITORY "https://github.com/CLIUtils/CLI11.git"
    GIT_TAG "v2.4.1"
)

CPMAddPackage(
    NAME "backward-cpp"
    GIT_REPOSITORY "https://github.com/bombela/backward-cpp.git"
    GIT_TAG "v1.6"
)

CPMAddPackage(
    NAME "abseil"
    GIT_REPOSITORY "https://github.com/abseil/abseil-cpp.git"
    GIT_TAG "20240116.1"
    OPTIONS
    "CMAKE_CXX_STANDARD 20"
    "ABSL_PROPAGATE_CXX_STD ON"
)

CPMAddPackage(
    NAME "magic_enum"
    GIT_REPOSITORY "https://github.com/Neargye/magic_enum.git"
    GIT_TAG "v0.9.0"
)

CPMAddPackage(
    NAME "cmake_git_version_tracking"
    GIT_REPOSITORY "https://github.com/andrew-hardin/cmake-git-version-tracking.git"
    GIT_TAG "7d9442bfade5a47b77291e4117f81cc65887c7b9"
)

CPMAddPackage(
    NAME "CDT"
    GIT_REPOSITORY "https://github.com/artem-ogre/CDT.git"
    GIT_TAG "1.4.0"
    SOURCE_SUBDIR "CDT"
    GIT_SUBMODULES "docs"
)

set(CMAKE_CXX_COMPILER_LAUNCHER "")
set(CMAKE_C_COMPILER_LAUNCHER "")