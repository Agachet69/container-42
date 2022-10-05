/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIteratorMap.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:03:34 by agachet           #+#    #+#             */
/*   Updated: 2022/10/05 20:16:32 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATORMAP_HPP
#define REVERSEITERATORMAP_HPP

#include "binarySearchTree.hpp"

namespace ft {
    template <class iter, class T>
	class reverse_iterator_m {
		public:
			typedef iter         						value_type;
			typedef std::ptrdiff_t  					difference_type;
			typedef T*   								pointer;
			typedef T& 									reference;

			value_type *_ptr;

		public:

			reverse_iterator_m(): _ptr(nullptr) {}

			reverse_iterator_m(const reverse_iterator_m &x) {
				*this = x;
			}

			reverse_iterator_m(value_type *x): _ptr(x) {}

			~reverse_iterator_m() {}

			value_type *get_internal_pointer(void) const {
				return _ptr;
			}

			reverse_iterator_m &operator=(const reverse_iterator_m &x) {
				if (this != &x)
					_ptr = x._ptr;
				return (*this);
			}

			bool operator==(const reverse_iterator_m &x) {
				return (_ptr == x._ptr);
			}

			bool operator!=(const reverse_iterator_m &x) {
				return (_ptr != x._ptr);
			}

			reference operator*() const {
				return (_ptr->_value);
			}

			pointer operator->() const {
				return (&_ptr->_value);
			}

			reverse_iterator_m &operator++() {
				_ptr = _ptr->prev();
				return (*this);
			}

			reverse_iterator_m operator++(int) {
				reverse_iterator_m tmp(*this);
				_ptr = _ptr->prev();
				return (tmp);
			}

			reverse_iterator_m &operator--() {
				_ptr = _ptr->next();
				return *this;
			}

			reverse_iterator_m operator--(int) {
				reverse_iterator_m tmp(*this);
				_ptr = _ptr->next();
				return tmp;
			}
	};

	template <class iter, class T, class reverse_iterator>
	class const_reverse_iterator {
		public:
			typedef iter         					value_type;
			typedef std::ptrdiff_t  				difference_type;
			typedef T*   							pointer;
			typedef T& 								reference;

		protected:
			value_type *_ptr;

		public:
			const_reverse_iterator(): _ptr(nullptr) {}

			const_reverse_iterator(const const_reverse_iterator &x) {
				*this = x;
			}

			const_reverse_iterator(pointer x): _ptr(x) {}

			const_reverse_iterator(const reverse_iterator &other) {
				_ptr = other.get_internal_pointer();
			}

			~const_reverse_iterator() {}

			value_type *get_internal_pointer(void) const {
				return _ptr;
			}

			const_reverse_iterator &operator=(const const_reverse_iterator &x) {
				if (this != &x)
					_ptr = x._ptr;
				return (*this);
			}

			bool operator==(const const_reverse_iterator &x) const {
				return (_ptr == x._ptr);
			}

			bool operator!=(const const_reverse_iterator &x) const {
				return (_ptr != x._ptr);
			}

			reference operator*() const {
				return (_ptr->_value);
			}

			const pointer operator->() const {
				return (&_ptr->_value);
			}

			const_reverse_iterator &operator++() {
				_ptr = _ptr->prev();
				return (*this);
			}

			const_reverse_iterator operator++(int) {
				const_reverse_iterator tmp(*this);
				_ptr = _ptr->prev();
				return (tmp);
			}

			const_reverse_iterator &operator--() {
				_ptr = _ptr->next();
				return *this;
			}

			const_reverse_iterator operator--(int) {
				const_reverse_iterator tmp(*this);
				_ptr = _ptr->next();
				return tmp;
			}
	};
}

#endif
