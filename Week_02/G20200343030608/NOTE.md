1.字母异位词分组
   ① 对每个字符串排序,作为字典的键
   ② 满足这个键的字符append到这个键对应的value中
2.二叉树-前序遍历
   ① 对于二叉树中的任何一个节点而言，它都有两个角色需要扮演，一个是作为值存储的角色（A），另一个角色是作为它所带领的子树的一个代表（B）。
   ② 设置bool变量，当前节点，判断一个节点时存储的值(True == A)，还是子树的代表（False == B）。
   ③ A：将所存储的值打印出来，B：继续探索由它带领的子树。 