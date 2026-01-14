#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

namespace lib {

	template<typename T, typename Allocator = std::allocator<T>>
	class Vector {
		
	private:
		Allocator allocator;
		T* vec;
		size_t m_size;
		size_t m_capacity;

		void add_capacity() {
			if (size() >= capacity()) {
				size_t new_capacity = !empty() ? 2 * capacity() : 3;
				T* new_vec = allocator.allocate(new_capacity);
				for (int i = 0; i < size(); ++i) {
					allocator.construct(new_vec + i, std::move(vec[i]));
				}
				size_t origin_size = size();
				clear();
				vec = new_vec;
				m_capacity = new_capacity;
				m_size = origin_size;
			}
		}

	public:
		class iterator {
			friend class Vector;
		private:
			T* m_iter;

			iterator(T *it) :
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

			iterator operator+(int step) const {
				return iterator(m_iter + step);
			}

			iterator operator-(int step) const {
				return iterator(m_iter - step);
			}
			
			ptrdiff_t operator-(const iterator& iter) const {
				return m_iter - iter.m_iter;
			}

			bool operator<(const iterator& iter) const {
				return m_iter < iter.m_iter;
			}

			bool operator==(const iterator& iter) const {
				return m_iter == iter.m_iter;
			}

			bool operator!=(const iterator& iter) const {
				return m_iter != iter.m_iter;
			}

			iterator& operator++() {
				++m_iter;
				return *this;
			}

			iterator operator++(int) {
				iterator it(*this);
				++m_iter;
				return it;
			}

			iterator& operator--() {
				--m_iter;
				return *this;
			}

			iterator operator--(int) {
				iterator it(*this);
				--m_iter;
				return it;
			}

			T& operator*() const {
				return *m_iter;
			}

			T* operator->() const {
				return m_iter;
			}

			bool operator!() {
				return !m_iter;
			}
		};

		class const_iterator {
			friend class Vector;
		private:
			const T* m_iter;

			const_iterator(T *it) :
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

			const_iterator operator+(int step) const {
				return const_iterator(m_iter + step);
			}

			const_iterator operator-(int step) const {
				return const_iterator(m_iter - step);
			}

			ptrdiff_t operator-(const const_iterator& iter) const {
				return m_iter - iter.m_iter;
			}

			bool operator<(const const_iterator& iter) const {
				return m_iter < iter.m_iter;
			}

			bool operator==(const const_iterator& iter) const {
				return m_iter == iter.m_iter;
			}

			bool operator!=(const const_iterator& iter) const {
				return m_iter != iter.m_iter;
			}

			const_iterator& operator++() {
				++m_iter;
				return *this;
			}

			const_iterator operator++(int) {
				const_iterator it(*this);
				++m_iter;
				return it;
			}

			const_iterator& operator--() {
				--m_iter;
				return *this;
			}

			const_iterator operator--(int) {
				const_iterator it(*this);
				--m_iter;
				return it;
			}

			const T& operator*() const {
				return *m_iter;
			}

			const T* operator->() const {
				return m_iter;
			}

			bool operator!() {
				return !m_iter;
			}
		};

		Vector() : 
			vec(nullptr),
			m_size(0),
			m_capacity(0){ }

		~Vector() {
			clear();
		}

		//拷贝构造
		Vector(const Vector& v) :
			vec(allocator.allocate(v.size())),
			m_size(v.m_size),
			m_capacity(v.m_capacity)
		{
			for(int i = 0; i < v.size(); ++i){
				allocator.construct(vec + i, v[i]);
			}
		}

		//拷贝赋值运算符
		Vector& operator=(const Vector& v) {
			if (&v == this) {
				return *this;
			}
			clear();
			vec = allocator.allocate(v.size());
			m_capacity = m_size = v.size();
			for (int i = 0; i < v.size(); ++i) {
				allocator.construct(vec + i, v[i]);
			}
			return *this;
		}

		//移动构造
		Vector(Vector&& v) noexcept :
			vec(v.vec),
			m_size(v.m_size),
			m_capacity(v.m_capacity)
		{
			v.vec = nullptr;
			v.m_size = v.m_capacity = 0;
		}

		//移动赋值运算符
		Vector& operator=(Vector&& v) noexcept {
			if (&v == this) {
				return *this;
			}
			clear();
			vec = v.vec;
			m_size = v.size();
			m_capacity = v.capacity();
			v.vec = nullptr;
			v.m_size = v.m_capacity = 0;
			return *this;
		}

		T& operator[](size_t index) {
			return const_cast<T&>(const_cast<const Vector&>(*this).operator[](index));
		}

		const T& operator[](size_t index) const {
			if (index >= size()) {
				throw std::out_of_range("Operator[]() out of range!");
			}
			return vec[index];
		}


		void push_back(T val) {
			add_capacity();
			allocator.construct(vec + size(), std::move(val));
			++m_size;
		}

		void pop_back() {
			if (empty()) {
				throw std::out_of_range("Pop_back() out of range!");
			}
			allocator.destroy(vec + size() - 1);
			--m_size;
		}

		template<typename ...Args>
		void emplace_back(Args &&...args) {
			add_capacity();
			allocator.construct(vec + size(), std::forward<Args>(args)...);
			++m_size;
		}

		T& front() {
			return const_cast<T&>(const_cast<const Vector&>(*this).front());
		}

		const T& front() const {
			if (empty()) {
				throw std::out_of_range("Front() out of range!");
			}
			return vec[0];
		}

		T& back() {
			return const_cast<T&>(const_cast<const Vector&>(*this).back());
		}

		const T& back() const {
			if (empty()) {
				throw std::out_of_range("Operator[] out of range!");
			}
			return vec[size() - 1];
		}

		iterator insert(iterator iter, T val) {
			if (end() < iter || iter < begin()) {
				throw std::out_of_range("Insert out of range!");
			}
			size_t from_end = end() - iter; //距离end的长度
			add_capacity();
			if (!from_end) {
				//要在end处添加元素，直接添加
				allocator.construct(vec + size(), std::move(val));
				++m_size;
				return begin() + size();
			}
			//要在其他位置添加元素
			//在end处先构造一个元素
			allocator.construct(vec + size(), std::move(vec[size() - 1]));
			//移动from_end - 1个元素
			int i = 1;
			for (; i < from_end; ++i) {
				vec[size() - i] = std::move(vec[size() - i - 1]);
			}
			vec[size() - i] = std::move(val);
			++m_size;
			return end() - from_end - 1;
		}

		template<typename ...Args>
		iterator emplace(iterator iter, Args &&...args) {
			if (end() < iter || iter < begin()) {
				throw std::out_of_range("Insert out of range!");
			}
			size_t from_end = end() - iter;
			add_capacity();
			if (!from_end) {
				allocator.construct(vec + size(), std::forward<Args>(args)...);
				++m_size;
				return begin() + size();
			}
			allocator.construct(vec + size(), std::move(vec[size() - 1]));
			int i = 1;
			for (; i < from_end; ++i) {
				vec[size() - i] = std::move(vec[size() - i - 1]);
			}
			allocator.destroy(vec + size() - i);
			allocator.construct(vec + size() - i, std::forward<Args>(args)...);
			++m_size;
			return end() - from_end - 1;
		}

		size_t size() const {
			return m_size;
		}

		size_t capacity() const {
			return m_capacity;
		}
		
		bool empty() const {
			return !size();
		}

		iterator erase(const iterator& iter) {
			if (end() < iter || end() == iter || iter < begin()) {
				throw std::out_of_range("Insert out of range!");
			}

			ptrdiff_t from_begin = iter - begin();
			for (int i = from_begin; i < size() - 1; ++i) {
				vec[i] = std::move(vec[i + 1]);
			}
			allocator.destroy(vec + size() - 1);
			--m_size;
			return begin() + from_begin;
		}

		void clear() {
			if (vec == nullptr)
				return;
			for (int i = m_size - 1; i >= 0; --i) {
				allocator.destroy(vec + i);
			}
			allocator.deallocate(vec, capacity());
			m_size = 0;
			m_capacity = 0;
			vec = nullptr;
		}

		iterator begin() {
			return iterator(vec);
		}

		iterator end() {
			return iterator(vec + size());
		}

		const_iterator cbegin() const {
			return const_iterator(vec);
		}

		const_iterator cend() const {
			return const_iterator(vec + size());
		}

	};
}