#define MAIN_EXECUTABLE
#include "test.hpp"

#include "cached_resource.hpp"

auto adder = [](int& dest, int& src) -> void { dest += src; };

template<typename T>
struct Traits
{
    using ContainerType = std::deque<T>;
    static constexpr int cacheGap = 3;
    static constexpr int maxCount = sk::ResourceTraits<T>::maxCount;
};

TEST("[CachedResource] Undo/Redo")
{
    sk::CachedResource<int, Traits<int>> res{ adder };

    for(int i = 0; i < 10; ++i) {
        res.emplaceBack(i + 1);
    }

    int sum{ 0 };
    res.reduceTo(sum);

    ASSERT(sum == 55);
    ASSERT(res.getLast() == 10);
    ASSERT((*res.getLastCache()) == 45);

    bool undo = res.undo();

    ASSERT(undo == true);
    ASSERT((*res.getLastCache()) == 45);
    ASSERT(res.underUndo());

    undo = res.undo();

    ASSERT(undo == true);
    ASSERT((*res.getLastCache()) == 21);
    ASSERT(res.underUndo());

    bool redo = res.redo();

    ASSERT(redo == true);
    ASSERT(*(res.getLastCache()) == 45);
    ASSERT(res.underUndo());

    redo = res.redo();

    ASSERT(redo == false);
    ASSERT(*(res.getLastCache()) == 45);
    ASSERT(res.underUndo() == false);

    for(int i = 0; i < 9; ++i) {
        undo = res.undo();
        ASSERT(res.underUndo());
    }

    ASSERT(undo == true);
    ASSERT(res.getLastCache() == nullptr);
    ASSERT(res.getLast() == 1);
    ASSERT(res.underUndo());

    undo = res.undo();

    ASSERT(undo == true);
    ASSERT(res.underUndo());

    sum = 0;
    res.reduceTo(sum);

    ASSERT(sum == 0);

    undo = res.undo();

    ASSERT(undo == false);
    ASSERT(res.underUndo());

    for(int i = 0; i < 9; ++i) {
        redo = res.redo();
    }

    ASSERT(redo == true);
    ASSERT(res.underUndo());

    redo = res.redo();

    ASSERT(redo == false);
    ASSERT(res.underUndo() == false);
}
