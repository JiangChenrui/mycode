    // Person & operator= (Person &p) {
    //     // 编译器提供浅拷贝
    //     // this->m_Height = p.m_Height;

    //     // 应该先判断是否有属性在堆区，如果有先释放干净，然后在深拷贝
    //     if (m_Height != NULL) {
    //         delete m_Height;
    //         m_Height = NULL;
    //     }
    //     cout << "重载运算符=" << endl;
    //     m_A = p.m_A;
    //     m_Age = p.m_Age;
    //     m_Height = new int (*p.m_Height);
    //     return *this;
    // }
