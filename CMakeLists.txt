
project(c_dfDIJoystick2 C)

add_executable(c_dfDIJoystick2 main.c)
target_link_libraries(c_dfDIJoystick2 dinput rpcrt4)

