FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.9.1
)

# CMake 3.14+
FetchContent_GetProperties(catch)
if(NOT catch_POPULATED)
FetchContent_POPULATE(catch)
add_subdirectory(${catch_SOURCE_DIR} ${catch_BINARY_DIR})
endif()

include(CTest)

set(LANGS en fr es it zh)


SET(LANG_OBJS "")

function(make_lang_test lang)
    set(TNAME ${lang}_test)

    set(myobj  "$<TARGET_OBJECTS:${TNAME}>")
    list(APPEND LANG_OBJS ${myobj})
    set(LANG_OBJS ${LANG_OBJS} PARENT_SCOPE)

    add_library(${TNAME} OBJECT lang_test.cpp)
    target_compile_definitions(${TNAME} PRIVATE -DLANG_TEST_LANG=\"${lang}\")
    target_link_libraries(${TNAME} PRIVATE Catch2::Catch2 PRIVATE localization)
endfunction(make_lang_test)



foreach(MYLANG ${LANGS})
    make_lang_test(${MYLANG})
endforeach(MYLANG)

add_executable(tests main.cpp ${LANG_OBJS})
target_link_libraries(tests PUBLIC Catch2::Catch2 localization)

