// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_DETAIL_PARALLEL_INL_H_
#define INCLUDE_JET_DETAIL_PARALLEL_INL_H_

#include "jet/helpers/macros.h"
#include "jet/math/constants/constants.h"
#include "parallel.h"

#include <algorithm>
#include <functional>
#include <future>
#include <vector>

#include <tbb/tbb.h>

namespace jet {

template<typename RandomIterator, typename T>
void
parallelFill(const RandomIterator& begin, const RandomIterator& end, const T& value, ExecutionPolicy policy)
{
  auto diff = end - begin;
  if (diff <= 0) {
    return;
  }

  size_t size = static_cast<size_t>(diff);
  parallelFor(
    kZeroSize, size, [begin, value](size_t i) { begin[i] = value; }, policy);
}

// Adopted from http://ideone.com/Z7zldb
template<typename IndexType, typename Function>
void
parallelFor(IndexType start, IndexType end, const Function& func, ExecutionPolicy policy)
{
  if (start > end) {
    return;
  }

  if (policy == ExecutionPolicy::kParallel) {
    tbb::parallel_for(start, end, func);
  } else {
    for (auto i = start; i < end; ++i) {
      func(i);
    }
  }
}

template<typename IndexType, typename Function>
void
parallelRangeFor(IndexType start, IndexType end, const Function& func, ExecutionPolicy policy)
{
  if (start > end) {
    return;
  }

  if (policy == ExecutionPolicy::kParallel) {
    tbb::parallel_for(tbb::blocked_range<IndexType>(start, end),
                      [&func](const tbb::blocked_range<IndexType>& range) { func(range.begin(), range.end()); });
  } else {
    func(start, end);
  }
}

template<typename IndexType, typename Function>
void
parallelFor(IndexType beginIndexX, IndexType endIndexX, IndexType beginIndexY, IndexType endIndexY, const Function& function, ExecutionPolicy policy)
{
  parallelFor(
    beginIndexY,
    endIndexY,
    [&](IndexType j) {
      for (IndexType i = beginIndexX; i < endIndexX; ++i) {
        function(i, j);
      }
    },
    policy);
}

template<typename IndexType, typename Function>
void
parallelRangeFor(IndexType beginIndexX,
                 IndexType endIndexX,
                 IndexType beginIndexY,
                 IndexType endIndexY,
                 const Function& function,
                 ExecutionPolicy policy)
{
  parallelRangeFor(
    beginIndexY, endIndexY, [&](IndexType jBegin, IndexType jEnd) { function(beginIndexX, endIndexX, jBegin, jEnd); }, policy);
}

template<typename IndexType, typename Function>
void
parallelFor(IndexType beginIndexX,
            IndexType endIndexX,
            IndexType beginIndexY,
            IndexType endIndexY,
            IndexType beginIndexZ,
            IndexType endIndexZ,
            const Function& function,
            ExecutionPolicy policy)
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
    },
    policy);
}

template<typename IndexType, typename Function>
void
parallelRangeFor(IndexType beginIndexX,
                 IndexType endIndexX,
                 IndexType beginIndexY,
                 IndexType endIndexY,
                 IndexType beginIndexZ,
                 IndexType endIndexZ,
                 const Function& function,
                 ExecutionPolicy policy)
{
  parallelRangeFor(
    beginIndexZ,
    endIndexZ,
    [&](IndexType kBegin, IndexType kEnd) { function(beginIndexX, endIndexX, beginIndexY, endIndexY, kBegin, kEnd); },
    policy);
}

template<typename IndexType, typename Value, typename Function, typename Reduce>
Value
parallelReduce(IndexType start, IndexType end, const Value& identity, const Function& func, const Reduce& reduce, ExecutionPolicy policy)
{
  if (start > end) {
    return identity;
  }

  if (policy == ExecutionPolicy::kParallel) {
    return tbb::parallel_reduce(
      tbb::blocked_range<IndexType>(start, end),
      identity,
      [&func](const tbb::blocked_range<IndexType>& range, const Value& init) { return func(range.begin(), range.end(), init); },
      reduce);
  } else {
    (void)reduce;
    return func(start, end, identity);
  }
}

template<typename RandomIterator, typename CompareFunction>
void
parallelSort(RandomIterator begin, RandomIterator end, CompareFunction compareFunction, ExecutionPolicy policy)
{
  if (end < begin) {
    return;
  }

  if (policy == ExecutionPolicy::kParallel) {
    tbb::parallel_sort(begin, end, compareFunction);
  } else {
    std::sort(begin, end, compareFunction);
  }
}

template<typename RandomIterator>
void
parallelSort(RandomIterator begin, RandomIterator end, ExecutionPolicy policy)
{
  parallelSort(begin, end, std::less<typename std::iterator_traits<RandomIterator>::value_type>(), policy);
}

} // namespace jet

#endif // INCLUDE_JET_DETAIL_PARALLEL_INL_H_
