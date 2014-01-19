/**
 * Non-metric Space Library
 *
 * Authors: Bilegsaikhan Naidan (https://github.com/bileg), Leonid Boytsov (http://boytsov.info).
 * With contributions from Lawrence Cayton (http://lcayton.com/).
 *
 * For the complete list of contributors and further details see:
 * https://github.com/searchivarius/NonMetricSpaceLib 
 * 
 * Copyright (c) 2010--2013
 *
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */

#include <algorithm>
#include <sstream>

#include "space.h"
#include "rangequery.h"
#include "knnquery.h"
#include "incremental_quick_select.h"
#include "perm_index_incr_bin.h"
#include "utils.h"

namespace similarity {

void Binarize(const vector<PivotIdType> &perm, const PivotIdType thresh, vector<uint32_t>&bin_perm) {
  size_t bin_perm_word_qty = (perm.size() + 31)/32;

  bin_perm.resize(bin_perm_word_qty);

  for (size_t i = 0; i < perm.size(); ++i) {
    bool b =perm[i] <= thresh;

    if (b) {
      bin_perm[i/32] |= (1<<(i%32)) ;
    }
  }
}

unsigned BinHamming(const uint32_t* a, const uint32_t* b, size_t qty) {
  unsigned res = 0;
  for (size_t i = 0; i < qty; ++i) {
    //  __builtin_popcount quickly computes the number on 1s
    res +=  __builtin_popcount(a[i] ^ b[i]);
  }
  return res;
}

template <typename dist_t, PivotIdType (*perm_func)(const PivotIdType*, const PivotIdType*, size_t)>
PermutationIndexIncrementalBin<dist_t, perm_func>::PermutationIndexIncrementalBin(
    const Space<dist_t>* space,
    const ObjectVector& data,
    const size_t num_pivot,
    const size_t bin_threshold,
    const double db_scan_fraction)
    : data_(data),   // reference
      bin_threshold_(bin_threshold),
      db_scan_(static_cast<size_t>(db_scan_fraction * data.size())),
      bin_perm_word_qty_((num_pivot + 31)/32) {
  CHECK(db_scan_fraction > 0.0);
  CHECK(db_scan_fraction <= 1.0);

  GetPermutationPivot(data, space, num_pivot, &pivot_);

  permtable_.resize(data.size() * bin_perm_word_qty_);

  for (size_t i = 0, start = 0; i < data.size(); ++i, start += bin_perm_word_qty_) {
    Permutation TmpPerm;
    GetPermutation(pivot_, space, data[i], &TmpPerm);
    CHECK(TmpPerm.size() == num_pivot);
    vector<uint32_t>  binPivot;
    Binarize(TmpPerm, bin_threshold_, binPivot);
    CHECK(binPivot.size() == bin_perm_word_qty_);
    memcpy(&permtable_[start], &binPivot[0], bin_perm_word_qty_ * sizeof(binPivot[0]));
  }

  LOG(INFO) << "# pivots                  = " << num_pivot;
  LOG(INFO) << "# binarization threshold = "  << bin_threshold_;
  LOG(INFO) << "# binary entry size (words) = "  << bin_perm_word_qty_;
  LOG(INFO) << "db scan fraction = " << db_scan_fraction;
  //SavePermTable(permtable_, "permtab");
}

template <typename dist_t, PivotIdType (*perm_func)(const PivotIdType*, const PivotIdType*, size_t)>
PermutationIndexIncrementalBin<dist_t, perm_func>::~PermutationIndexIncrementalBin() {
}

template <typename dist_t, PivotIdType (*perm_func)(const PivotIdType*, const PivotIdType*, size_t)>
const std::string PermutationIndexIncrementalBin<dist_t, perm_func>::ToString() const {
  std::stringstream str;
  str <<  "permutation binarized (incr. sorting)";
  return str.str();
}

template <typename dist_t, PivotIdType (*perm_func)(const PivotIdType*, const PivotIdType*, size_t)> 
template <typename QueryType>
void PermutationIndexIncrementalBin<dist_t, perm_func>::GenSearch(QueryType* query) {
  Permutation perm_q;
  GetPermutation(pivot_, query, &perm_q);
  vector<uint32_t>  binPivot;
  Binarize(perm_q, bin_threshold_, binPivot);

  std::vector<IntInt> perm_dists;
  perm_dists.reserve(data_.size());

  for (size_t i = 0, start = 0; i < data_.size(); ++i, start += bin_perm_word_qty_) {
    perm_dists.push_back(std::make_pair(BinHamming(&permtable_[start], &binPivot[0], bin_perm_word_qty_), i));
  }

  IncrementalQuickSelect<IntInt> quick_select(perm_dists);
  for (size_t i = 0; i < db_scan_; ++i) {
    const size_t idx = quick_select.GetNext().second;
    quick_select.Next();
    query->CheckAndAddToResult(data_[idx]);
  }
}

template <typename dist_t, PivotIdType (*perm_func)(const PivotIdType*, const PivotIdType*, size_t)>
void PermutationIndexIncrementalBin<dist_t, perm_func>::Search(
    RangeQuery<dist_t>* query) {
  GenSearch(query);
}

template <typename dist_t, PivotIdType (*perm_func)(const PivotIdType*, const PivotIdType*, size_t)>
void PermutationIndexIncrementalBin<dist_t, perm_func>::Search(
    KNNQuery<dist_t>* query) {
  GenSearch(query);
}


template class PermutationIndexIncrementalBin<float,SpearmanRho>;
template class PermutationIndexIncrementalBin<double,SpearmanRho>;
template class PermutationIndexIncrementalBin<int,SpearmanRho>;
template class PermutationIndexIncrementalBin<float,SpearmanFootrule>;
template class PermutationIndexIncrementalBin<double,SpearmanFootrule>;
template class PermutationIndexIncrementalBin<int,SpearmanFootrule>;
template class PermutationIndexIncrementalBin<float,SpearmanRhoSIMD>;
template class PermutationIndexIncrementalBin<double,SpearmanRhoSIMD>;
template class PermutationIndexIncrementalBin<int,SpearmanRhoSIMD>;
template class PermutationIndexIncrementalBin<float,SpearmanFootruleSIMD>;
template class PermutationIndexIncrementalBin<double,SpearmanFootruleSIMD>;
template class PermutationIndexIncrementalBin<int,SpearmanFootruleSIMD>;

}  // namespace similarity

