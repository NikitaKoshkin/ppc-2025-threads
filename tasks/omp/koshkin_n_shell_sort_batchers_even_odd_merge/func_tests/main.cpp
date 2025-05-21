#include <gtest/gtest.h>

#include <algorithm>
#include <cstdint>
#include <functional>
#include <memory>
#include <vector>

#include "core/task/include/task.hpp"
#include "omp/koshkin_n_shell_sort_batchers_even_odd_merge/include/ops_omp.hpp"

TEST(koshkin_n_shell_sort_batchers_even_odd_merge_omp, test_144) {
  bool order = true;
  std::vector<int> in = {5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
  std::vector<int> out(in.size(), 0);

  std::vector<int> res = in;
  std::ranges::sort(res.begin(), res.end());

  auto task_data_omp = std::make_shared<ppc::core::TaskData>();
  task_data_omp->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  task_data_omp->inputs_count.emplace_back(in.size());
  task_data_omp->inputs.emplace_back(reinterpret_cast<uint8_t *>(&order));
  task_data_omp->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  task_data_omp->outputs_count.emplace_back(out.size());

  koshkin_n_shell_sort_batchers_even_odd_merge_omp::TestTaskOpenMP test_task_omp(task_data_omp);
  ASSERT_EQ(test_task_omp.Validation(), true);
  test_task_omp.PreProcessing();
  test_task_omp.Run();
  test_task_omp.PostProcessing();
  EXPECT_EQ(out, res);
}