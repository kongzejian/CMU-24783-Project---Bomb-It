add_library(bitmap bitmap.cpp bitmap.h)
target_link_libraries(bitmap ysbitmap)
target_include_directories(bitmap PUBLIC .)