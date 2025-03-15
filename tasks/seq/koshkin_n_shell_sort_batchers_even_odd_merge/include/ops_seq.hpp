#pragma once

#include <utility>
#include <vector>

#include "core/task/include/task.hpp"

namespace koshkin_n_shell_sort_batchers_even_odd_merge_seq {

class TestTaskSequential : public ppc::core::Task {
 public:
  void swap(std::vector<int>& a, int i, int j, bool order);
  void BatcherMerge(std::vector<int>& a, int start, int end, bool order);
  void shellBatcherSort(std::vector<int>& arr, bool order);
  explicit TestTaskSequential(ppc::core::TaskDataPtr task_data) : Task(std::move(task_data)) {}
  bool PreProcessingImpl() override;
  bool ValidationImpl() override;
  bool RunImpl() override;
  bool PostProcessingImpl() override;

 private:
  std::vector<int> input_, output_;
  bool input_order;  // порядок сортировки (1 - по возрастанию, 0 - по убыванию)"
};

}  // namespace koshkin_n_shell_sort_batchers_even_odd_merge_seq