# 大学生 STL 详细学习路线

> 这是一条不绑定学习时长的知识递进路线。建议按阶段顺序推进：先理解为什么使用某个组件，再记常用接口，最后通过练习形成选型能力。

## 一、适合对象与学习目标

### 适合对象

本路线适合已经具备以下基础的大学生：

- 掌握 C++ 变量、分支、循环、函数和基本输入输出。
- 理解类、对象、构造函数、封装和继承的基本概念。
- 会使用指针、引用、数组和动态内存。
- 接触过函数模板或类模板，但尚未系统学习 STL。

如果这些内容还不熟，可以先完成“阶段一”的前置知识检查，再开始 STL 主体。

### 总体目标

完成路线后，应当能够：

1. 理解容器、迭代器、算法和函数对象如何协作。
2. 根据数据特点选择合适的容器，而不是只会使用 `vector`。
3. 熟练使用常见容器、算法和容器适配器解决实际问题。
4. 正确处理迭代器失效、算法前置条件和比较器规则。
5. 看懂常见 STL 类型声明、模板报错和复杂度描述。
6. 使用 STL 完成刷题、课程设计和中小型 C++ 项目。

### 掌握层级

- **必须掌握**：高频内容，应能脱离资料独立使用。
- **理解原理**：知道为什么这样设计，能够解释常见现象。
- **了解即可**：知道用途和基本写法，需要时能够查文档使用。
- **进阶拓展**：基础扎实后再学习，不阻塞主线。

## 二、学习路线总览

```text
C++ 前置知识
    ↓
STL 整体结构
    ↓
string 与顺序容器
    ↓
关联容器与无序关联容器
    ↓
stack / queue / priority_queue
    ↓
迭代器、范围与失效规则
    ↓
标准算法与数值算法
    ↓
Lambda、函数对象与自定义类型
    ↓
容器选型、复杂度与性能意识
    ↓
现代 C++ 补充与综合项目
```

学习每个组件时，都要回答以下问题：

1. 它解决什么问题？
2. 它的核心数据结构是什么？
3. 哪些操作快，哪些操作慢？
4. 它对迭代器和元素有什么限制？
5. 哪些场景不应该使用它？

---

## 阶段一：补齐 STL 所需的 C++ 前置知识

### 学习目标

能够读懂 STL 的模板类型、函数参数、比较器和 Lambda 写法，为后续理解容器与算法扫清障碍。

### 核心知识点

1. **函数模板与类模板**
   - `template <typename T>` 的含义。
   - 模板参数与普通函数参数的区别。
   - `vector<int>`、`map<string, int>` 为什么是不同的具体类型。
   - 模板实例化的基本概念。

2. **引用与 `const`**
   - 区分 `T`、`T&`、`const T&` 和 `T&&`。
   - 理解为什么遍历大对象时常写 `const auto& value`。
   - 知道什么时候需要修改元素，什么时候应该保持只读。

3. **类型推导**
   - `auto` 的基本使用。
   - `decltype` 的基本含义。
   - 避免手写冗长的迭代器类型。

4. **对象语义**
   - 拷贝构造、拷贝赋值的基本概念。
   - 移动构造和移动赋值解决什么问题。
   - 容器保存的是对象本身时，插入和扩容可能发生拷贝或移动。

5. **运算符重载**
   - 理解 `operator<` 和 `operator==`。
   - 知道自定义类型排序、查找和去重为什么需要比较规则。

6. **Lambda 表达式**
   - 基本形式：`[capture](parameters) -> return_type { body }`。
   - 值捕获 `[=]`、引用捕获 `[&]` 和指定捕获 `[limit]`。
   - Lambda 在 `sort`、`find_if`、`count_if` 中的作用。

7. **复杂度基础**
   - 能理解 `O(1)`、`O(log n)`、`O(n)` 和 `O(n log n)`。
   - 知道复杂度描述的是规模增长趋势，不是精确运行时间。

### 最小示例

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{5, 2, 8, 1};
    int limit = 3;

    auto it = std::find_if(values.begin(), values.end(),
                           [limit](int value) { return value > limit; });

    if (it != values.end()) {
        std::cout << *it << '\n';
    }
}
```

### 练习任务

- 编写一个函数模板，返回两个值中的较大者。
- 定义 `Student` 结构体，并重载 `operator==`。
- 使用 Lambda 判断整数是否为偶数。
- 分别用值传递、引用传递和常量引用传递接收一个 `string`，解释差异。

### 常见错误

- 对大对象不必要地按值复制。
- 使用 `auto` 后忽略引用，导致修改的是副本。
- Lambda 需要修改外部变量时却使用值捕获。
- 比较器使用 `<=`，破坏严格弱序要求。

### 阶段验收标准

- 能读懂 `std::vector<std::pair<std::string, int>>`。
- 能解释 `const auto&` 的用途。
- 能写出带捕获的 Lambda。
- 能用大 O 表示法比较线性查找和二分查找。

---

## 阶段二：建立 STL 整体认识

### 学习目标

理解 STL 不是零散 API 的集合，而是一套用迭代器连接数据结构与通用算法的设计体系。

### STL 的主要组成

1. **容器（Containers）**：保存和组织数据，例如 `vector`、`list`、`map`。
2. **迭代器（Iterators）**：统一访问容器中的元素，类似受约束的指针。
3. **算法（Algorithms）**：通过迭代器处理数据，例如 `sort`、`find`、`count`。
4. **函数对象（Function Objects）**：向算法提供行为，例如 `less`、`greater` 和 Lambda。
5. **容器适配器（Container Adaptors）**：限制底层容器接口，形成栈、队列和优先队列。
6. **分配器（Allocators）**：管理容器所需内存；入门阶段了解作用即可。

### 核心协作方式

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{3, 1, 4, 1, 5};

    std::sort(values.begin(), values.end());
    auto it = std::find(values.begin(), values.end(), 4);

    if (it != values.end()) {
        std::cout << "找到元素，下标为 "
                  << std::distance(values.begin(), it) << '\n';
    }
}
```

这段代码中：

- `vector` 负责保存数据。
- `begin()` 和 `end()` 构成左闭右开的范围 `[begin, end)`。
- `sort` 和 `find` 只依赖迭代器，不需要知道完整容器类型。
- `it == end()` 表示查找失败。

### 必须掌握的基本接口

- 范围：`begin()`、`end()`、`cbegin()`、`cend()`。
- 状态：`size()`、`empty()`。
- 常用算法入口：`sort`、`find`、`count`。
- 范围 `for`：`for (const auto& value : container)`。

### 练习任务

- 创建一个整数 `vector`，分别用下标、迭代器和范围 `for` 遍历。
- 对数据排序后查找目标值。
- 用 `count` 统计指定元素出现次数。
- 画出“容器—迭代器—算法—函数对象”的关系图并口头解释。

### 常见错误

- 解引用 `end()`。
- 查找失败后仍然使用 `*it`。
- 误以为所有算法都能直接接收容器对象。
- 忘记包含对应头文件，如 `<algorithm>`。

### 阶段验收标准

- 能解释 `[begin, end)` 为什么不包含 `end()`。
- 能完整写出 `vector + sort + find` 示例。
- 能说清容器和算法如何通过迭代器解耦。

---

## 阶段三：掌握 `string` 与顺序容器

### 学习目标

理解连续存储、分段连续存储和链式存储的差异，熟练掌握 `string` 与 `vector`，能够按场景选择其他顺序容器。

### 3.1 `std::string`：必须掌握

重点接口：

- 构造与赋值：构造函数、`assign`、`operator=`。
- 状态与访问：`size`、`empty`、`operator[]`、`at`、`front`、`back`。
- 修改：`append`、`insert`、`erase`、`replace`、`push_back`。
- 查找与截取：`find`、`rfind`、`substr`。
- 输入与转换：`getline`、`stoi`、`stol`、`stod`、`to_string`。

关键认识：

- `find` 失败返回 `std::string::npos`。
- `operator[]` 通常不检查越界，`at` 会进行边界检查。
- 使用 `getline` 前要处理前一次格式化输入遗留的换行符。

练习：实现邮箱格式的基础检查、单词切分、字符串替换和 CSV 行解析。

### 3.2 `std::array`：必须掌握基本使用

- 大小在编译期固定：`std::array<int, 5>`。
- 支持 `size`、`begin`、`end` 和标准算法。
- 与内置数组相比，类型信息更完整，传参更安全。
- 适合长度固定、需要栈上对象语义的数据。

常用 API：`fill`、`at`、`front`、`back`、`data`、`swap`。

### 3.3 `std::vector`：必须熟练

重点接口：

- 构造：默认构造、指定大小、指定初值、初始化列表。
- 插入删除：`push_back`、`emplace_back`、`pop_back`、`insert`、`erase`、`clear`。
- 元素访问：`operator[]`、`at`、`front`、`back`、`data`。
- 容量管理：`size`、`capacity`、`reserve`、`resize`、`shrink_to_fit`。

重点原理：

- `vector` 使用连续内存，随机访问通常为 `O(1)`。
- 尾部追加的均摊复杂度通常为 `O(1)`。
- 中间插入、删除需要移动后续元素，通常为 `O(n)`。
- `reserve` 改变容量但不改变元素个数；`resize` 改变元素个数。
- 扩容后，原有迭代器、指针和引用通常全部失效。

### 3.4 `std::deque`：理解并会选用

- 支持两端高效插入和删除。
- 支持随机访问，但存储通常不是单块连续内存。
- 不要把 `deque` 的元素地址当作连续数组使用。
- 适合双端操作频繁且仍需要下标访问的场景。

常用 API：`push_front`、`push_back`、`pop_front`、`pop_back`、`front`、`back`。

### 3.5 `std::list`：理解链式容器

- 双向链表，不支持下标和随机访问。
- 已知位置时插入、删除通常为 `O(1)`。
- 查找某个值仍然需要 `O(n)`，不能因为删除快就认为所有操作都快。
- 提供成员算法：`sort`、`merge`、`splice`、`remove`、`unique`。

### 3.6 `std::forward_list`：了解即可

- 单向链表，只能向前遍历。
- 没有普通的 `size()` 使用体验，操作常围绕 `before_begin`、`insert_after` 和 `erase_after`。
- 适合内存要求严格且只需单向链式操作的特殊场景。

### 容器对比

| 容器 | 存储特点 | 随机访问 | 两端操作 | 中间插删 | 典型用途 |
|---|---|---:|---:|---:|---|
| `array` | 固定连续 | 快 | 大小固定 | 大小固定 | 固定长度数据 |
| `vector` | 动态连续 | 快 | 尾部快 | 通常较慢 | 默认首选顺序容器 |
| `deque` | 分段连续 | 快 | 两端快 | 通常较慢 | 双端队列 |
| `list` | 双向链式 | 不支持 | 快 | 已知位置时快 | 稳定迭代器、节点操作 |
| `forward_list` | 单向链式 | 不支持 | 前端快 | 已知前驱时快 | 低开销单向链表 |

### 练习任务

- 用 `vector` 保存学生成绩，完成增删改查、排序和统计。
- 用 `deque` 模拟两端都能加入人员的候车队列。
- 用 `list` 实现任务节点的移动和合并。
- 比较 `reserve` 前后多次追加元素时容量变化。
- 安全删除 `vector` 中的全部负数。

### 常见错误

- 对空容器调用 `front`、`back` 或 `pop_back`。
- 混淆 `reserve` 与 `resize`。
- 保存 `vector` 元素地址后继续追加，导致悬空指针。
- 对 `list` 使用 `std::sort`；应使用 `list::sort`。
- 认为链表查找也能达到常数复杂度。

### 阶段验收标准

- 能独立完成基于 `vector` 的成绩管理程序。
- 能解释 `size` 和 `capacity` 的区别。
- 能根据连续性、随机访问和插删位置选择顺序容器。
- 能说明至少三种常见的 `vector` 迭代器失效场景。

---

## 阶段四：掌握有序关联容器

### 学习目标

理解键、值、自动排序和唯一性，能够使用树结构容器完成有序查找、去重和映射。

### 核心容器

1. **`set<Key>`**
   - 元素即键，自动有序且不重复。
   - 适合有序去重、区间查询和成员判断。

2. **`multiset<Key>`**
   - 自动有序，允许等价键重复。
   - 适合需要保存重复值的有序数据。

3. **`map<Key, Value>`**
   - 保存键值对，键有序且唯一。
   - 元素类型近似 `pair<const Key, Value>`，键不能直接修改。

4. **`multimap<Key, Value>`**
   - 允许一个键对应多个值。
   - 适合一个分类下保留多条有序记录。

### 必须掌握的 API

- 插入：`insert`、`emplace`、`try_emplace`（C++17）。
- 查找：`find`、`count`、`contains`（C++20，进阶了解）。
- 删除：`erase`、`clear`。
- 边界：`lower_bound`、`upper_bound`、`equal_range`。
- `map` 访问：`operator[]`、`at`。

### 关键规则

- 常见实现基于平衡搜索树，查找、插入、删除通常为 `O(log n)`。
- `map[key]` 在键不存在时会插入一个默认值；只查询时优先使用 `find` 或 `at`。
- `set` 中的键和 `map` 中的键不能直接修改，因为修改可能破坏排序。
- `lower_bound(key)` 返回第一个“不小于 key”的位置。
- `upper_bound(key)` 返回第一个“大于 key”的位置。
- 插入通常不会使已有迭代器失效；删除只会使指向被删除元素的迭代器失效。

### 示例：统计并有序输出

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> frequency;
    for (const std::string& word : {"stl", "map", "stl"}) {
        ++frequency[word];
    }

    for (const auto& [word, count] : frequency) {
        std::cout << word << ": " << count << '\n';
    }
}
```

### 练习任务

- 使用 `set` 对整数去重并升序输出。
- 使用 `map` 实现姓名到成绩的映射。
- 使用 `multiset` 维护可重复分数并查询分数区间。
- 使用 `equal_range` 找出 `multimap` 中某个键对应的全部值。
- 为 `Student` 编写比较器，先按成绩降序，再按学号升序。

### 常见错误

- 只想判断键是否存在，却使用 `map[key]` 创建了新元素。
- 试图直接修改 `set` 元素或 `map` 的键。
- 自定义比较器使用 `<=` 或 `>=`。
- 把“比较结果等价”误解为对象所有字段完全相等。

### 阶段验收标准

- 能解释 `set`、`multiset`、`map` 和 `multimap` 的区别。
- 能正确使用 `find`、`lower_bound` 和 `equal_range`。
- 能为自定义类型提供稳定且无矛盾的排序规则。

---

## 阶段五：掌握无序关联容器

### 学习目标

理解哈希表的基本工作方式，能够在不要求有序时进行快速查找、去重和频率统计。

### 核心容器

- `unordered_set<Key>`：键唯一、无序。
- `unordered_multiset<Key>`：键可重复、无序。
- `unordered_map<Key, Value>`：键值映射、键唯一、无序。
- `unordered_multimap<Key, Value>`：键可重复、无序。

### 核心知识点

- 哈希函数把键映射到桶。
- 不同键可能进入同一个桶，这称为哈希冲突。
- 平均查找、插入、删除复杂度通常为 `O(1)`，最坏情况可能退化为 `O(n)`。
- 扩桶（rehash）可能使迭代器失效。
- `load_factor` 表示当前装载因子，`max_load_factor` 控制扩桶阈值。
- 自定义键通常需要自定义哈希函数和相等判断。

### 常用 API

- `insert`、`emplace`、`find`、`count`、`erase`。
- `bucket_count`、`bucket_size`、`load_factor`。
- `reserve`、`rehash`。

### 有序容器与无序容器选型

选择 `map/set`：

- 需要按键有序遍历。
- 需要 `lower_bound`、`upper_bound` 等范围查询。
- 希望复杂度稳定在 `O(log n)`。

选择 `unordered_map/unordered_set`：

- 主要需求是快速查找、计数或判重。
- 不关心遍历顺序。
- 键具有可靠的哈希实现。

### 练习任务

- 使用 `unordered_map` 统计一段文本中的单词频率。
- 使用 `unordered_set` 判断数组中是否存在重复值。
- 实现“两数之和”，保存已经访问过的数字及其位置。
- 为二维坐标类型编写自定义哈希函数。
- 比较 `map` 与 `unordered_map` 的输出顺序和适用场景。

### 常见错误

- 依赖无序容器的遍历顺序。
- 认为平均 `O(1)` 等于任何情况下都为常数时间。
- 自定义哈希与相等判断不一致：相等对象必须得到相同哈希值。
- 扩桶后继续使用旧迭代器。

### 阶段验收标准

- 能解释哈希、桶、冲突和装载因子。
- 能完成单词频率统计和快速判重。
- 能根据是否需要有序和范围查询选择树容器或哈希容器。

---

## 阶段六：掌握容器适配器

### 学习目标

理解受限接口如何表达特定数据结构，能够用栈、队列和优先队列解决典型问题。

### 6.1 `stack`：后进先出

常用 API：`push`、`emplace`、`pop`、`top`、`empty`、`size`。

典型场景：

- 括号匹配。
- 表达式求值。
- 撤销操作。
- 深度优先搜索的迭代写法。
- 单调栈问题。

### 6.2 `queue`：先进先出

常用 API：`push`、`emplace`、`pop`、`front`、`back`、`empty`、`size`。

典型场景：

- 排队模拟。
- 广度优先搜索（BFS）。
- 消息和任务按到达顺序处理。

### 6.3 `priority_queue`：动态维护最高优先级

常用 API：`push`、`emplace`、`pop`、`top`、`empty`、`size`。

```cpp
#include <functional>
#include <queue>
#include <vector>

std::priority_queue<int> max_heap;
std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
```

典型场景：

- Top K。
- 动态取得最大值或最小值。
- 任务优先级调度。
- Dijkstra 最短路。
- 合并多组有序数据。

### 关键规则

- `pop()` 不返回被删除的元素，应先读取 `top()` 或 `front()`。
- 调用 `top`、`front`、`back` 或 `pop` 前先检查 `empty()`。
- `priority_queue` 默认让最大元素位于顶部。
- `priority_queue` 的比较器含义容易与 `sort` 混淆，应通过小样例验证顶部元素。

### 练习任务

- 使用 `stack` 判断括号序列是否合法。
- 使用 `queue` 完成网格最短步数 BFS。
- 使用小根堆寻找第 K 大元素。
- 为任务结构体定义优先级：优先级高者先出，相同则截止编号小者先出。

### 阶段验收标准

- 能独立判断 LIFO、FIFO 和优先级访问场景。
- 能写出大根堆、小根堆和自定义类型优先队列。
- 能解释为什么适配器不提供任意位置遍历接口。

---

## 阶段七：深入迭代器与范围

### 学习目标

理解不同算法对迭代器能力的要求，并能安全遍历、修改和删除容器元素。

### 迭代器类别

1. **输入迭代器**：从序列读取一次。
2. **输出迭代器**：向序列写入一次。
3. **前向迭代器**：可多次向前遍历。
4. **双向迭代器**：可执行 `++` 和 `--`。
5. **随机访问迭代器**：支持 `it + n`、差值和下标式访问。
6. **连续迭代器**（C++20）：元素在内存中连续排列。

### 容器与迭代器能力

| 容器 | 典型迭代器能力 |
|---|---|
| `array`、`vector`、`deque` | 随机访问 |
| `list`、`map`、`set` | 双向 |
| `forward_list`、无序关联容器 | 前向 |

### 必须掌握的工具

- `begin`、`end`、`cbegin`、`cend`。
- `rbegin`、`rend`、`crbegin`、`crend`。
- `std::advance`：移动迭代器。
- `std::distance`：计算两个迭代器之间的距离。
- `std::next`、`std::prev`：返回移动后的新迭代器。
- 插入迭代器：`back_inserter`、`front_inserter`、`inserter`。

### 迭代器失效规则

1. **`vector`**
   - 扩容：全部迭代器、引用和指针失效。
   - 未扩容的尾部插入：`end()` 失效。
   - 中间插入或删除：操作位置及其后的迭代器通常失效。

2. **`deque`**
   - 插入和删除的失效规则较复杂，不要长期保存迭代器。
   - 具体场景应查对应标准版本资料。

3. **`list`、`forward_list`**
   - 插入通常不影响已有迭代器。
   - 删除只使指向被删除元素的迭代器失效。

4. **`map`、`set`**
   - 插入通常不影响已有迭代器。
   - 删除只使指向被删除元素的迭代器失效。

5. **无序关联容器**
   - 扩桶会使迭代器失效。
   - 指向元素的引用和指针通常在扩桶后仍可用，但删除元素后失效。

### 安全删除示例

```cpp
for (auto it = values.begin(); it != values.end();) {
    if (*it < 0) {
        it = values.erase(it);
    } else {
        ++it;
    }
}
```

### 练习任务

- 分别用迭代器遍历 `vector`、`list`、`map`。
- 使用反向迭代器输出序列。
- 使用 `distance` 求查找结果的逻辑位置。
- 安全删除 `map` 中值不合格的记录。
- 设计实验观察 `vector` 扩容前后的地址变化。

### 常见错误

- 对 `list`、`map` 或 `set` 使用 `it + n`。
- 删除元素后继续递增已经失效的迭代器。
- 缓存 `end()` 后修改容器，仍使用旧的结束迭代器。
- 把 `const_iterator` 误解为“迭代器本身不能移动”。

### 阶段验收标准

- 能根据算法要求判断某个容器能否直接使用该算法。
- 能写出遍历时安全删除元素的代码。
- 能解释 `iterator`、`const_iterator` 和反向迭代器的区别。

---

## 阶段八：系统掌握标准算法

### 学习目标

用标准算法表达“做什么”，减少重复手写循环，并牢记算法的范围要求、复杂度和副作用。

### 8.1 遍历与判断

- `for_each`：对范围内每个元素执行操作。
- `all_of`：全部满足条件。
- `any_of`：至少一个满足条件。
- `none_of`：全部不满足条件。

### 8.2 查找与计数

- `find`、`find_if`、`find_if_not`。
- `count`、`count_if`。
- `search`、`find_end`、`adjacent_find`（理解用途）。

### 8.3 排序与选择

- `sort`：常规排序，要求随机访问迭代器。
- `stable_sort`：保持等价元素原有相对顺序。
- `partial_sort`：只保证前一部分有序。
- `nth_element`：把第 n 个位置放到排序后应在的位置。
- `is_sorted`、`is_sorted_until`：检查有序性。

### 8.4 二分相关算法

- `binary_search`：判断值是否存在。
- `lower_bound`：第一个不小于目标的位置。
- `upper_bound`：第一个大于目标的位置。
- `equal_range`：同时得到相等区间的左右边界。

使用这些算法前，范围必须按照相同的比较规则有序。

### 8.5 复制、变换和填充

- `copy`、`copy_if`、`copy_n`。
- `transform`。
- `fill`、`fill_n`。
- `generate`。

向另一个容器复制时，要么提前分配足够空间，要么使用 `back_inserter` 等插入迭代器。

### 8.6 删除、替换和去重

- `remove`、`remove_if`。
- `replace`、`replace_if`。
- `unique`。
- `reverse`、`rotate`。

`remove` 和 `unique` 不会改变容器大小，而是把保留元素移动到前方并返回新的逻辑结尾。

```cpp
values.erase(std::remove(values.begin(), values.end(), target),
             values.end());
```

这是经典的 **erase-remove 惯用法**。C++20 可了解 `std::erase` 和 `std::erase_if`。

### 8.7 集合算法

- `set_union`。
- `set_intersection`。
- `set_difference`。
- `set_symmetric_difference`。
- `includes`。

集合算法要求输入范围有序，并且输出范围必须具有足够空间或使用插入迭代器。

### 8.8 数值算法

需要包含 `<numeric>`：

- `accumulate`：累加或折叠。
- `inner_product`：内积或双序列折叠。
- `partial_sum`：前缀和。
- `adjacent_difference`：相邻差分。
- `iota`：生成连续值。

注意 `accumulate` 的初始值类型会影响整个计算类型，例如使用 `0.0` 保留浮点结果。

### 算法学习模板

学习每个算法时记录：

1. 所在头文件。
2. 输入范围和返回值。
3. 所需迭代器类别。
4. 是否要求有序。
5. 是否修改元素。
6. 是否改变容器大小。
7. 时间复杂度。

### 练习任务

- 对整数序列排序并去重。
- 查找第一个高于平均分的学生。
- 统计及格人数并判断是否全部提交作业。
- 删除全部负数并替换异常值。
- 求两个有序序列的交集与并集。
- 使用 `nth_element` 求中位数或第 K 小元素。
- 使用 `partial_sum` 构造前缀和。

### 常见错误

- 对无序范围调用 `lower_bound`。
- 以为 `remove` 会真正缩短容器。
- 对 `list` 调用需要随机访问迭代器的 `sort`。
- 输出容器没有空间却直接把 `begin()` 作为复制目标。
- 输入序列和算法使用了不同的比较规则。

### 阶段验收标准

- 能优先考虑标准算法，而不是立即手写循环。
- 能正确写出排序去重和 erase-remove。
- 能说明 `sort`、`stable_sort`、`partial_sort`、`nth_element` 的区别。
- 能正确使用二分算法和数值算法。

---

## 阶段九：函数对象、Lambda 与自定义类型

### 学习目标

让标准算法和容器处理自定义业务对象，并确保比较和相等关系正确。

### 核心内容

1. **标准函数对象**
   - `std::less`、`std::greater`、`std::equal_to`。
   - 算术函数对象和逻辑函数对象了解用途即可。

2. **Lambda 深入**
   - 指定值捕获和引用捕获。
   - `mutable` Lambda。
   - 泛型 Lambda：参数使用 `auto`。
   - Lambda 作为算法参数和比较器。

3. **自定义比较器**
   - 函数、函数对象和 Lambda 三种写法。
   - 为 `sort`、`set`、`map`、`priority_queue` 提供比较规则。

4. **严格弱序**
   - `comp(a, a)` 必须为 `false`。
   - 若 `comp(a, b)` 为 `true`，则 `comp(b, a)` 必须为 `false`。
   - 比较关系必须具有传递性。
   - 等价元素的两个比较方向都应为 `false`。

### 示例：多条件排序

```cpp
struct Student {
    std::string id;
    std::string name;
    int score;
};

std::sort(students.begin(), students.end(),
          [](const Student& left, const Student& right) {
              if (left.score != right.score) {
                  return left.score > right.score;
              }
              return left.id < right.id;
          });
```

### 练习任务

- 学生按成绩降序、学号升序排列。
- 使用 `find_if` 查找第一个满足多个条件的对象。
- 使用 `count_if` 统计高于动态阈值的对象。
- 为 `set<Student>` 编写函数对象比较器。
- 为 `priority_queue<Task>` 编写任务优先级比较器。

### 常见错误

- 比较器返回 `left.score >= right.score`。
- Lambda 引用捕获的对象已经离开生命周期。
- `sort` 的比较器修改参与比较的对象。
- 混淆 `priority_queue` 比较器和最终顶部元素之间的关系。

### 阶段验收标准

- 能写出至少两级排序规则。
- 能解释严格弱序，并发现 `<=` 比较器的问题。
- 能让自定义结构体用于排序、有序容器和优先队列。

---

## 阶段十：容器选型、复杂度与性能意识

### 学习目标

从问题特征出发选择数据结构，并能解释选择依据和代价。

### 快速选型表

| 需求 | 优先考虑 | 关键理由 |
|---|---|---|
| 动态数组、随机访问 | `vector` | 连续存储、缓存友好、通用性强 |
| 固定长度数组 | `array` | 大小固定、支持 STL 接口 |
| 两端频繁操作 | `deque` | 头尾插删高效 |
| 已知位置的节点移动 | `list` | 节点操作、迭代器较稳定 |
| 自动排序并去重 | `set` | 有序唯一键 |
| 有序键值映射 | `map` | 有序键、范围查询 |
| 快速判重 | `unordered_set` | 平均常数查找 |
| 频率统计 | `unordered_map` | 键值计数、平均常数查找 |
| 后进先出 | `stack` | 受限栈接口 |
| 先进先出或 BFS | `queue` | 受限队列接口 |
| 动态最大值、最小值或 Top K | `priority_queue` | 堆顶访问高效 |

### 选型决策路径

1. 数据量是否固定？固定可考虑 `array`，否则继续。
2. 是否只需要尾部增长和随机访问？优先 `vector`。
3. 是否需要按键快速查找？继续判断是否要求有序。
4. 要求有序或区间查询：选择 `map/set`。
5. 不要求顺序、重视平均查找速度：选择无序关联容器。
6. 是否只允许特定访问顺序？考虑栈、队列或优先队列。
7. 是否真的需要链表？只有节点稳定性和拼接收益明确时再选 `list`。

### 性能意识

- 大 O 相同并不代表实际速度相同；连续内存通常具有更好的缓存局部性。
- `vector` 往往是顺序容器的默认选择。
- 提前知道大致元素数量时，可用 `reserve` 减少扩容。
- 插入对象时理解 `push_back` 与 `emplace_back` 的语义，不要机械替换。
- 传递大对象时优先考虑 `const&`，需要取得所有权时再考虑移动。
- 优化前先保证正确，并通过测量确认瓶颈。

### 练习任务

- 为通讯录、排行榜、单词统计、BFS 和 Top K 分别选择容器并解释理由。
- 对同一问题分别使用 `map` 与 `unordered_map`，比较输出特征。
- 估算在 `vector` 中间插入与在尾部追加的复杂度。
- 找出一个不适合使用 `list` 的场景并解释原因。

### 常见错误

- 只凭“理论复杂度更低”选择容器，忽略顺序、内存和数据规模。
- 所有场景都使用 `vector`，或为了显示高级而滥用 `list`。
- 需要范围查询却选择 `unordered_map`。
- 未测量就进行复杂的微优化。

### 阶段验收标准

- 面对新问题时能给出容器选择、复杂度和替代方案。
- 能解释为什么 `vector` 经常比链表更快。
- 能识别是否需要有序、唯一、随机访问或优先级访问。

---

## 阶段十一：现代 C++ 与 STL 补充

### 学习目标

使用现代语法减少样板代码，了解标准库中常见的工具类型，并为进一步学习范围库做好准备。

### 必须掌握或理解

1. **范围 `for`**

```cpp
for (const auto& [name, score] : scores) {
    // 只读访问
}
```

2. **结构化绑定（C++17）**
   - 拆解 `pair`、`tuple` 和 `map` 元素。
   - 注意使用 `auto`、`auto&`、`const auto&` 时是否复制。

3. **原位构造**
   - `emplace`、`emplace_back`、`try_emplace`。
   - 理解它们的语义和适用场景，不把它们当作无条件更快的替代品。

4. **工具类型**
   - `pair`：两个相关值。
   - `tuple`：固定数量、不同类型的值。
   - `optional`（C++17）：可能不存在的返回值。
   - `variant`（C++17）：有限种类型中的一种。

5. **范围库（C++20，进阶拓展）**
   - `std::ranges` 算法可以直接接收范围。
   - Views 支持惰性过滤、变换和组合。
   - 先熟练传统迭代器算法，再进入范围库。

### 练习任务

- 用结构化绑定遍历 `map`。
- 使用 `optional<Student>` 表示可能查不到学生。
- 使用 `variant<int, string>` 表示两种输入结果。
- 把一个传统算法示例改写为 C++20 ranges 版本并比较可读性。

### 常见错误

- 结构化绑定默认复制，修改后原容器没有变化。
- 对 `optional` 未检查就调用 `value()`。
- 为简单问题过度使用 `tuple`，导致字段含义不清。
- 尚未掌握迭代器和算法就直接依赖复杂 ranges 管道。

### 阶段验收标准

- 能使用结构化绑定和 `optional` 写出清晰代码。
- 能解释 `push_back` 与 `emplace_back` 的语义差异。
- 知道传统 STL 算法和 ranges 的关系。

---

## 阶段十二：综合训练与项目路线

### 学习目标

把容器、迭代器、算法和比较器组合成完整程序，形成从需求分析到数据结构选择的能力。

### 基础练习方向

1. 整数排序、去重和频率统计。
2. 字符串查找、替换和单词切分。
3. 学生成绩的最高分、最低分、平均分和排名。
4. 括号匹配与简单表达式检查。
5. 队列模拟和网格 BFS。
6. 两个有序序列的合并、交集和差集。
7. 第 K 大元素和 Top K 高频元素。
8. 按多个字段排序结构体。

### 进阶练习方向

1. 两数之和与最长连续序列：练习哈希容器。
2. 滑动窗口最大值：练习 `deque`。
3. 下一个更大元素：练习单调栈。
4. 区间合并：练习排序与 `vector`。
5. 单词词典和前缀统计：比较树容器、哈希容器与其他结构。
6. Dijkstra 最短路：练习 `priority_queue` 和邻接表。
7. 多路归并：练习小根堆。

### 综合项目一：学生成绩管理系统

建议功能：

- 添加、删除、修改和查询学生。
- 按学号快速查询。
- 按成绩与学号进行多条件排序。
- 计算平均分、中位数、最高分和最低分。
- 统计各分数段人数。
- 导入和导出简单文本数据。

建议组件：

- `vector<Student>` 保存用于排序和展示的记录。
- `unordered_map<string, size_t>` 建立学号索引。
- `sort`、`find_if`、`accumulate`、`count_if` 完成处理。

验收重点：数据修改后索引是否同步，排序后是否仍能正确查询。

### 综合项目二：文本单词频率分析器

建议功能：

- 读取多行文本。
- 统一大小写并清理标点。
- 统计单词频率。
- 按字典序输出。
- 按频率降序、单词升序输出。
- 输出 Top K 高频词。

建议组件：`string`、`unordered_map`、`vector<pair<string, int>>`、`sort`、`priority_queue`。

### 综合项目三：任务优先级调度器

建议功能：

- 添加任务名称、优先级和序号。
- 始终取得当前最优先任务。
- 相同优先级按加入顺序处理。
- 支持完成、取消和查询任务。
- 输出剩余任务摘要。

建议组件：`priority_queue`、自定义比较器、`unordered_set` 或惰性删除策略。

### 综合项目四：通讯录管理系统

建议功能：

- 添加、删除、修改和查找联系人。
- 检查姓名或电话号码是否重复。
- 按姓名有序输出。
- 支持关键字筛选。
- 保存和加载文本文件。

建议组件：`map`、`unordered_map`、`set`、`string` 和标准算法。

### 项目完成标准

- 在编码前写出数据结构选择及原因。
- 把数据模型、业务操作和输入输出拆分为独立函数或类。
- 对空数据、重复数据、查找失败和非法输入进行处理。
- 使用标准算法替代适合被替代的手写循环。
- 准备一组覆盖正常情况和边界情况的测试数据。
- 能解释主要操作的时间复杂度。

---

## 十三、STL 高频错误总清单

1. 对空容器调用 `front`、`back`、`top` 或 `pop`。
2. 解引用 `end()` 或查找失败返回的迭代器。
3. 使用 `map[key]` 进行只读查询，意外创建元素。
4. 忘记 `remove`、`remove_if` 和 `unique` 不会改变容器大小。
5. 在无序数据上使用 `binary_search` 或 `lower_bound`。
6. 对 `list` 使用要求随机访问迭代器的 `std::sort`。
7. 在 `vector` 扩容后继续使用旧迭代器、指针或引用。
8. 遍历时删除元素，却没有接收 `erase` 返回的新迭代器。
9. 修改 `set` 元素或 `map` 键，破坏容器内部顺序。
10. 自定义比较器使用 `<=` 或 `>=`，不满足严格弱序。
11. 依赖 `unordered_map` 或 `unordered_set` 的遍历顺序。
12. 使用算法复制元素时，没有为输出范围准备空间。
13. `accumulate` 使用错误类型的初始值，导致精度丢失。
14. 把 `reserve` 当作 `resize`，随后使用下标访问不存在的元素。
15. 范围 `for` 使用 `auto` 复制元素，修改未作用到容器。
16. 忘记为算法包含 `<algorithm>`，为数值算法包含 `<numeric>`。
17. 混淆 `priority_queue` 比较器与堆顶元素含义。
18. 只背 API，不理解复杂度、前置条件和迭代器能力。

---

## 十四、最终能力验收清单

完成路线后，逐项检查：

- [ ] 能解释 STL 的主要组成以及它们如何协作。
- [ ] 能写出 `vector`、`string`、`map`、`unordered_map` 和 `set` 的常用操作。
- [ ] 能根据场景选择 `vector`、`deque`、`list` 或 `array`。
- [ ] 能根据是否需要有序选择 `map` 或 `unordered_map`。
- [ ] 能使用 `stack`、`queue` 和 `priority_queue` 解决典型问题。
- [ ] 能解释各类迭代器的能力差异。
- [ ] 能列举主要容器的迭代器失效规则。
- [ ] 能正确使用 `sort`、`find_if`、`count_if` 和 `transform`。
- [ ] 能正确使用 `lower_bound`、`upper_bound` 和 `equal_range`。
- [ ] 能写出 erase-remove 惯用法并解释它为何需要两个步骤。
- [ ] 能使用 `accumulate`、`partial_sum` 等数值算法。
- [ ] 能为自定义类型编写多条件比较器。
- [ ] 能解释严格弱序，并避免使用 `<=` 作为排序比较器。
- [ ] 能分析常见容器操作的时间复杂度。
- [ ] 能完成至少一个综合项目，并解释其中的容器选型。

---

## 十五、建议建立的最小示例文件

每个文件只验证一个主题，方便编译、调试和复习：

```text
01_stl_overview.cpp
02_string_operations.cpp
03_vector_basics.cpp
04_vector_capacity.cpp
05_deque_and_list.cpp
06_set_and_map.cpp
07_unordered_containers.cpp
08_stack_queue.cpp
09_priority_queue.cpp
10_iterators.cpp
11_iterator_invalidation.cpp
12_find_count_algorithms.cpp
13_sort_binary_search.cpp
14_erase_remove.cpp
15_numeric_algorithms.cpp
16_lambda_comparator.cpp
17_custom_type_in_containers.cpp
18_container_selection.cpp
19_comprehensive_project.cpp
```

每个最小示例建议包含：

- 本例要验证的问题。
- 一组正常输入。
- 至少一个边界情况。
- 关键输出及预期结果。
- 对应操作的复杂度说明。

## 结语

学习 STL 的核心不是背诵所有成员函数，而是建立一条稳定的解题链路：

> 分析数据和操作特点 → 选择合适容器 → 使用迭代器描述范围 → 使用标准算法处理数据 → 检查复杂度、前置条件和失效规则。

当你能够解释“为什么选择这个容器和算法”，并能独立处理边界情况时，才算真正掌握了 STL。
