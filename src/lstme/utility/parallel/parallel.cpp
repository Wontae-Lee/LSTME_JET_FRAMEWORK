// From external
#include <oneTBB/include/tbb/tbb.h>


// From project
#include "constants.hpp"
#include "macros.hpp"
#include "parallel.hpp"

// From standard
#include <algorithm>
#include <functional>
#include <future>
#include <vector>

namespace lstme{

template<typename RandomIterator, typename T>
void
parallelFill(const RandomIterator& begin,
             const RandomIterator& end,
             const T& value
            )
{
  auto diff = end - begin;
  if (diff <= 0) {
    return;
  }

  size_t size = static_cast<size_t>(diff);
  parallelFor(
    kZeroSize, size, [begin, value](size_t i) { begin[i] = value; });
}

template<typename IndexType, typename Function>
void
parallelFor(IndexType start,
            IndexType end,
            const Function& func)
{
  if (start > end) {
    return;
  }

 
    tbb::parallel_for(start, end, func);
  
  }

template<typename IndexType, typename Function>
void
parallelRangeFor(IndexType start,
                 IndexType end,
                 const Function& func)
{
  if (start > end) {
    return;
  }


    tbb::parallel_for(tbb::blocked_range<IndexType>(start, end),
                      [&func](const tbb::blocked_range<IndexType>& range) {
                        func(range.begin(), range.end());
                      });

}


template<typename IndexType, typename Function>
void
parallelFor(IndexType beginIndexX,
            IndexType endIndexX,
            IndexType beginIndexY,
            IndexType endIndexY,
            const Function& function)
{
  parallelFor(
    beginIndexY,
    endIndexY,
    [&](IndexType j) {
      for (IndexType i = beginIndexX; i < endIndexX; ++i) {
        function(i, j);
      }
    });
}

template<typename IndexType, typename Function>
void
parallelRangeFor(IndexType beginIndexX,
                 IndexType endIndexX,
                 IndexType beginIndexY,
                 IndexType endIndexY,
                 const Function& function)
{
  parallelRangeFor(
    beginIndexY,
    endIndexY,
    [&](IndexType jBegin, IndexType jEnd) {
      function(beginIndexX, endIndexX, jBegin, jEnd);
    });
}

template<typename IndexType, typename Function>
void
parallelFor(IndexType beginIndexX,
            IndexType endIndexX,
            IndexType beginIndexY,
            IndexType endIndexY,
            IndexType beginIndexZ,
            IndexType endIndexZ,
            const Function& function)
{
  parallelFor(
    beginIndexZ,
    endIndexZ,
    [&](IndexType k) {
      for (IndexType j = beginIndexY; j < endIndexY; ++j) {
        for (IndexType i = beginIndexX; i < endIndexX; ++i) {
          function(i, j, k);
        }
      }
    }
    );
}

template<typename IndexType, typename Function>
void
parallelRangeFor(IndexType beginIndexX,
                 IndexType endIndexX,
                 IndexType beginIndexY,
                 IndexType endIndexY,
                 IndexType beginIndexZ,
                 IndexType endIndexZ,
                 const Function& function)
{
  parallelRangeFor(
    beginIndexZ,
    endIndexZ,
    [&](IndexType kBegin, IndexType kEnd) {
      function(beginIndexX, endIndexX, beginIndexY, endIndexY, kBegin, kEnd);
    });
}

template<typename IndexType, typename Value, typename Function, typename Reduce>
Value
parallelReduce(IndexType start,
               IndexType end,
               const Value& identity,
               const Function& func,
               const Reduce& reduce)
{
  if (start > end) {
    return identity;
  }


   tbb::parallel_reduce(tbb::blocked_range<IndexType>(start, end),identity,[&func](const tbb::blocked_range<IndexType>& range, const Value& init) 
   {
        return func(range.begin(), range.end(), init);
    },
      reduce);
  } 





template<typename RandomIterator, typename CompareFunction>
void
parallelSort(RandomIterator begin,
             RandomIterator end,
             CompareFunction compareFunction
            )
{
  if (end < begin) {
    return;
  }


  
    tbb::parallel_sort(begin, end, compareFunction);
  } 


template<typename RandomIterator>
void
parallelSort(RandomIterator begin, RandomIterator end)
{
  parallelSort(
    begin,
    end,
    std::less<typename std::iterator_traits<RandomIterator>::value_type>());
}

} // namespace lstme
