class Interface {
public:
 static const int member;
 virtual void test() = 0;
 virtual void test1() = 0;
 virtual void test2() = 0;
};

class NoInterface1 {
public:
 const int member;
 virtual void test() = 0;
 virtual void test1() = 0;
 virtual void test2() = 0;
};

class NoInterface2 {
public:
 const int member;
 virtual void test();
 virtual void test1() = 0;
 virtual void test2() = 0;
};

class AbstractClass {
public:
 virtual void test() = 0;
 virtual void test1();
};

class NoAbstractClass {
public:
 virtual void test();
 virtual void test1();
};
