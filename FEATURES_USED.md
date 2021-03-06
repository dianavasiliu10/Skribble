## STL
* `std::deque` used by default in [CachedResource](https://github.com/AlexandruIca/Skribble/blob/master/src/cached_resource.hpp)
* `std::optional` used by [DrawHistory](https://github.com/AlexandruIca/Skribble/blob/master/src/draw_history.hpp) to remember where the last drawn point was
* C++17's `emplace_back` returning a reference to the emplaced object used in [CachedLayers](https://github.com/AlexandruIca/Skribble/blob/master/src/draw_history.hpp)
* Helpers from `<iterator>` used in [CachedResource](https://github.com/AlexandruIca/Skribble/blob/master/src/cached_resource.hpp):
    - `std::advance`
    - `std::distance`
* C++17's `std::is_same_v` type trait used in [Tests](https://github.com/AlexandruIca/Skribble/blob/develop/tests/helper/test.hpp)
* C++14's `_v` type traits used in [Tests](https://github.com/AlexandruIca/Skribble/blob/develop/tests/helper/test.hpp)
* Multithreading utilities used in [Tests](https://github.com/AlexandruIca/Skribble/blob/develop/tests/helper/test.hpp) to run tests in parallel:
    - `std::atomic`
    - `std::thread`
    - `std::condition_variable`
    - `std::mutex`
    - `std::unique_lock`
    - `std::future`
    - `std::packaged_task`
* C++17's `std::filesystem` used to iterate over test reports in [Tests](https://github.com/AlexandruIca/Skribble/blob/develop/tests/helper/test.hpp)
* C++17's `std::invoke` and `std::invoke_result_t` used to return the correct type in [ThreadPool::push](https://github.com/AlexandruIca/Skribble/blob/develop/tests/helper/test.hpp) and to pass correct function call to thread pool workers
* `std::shared_ptr` used in [ThreadPool::push](https://github.com/AlexandruIca/Skribble/blob/develop/tests/helper/test.hpp) to correctly store the result of the given function

## Language
* Lambdas used for `reduceTo` in [DrawHistory](https://github.com/AlexandruIca/Skribble/blob/master/src/draw_history.cpp)
* Trailing return types used basically everywhere
* Init statments in `if` used in [DrawHistory](https://github.com/AlexandruIca/Skribble/blob/master/src/draw_history.cpp) in `drawAt`
* C++17's `[[nodiscard]]` used almost everywhere
* `explicit` used for most constructors
* `noexcept` move constructors and assignment operators whenever appropiate
* C++17's nested namespace definition used for [CachedLayers](https://github.com/AlexandruIca/Skribble/blob/master/src/draw_history.hpp)
* Anonymous namespaces used to define tests that do not conflict with other tests defined in different files but at the same line in [Tests](https://github.com/AlexandruIca/Skribble/blob/develop/tests/helper/test.hpp)
* `constexpr` used for configuration in [CachedLayers](https://github.com/AlexandruIca/Skribble/blob/master/src/draw_history.hpp) and [config](https://github.com/AlexandruIca/Skribble/blob/master/src/canvas_config.hpp)
* C++17's `inline` variables used in [config](https://github.com/AlexandruIca/Skribble/blob/master/src/canvas_config.hpp)
* Templates used in [CachedResource](https://github.com/AlexandruIca/Skribble/blob/master/src/cached_resource.hpp)
* `static_assert` used in [CachedResource](https://github.com/AlexandruIca/Skribble/blob/master/src/cached_resource.hpp)
* Variadic templates + fold expressions + perfect forwarding used to implement:
    - `emplaceBack` in [CachedResource](https://github.com/AlexandruIca/Skribble/blob/master/src/cached_resource.hpp)
    - `sk::format` in [Format](https://github.com/AlexandruIca/Skribble/blob/develop/src/format.hpp)
    - `ThreadPool::push` in [Tests](https://github.com/AlexandruIca/Skribble/blob/develop/tests/helper/test.hpp)
* Abstract class `TestBase` in [Tests](https://github.com/AlexandruIca/Skribble/blob/develop/tests/helper/test.hpp)
* Exceptions used in [Tests](https://github.com/AlexandruIca/Skribble/blob/develop/tests/helper/test.hpp) to check if a test is being pushed after termination

## Extra
* A variation of the command pattern is used in [CachedResource](https://github.com/AlexandruIca/Skribble/blob/master/src/cached_resource.hpp). The standard way was not used because it was not suited for storing layers of 'paint'. Each new layer is immutable
* Observer pattern using Qt's slots mechanism in [Canvas](https://github.com/AlexandruIca/Skribble/blob/master/src/canvas.hpp)
* QML used for declaring the user interface. All zooming/scrolling is implemented in QML, thus the UI and implementation are independent
* Clang-Tidy used to check for mistakes/improvements in code using [scripts/run-clang-tidy.py](https://github.com/AlexandruIca/Skribble/blob/master/scripts/run-clang-tidy.py)
* Clang-Format used to format the code (and verify that the code is formatted according to `.clang-format` using [scripts/run-clang-format.py](https://github.com/AlexandruIca/Skribble/blob/master/scripts/run-clang-format.py))
* Clazy used to check for common Qt mistakes/improvements in code using [scripts/run-clazy.sh](https://github.com/AlexandruIca/Skribble/blob/master/scripts/run-clazy.sh)
* Modern CMake used to describe how the code should be built, making use of `EXPORT_COMPILE_COMMANDS` to get a compilation database for other tools to use
* `cmake-format` is used to format all CMake files according to `.cmake-format.yaml` using the [scripts/run-cmake-format.sh](https://github.com/AlexandruIca/Skribble/blob/master/scripts/run-cmake-format.sh)
* Addres, Leak, Undefined sanitizers are used to check for memory leaks and undefined behavior in code
* Code coverage can be generated by specifying `-DENABLE_COVERAGE=ON` when calling `cmake`
* All tests defined in [tests/](https://github.com/AlexandruIca/Skribble/tree/develop/tests) are run with `ctest` by having `-DENABLE_TESTS=ON`
