# University STL Learning Route Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** 在仓库根目录创建一份不含时间安排、面向大学生的系统化 STL 详细学习路线。

**Architecture:** 使用单个 Markdown 文件承载完整路线，按“前置知识—整体认识—容器—迭代器—算法—高级组合—工程实践—综合项目”递进。每个主要阶段用统一栏目连接知识、API、练习、易错点和验收标准，使文件既能顺序学习，也能用于复习检查。

**Tech Stack:** UTF-8 Markdown、C++11/C++17 标准库术语与示例

## Global Constraints

- 最终文件必须为仓库根目录下的 `大学生STL详细学习路线.md`。
- 不包含按周、按天或按课时安排的学习进度。
- 默认读者已经掌握 C++ 基础语法、类、引用和指针。
- 内容至少基于 C++11，并适当标注 C++17 内容。
- 不修改 `STL学前准备/STL学习路线和计划.txt`。

---

### Task 1: 创建并验证大学生 STL 详细学习路线

**Files:**
- Create: `大学生STL详细学习路线.md`
- Verify unchanged: `STL学前准备/STL学习路线和计划.txt`

**Interfaces:**
- Consumes: `docs/superpowers/specs/2026-07-19-university-stl-learning-route-design.md` 中确认的内容范围和编排原则。
- Produces: 一份可直接顺序学习、复习和自测的 Markdown 学习路线。

- [ ] **Step 1: 记录旧文件状态**

运行：

```powershell
git status --short -- 'STL学前准备/STL学习路线和计划.txt'
```

预期：无输出，表示旧文件当前没有未提交改动。

- [ ] **Step 2: 创建正式学习路线文件**

使用 `apply_patch` 新建 `大学生STL详细学习路线.md`，并写入以下完整结构：

1. 使用说明：适合对象、总目标、路线总览、掌握层级标记。
2. 阶段一——C++ 前置知识：模板、引用与 `const`、对象语义、运算符重载、Lambda、复杂度基础。
3. 阶段二——STL 整体认识：容器、迭代器、算法、函数对象、适配器、分配器，以及组件协作示例。
4. 阶段三——`string` 与顺序容器：`array`、`vector`、`deque`、`list`、`forward_list`，重点讲选型和迭代器失效。
5. 阶段四——关联容器：`set`、`multiset`、`map`、`multimap`，包括比较器和只查询时避免 `operator[]`。
6. 阶段五——无序关联容器：`unordered_set`、`unordered_map`，包括哈希、桶、冲突、自定义哈希和有序/无序选型。
7. 阶段六——容器适配器：`stack`、`queue`、`priority_queue`，覆盖括号匹配、BFS、Top K 和自定义优先级。
8. 阶段七——迭代器与范围：迭代器类别、`begin/end`、`const_iterator`、反向迭代器、辅助函数和失效规则。
9. 阶段八——标准算法：遍历、查找、计数、排序、二分、复制、变换、删除、去重、集合与数值算法。
10. 阶段九——函数对象与自定义类型：标准函数对象、Lambda 捕获、自定义比较器、严格弱序和结构体排序。
11. 阶段十——容器选型与复杂度：按访问、插入、删除、顺序、去重、统计和优先级场景给出决策路径。
12. 阶段十一——现代 C++ 补充：范围 `for`、结构化绑定、`emplace`、`optional`、`variant` 和范围库的进阶提示。
13. 阶段十二——综合训练：基础题、进阶题和学生成绩管理、单词统计、任务调度、通讯录项目。
14. 常见错误清单、最终能力验收清单和建议的最小示例文件清单。

每个主要阶段都写明学习目标、核心知识点、常用 API、练习任务、常见错误和验收标准。示例代码使用带语言标记的 C++ 代码块，并保持可独立理解。

- [ ] **Step 3: 检查结构和禁用内容**

运行：

```powershell
rg -n '^## |^### ' '大学生STL详细学习路线.md'
rg -n '第[一二三四五六七八九十0-9]+(周|天)|每天|课时安排' '大学生STL详细学习路线.md'
```

预期：第一条命令列出完整章节；第二条命令无输出，确认没有时间安排。

- [ ] **Step 4: 检查重点知识覆盖**

运行：

```powershell
rg -n 'vector|unordered_map|priority_queue|迭代器失效|erase-remove|lower_bound|严格弱序|复杂度|综合项目' '大学生STL详细学习路线.md'
```

预期：所有关键词至少出现一次，并处于对应学习阶段或检查清单中。

- [ ] **Step 5: 检查文件质量与旧文件状态**

运行：

```powershell
git diff --check
git status --short -- '大学生STL详细学习路线.md' 'STL学前准备/STL学习路线和计划.txt'
```

预期：`git diff --check` 无报错；状态只显示新建的 `大学生STL详细学习路线.md`，旧文件不显示。

- [ ] **Step 6: 提交正式学习路线**

```powershell
git add -- '大学生STL详细学习路线.md'
git commit -m "docs: add detailed university STL learning route"
```

预期：提交成功，且提交只包含正式学习路线文件。
