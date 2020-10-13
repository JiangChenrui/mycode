#ifndef MYALGORITHM_HPP
#define MYALGORITHM_HPP
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <sstream>
using namespace std;

/**
 * 计算整数的划分数
 */
int P(int n, int m) {
    if (m == 1) return 1;
    if (m > n) return P(n, n);
    if (m == n) return 1 + P(n, m - 1);
    return P(n, m - 1) + P(n - m, m);
}

/**
 * 递归的折半查找
 * @param arr[] 容器
 * @param n 元素个数
 * @param key 查找值
 * @return
 */
int bin_search(int arr[], int low, int high, int key) {
    int mid;
    if (low > high) return -1;
    mid = (low + high) / 2;
    if (arr[mid] == key) return 1;
    if (arr[mid] > key)
        return bin_search(arr, low, mid - 1, key);
    else
        return bin_search(arr, mid + 1, high, key);
}

// 四皇后问题
int count = 0;

/**
 * 判断当前点是否可行
 */
int isCorrect(int i, int j, int (*QueenArray)[4]) {
    int s, t;
    // 判断行
    for (s = i, t = 0; t < 4; ++t)
        if (QueenArray[s][t] == 1 && t != j) return 0;
    // 判断列
    for (s = 0, t = j; s < 4; ++s)
        if (QueenArray[s][t] == 1 && s != i) return 0;
    // 判断左上
    for (s = i - 1, t = j - 1; s >= 0 && t >= 0; s--, t--)
        if (QueenArray[s][t] == 1) return 0;
    // 判读右上
    for (s = i - 1, t = j + 1; s >= 0 && t < 4; s--, t++)
        if (QueenArray[s][t] == 1) return 0;
    // 判断左下
    for (s = i + 1, t = j - 1; s < 4 && t >= 0; s++, t--)
        if (QueenArray[s][t] == 1) return 0;
    // 判读右下
    for (s = i + 1, t = j + 1; s < 4 && t < 4; s++, t++)
        if (QueenArray[s][t] == 1) return 0;

    return 1;
}

/**
 * 回溯法解决4皇后问题
 * @param queenNum 当前皇后数量
 * @param QueenArray 皇后数组
 */
void Queen(int queenNum, int (*QueenArray)[4], int &count) {
    int i, k;
    // 四个皇后都确定
    if (queenNum == 4) {
        for (i = 0; i < 4; i++) {
            for (k = 0; k < 4; k++) cout << QueenArray[i][k] << ' ';
            cout << endl;
        }
        cout << endl;
        count++;
        return;
    }
    for (i = 0; i < 4; i++) {
        if (isCorrect(i, queenNum, QueenArray)) {
            QueenArray[i][queenNum] = 1;
            Queen(queenNum + 1, QueenArray, count);
            QueenArray[i][queenNum] = 0;
        }
    }
}

/**
 * 上台阶问题
 * @param n 台阶数
 * @return
 */
int UpStairs(int n) {
    if (n < 0) return -1;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return UpStairs(n - 1) + UpStairs(n - 2);
}

// 使用动态规划解决
int UpStairs2(int n) {
    if (n < 0) return -1;
    if (n == 1) return 1;
    if (n == 2) return 2;
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    if (n < 0) return -1;
    if (n < 3) return dp[n];
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

/**
 * 编辑距离
 */
int miniDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();
    // vector <vector <int>> dp[n1][n2];
    // 开辟空间
    int **dp = new int *[n1 + 1];
    for (int i = 0; i <= n1; ++i) dp[i] = new int[n2 + 1]();
    // 初始化
    for (int i = 0; i < n1; ++i) dp[i + 1][0] = dp[i][0] + 1;
    for (int i = 0; i < n2; ++i) dp[0][i + 1] = dp[0][i] + 1;

    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j)
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] =
                    min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
    }
    // 释放空间
    for (int i = 0; i < n1; ++i) delete[] dp[i];
    delete[] dp;

    return dp[n1][n2];
}

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 链表反转
 */
ListNode *ReverseList(ListNode *pHead) {
    if (pHead == NULL) 
        return NULL;
    ListNode *pre = NULL;
    ListNode *next = NULL;
    while (pHead != NULL) {
        next = pHead->next;
        pHead->next = pre;
        pre = pHead;
        pHead = next;
    }
    return pre;
}

// 递归
ListNode *ReverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode* node = ReverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
}

int Partition(vector<int> &arr, int start, int end) {
    // 降序排列
    if (start == end)
        return start;
    int left = start, right = end, key = arr[start];
    while (left < right) {
        while (left < right && arr[right] <= key)
            right--;
        arr[left] = arr[right];
        while (left < right && arr[left] >= key)
            left++;
        arr[right] = arr[left];
    }
    arr[left] = key;
    return left;
}

/**
 * 寻找第k大
 */
int findKth(vector<int> a, int n, int K) {
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high) {
        mid = Partition(a, low, high);
        if (K < mid + 1) {
            // 在左半段
            high = mid - 1;
        } else  if (K > mid + 1) {
            // 在右半段
            low = mid + 1;
        } else {
            return a[mid];
        }
    }
    return -1;
}

void testFindKth() {
    vector<int> arr = {19, 2, 3, 4, 9, 12};
    cout << findKth(arr, arr.size(), 3) << endl;
}

// 括号序列
bool isValid(string s) {
    // 如果字符串长度不是偶数，则不合法
    if (s.size() & 1 != 0)
        return false;
    stack<char> temp;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            temp.push(s[i]);
        else {
            if (temp.empty())
                return false;
            switch (s[i]) {
                case '}':
                    if (temp.top() == '{')
                        temp.pop();
                    break;
                case ']':
                    if (temp.top() == '[')
                        temp.pop();
                    break;
                case ')':
                    if (temp.top() == '(')
                        temp.pop();
                    break;
                default:
                    return false;
            }
        }
    }
    if (!temp.empty())
        return false;
    return true;
}

/**
 * 链表中的节点每k有一组翻转
 * @param head
 * @param k
 * @return
 */
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL)
        return NULL;
    ListNode *temp = head;
    int len = 0;
    while (temp != NULL) {
        temp = temp->next;
        ++len;
    }
    temp = head;
    if (len < k)
        return head;
    ListNode *pre = NULL;
    ListNode *next = NULL;
    for (int i = 0; i < k; ++i) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    temp->next = reverseKGroup(head, k);
    return pre;    
}

/**
 * 二分查找
 * @param n int整型 数组长度
 * @param v int整型 查找值
 * @param a int整型vector 有序数组
 * @return int整型
 */
int upper_bound_(int n, int v, vector<int>& a) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] >= v) {
            if (mid == 0 || a[mid-1] < v)
                return mid + 1;
            else
                right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return n + 1;
}


/**
 * 判断给定的链表是否有环
 * @param head
 * @return
 */
bool hasCycle(ListNode *head) {
    ListNode *low, *quick;
    low = quick = head;
    while (quick->next->next != NULL && quick->next != NULL) {
        low = low->next;
        quick = quick->next->next;
        if (low == quick)
            return true;
    }
    return false;
}

/**
 * 合并有序链表
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(-1);
    ListNode *temp = head;
    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            temp->next = l2;
            break;
        }
        if (l2 == NULL) {
            temp->next = l1;
            break;
        }
        if (l1->val < l2->val) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    return head->next;
}

/**
 * 链表中环的入口节点
 */
ListNode *detectCycle(ListNode *head) {
    if (head == NULL)
        return 0;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return NULL;
    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

/**
 * 删除链表倒数第N个节点
 * @param head ListNode类 
 * @param n int整型 
 * @return ListNode类
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL)
        return NULL;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;
    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return dummy->next;
}

/**
 * 两个链表相加生成相加链表
 */
ListNode* addInList(ListNode* head1, ListNode* head2) {
    stack<ListNode *> s1;
    stack<ListNode *> s2;
    while (head1) {
        s1.push(head1);
        head1 = head1->next;
    }
    while (head2) {
        s2.push(head2);
        head2 = head2->next;
    }
    int flag = 0;
    while (!s1.empty() || !s2.empty()) {
        int sum = flag;
        if (!s1.empty()) {
            sum += s1.top()->val;
            head1 = s1.top();
            s1.pop();
        }
        if (!s2.empty()) {
            sum += s2.top()->val;
            if (s2.size() > s1.size())
                head1 = s2.top();
            s2.pop();
        }
        if (sum < 10) {
            head1->val = sum;
            flag = 0;
        } else {
            head1->val = sum % 10;
            flag = sum / 10;
        }
    }
    if (flag > 0) {
        ListNode *head = new ListNode(flag);
        head->next = head1;
        return head;
    }
    return head1;
}

/**
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 */
int MyAdd (int num1, int num2) {
    while (num2 != 0) {
        int temp = num1 ^ num2;
        num2 = (num1 & num2) << 1;
        num1 = temp;
    }
    return num1;
}

// 将字符串转换为一个整数
int StrToInt(string str) {
    if (str.empty())
        return 0;
    int res = 0;
    int mark = (str[0] == '-') ? -1 : 1;
    int i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    for (; i < str.size(); ++i) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        res = res*10 + str[i] - '0';
    }
    return res*mark;
}

// 数组中重复的数字
bool duplicate(int numbers[], int length, int* duplication) {
    if (length == 0 || length == 1)
        return false;
    int *tempArr = new int[length]();
    for (int i = 0; i < length; ++i) {
        if (tempArr[numbers[i]] == 0)
            tempArr[numbers[i]] = 1;
        else {
            *duplication = numbers[i];
            return true;
        }
    }
    return false;
}

// 构建乘积数组
vector<int> multiply(const vector<int>& A) {
    vector<int> B(A.size(), 1);
    B[0] = 1;
    for (int i = 1; i < A.size(); ++i) {
        B[i] = B[i-1] * A[i-1];
    }
    int temp = 1;
    for (int j = A.size() - 1; j >= 0; j--) {
        B[j] *= temp;
        temp *= A[j];
    }
    return B;
}

// 正则表达式匹配
bool match(char* str, char* pattern) {
    if (*str == '\0' && *pattern == '\0')
        return true;
    if (*pattern == '\0')
        return false;
    if (*(pattern+1) != '*') {
        if (*str != '\0' && (*str == *pattern || *pattern == '.'))
            return match(str+1, pattern+1);
        else 
            return false;
    } else {
        bool ret = false;
        if (*str != '\0' && (*str == *pattern || *pattern == '.'))
            ret = match(str+1, pattern);
        return ret || match(str, pattern + 2);
    }
}

/**
 * 表示数值的字符串
 * 第二次出现加减号，必须紧跟在e之后
 * e之后不能有小数
 */
bool isNumeric(char *string) {
    // 标记符号、小数点、e是否出现过
    bool sign = false, decimal = false, hasE = false;
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == '+' || string[i] == '-') {
            if (!sign && i > 0 && string[i-1] != 'e' && string[i-1] != 'E')
                return false;
            if (sign && string[i-1] != 'e' && string[i-1] != 'E')
                return false;
            sign = true;
        } else if (string[i] == 'e' || string[i] == 'E') {
            if (i == strlen(string) - 1)
                return false;
            if (hasE)
                return false;
            hasE = true;
        } else if (string[i] == '.') {
            if (hasE || decimal)
                return false;
            decimal = true;
        } else if (string[i] < '0' || string[i] > '9')
            return false;
    }
    return true;
}

// 字符流中第一个不重复的字符
class Solution {
public:
    Solution() {
        memset(cnt, 0, sizeof(cnt)/sizeof(int));
    }
    ~Solution() {
        free(cnt);
    }
    void Insert(char ch) {
        ++cnt[ch - '\0'];
        if (cnt[ch - '\0'] == 1)
            data.push(ch);
    }
    char FirstAppearingOnce() {
        while (!data.empty() && cnt[data.front() - '\0'] > 1)
            data.pop();
        if (data.empty())
            return '#';
        return data.front();
    }
private:
    queue<char> data;
    unsigned cnt[128];
};

// 链表中环的入口结点
ListNode* EntryNodeOfLoop(ListNode* pHead) {
    ListNode *slow, *fast;
    slow = fast = pHead;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return NULL;
    fast = pHead;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

// 删除链表中重复的结点
ListNode* deleteDuplication(ListNode* pHead) {
    ListNode *slow, *fast;
    ListNode *Head = new ListNode(0);
    Head->next = pHead;
    slow = Head;
    fast = Head->next;
    while (fast != NULL) {
        if (fast->next != NULL && fast->val == fast->next->val) {
            while (fast->next != NULL && fast->val == fast->next->val)
                fast = fast->next;
            slow->next = fast->next;
            fast = fast->next;
        } else {
            slow = slow->next;
            fast = fast->next;
        }
    } 
    return Head->next;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

void inorder(TreeNode *node, vector<int> &res) {
    if (node == NULL)
        return;
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
}

// 二叉树中序遍历
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}

// 非递归方式中序遍历
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> node;
    while (root != NULL || !node.empty()) {
        for (; root != NULL; root = root->left) {
            node.push(root);
        }
        res.push_back(node.top()->val);
        root = node.top()->right;
        node.pop();
    }
    return res;
}

void preorder(TreeNode* node, vector<int> &res) {
    if (!node)
        return;
    res.push_back(node->val);
    preorder(node->left, res);
    preorder(node->right, res);
}
// 二叉树前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
}

// 使用迭代方式实现前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> node;
    while (root!=NULL || !node.empty()) {
        for (; root!=NULL; root = root->left) {
            res.push_back(root->val);
            node.push(root);
        }
        root = node.top()->right;
        node.pop();
    }
    return res;
}

void postorder(TreeNode* node, vector<int> &res) {
    if (!node)
        return;
    postorder(node->left, res);
    postorder(node->right, res);
    res.push_back(node->val);
}

// 二叉树后序遍历
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root, res);
    return res;
}
// 使用迭代方式实现后序遍历
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> node;
    TreeNode *cur = root;
    while (cur != NULL || !node.empty()) {
        while (cur) {
            res.push_back(cur->val);
            node.push(cur);
            cur = cur->right;
        }
        cur = node.top()->left;
        node.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

void levelOrder(TreeNode* root, int level, vector<vector<int>> &v) {
    if (root == NULL)
        return;
    if (v.size() < level + 1)
        v.resize(level + 1);
    v[level].push_back(root->val);
    levelOrder(root->left, level+1, v);
    levelOrder(root->right, level+1, v);
}
// 二叉树的层序遍历
vector<vector <int>> levelOrder(TreeNode* root) {
    vector<vector <int>> res;
    levelOrder(root, 0, res);
    return res;
}

// 迭代法
vector<vector <int>> levelOrder(TreeNode* root) {
    vector<vector <int>> res;
    if (root == NULL)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        res.push_back(vector<int>());
        for (int i = 0; i < size; ++i) {
            TreeNode* temp = q.front();
            q.pop();
            res[level].push_back(temp->val);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        ++level;
    }
    return res;
}

void zigzagLevel(TreeNode* node, int level, vector<vector <int>> &res) {
    if (node == NULL)
        return;
    if (res.size() < level + 1)
        res.push_back(vector<int>());
    if (level % 2 == 0)
        res[level].push_back(node->val);
    else
        res[level].insert(res[level].begin(), node->val);
    zigzagLevel(node->left, level+1, res);
    zigzagLevel(node->right, level+1, res);    
}
// 二叉树的锯齿形层次遍历
vector<vector <int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector <int>> res;
    zigzagLevel(root, 0, res);
    return res;
}

// 迭代法
vector<vector <int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector <int>> res;
    if (root == NULL)
        return res;
    queue<TreeNode*> q;
    int level = 0;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        res.push_back(vector<int>());
        for (int i = 0; i < size; ++i) {
            TreeNode* temp = q.front();
            q.pop();
            if (level % 2 == 0)
                res[level].push_back(temp->val);
            else
                res[level].insert(res[level].begin(), temp->val);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        ++level;
    }
    return res;
}

// 二叉树的最大深度
int maxDepth(TreeNode* root) {
    queue<TreeNode*> q;
    if (root == NULL)
        return 0;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        ++level;
    }
    return level;
}

int maxDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1+max(maxDepth(root->left), maxDepth(root->right));
}

// 二叉树的层次遍历2
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector <int>> res;
    if (root == NULL)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            temp.push_back(node->val);
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        res.push_back(temp);
    }
    reverse(res.begin(), res.end());
    return res;
}

// 二叉树的最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q)
        return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    if (left && right)
        return root;
    return NULL;
}

// 二叉搜索树的最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val > q->val)
        swap(p, q);
    while (root != NULL) {
        if (root->val < p->val)
            root = root->right;
        else if (root->val > q->val)
            root = root->left;
        else
            break;
    }
    return root;
}

int GetTreeDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + max(GetTreeDepth(root->left), GetTreeDepth(root->right));
}

// 平衡二叉树
bool isBalanced(TreeNode* root) {
    if (root == NULL)
        return true;
    if (abs(GetTreeDepth(root->left) - GetTreeDepth(root->right)) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

int recur(TreeNode* node) {
    if (node == NULL)
        return 0;
    int left = recur(node->left);
    if (left == -1)
        return -1;
    int right = recur(node->right);
    if (right == -1)
        return -1;
    return abs(left-right) < 2 ? max(left, right) + 1 : -1;
}
bool isBalanced(TreeNode* root) {
    if (root == NULL)
        return true;
    return recur(root) != -1;
}

// 验证二叉搜索树
bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stack;
    long long inorder = INT32_MIN - 1;
    while (root != NULL || !stack.empty()) {
        for (; root != NULL; root = root->left)
            stack.push(root);
        if (stack.top()->val <= inorder)
            return false;
        inorder = stack.top()->val;
        root = stack.top()->right;
        stack.pop();
    }
    return true;
}

// 二叉搜索树中的插入操作
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* node = root;
    if (root == NULL) {
        root = new TreeNode(val);
        return root;
    }
    while (node != NULL) {
        if (node->val > val) {
            if (node->left != NULL)
                node = node->left;
            else {
                node->left = new TreeNode(val);
                break;
            }
        } else if (node->val < val){
            if (node->right != NULL)
                node = node->right;
            else {
                node->right = new TreeNode(val);
                break;
            }
        }
        
    }
    return root;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);
    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}

/**
 * 二叉树的最大路径和
 * @param root
 * @param sum
 * @return ret 当前结点最大路径和
 */
int maxPathSum(TreeNode* root, int &sum) {
    if (root == NULL)
        return 0;
    // 左结点最大路径和
    int left = max(maxPathSum(root->left, sum), 0);
    // 右节点最大路径和
    int right = max(maxPathSum(root->right, sum), 0);
    // 左节点+右节点+当前节点的路径和
    int lmr = root->val + left + right;
    sum = max(sum, lmr);
    // 返回当前节点可以连接父节点的最大值
    return root->val + max(left, right);
}
int maxPathSum(TreeNode* root) {
    int val = INT8_MIN;
    maxPathSum(root, val);
    return val;
}

// 二叉树的右视图
vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> node;
    vector<int> res;
    if (root == NULL)
        return res;
    node.push(root);
    while (!node.empty()) {
        int size = node.size();
        TreeNode* temp;
        for (int i = 0; i < size; ++i) {
            temp = node.front();
            node.pop();
            if (temp->left != NULL)
                node.push(temp->left);
            if (temp->right != NULL)
                node.push(temp->right);
        }
        res.push_back(temp->val);
    }
    return res;
}

// 恢复二叉搜索树
void recoverTree(TreeNode* root) {
    if (root == NULL)
        return;
    stack<TreeNode*> node;
    vector<TreeNode*> num;
    vector<int> swap;
    TreeNode* head = root;
    while (head != NULL || !node.empty()) {
        for (; head != NULL; head = head->left)
            node.push(head);
        num.push_back(node.top());
        head = node.top()->right;
        node.pop();
    }
    for (int i = 0; i < num.size() - 1; ++i) {
        if (num[i]->val > num[i+1]->val)
            swap.push_back(i);
    }
    if (swap.size() == 1) {
        int temp = num[swap[0]]->val;
        num[swap[0]]->val = num[swap[0]+1]->val;
        num[swap[0]+1]->val = temp;     
    } else {
        int temp = num[swap[0]]->val;
        num[swap[0]]->val = num[swap[1]+1]->val;
        num[swap[1]+1]->val = temp;
    }
}

// 最长公共子序列
int longestCommonSubsequence(string text1, string text2) {
    if (text1.empty() || text2.empty())
        return 0;
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

// 最长回文子序列
int longestPalindromeSubseq(string s) {
    int len = s.size();
    vector<vector<int>> dp(len+1, vector<int>(len+1));
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (s[i] == s[len-1-j])
                dp[i+1][j+1] = 1 + dp[i][j];
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    return dp[len][len];
}

int minNumSquares(int n) {
    if (n == 0)
        return 0;
    int count = INT32_MAX;
    for (int i = 1; i * i <= n; ++i)
        count = min(count, minNumSquares(n - i * i) + 1);
    return count;
}

// 完全平方数
int numSquares(int n) {
    return minNumSquares(n);
}

int numSquares(int n) {
    vector<int> dp(n+1, n+1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j)
            dp[i] = min(dp[i], dp[i-j*j] + 1);
    }
    return dp[n];
}

// 两两交换链表中的节点
ListNode* swapPairs(ListNode* head) {
    ListNode* res = new ListNode(0);
    res->next = head;
    ListNode* first = res;
    while (first->next != NULL && first->next->next != NULL) {
        ListNode* second = first->next;
        ListNode* third = first->next->next;

        first->next = third;
        second->next = third->next;
        third->next = second;

        first = second;
    }
    return res->next;
}

// 杨辉三角
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; ++i) {
        res.push_back(vector<int> (i+1, 1));
    }
    for (int i = 2; i < numRows; ++i) {
        for (int j = 1; j < i; ++j)
            res[i][j] = res[i-1][j-1] + res[i-1][j];
    }
    return res;
}

// 杨辉三角2
vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex+1, 1);
    for (int i = 2; i < rowIndex+1; ++i) {
        for (int j = i - 1 ; j > 0; j--)
            res[j] = res[j-1] + res[j];
    }
    return res;
}

// 计算平方数
double quickMul(double x, long long N) {
    double ans = 1.0;
    while (N > 0) {
        if (N & 1 == 1)
            ans *= x;
        x *= x;
        N = N >> 1;
    }
    return ans;
}
double quickMul(double x, long long n) {
    if (n == 0)
        return 1.0;
    double half = quickMul(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}
double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
}

// 第k个语法符号
int kthGrammar(int N, int K) {
    if (N == 1)
        return 0;
    return kthGrammar(N - 1, (K + 1) / 2) == 0 ? (1 - (K % 2)) : (K % 2);
}

// 不同的二叉搜索树2
vector<TreeNode*> generateTrees(int start, int n) {
    vector<TreeNode*> ans;
    if (start > n) return {NULL};
    for (int i = start; i <= n; ++i) {
        for (auto left : generateTrees(start, i - 1)) {
            for (auto right : generateTrees(i+1, n)) {
                TreeNode* root = new TreeNode(i, left, right);
                ans.push_back(root);
            }
        }
    }
    return ans;
}
vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTrees(1, n);
}

// 礼物的最大价值
int maxValue(vector<vector<int>> &grid) {
    if (grid.empty())
        return 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
        }
    }
    return dp[m][n];
}

// 滑动窗口
// 最长不含重复字符的子字符串
int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) return 0;
    unordered_set<char> dp;
    int maxStr = 0;
    int left = 0;
    for (int i = 0; i < s.size(); ++i) {
        while (dp.find(s[i]) != dp.end()) {
            dp.erase(s[left]);
            left++;
        }
        maxStr = max(maxStr, i-left+1);
        dp.insert(s[i]);
    }
    return maxStr;
}

// 树的子结构
bool recur(TreeNode* A, TreeNode* B) {
    if (B == NULL)
        return true;
    if (A == NULL || A->val != B->val)
        return false;
    return recur(A->left, B->left) && recur(A->right, B->right);
}
bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == NULL || B == NULL)
        return false;
    bool root = recur(A, B);
    bool left = isSubStructure(A->left, B);
    bool right = isSubStructure(A->right, B);
    return root || left || right;
}

// 二叉树的镜像
TreeNode* mirrorTree(TreeNode* root) {
    if (root == NULL)
        return NULL;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;
}

// 迭代法
TreeNode* mirrorTree(TreeNode* root) {
    if (root == NULL)
        return NULL;
    stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        if (node->left != NULL) stack.push(node->left);
        if (node->right != NULL) stack.push(node->right);
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp; 
    }
    return root;
}

// 对称二叉树
bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;
    if (left->val != right->val)
        return false;
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}
bool isSymmetric(TreeNode* root) {
    if (root == NULL)
        return true;
    return isSymmetric(root->left, root->right);
}

// 二叉树中和为某一值的路径
void pathSum(TreeNode* root, vector<vector<int>>& res, vector<int>& temp, int sum) {
    if (root == NULL) {
        return;
    }
    temp.push_back(root->val);
    if (root->val == sum && root->left == NULL && root->right == NULL)
        res.push_back(temp);
    pathSum(root->left, res, temp, sum-root->val);
    pathSum(root->right, res, temp, sum-root->val);
    temp.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    vector<int> tmp;
    pathSum(root, res, tmp, sum);
    return res;
}

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// 二叉搜索树与双向链表
class treeToDouble {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node *pre, *head;
    void dfs(Node* cur) {
        if(cur == nullptr) return;
        dfs(cur->left);
        if(pre != nullptr) pre->right = cur;
        else head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};

// 字符串的排列
void dfs(string s, int start, set<string>& res) {
    if (s.size() == start) {
        res.insert(s);
        return;
    }
    for (int i = start; i < s.size(); ++i) {
        swap(s[i], s[start]);
        dfs(s, start+1, res);
        swap(s[i], s[start]);
    }
}
void dfs(string s, int start, vector<string>& res) {
    if (s.size() == start) {
        res.push_back(s);
        return;
    }
    set<char> st;
    for (int i = start; i < s.size(); ++i) {
        if (st.count(s[i])) continue;
        st.insert(s[i]);
        swap(s[i], s[start]);
        dfs(s, start+1, res);
        swap(s[i], s[start]);
    }
}
vector<string> permutation(string s) {
    vector<string> res;
    dfs(s, 0, res);
    return res;
}

// 二叉树第k大节点
int kthLargest(TreeNode* root, int k) {
    if (root == NULL)
        return 0;
    stack<TreeNode*> node;
    int num = 1;
    while (root != NULL || !node.empty()) {
        for (; root != NULL; root = root->right) {
            node.push(root);
        }
        root = node.top()->left;
        if (num == k)
            return node.top()->val;
        node.pop();
        num++;
    }
    return 0;
}

// 二叉搜索树的后序遍历序列
bool recur(vector<int> postorder, int start, int end) {
    if (start >= end) return true;
    int p = start;
    while (postorder[p] < postorder[end]) p++;
    int m = p;
    while (postorder[p] > postorder[end]) p++;
    return p==end && recur(postorder, start, m-1) && recur(postorder, m, end-1);
}
bool verifyPostorder(vector<int>& postorder) {
    return recur(postorder, 0, postorder.size()-1);
}

// 数据流中的中位数
class MedianFinder {
public:
    MedianFinder() {}
    void addNum(int num) {
        if (A.size() != B.size()) {
            A.push(num);
            B.push(A.top());
            A.pop();
        } else {
            B.push(num);
            A.push(B.top());
            B.pop();
        }
    }
    double findMedian() {
        return A.size() != B.size() ? A.top() : (A.top() + B.top()) / 2.0;
    }
private:
    priority_queue<int, vector<int>, greater<int>> A;
    priority_queue<int, vector<int>, less<int>> B;
};

// 左旋字符串
string reverseLeftWords(string s, int n) {
    // return s.substr(n, s.size()) + s.substr(0, n);
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());
    return s;
}

// 滑动窗口的最大值
int findMax(const vector<int> nums, int i, int j) {
    int maxval = nums[i];
    for (; i <= j; ++i) {
        maxval = max(maxval, nums[i]);
    }
    return maxval;
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    if (nums.size() == 0)
        return ans;
    int maxval = findMax(nums, 0, k-1);
    ans.push_back(maxval);
    for (int j = k, i = 1; j < nums.size(); ++j, ++i) {
        if (nums[j] > maxval)
            maxval = nums[j];
        else if (nums[i-1] == maxval)
            maxval = findMax(nums, i, j);
        ans.push_back(maxval);
    }
    return ans;
}

// 字符串转换为整数
int strToInt(string str) {
    int res = 0, bndry = INT32_MAX / 10;
    int i = 0, sign = 1, length = str.size();
    if (length == 0)
        return 0;
    while (str[i] == ' ')
        if (++i == length) return 0;
    if (str[i] == '-') sign = -1;
    if (str[i] == '-' || str[i] == '+') i++;
    for (int j = i; j < length; j++) {
        if (str[j] < '0' || str[j] > '9') break;
        if (res > bndry || res == bndry && str[j] > '7')
            return sign == 1 ? INT32_MAX : INT32_MIN;
        res = res * 10 + (str[j] - '0');
    }
    return sign*res;
}

// 股票的最大利润
int maxProfit(vector<int>& prices) {
    int cost = INT32_MAX, profit = 0;
    for (int price : prices) {
        cost = min(cost, price);
        profit = max(profit, price-cost);
    }
    return profit;
}

// 买卖股票的最佳时机二
int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i-1])
            profit += prices[i] - prices[i-1];
    }
    return profit;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = -prices[0];
    for (int i = 0; i < n; ++i) {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, temp-prices[i]);
    }
    return dp_i_0;
}

// 买卖股票的最佳时机三
int maxProfit(vector<int>& prices) {
    int days = prices.size();
    vector<vector<vector<int>>> dp(days, vector<vector<int>>(3, vector<int>(2)));
    for (int i = 0; i < days; ++i)
        for (int j = 0; j < 3; ++j) {
            if (i - 1 == -1) {
                dp[i][j][0] = 0;
                dp[i][j][1] = -prices[i];
                continue;
            }
            if (j == 0) {
                dp[i][j][0] = 0;
                dp[i][j][1] = max(dp[i-1][0][1], dp[i-1][0][0]-prices[i]);
                continue;
            }
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
        }
    return dp[days-1][2][0];
}

// 买卖股票的最佳时机四
int maxProfit(int k, vector<int>& prices) {
    int days = prices.size();
    if (k == 0)
        return 0;
    if (k > days/2)
        maxProfit(prices);
    vector<vector<vector<int>>> dp(days, vector<vector<int>>(k+1, vector<int>(2)));
    for (int i = 0; i < days; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (i - 1 == -1) {
                dp[i][j][0] = 0;
                dp[i][j][1] = -prices[i];
                continue;
            }
            if (j == 0) {
                dp[i][j][0] = 0;
                dp[i][j][1] = max(dp[i-1][0][1], dp[i-1][0][0] - prices[i]);
                continue;
            }
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
        }
    }
    return dp[days-1][k][0];
}

// 矩阵中的路径
bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
    if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || board[i][j] != word[k])
        return false;
    if (k == word.size() - 1) return true;
    char temp = board[i][j];
    board[i][j] = '\0';
    if (dfs(board, word, i+1, j, k+1) || dfs(board, word, i-1, j, k+1) ||
        dfs(board, word, i, j+1, k+1) || dfs(board, word, i, j-1, k+1) )
                    return true;
    board[i][j] = temp;
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j)
            if (dfs(board, word, i, j, 0)) 
                return true;
    }
    return false;
}

// 把数组排成最小的数
string minNumber(vector<int> &nums) {
    string res;
    vector<string> strs;
    for (auto a:nums) {
        strs.push_back(to_string(a));
    }
    sort(strs.begin(), strs.end(), [](string &x, string &y) {return x+y < y+x;});
    for (auto a:strs) {
        res += a;
    }
    return res;
}

// 扑克牌中的顺子
bool isStraight(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int flag = 0;
    for (int i = 0; i < nums.size()-1; ++i) {
        if (nums[i] == 0) {
            flag++;
            continue;
        }
        if (nums[i]+1 == nums[i+1])
            continue;
        else if (nums[i] == nums[i+1])
            return false;
        else {
            flag -= nums[i+1] - nums[i] - 1;
        }
        if (flag < 0)
            return false;
    }
    return true;
}
bool isStraight(vector<int> &nums) {
    unordered_set<int> repeat;
    int maxNum = 0, minNum = 14;
    for (int num:nums) {
        if (num == 0) continue;
        maxNum = max(maxNum, num);
        minNum = min(minNum, num);
        if (repeat.find(num) != repeat.end()) return false;
        repeat.insert(num);
    }
    return maxNum - minNum < 5;
}

// 数组中重复的数字
int findRepeatNumber(vector<int>& nums) {
    unordered_set<int> repeat;
    for (int num:nums) {
        if (repeat.find(num) != repeat.end()) return num;
        repeat.insert(num);
    }
    return -1;
}
int findRepeatNumber(vector<int> &nums) {
    unordered_map<int , bool> map;
    for (int num : nums) {
        if (map[num]) return num;
        map[num] = true;
    }
    return -1;
}

// 二维数组中的查找
bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    int i = matrix.size() - 1, j = 0;
    while (i >=0 && j < matrix[0].size()) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            i--;
        else
            j++;
    }
    return false;
}

// 旋转数组的最小数字
int minArray(vector<int> &numbers) {
    int end = numbers.size() - 1;
    int start = 0;
    while (start < end) {
        int mid = (end + start) / 2;
        if (numbers[mid] < numbers[end]) {
            end = mid;
        } else if (numbers[mid] > numbers[end]){
            start = mid + 1;
        } else {
            end--;
        }
    }
    return numbers[start];
}

// 第一个只出现一次的字符
char firstUniqChar(string s)  {
    unordered_map<char, bool> dic;
    for (char a : s)
        dic[a] = dic.find(a) == dic.end();
    for (char c : s)
        if (dic[c]) return c;
    return ' ';
}
char firstUniqChar(string s) {
    vector<char> keys;
    unordered_map<char, bool> dic;
    for (char c : s) {
        if (dic.find(c) == dic.end())
            keys.push_back(c);
        dic[c] = dic.find(c) == dic.end();
    }
    for (char c : keys) {
        if (dic[c]) return c;
    }
    return ' ';
}

// 在排序数组中查找数字
int search(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (nums[mid] <= target) i = mid + 1;
        else j = mid - 1;
    }
    int right = i;
    if (j >= 0 && nums[j] != target) return 0;
    i = 0, j = nums.size() - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (nums[mid] < target) i = mid + 1;
        else j = mid - 1;
    }
    int left = j;
    return right - left - 1;
}

// 0~n-1中缺失的数字
int missingNumber(vector<int> &nums) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (nums[mid] > mid) end = mid - 1;
        else start = mid + 1;
    }
    return start+1;
}

// 删除链表的节点
ListNode* deleteNode(ListNode* head, int val) {
    ListNode* res = new ListNode(-1);
    res->next = head;
    ListNode* node = res;
    while (head != NULL) {
        if (head->val == val) {
            node->next = head->next;
        }
        node = node->next;
        head = head->next;
    }
    return res->next;
}

// 调整数组顺序是奇数位于偶数前面
vector<int> exchange(vector<int> &nums) {
    int start = 0, end = nums.size() - 1;
    while (start < end) {
        while (nums[start] % 2 != 0) start++;
        while (nums[end] %2 == 0) end--;
        swap(nums[start], nums[end]);
    }
    return nums;
}

// 和为s的两个数字
vector<int> twoSum(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    vector<int> res;
    while (start < end) {
        if (nums[start] + nums[end] == target) {
            res.push_back(nums[start]);
            res.push_back(nums[end]);
            return res;
        } else if (nums[start] + nums[end] < target) start++;
        else end--;
    }
    return res;
}

/**
 * 字符串分割
 * @param str 原字符串
 * @param splitChar 分割字符
 * @return 分割后的字符串数组
 */
vector<string> split(const string &str, const string &splitChar) {
    vector<string> res;
    if (str == "")
        return res;
    string strs = str + splitChar;
    size_t pos = strs.find(splitChar);

    while (pos != strs.npos) {
        string temp = strs.substr(0, pos);
        if (temp != " " && temp != "")
            res.push_back(temp);
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(splitChar);
    }
    return res;
}
// 翻转单词顺序
string reverseWords(string s) {
    string res;
    const string splitChar = " ";
    vector<string> store = split(s, splitChar);
    if (store.size() == 0)
        return "";
    int len = store.size() - 1;
    res = store[len--];
    while(len >=0) {
        res += " " + store[len--];
    }
    return res;
}

string reverseWords(string s) {
    stack<string> stk;
    string res,str;
    istringstream ss(s);
    while (ss >> str) stk.push(str), stk.push(" ");
    if (!stk.empty()) stk.pop();
    while (!stk.empty()) res += stk.top(), stk.pop();
    return res;
}

// 二进制中1的个数
int hammingWeight(uint32_t n) {
    int res = 0;
    while (n > 0) {
        if (n & 1 == 1) res++;
        n >>= 1;
    }
    return res;
}

// 不用加减乘除做加法
int add(int a, int b) {
    while(b != 0)
    {
        int c = (unsigned int)(a & b) << 1;
        a ^= b;
        b = c;
    }
    return a;
}

// 剪绳子
int cuttingRope(int n) {
    if (n <= 3) return n-1;
    int res;
    switch(n%3) {
        case 0:
            res = pow(3, n / 3);
            break;
        case 1:
            res = pow(3, n / 3 - 1) * 4;
            break;
        case 2:
            res = pow(3, n / 3) * 2;
            break;
    }
    return res;
}

// 剪绳子2
int cuttingRope(int n) {
    if (n <= 3) return n-1;
    int b = n % 3, p = 1000000007;
    long rem = 1, x = 3;
    for (int a = n / 3 - 1; a > 0; a /= 2) {
        if (a % 2 == 1) rem = (rem * x) % p;
        x = (x * x) % p;
    }
    if (b == 0) return (int)(rem*3%p);
    if (b == 1) return (int)(rem*4%p);
    return (int)(rem*6%p);
}

// 1~n整数中1出现的次数
int countDigitOne(int n) {
    long digit = 1;
    int high = n / 10, cur = n % 10, low = 0, res = 0;
    while (high != 0 || cur != 0) {
        if (cur == 0) res += high * digit;
        else if (cur == 1) res += high * digit + low + 1;
        else res += (high + 1) * digit;
        low += cur * digit;
        cur = high % 10;
        high /= 10;
        digit *= 10;
    }
    return res;
}

// 数字序列中某一位的数字
int findNthDigit(int n) {
    if (n < 10) return n;
    int digit = 1;
    long start = 1;
    long count = 9;
    while (n > count) {
        n -= count;
        start *= 10;
        digit += 1;
        count = digit * start * 9;
    }
    long num = start + (n - 1) / digit;
    return to_string(num)[(n - 1) % digit] - '0';
}

// 构建乘积数组
vector<int> constructArr(vector<int>& a) {
    int len = a.size();
    if (len == 0) return {};
    vector<int> res(len, 1);
    int temp = 1;
    for (int i = 1; i < len; ++i) {
        res[i] = res[i-1] * a[i-1];
    }
    for (int i = len - 2; i >=0; i--) {
        temp *= a[i+1];
        res[i] *= temp;
    }
    return res;
}

// 顺时针打印矩阵
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    vector<int> res;
    int left = 0, right = matrix[0].size()-1, top = 0, down = matrix.size()-1;
    while (true) {
        for (int i = left; i <= right; ++i) {
            res.push_back(matrix[top][i]);
        }
        if (++top > down) break;
        for (int i = top; i <= down; ++i) {
            res.push_back(matrix[i][right]);
        }
        if (--right < left) break;
        for (int i = right; i >= left; --i) {
            res.push_back(matrix[down][i]);
        }
        if (--down < top) break;
        for (int i = down; i >= top; --i) {
            res.push_back(matrix[i][left]);
        }
        if (++left > right) break;
    }
    return res;
}

// 栈的压入、弹出序列
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;
    int i = 0;
    for (int num : pushed) {
        stk.push(num);
        while (!stk.empty() && stk.top() == popped[i]) {
            stk.pop();
            i++;
        }
    }
    return stk.empty();
}

// 二叉树的最小深度
int minDepth(TreeNode* root) {
    queue<TreeNode*> nodes;
    int depth = 1;
    if (root == NULL) return 0;
    nodes.push(root);
    while (!nodes.empty()) {
        int size = nodes.size();
        for (int i = 0; i < size; ++i) {
            if (nodes.front()->left == NULL && nodes.front()->right == NULL) return depth;
            if (nodes.front()->left != NULL) nodes.push(nodes.front()->left);
            if (nodes.front()->right != NULL) nodes.push(nodes.front()->right);
            nodes.pop();
        }
        depth++;
    }
    return depth;
}

// 打开转盘锁
string plusUp(string str, int i) {
    string s = str;
    if (s[i] == '9') s[i] = '0';
    else s[i] += 1;
    return s;
}
string plusDown(string str, int i) {
    string s = str;
    if (s[i] == '0') s[i] = '9';
    else s[i] -= 1;
    return s;
}

int openLock(vector<string>& deadends, string target) {
    queue<string> q;
    // 记录死亡密码
    unordered_set<string> deads;
    deads.insert(deadends.begin(), deadends.end());
    // 记录已经穷举过的密码
    unordered_set<string> visited;
    q.push("0000");
    visited.insert("0000");
    int step = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            string temp = q.front();
            q.pop();
            if (deads.find(temp) != deads.end()) continue;
            if (temp == target) return step;
            // 遍历相邻节点
            for (int j = 0; j < 4; ++j) {
                string up = plusUp(temp, j);
                if (visited.find(up) == visited.end()) {
                    q.push(up);
                    visited.insert(up);
                }
                string down = plusDown(temp, j);
                if (visited.find(down) == visited.end()) {
                    q.push(down);
                    visited.insert(down);
                }
            }
        }
        step++;
    }
    return -1;
}

// 在排序数组中查找元素的第一个和最后一个位置
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) right = mid - 1;
        else left = mid + 1;  
    }
    if (left >= nums.size() || nums[left] != target) res.push_back(-1);
    else res.push_back(left);

    right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid - 1;
    }
    if (right < 0 || nums[right] != target) res.push_back(-1);
    else res.push_back(right);
    return res;
}

vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> res = {-1, -1};
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            int temp = mid;
            while (temp >= left && nums[temp] == target)
                temp--;
            res[0] = temp + 1;
            temp = mid;
            while (temp <= right && nums[temp] == target)
                temp++;
            res[1] = temp - 1;
            break;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    return res;
}

// 最小子串覆盖
string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    // 记录最小覆盖子串的起始索引及长度
    int start = 0, len = INT32_MAX;
    while (right < s.size()) {
        char c = s[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        while (valid == need.size()) {
            if (right - left < len) {
                start = left;
                len = right - left;
            }
            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    return len == INT32_MAX ? "" : s.substr(start, len);
}

// 字符串的排列
bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;
    for (char a : s1) need[a]++;

    int left = 0, right = 0;
    int valid = 0;
    while (right < s2.size()) {
        char c = s2[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        while (right - left >= s1.size()) {
            if (valid == need.size()) return true;
            char d = s2[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return false;
}

// 找到字符串中所有字母异位词
vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need, window;
    for (char a : p) need[a]++;
    vector<int> res;
    
    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        while (right - left >= p.size()) {
            if (valid == need.size()) res.push_back(left);
            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return res;
}

// 无重复字符的最长子串
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int res = 0;
    int left = 0, right = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        window[c]++;
        
        while (window[c] > 1) {
            char d = s[left];
            left++;
            window[d]--;
        }
        res = max(res, right - left);
    }
    return res;
}
#endif