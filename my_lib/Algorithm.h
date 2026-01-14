#pragma once

#include <iostream>
#include <random>
#include <cassert>
#include <ctime>
#include <cstring>
#include <memory>

namespace lib {
	int test_arr(int *&arr) {
		std::default_random_engine e((unsigned int)time(NULL));
		std::uniform_int_distribution<int> num_u(1, 1000000);
		std::uniform_int_distribution<int> member_u(INT_MIN, INT_MAX);
		/*std::uniform_int_distribution<int> num_u(1, 10);
		std::uniform_int_distribution<int> member_u(0, 50);*/
		int num = num_u(e);

		arr = new int[num] {};
		for (int i = 0; i < num; ++i) {
			arr[i] = member_u(e);
		}
		return num;

	}

	template<typename T>
	void quick_sort(T *arr, int beg, int end) {
		if (beg >= end) {
			return;
		}

		T val = arr[beg];
		int left = beg;
		int right = end;
		while (left != right) {
			while (left < right && arr[right] >= val) {
				--right;
			}
			if (left >= right) {
				break;
			}
			arr[left++] = arr[right];
			while (left < right && arr[left] <= val) {
				assert(right >= beg && right <= end);
				++left;
			}
			if (left >= right) {
				break;
			}
			arr[right--] = arr[left];
		}

		arr[left] = val;
		quick_sort(arr, beg, left - 1);
		quick_sort(arr, left + 1, end);
	}

	//快速排序
	template<typename T>
	void quick_sort(T arr, int num) {
		if (!arr || num <= 1)
			return;
		quick_sort(arr, 0, num - 1);
	}

	template<typename T>
	void recursive_sort(T* arr, int beg, int end) {
		if (beg >= end) {
			return;
		}
		int num = end - beg;
		int mid = beg + (num - 1) / 2;
		recursive_sort(arr, beg, mid);
		recursive_sort(arr, mid + 1, end);
		T* tmp = new T[num]{};
		int fir = beg;
		int sec = mid + 1;
		int i = 0;
		while (fir <= mid && sec <= end) {
			tmp[i++] = arr[fir] <= arr[sec] ? arr[fir++] : arr[sec++];
		}
		int last_beg = fir > mid ? sec : fir;
		int last_end = fir > mid ? end : mid;
		while (last_beg <= last_end) {
			tmp[i++] = arr[last_beg++];
		}
		i = 0;
		for (int j = beg; j <= end; ++j) {
			arr[j] = tmp[i++];
		}
		delete[] tmp;
	}

	//归并排序
	template<typename T>
	void recursive_sort(T *arr, int n) {
		if (!arr || n <= 1)
			return;
		recursive_sort(arr, 0, n - 1);
	}
	
	//建立next数组
	inline std::unique_ptr<int[]> get_next(const char *str, int n) {
		std::unique_ptr<int[]> next(new int[n]);
		next[0] = -1;
		if (n == 1) {
			return next;
		}
		next[1] = 0;
		int j = 0;
		for (int i = 2; i < n;) {
			if (str[j] == str[i - 1]) {
				next[i++] = ++j;
			}
			else {
				j = next[j];
				if (j == -1) {
					++j;
					next[i++] = 0;
				}
			}
		}
		return next;
	}

	//KMP查找
	//从str1查找str2
	inline int str_find(const char* str1, const char* str2) {
		if (!str1 && !str2) {
			return -1;
		}
		if (!str1 || !str2) {
			return -1;
		}
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		if (len1 < len2) {
			return -1;
		}
		if (len2 == 0) {
			return 0;
		}
		std::unique_ptr<int[]> next(get_next(str2, len2));
		int cur1 = 0;
		int cur2 = 0;
		
		while (cur2 != len2 && cur1 != len1) {
			if (str1[cur1] == str2[cur2]) {
				++cur1;
				++cur2;
			}
			else {
				cur2 = next[cur2];
				if (cur2 == -1) {
					++cur1;
					++cur2;
				}
			}
		}
		if (cur2 == len2) {
			return cur1 - len2;
		}
		return -1;
	}

}