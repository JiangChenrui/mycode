#ifndef MYALGORITHM_HPP
#define MYALGORITHM_HPP
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
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
void Queen(int queenNum, int (*QueenArray)[4]) {
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
            Queen(queenNum + 1, QueenArray);
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
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
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
#endif