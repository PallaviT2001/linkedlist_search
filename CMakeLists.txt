cmake_minimum_required(VERSION 3.16)

project(linkedlist_search LANGUAGES C)

add_executable(linkedlist_search main.c)

include(GNUInstallDirs)
install(TARGETS linkedlist_search
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
