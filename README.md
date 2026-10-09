C-EASY-3 Step 1：顺序存储二叉树

一、什么是树和二叉树
树是一种非线性数据结构。二叉树是每个节点最多有两个子节点的树，分别叫左孩子和右孩子。
二叉树的特点：每个节点最多两个子节点，有左右之分，不能颠倒。

二、顺序存储
用数组来存二叉树。为了利用数学关系，我们从下标 1 开始存根节点，这样：
根节点下标为 i，左孩子下标为 2i，右孩子下标为 2i+1。
每个节点用一个结构体存，包含 data 和 used（标记这个位置有没有节点）。

三、函数实现
init_tree：初始化树。遍历数组把所有 used 置为 false，size 置为 0。
set_root：在 nodes[1] 处创建根节点。
set_left_child / set_right_child：传入父节点下标 parent_node，左孩子放在 2*parent_node，右孩子放在 2*parent_node+1。需要检查下标是否越界。
level_order：层序遍历。按下标顺序打印，used 为 false 打印 -1，每层末尾换行。

四、层序遍历的换行技巧
用一个变量 next_level 记录下一层的起始下标，初始为 2。
当 i == next_level - 1 时说明当前层结束，打印换行，然后 next_level 翻倍。

代码文件：binary_tree.c