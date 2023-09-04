add_executable( main main.cpp main_window.cpp main_window.ui )
target_link_libraries(main PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
target_compile_options( main PRIVATE -Wall -Wextra -Wpedantic -Werror )
install(TARGETS main DESTINATION bin)