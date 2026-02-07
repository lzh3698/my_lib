#pragma once

#include <iostream>
#include <utility>
#include <stdexcept>

namespace lib{

	template<typename T>
	class List {

	private:
		struct node {

			T value;
			node* m_left;
			node* m_right;

			template<typename ...Args>
			node(node* left, node* right, Args &&...args) :
				value(std::forward<Args>(args)...),
				m_left(left),
				m_right(right)
			{

			}
		};

		class iterator;

		node* find_iterator(const iterator& iter) {
			node* cur = m_head->m_right;
			while (cur != iter.m_iter && cur != m_head) {
				cur = cur->m_right;
			}
			return cur;
		}

		node* m_head;	// 哨兵节点
		size_t m_size;

	public :
		List() :
			m_head(new node(nullptr, nullptr, T())),
			m_size(0)
		{
			m_head->m_left = m_head;
			m_head->m_right = m_head;
		}

		~List() {
			clear();	// clear删除除了哨兵节点的其他节点
			delete m_head;
		}

		// 拷贝构造
		List(const List& l) : List()
		{
			if (!l.m_size) {
				return;
			}
			node* origin_cur = l.m_head->m_right;
			node* origin_end = l.m_head;
			node* this_pre = m_head;
			node* this_cur = nullptr;

			while (origin_cur != origin_end) {
				this_cur = new node(this_pre, m_head, origin_cur->value);
				m_head->m_left = this_cur;
				this_pre->m_right = this_cur;
				this_pre = this_pre->m_right;
				origin_cur = origin_cur->m_right;
			}

			m_size = l.m_size;
		}

		// 移动构造
		List(List&& l) noexcept : List()
		{
			m_head->m_right = l.m_head->m_right;
			m_head->m_left = l.m_head->m_left;
			m_head->m_left->m_right = m_head;
			m_head->m_right->m_left = m_head;

			m_size = l.m_size;
			l.m_head->m_left = l.m_head;
			l.m_head->m_right = l.m_head;
			l.m_size = 0;
		}

		// 拷贝赋值运算符
		List& operator=(List l) {
			std::swap(l.m_head, m_head);
			std::swap(l.m_size, m_size);
			return *this;
		}

		// 迭代器，内部维护指针
		class iterator {
			friend class List;
		private:

			node* m_iter;

			iterator(node* it) :
				m_iter(it)
			{

			}

		public:
			iterator() :
				m_iter(nullptr)
			{

			}

			~iterator() = default;

			iterator(const iterator& iter) :
				m_iter(iter.m_iter)
			{

			}

			bool operator==(const iterator& iter) const {
				return m_iter == iter.m_iter;
			}

			bool operator!=(const iterator& iter) const {
				return m_iter != iter.m_iter;
			}

			iterator& operator++() {
				m_iter = m_iter->m_right;
				return *this;
			}

			iterator operator++(int) {
				iterator it(*this);
				m_iter = m_iter->m_right;
				return it;
			}

			iterator& operator--() {
				m_iter = m_iter->m_left;
				return *this;
			}

			iterator operator--(int) {
				iterator it(*this);
				m_iter = m_iter->m_left;
				return it;
			}

			T& operator*() const {
				return m_iter->value;
			}

			T* operator->() const {
				return &m_iter->value;
			}

			bool operator!() {
				return !m_iter;
			}
		};

		// const迭代器
		class const_iterator {
		private:
			friend class List;

			const node* m_iter;

			const_iterator(node* it) :
				m_iter(it)
			{

			}

		public:
			const_iterator() :
				m_iter(nullptr)
			{

			}

			~const_iterator() = default;

			const_iterator(const const_iterator& iter) :
				m_iter(iter.m_iter)
			{

			}

			bool operator==(const const_iterator& iter) const {
				return m_iter == iter.m_iter;
			}

			bool operator!=(const const_iterator& iter) const {
				return m_iter != iter.m_iter;
			}

			const_iterator& operator++() {
				m_iter = m_iter->m_right;
				return *this;
			}

			const_iterator operator++(int) {
				const_iterator it(*this);
				m_iter = m_iter->m_right;
				return it;
			}

			const_iterator& operator--() {
				m_iter = m_iter->m_left;
				return *this;
			}

			const_iterator operator--(int) {
				const_iterator it(*this);
				m_iter = m_iter->m_left;
				return it;
			}

			const T& operator*() const {
				return m_iter->value;
			}

			const T* operator->() const {
				return &m_iter->value;
			}

			bool operator!() {
				return !m_iter;
			}
		};

		iterator begin() {
			return iterator(m_head->m_right);
		}

		iterator end() {
			return iterator(m_head);
		}

		const_iterator cbegin() const {
			return const_iterator(m_head->m_right);
		}

		const_iterator cend() const {
			return const_iterator(m_head);
		}

		// 删除元素
		void erase(const iterator& iter) {
			if (!m_size) {
				throw std::out_of_range("erase() out of range");
			}
			node *pos = find_iterator(iter);
			if (pos == m_head) {
				throw std::out_of_range("erase() out of range");
			}
			pos->m_left->m_right = pos->m_right;
			pos->m_right->m_left = pos->m_left;
			delete pos;
			--m_size;
		}

		// 插入元素
		iterator insert(const iterator& iter, T val) {
			node* pos = find_iterator(iter);
			node* pre = pos->m_left;
			node* new_node = new node(pre, pos, std::move(val));
			pos->m_left = new_node;
			pre->m_right = new_node;
			++m_size;
			return iterator(new_node);
		}

		// 置入元素
		template<typename ...Args>
		iterator emplace(const iterator& iter, Args &&...args) {
			node* pos = find_iterator(iter);
			node* pre = pos->m_left;
			node* new_node = new node(pre, pos, std::forward<Args>(args)...);
			pos->m_left = new_node;
			pre->m_right = new_node;
			++m_size;
			return iterator(new_node);
		}

		// 清空元素，除了哨兵节点
		void clear() {
			node* cur = m_head->m_right;
			node* end = m_head;
			while (cur != end) {
				node* del = cur;
				cur = cur->m_right;
				delete del;
			}
			m_head->m_left = m_head;
			m_head->m_right = m_head;
			m_size = 0;
		}

		// 头插
		void push_front(T val) {
			node* new_node = new node(m_head, m_head->m_right, std::move(val));
			m_head->m_right = new_node;
			new_node->m_right->m_left = new_node;
			++m_size;
		}

		// 尾插
		void push_back(T val) {
			node* new_node = new node(m_head->m_left, m_head, std::move(val));
			m_head->m_left = new_node;
			new_node->m_left->m_right = new_node;
			++m_size;
		}

		// 头部置入
		template<typename ...Args>
		void emplace_front(Args &&...args) {
			node* new_node = new node(m_head, m_head->m_right, std::forward<Args>(args)...);
			m_head->m_right = new_node;
			new_node->m_right->m_left = new_node;
			++m_size;
		}

		// 尾部置入
		template<typename ...Args>
		void emplace_back(Args &&...args) {
			node* new_node = new node(m_head->m_left, m_head, std::forward<Args>(args)...);
			m_head->m_left = new_node;
			new_node->m_left->m_right = new_node;
			++m_size;
		}

		// 获取大小
		size_t size() {
			return m_size;
		}

		// 判断是否为空
		bool empty() {
			return !size();
		}

		// 获取头部元素
		T& front() {
			return m_head->m_right->value;
		}

		// 获取尾部元素
		T& back() {
			return m_head->m_left->value;
		}

		const T& front() const {
			return m_head->m_right->value;
		}

		const T& back() const {
			return m_head->m_left->value;
		}
	};
}
