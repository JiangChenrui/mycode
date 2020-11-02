#ifndef UNION_FIND
#define UNION_FIND
#include <vector>
#include <iostream>

using namespace std;

// quick-find
class UF {
public:
    UF(int N) {
        this->id_count = N;
        id.reserve(N);
        for (int i = 0; i < N; ++i) id[i] = i;
    }
    int count() {
        return id_count;
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    int find(int p) {
        return id[p];
    }
    void unionMemeber(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID == qID) return;

        for (int i = 0; i < id_count; ++i) {
            if (id[i] == pID) id[i] = qID;
        }
        id_count--;
    }

private:
    vector<int> id;
    int id_count;
};

// quick-union
class QuickUnion {
public:
    QuickUnion(int N) {
        id_count = N;
        id.reserve(N);
        for (int i = 0; i < N; ++i) id[i] = i;
    }
    int count() { return id_count; }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    int find(int p) {
        while (p != id[p]) p = id[p];
        return p;
    }
    void unionMemeber(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) return;

        id[pRoot] = qRoot;
        id_count--;
    }
private:
    vector<int> id;
    int id_count;
};

// 加权的quick-union
class WeightQuickUnionUF {
public:
    WeightQuickUnionUF(int N) {
        id_count = N;
        id.reserve(N);
        for (int i = 0; i < N; ++i) id[i] = i;
        sz = vector<int>(N, 1);
    }
    int count() { return id_count; }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    int find(int p) {
        while (p != id[p]) p = id[p];
        return p;
    }
    void unionMemeber(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) return;
        if (sz[pRoot] < sz[qRoot]) {
            id[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            id[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
        id_count--;
    }
private:
    vector<int> id;
    int id_count;
    vector<int> sz;
};
#endif