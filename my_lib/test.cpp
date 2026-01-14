#include <iostream>
#include <algorithm>
#include <thread>
#include "Algorithm.h"
#include <memory>
#include "Vector.hpp"
#include "List.hpp"
using namespace std;
using namespace lib;

int main() {

	return 0;
}

// 测试类
//#include <iostream>
//#include <string>
//#include <utility>
//
//struct TestObject {
//    int id;
//    std::string name;
//
//    // 默认构造函数
//    TestObject() : id(0), name("default") {
//        std::cout << "TestObject default constructor: " << id << std::endl;
//    }
//
//    // 带参数的构造函数
//    TestObject(int i, const std::string& n) : id(i), name(n) {
//        std::cout << "TestObject constructor (string&): " << id << ", " << name << std::endl;
//    }
//
//    // 支持右值引用
//    TestObject(int i, std::string&& n) : id(i), name(std::move(n)) {
//        std::cout << "TestObject constructor (string&&): " << id << ", " << name << std::endl;
//    }
//
//    // 支持const char*（字符串字面量）
//    TestObject(int i, const char* n) : id(i), name(n) {
//        std::cout << "TestObject constructor (const char*): " << id << ", " << name << std::endl;
//    }
//
//    // 拷贝构造函数
//    TestObject(const TestObject& other) : id(other.id), name(other.name) {
//        std::cout << "TestObject copy constructor: " << id << std::endl;
//    }
//
//    // 移动构造函数
//    TestObject(TestObject&& other) noexcept : id(other.id), name(std::move(other.name)) {
//        std::cout << "TestObject move constructor: " << id << std::endl;
//        other.id = -1;
//    }
//
//    // 拷贝赋值运算符
//    TestObject& operator=(const TestObject& other) {
//        std::cout << "TestObject copy assignment: " << id << " <- " << other.id << std::endl;
//        if (this != &other) {
//            id = other.id;
//            name = other.name;
//        }
//        return *this;
//    }
//
//    // 移动赋值运算符
//    TestObject& operator=(TestObject&& other) noexcept {
//        std::cout << "TestObject move assignment: " << id << " <- " << other.id << std::endl;
//        if (this != &other) {
//            id = other.id;
//            name = std::move(other.name);
//            other.id = -1;
//        }
//        return *this;
//    }
//
//    // 析构函数
//    ~TestObject() {
//        std::cout << "TestObject destructor: " << id << std::endl;
//    }
//
//    // 相等运算符
//    bool operator==(const TestObject& other) const {
//        return id == other.id && name == other.name;
//    }
//
//    // 输出运算符（便于调试）
//    friend std::ostream& operator<<(std::ostream& os, const TestObject& obj) {
//        os << "TestObject{id=" << obj.id << ", name=\"" << obj.name << "\"}";
//        return os;
//    }
//};
//
//// 测试函数
//void test_basic_functionality() {
//    std::cout << "\n=== 测试基础功能 ===" << std::endl;
//
//    lib::List<int> list;
//
//    // 测试初始状态
//    assert(list.empty());
//    assert(list.size() == 0);
//
//    // 测试push_back
//    list.push_back(1);
//    list.push_back(2);
//    list.push_back(3);
//
//    assert(!list.empty());
//    assert(list.size() == 3);
//    assert(list.front() == 1);
//    assert(list.back() == 3);
//
//    // 测试push_front
//    list.push_front(0);
//    assert(list.size() == 4);
//    assert(list.front() == 0);
//    assert(list.back() == 3);
//
//    // 测试迭代器遍历
//    std::cout << "遍历list: ";
//    int expected[] = { 0, 1, 2, 3 };
//    int i = 0;
//    for (auto it = list.begin(); it != list.end(); ++it) {
//        std::cout << *it << " ";
//        assert(*it == expected[i++]);
//    }
//    std::cout << std::endl;
//
//    // 测试基于范围的for循环
//    std::cout << "基于范围的for循环: ";
//    i = 0;
//    for (int value : list) {
//        std::cout << value << " ";
//        assert(value == expected[i++]);
//    }
//    std::cout << std::endl;
//
//    std::cout << "基础功能测试通过！" << std::endl;
//}
//
//void test_insert_and_erase() {
//    std::cout << "\n=== 测试插入和删除 ===" << std::endl;
//
//    lib::List<int> list;  // 假设支持初始化列表
//    list.push_back(1);
//    list.push_back(2);
//    list.push_back(3);
//
//    // 测试插入
//    auto it = list.begin();
//    ++it;  // 指向第二个元素
//    it = list.insert(it, 99);
//    assert(*it == 99);
//    assert(list.size() == 4);
//
//    std::cout << "插入后: ";
//    for (int v : list) std::cout << v << " ";
//    std::cout << std::endl;
//
//    // 测试emplace
//    it = list.begin();
//    it = list.emplace(it, 88);  // 在开头插入
//    assert(*it == 88);
//    assert(list.size() == 5);
//
//    std::cout << "emplace后: ";
//    for (int v : list) std::cout << v << " ";
//    std::cout << std::endl;
//
//    // 测试删除
//    it = list.begin();
//    ++it;  // 指向第二个元素
//    list.erase(it);
//    assert(list.size() == 4);
//
//    std::cout << "删除后: ";
//    for (int v : list) std::cout << v << " ";
//    std::cout << std::endl;
//
//    // 测试clear
//    list.clear();
//    assert(list.empty());
//    assert(list.size() == 0);
//
//    std::cout << "插入删除测试通过！" << std::endl;
//}
//
//void test_copy_and_move() {
//    std::cout << "\n=== 测试拷贝和移动 ===" << std::endl;
//
//    // 测试拷贝构造
//    lib::List<int> original;
//    original.push_back(1);
//    original.push_back(2);
//    original.push_back(3);
//
//    lib::List<int> copy(original);
//    assert(copy.size() == original.size());
//
//    std::cout << "原list: ";
//    for (int v : original) std::cout << v << " ";
//    std::cout << std::endl;
//
//    std::cout << "拷贝list: ";
//    for (int v : copy) std::cout << v << " ";
//    std::cout << std::endl;
//
//    // 验证是深拷贝
//    original.push_back(4);
//    assert(original.size() == 4);
//    assert(copy.size() == 3);
//
//    // 测试移动构造
//    lib::List<int> moved(std::move(original));
//    assert(moved.size() == 4);
//    assert(original.empty());
//
//    std::cout << "移动后moved: ";
//    for (int v : moved) std::cout << v << " ";
//    std::cout << std::endl;
//
//    std::cout << "移动后original大小: " << original.size() << std::endl;
//
//    // 测试拷贝赋值
//    lib::List<int> assigned;
//    assigned = copy;
//    assert(assigned.size() == copy.size());
//
//    std::cout << "赋值后assigned: ";
//    for (int v : assigned) std::cout << v << " ";
//    std::cout << std::endl;
//
//    std::cout << "拷贝移动测试通过！" << std::endl;
//}
//
//void test_custom_object() {
//    std::cout << "\n=== 测试自定义对象 ===" << std::endl;
//
//    lib::List<TestObject> list;
//
//    std::cout << "\n1. 测试emplace_back（不同参数类型）:" << std::endl;
//    list.emplace_back(1, "Alice");        // const char*
//    list.emplace_back(2, std::string("Bob"));  // std::string&&
//    std::string charlie = "Charlie";
//    list.emplace_back(3, charlie);        // const std::string&
//
//    std::cout << "\n2. 测试push_back（拷贝）:" << std::endl;
//    TestObject obj(4, "David");
//    list.push_back(obj);  // 调用拷贝构造函数
//
//    std::cout << "\n3. 测试push_back（移动）:" << std::endl;
//    list.push_back(TestObject(5, "Eve"));  // 调用移动构造函数
//
//    std::cout << "\n4. 遍历自定义对象:" << std::endl;
//    for (const auto& obj : list) {
//        std::cout << "  " << obj << std::endl;
//    }
//
//    std::cout << "\n5. 测试迭代器操作:" << std::endl;
//    auto it = list.begin();
//    std::cout << "  第一个元素: " << *it << std::endl;
//    ++it;
//    std::cout << "  第二个元素: " << it->id << ", " << it->name << std::endl;
//
//    std::cout << "\n6. 测试插入和删除:" << std::endl;
//    it = list.begin();
//    ++it;  // 指向第二个元素
//    list.insert(it, TestObject(99, "Inserted"));
//
//    std::cout << "  插入后遍历:" << std::endl;
//    for (const auto& obj : list) {
//        std::cout << "    " << obj << std::endl;
//    }
//
//    it = list.begin();
//    ++it;
//    list.erase(it);
//
//    std::cout << "  删除后遍历:" << std::endl;
//    for (const auto& obj : list) {
//        std::cout << "    " << obj << std::endl;
//    }
//
//    std::cout << "\n7. 清空list（会调用析构函数）:" << std::endl;
//    list.clear();
//
//    std::cout << "自定义对象测试通过！" << std::endl;
//}
//
//void test_edge_cases() {
//    std::cout << "\n=== 测试边界情况 ===" << std::endl;
//
//    // 测试空list
//    lib::List<int> empty_list;
//    assert(empty_list.begin() == empty_list.end());
//
//    // 测试单个元素
//    lib::List<int> single;
//    single.push_back(42);
//    assert(single.size() == 1);
//    assert(single.front() == 42);
//    assert(single.back() == 42);
//    assert(single.begin() != single.end());
//
//    std::cout << "单元素list: ";
//    for (int v : single) std::cout << v << " ";
//    std::cout << std::endl;
//
//    // 测试在begin和end插入
//    lib::List<int> list;
//    list.insert(list.end(), 1);
//    list.insert(list.begin(), 0);
//    list.insert(list.end(), 2);
//
//    std::cout << "在begin和end插入: ";
//    for (int v : list) std::cout << v << " ";
//    std::cout << std::endl;
//
//    // 测试删除唯一元素
//    lib::List<int> one;
//    one.push_back(99);
//    one.erase(one.begin());
//    assert(one.empty());
//
//    std::cout << "边界情况测试通过！" << std::endl;
//}
//
//void test_iterator_operations() {
//    std::cout << "\n=== 测试迭代器操作 ===" << std::endl;
//
//    lib::List<int> list;
//    for (int i = 0; i < 5; ++i) {
//        list.push_back(i * 10);
//    }
//
//    // 测试前向迭代
//    std::cout << "前向迭代: ";
//    for (auto it = list.begin(); it != list.end(); ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;
//
//    // 测试后向迭代（需要支持双向迭代器）
//    std::cout << "后向迭代: ";
//    auto it = list.end();
//    if (it != list.begin()) {
//        do {
//            --it;
//            std::cout << *it << " ";
//        } while (it != list.begin());
//    }
//    std::cout << std::endl;
//
//    // 测试迭代器自增/自减
//    it = list.begin();
//    assert(*it == 0);
//
//    auto it2 = ++it;
//    assert(*it == 10);
//    assert(*it2 == 10);
//
//    auto it3 = it++;
//    assert(*it == 20);
//    assert(*it3 == 10);
//
//    std::cout << "迭代器操作测试通过！" << std::endl;
//}
//
//void test_const_iterator() {
//    std::cout << "\n=== 测试const迭代器 ===" << std::endl;
//
//    lib::List<int> list;
//    list.push_back(100);
//    list.push_back(200);
//    list.push_back(300);
//
//    // 测试const迭代器
//    std::cout << "const迭代器遍历: ";
//    for (auto it = list.cbegin(); it != list.cend(); ++it) {
//        std::cout << *it << " ";
//        // *it = 999;  // 这行应该编译错误，因为const迭代器返回的是const引用
//    }
//    std::cout << std::endl;
//
//    // 测试const对象的迭代器
//    const lib::List<int>& const_list = list;
//    std::cout << "const对象遍历: ";
//    for (auto it = const_list.cbegin(); it != const_list.cend(); ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "const迭代器测试通过！" << std::endl;
//}
//
//void test_performance() {
//    std::cout << "\n=== 测试性能（大量数据）===" << std::endl;
//
//    lib::List<int> list;
//    const int COUNT = 10000;
//
//    // 测试push_back性能
//    for (int i = 0; i < COUNT; ++i) {
//        list.push_back(i);
//    }
//    assert(list.size() == COUNT);
//
//    // 测试遍历性能
//    int sum = 0;
//    for (int value : list) {
//        sum += value;
//    }
//    std::cout << "前" << COUNT << "个数的和: " << sum << std::endl;
//    assert(sum == COUNT * (COUNT - 1) / 2);
//
//    // 测试中间插入性能
//    auto it = list.begin();
//    for (int i = 0; i < COUNT / 2; ++i) {
//        ++it;
//    }
//    list.insert(it, 99999);
//    assert(list.size() == COUNT + 1);
//
//    std::cout << "性能测试通过！" << std::endl;
//}
//
//// 如果List不支持初始化列表，添加这个测试
//void test_without_initializer_list() {
//    std::cout << "\n=== 测试（无初始化列表支持）===" << std::endl;
//
//    lib::List<int> list;
//    for (int i = 1; i <= 5; ++i) {
//        list.push_back(i);
//    }
//
//    std::cout << "手动添加元素: ";
//    for (int v : list) std::cout << v << " ";
//    std::cout << std::endl;
//}
//
//int main() {
//    try {
//        std::cout << "开始测试List容器..." << std::endl;
//
//        test_basic_functionality();
//        test_insert_and_erase();
//        test_copy_and_move();
//        test_custom_object();
//        test_edge_cases();
//        test_iterator_operations();
//        test_const_iterator();
//        test_performance();
//        test_without_initializer_list();
//
//        std::cout << "\n=== 所有测试通过！ ===" << std::endl;
//        return 0;
//
//    }
//    catch (const std::exception& e) {
//        std::cerr << "\n测试失败，异常: " << e.what() << std::endl;
//        return 1;
//    }
//    catch (...) {
//        std::cerr << "\n测试失败，未知异常" << std::endl;
//        return 1;
//    }
//}

//int main() {
	//Vector<int> vec;
	//const Vector<int> cvec;

	/*Vector<string> vec;
	vec.push_back("abc");
	vec.push_back("aaa");
	vec.push_back("ccc");

	Vector<string>::iterator it = vec.begin();
	cout << it->size() << " " << *it->begin() << endl;
	it++;
	*it = "xjijwqnw";
	cout << *it << endl;*/

	/*vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	Vector<int>::iterator it = vec.begin();
	Vector<int>::const_iterator cit = vec.cbegin();
	cout << *it << endl;
	cout << *cit << endl;
	it++;
	cit++;
	cout << *it << endl;
	cout << *cit << endl;
	*it = 100;
	cout << *it << endl;
	cit++;
	cout << *cit << endl;

	Vector<int>::const_iterator cvecit = cvec.cbegin();*/


//	return 0;
//}

//#include <cassert>
//#include <string>
//
//using namespace lib;
//
//// 测试辅助函数：打印 Vector 内容
//template<typename T>
//void print_vector(const Vector<T>& v, const std::string& name) {
//    std::cout << name << ": ";
//    for (size_t i = 0; i < v.size(); ++i) {
//        std::cout << v[i] << " ";
//    }
//    std::cout << "| size=" << v.size()
//        << ", capacity=" << v.capacity()
//        << ", empty=" << v.empty() << std::endl;
//}
//
//// 测试基础功能
//void test_basic_functionality() {
//    std::cout << "=== 测试基础功能 ===" << std::endl;
//
//    // 默认构造
//    Vector<int> v1;
//    assert(v1.size() == 0);
//    assert(v1.capacity() == 0);
//    assert(v1.empty());
//    print_vector(v1, "v1 (默认构造)");
//
//    // push_back
//    v1.push_back(1);
//    v1.push_back(2);
//    v1.push_back(3);
//    assert(v1.size() == 3);
//    assert(!v1.empty());
//    assert(v1[0] == 1);
//    assert(v1[1] == 2);
//    assert(v1[2] == 3);
//    print_vector(v1, "v1 (push_back 1,2,3)");
//
//    // front 和 back
//    assert(v1.front() == 1);
//    assert(v1.back() == 3);
//
//    // pop_back
//    v1.pop_back();
//    assert(v1.size() == 2);
//    assert(v1.back() == 2);
//    print_vector(v1, "v1 (pop_back)");
//
//    // 重新添加元素
//    v1.push_back(4);
//    v1.push_back(5);
//    assert(v1.size() == 4);
//    assert(v1.capacity() >= 4);
//    print_vector(v1, "v1 (push_back 4,5)");
//
//    // 拷贝构造
//    Vector<int> v2(v1);
//    assert(v2.size() == v1.size());
//    for (size_t i = 0; i < v1.size(); ++i) {
//        assert(v2[i] == v1[i]);
//    }
//    print_vector(v2, "v2 (拷贝构造自v1)");
//
//    // 修改 v2 不影响 v1
//    v2[0] = 100;
//    assert(v1[0] == 1);
//    assert(v2[0] == 100);
//
//    // 拷贝赋值
//    Vector<int> v3;
//    v3 = v1;
//    assert(v3.size() == v1.size());
//    for (size_t i = 0; i < v1.size(); ++i) {
//        assert(v3[i] == v1[i]);
//    }
//    print_vector(v3, "v3 (拷贝赋值自v1)");
//
//    // 移动构造
//    Vector<int> v4(std::move(v2));
//    assert(v4.size() == 4);
//    assert(v4[0] == 100);
//    assert(v2.empty());  // v2 应该被移动
//    print_vector(v4, "v4 (移动构造自v2)");
//    print_vector(v2, "v2 (被移动后)");
//
//    // 移动赋值
//    Vector<int> v5;
//    v5 = std::move(v3);
//    assert(v5.size() == 4);
//    assert(v5[0] == 1);
//    assert(v3.empty());  // v3 应该被移动
//    print_vector(v5, "v5 (移动赋值自v3)");
//    print_vector(v3, "v3 (被移动后)");
//
//    // clear
//    v1.clear();
//    assert(v1.empty());
//    assert(v1.size() == 0);
//    print_vector(v1, "v1 (clear后)");
//
//    std::cout << "基础功能测试通过！\n" << std::endl;
//}

//// 测试迭代器
//void test_iterators() {
//    std::cout << "=== 测试迭代器 ===" << std::endl;
//
//    Vector<int> v;
//    for (int i = 0; i < 5; ++i) {
//        v.push_back(i * 10);
//    }
//
//    // 正向迭代
//    std::cout << "正向遍历: ";
//    for (auto it = v.begin(); it != v.end(); ++it) {
//        std::cout << *it << " ";
//        *it += 1;  // 修改元素
//    }
//    std::cout << std::endl;
//
//    // 验证修改
//    std::cout << "修改后: ";
//    for (size_t i = 0; i < v.size(); ++i) {
//        std::cout << v[i] << " ";
//        assert(v[i] == i * 10 + 1);
//    }
//    std::cout << std::endl;
//
//    // 迭代器运算
//    auto it1 = v.begin();
//    auto it2 = v.begin() + 2;
//    assert(it2 - it1 == 2);
//    assert(it1 < it2);
//    assert(it1 != it2);
//
//    // 后置++
//    auto it3 = v.begin();
//    auto old_it = it3++;
//    assert(old_it == v.begin());
//    assert(it3 == v.begin() + 1);
//
//    // 前置--
//    --it3;
//    assert(it3 == v.begin());
//
//    std::cout << "迭代器测试通过！\n" << std::endl;
//}
//
//// 测试 insert 和 erase
//void test_insert_erase() {
//    std::cout << "=== 测试 insert 和 erase ===" << std::endl;
//
//    Vector<int> v;
//    for (int i = 0; i < 5; ++i) {
//        v.push_back(i);
//    }
//    print_vector(v, "初始状态");
//
//    // 在中间插入
//    auto it = v.insert(v.begin() + 2, 100);
//    assert(v.size() == 6);
//    assert(*it == 100);
//    assert(v[2] == 100);
//    print_vector(v, "在位置2插入100");
//
//    // 在开头插入
//    v.insert(v.begin(), 200);
//    assert(v[0] == 200);
//    assert(v.size() == 7);
//    print_vector(v, "在开头插入200");
//
//    // 在结尾插入
//    v.insert(v.end(), 300);
//    assert(v.back() == 300);
//    assert(v.size() == 8);
//    print_vector(v, "在结尾插入300");
//
//    // 测试 emplace_back
//    v.emplace_back(400);
//    assert(v.back() == 400);
//    assert(v.size() == 9);
//    print_vector(v, "emplace_back 400");
//
//    // 测试 emplace
//    v.emplace(v.begin() + 1, 500);
//    assert(v[1] == 500);
//    assert(v.size() == 10);
//    print_vector(v, "在位置1 emplace 500");
//
//    // 测试 erase - 删除中间元素
//    it = v.erase(v.begin() + 3);
//    assert(v.size() == 9);
//    assert(*it == 100);  // 删除的是元素1，所以下一个是100
//    print_vector(v, "删除位置3的元素");
//
//    // 测试 erase - 删除开头元素
//    it = v.erase(v.begin());
//    assert(v.size() == 8);
//    assert(*it == 500);  // 删除200后，500成为开头
//    print_vector(v, "删除开头元素");
//
//    // 测试 erase - 删除结尾元素
//    it = v.erase(v.end() - 1);
//    assert(v.size() == 7);
//    assert(it == v.end());  // 删除最后一个元素后返回end()
//    print_vector(v, "删除结尾元素");
//
//    // 测试 erase - 连续删除
//    v.erase(v.begin());
//    v.erase(v.begin());
//    v.erase(v.begin());
//    assert(v.size() == 4);
//    print_vector(v, "连续删除3个开头元素");
//
//    // 测试异常情况
//    bool exception_caught = false;
//    try {
//        v.erase(v.end());  // 不能删除end()
//    }
//    catch (const std::out_of_range&) {
//        exception_caught = true;
//    }
//    assert(exception_caught);
//
//    exception_caught = false;
//    try {
//        v.insert(v.end() + 1, 999);  // 超出范围插入
//    }
//    catch (const std::out_of_range&) {
//        exception_caught = true;
//    }
//    assert(exception_caught);
//
//    std::cout << "insert 和 erase 测试通过！\n" << std::endl;
//}
//
//// 测试边界条件和异常
//void test_edge_cases_and_exceptions() {
//    std::cout << "=== 测试边界条件和异常 ===" << std::endl;
//
//    Vector<int> v;
//
//    // 测试空容器的 front/back/pop_back
//    bool exception_caught = false;
//    try {
//        v.front();
//    }
//    catch (const std::out_of_range&) {
//        exception_caught = true;
//    }
//    assert(exception_caught);
//
//    exception_caught = false;
//    try {
//        v.back();
//    }
//    catch (const std::out_of_range&) {
//        exception_caught = true;
//    }
//    assert(exception_caught);
//
//    exception_caught = false;
//    try {
//        v.pop_back();
//    }
//    catch (const std::out_of_range&) {
//        exception_caught = true;
//    }
//    assert(exception_caught);
//
//    // 测试 operator[] 越界
//    v.push_back(1);
//    exception_caught = false;
//    try {
//        int x = v[1];  // 索引越界
//    }
//    catch (const std::out_of_range&) {
//        exception_caught = true;
//    }
//    assert(exception_caught);
//
//    // 测试大量元素
//    Vector<int> large;
//    for (int i = 0; i < 1000; ++i) {
//        large.push_back(i);
//    }
//    assert(large.size() == 1000);
//    assert(large.capacity() >= 1000);
//    for (int i = 0; i < 1000; ++i) {
//        assert(large[i] == i);
//    }
//
//    // 测试容量增长
//    std::cout << "容量增长测试:" << std::endl;
//    Vector<int> growth_test;
//    for (int i = 0; i < 20; ++i) {
//        growth_test.push_back(i);
//        std::cout << "size=" << growth_test.size()
//            << ", capacity=" << growth_test.capacity() << std::endl;
//    }
//
//    std::cout << "边界条件和异常测试通过！\n" << std::endl;
//}
//
//// 测试自定义类型
//class TestClass {
//public:
//    int value;
//    std::string name;
//
//    TestClass() : value(0), name("default") {
//        std::cout << "默认构造: " << name << std::endl;
//    }
//
//    TestClass(int v, const std::string& n) : value(v), name(n) {
//        std::cout << "有参构造: " << name << "(" << value << ")" << std::endl;
//    }
//
//    TestClass(const TestClass& other) : value(other.value), name(other.name) {
//        std::cout << "拷贝构造: " << name << " from " << other.name << std::endl;
//    }
//
//    TestClass(TestClass&& other) noexcept : value(other.value), name(std::move(other.name)) {
//        std::cout << "移动构造: " << name << std::endl;
//        other.value = -1;
//    }
//
//    TestClass& operator=(const TestClass& other) {
//        if (this != &other) {
//            value = other.value;
//            name = other.name;
//            std::cout << "拷贝赋值: " << name << " = " << other.name << std::endl;
//        }
//        return *this;
//    }
//
//    TestClass& operator=(TestClass&& other) noexcept {
//        if (this != &other) {
//            value = other.value;
//            name = std::move(other.name);
//            other.value = -1;
//            std::cout << "移动赋值: " << name << std::endl;
//        }
//        return *this;
//    }
//
//    ~TestClass() {
//        std::cout << "析构: " << name << std::endl;
//    }
//
//    friend std::ostream& operator<<(std::ostream& os, const TestClass& obj) {
//        os << obj.name << "(" << obj.value << ")";
//        return os;
//    }
//};
//
//void test_custom_type() {
//    std::cout << "\n=== 测试自定义类型 ===" << std::endl;
//
//    std::cout << "\n1. 创建Vector并push_back:" << std::endl;
//    Vector<TestClass> v;
//    v.push_back(TestClass(1, "first"));
//    v.push_back(TestClass(2, "second"));
//
//    std::cout << "\n2. emplace_back (避免临时对象):" << std::endl;
//    v.emplace_back(3, "third");
//
//    std::cout << "\n3. 遍历Vector:" << std::endl;
//    for (const auto& item : v) {
//        std::cout << item << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "\n4. 拷贝构造:" << std::endl;
//    Vector<TestClass> v2(v);
//
//    std::cout << "\n5. 移动构造:" << std::endl;
//    Vector<TestClass> v3(std::move(v2));
//
//    std::cout << "\n6. insert 和 emplace:" << std::endl;
//    v.insert(v.begin() + 1, TestClass(4, "inserted"));
//    v.emplace(v.begin() + 2, 5, "emplaced");
//
//    std::cout << "\n7. erase:" << std::endl;
//    v.erase(v.begin());
//
//    std::cout << "\n8. 退出作用域，自动析构..." << std::endl;
//}
//
//// 主测试函数
//int main() {
//    std::cout << "开始测试 lib::Vector\n" << std::endl;
//
//    try {
//        test_basic_functionality();
//        test_iterators();
//        test_insert_erase();
//        test_edge_cases_and_exceptions();
//        test_custom_type();
//
//        std::cout << "\n=========================================" << std::endl;
//        std::cout << "所有测试通过！" << std::endl;
//        std::cout << "=========================================" << std::endl;
//
//    }
//    catch (const std::exception& e) {
//        std::cerr << "\n测试失败，异常: " << e.what() << std::endl;
//        return 1;
//    }
//    catch (...) {
//        std::cerr << "\n测试失败，未知异常" << std::endl;
//        return 1;
//    }
//
//    return 0;
//}

//int main() {
//	
//
//	//int* arr = nullptr;
//	//for (int i = 0; i < 100; ++i) {
//	//	int num = test_arr(arr);
//	//	int* arr2 = new int[num] {};
//	//	int* arr3 = new int[num] {};
//	//	for (int i = 0; i < num; ++i) {
//	//		arr2[i] = arr[i];
//	//		arr3[i] = arr[i];
//	//	}
//	//	quick_sort(arr2, num);
//	//	std::sort(arr3, arr3 + num);
//	//	for (int i = 0; i < num; ++i) {
//	//		if (arr3[i] != arr2[i]) {
//	//			cout << "wrong:  " << endl;
//	//			for_each(arr, arr + num, [](int val) {
//	//				cout << val << " ";
//	//				});
//	//			cout << endl;
//	//			for_each(arr2, arr2 + num, [](int val) {
//	//				cout << val << " ";
//	//				});
//	//			cout << endl;
//	//			for_each(arr3, arr3 + num, [](int val) {
//	//				cout << val << " ";
//	//				});
//	//			cout << endl;
//	//			break;
//	//		}
//	//	}
//	//	cout << i << endl;
//	//	//this_thread::sleep_for(1s);
//	//	cout << endl;
//	//	delete[] arr;
//	//	delete[] arr2;
//	//	delete[] arr3;
//	//	arr = nullptr;
//	//	arr2 = nullptr;
//	//	arr3 = nullptr;
//	//}
//
//	///*int arr[]{ 22, 44 };
//	//recursive_sort(arr, 2);*/
//	//int* rarr = nullptr;
//	//for (int i = 0; i < 100; ++i) {
//	//	int num = test_arr(rarr);
//	//	int* rarr2 = new int[num] {};
//	//	int* rarr3 = new int[num] {};
//	//	for (int i = 0; i < num; ++i) {
//	//		rarr2[i] = rarr[i];
//	//		rarr3[i] = rarr[i];
//	//	}
//	//	recursive_sort(rarr2, num);
//	//	std::sort(rarr3, rarr3 + num);
//	//	for (int i = 0; i < num; ++i) {
//	//		if (rarr3[i] != rarr2[i]) {
//	//			cout << "wrong:  " << endl;
//	//			for_each(rarr, rarr + num, [](int val) {
//	//				cout << val << " ";
//	//				});
//	//			cout << endl;
//	//			for_each(rarr2, rarr2 + num, [](int val) {
//	//				cout << val << " ";
//	//				});
//	//			cout << endl;
//	//			for_each(rarr3, rarr3 + num, [](int val) {
//	//				cout << val << " ";
//	//				});
//	//			cout << endl;
//	//			break;
//	//		}
//	//	}
//	//	cout << i << endl;
//	//	//this_thread::sleep_for(1s);
//	//	cout << endl;
//	//	delete[] rarr;
//	//	delete[] rarr2;
//	//	delete[] rarr3;
//	//	rarr = nullptr;
//	//	rarr2 = nullptr;
//	//	rarr3 = nullptr;
//	//}
//
//	/*char arr1[] = "ABABABABC";
//	char arr2[] = "ABABC";
//	cout << str_find(arr1, arr2);*/
//
//	
//
//	
//	return 0;
//}