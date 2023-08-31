add_executable( main main.cpp )
target_link_libraries(main PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
target_compile_options( main PRIVATE -Wall -Wextra -Wpedantic -Werror )
add_test( main ${EXECUTABLE_OUTPUT_PATH}/main )