set(space_srcs
    ParticleTest.cpp
    SystemTest.cpp
)

set(space_libs
    geometry
    space
)

add_unit_test(
    space
    space_srcs
    space_libs
)
