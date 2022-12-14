/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:29:04 by agachet           #+#    #+#             */
/*   Updated: 2022/09/29 13:29:04 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "binarySearchTree.hpp"

namespace ft
{
    template <class iter, class T>
	class bidirectionnal_iterator {
		public:
			typedef iter         						value_type;
			typedef std::ptrdiff_t  					difference_type;
			typedef T*   								pointer;
			typedef T& 									reference;
			typedef std::bidirectional_iterator_tag		iterator_category;
		
			value_type *_ptr;
		
		public:
		
			bidirectionnal_iterator(): _ptr(nullptr) {}

			bidirectionnal_iterator(const bidirectionnal_iterator &x) {
				*this = x;
			}

			bidirectionnal_iterator(value_type *x): _ptr(x) {}

			~bidirectionnal_iterator() {}

			value_type *get_internal_pointer(void) const {
				return _ptr;
			}

			bidirectionnal_iterator &operator=(const bidirectionnal_iterator &x) {
				if (this != &x)
					_ptr = x._ptr;
				return (*this);
			}

			bool operator==(const bidirectionnal_iterator &x) {
				return (_ptr == x._ptr);
			}
	
			bool operator!=(const bidirectionnal_iterator &x) {
				return (_ptr != x._ptr);
			}

			reference operator*() const {
				return (_ptr->_value);
			}

			pointer operator->() const {
				return (&_ptr->_value);
			}

			bidirectionnal_iterator &operator++() {
				_ptr = _ptr->next();
				return (*this);
			}

			bidirectionnal_iterator operator++(int) {
				bidirectionnal_iterator tmp(*this);
				_ptr = _ptr->next();
				return (tmp);
			}

			bidirectionnal_iterator &operator--() {
				_ptr = _ptr->prev();
				return *this;
			}

			bidirectionnal_iterator operator--(int) {
				bidirectionnal_iterator tmp(*this);
				_ptr = _ptr->prev();
				return tmp;
			}
	};

	template <class iter, class T, class bidirectionnal_iterator>
	class const_bidirectionnal_iterator {
		public:
			typedef iter         					value_type;
			typedef std::ptrdiff_t  				difference_type;
			typedef T*   							pointer;
			typedef T& 								reference;
			typedef std::bidirectional_iterator_tag	iterator_category;
		
		protected:
			value_type *_ptr;
		
		public:
			const_bidirectionnal_iterator(): _ptr(nullptr) {}

			const_bidirectionnal_iterator(const const_bidirectionnal_iterator &x) {
				*this = x;
			}

			const_bidirectionnal_iterator(pointer x): _ptr(x) {}

			const_bidirectionnal_iterator(const bidirectionnal_iterator &other) {
				_ptr = other.get_internal_pointer();
			}

			~const_bidirectionnal_iterator() {}

			value_type *get_internal_pointer(void) const {
				return _ptr;
			}

			const_bidirectionnal_iterator &operator=(const const_bidirectionnal_iterator &x) {
				if (this != &x)
					_ptr = x._ptr;
				return (*this);
			}

			bool operator==(const const_bidirectionnal_iterator &x) const {
				return (_ptr == x._ptr);
			}

			bool operator!=(const const_bidirectionnal_iterator &x) const {
				return (_ptr != x._ptr);
			}

			reference operator*() const {
				return (_ptr->_value);
			}

			const pointer operator->() const {
				return (&_ptr->_value);
			}

			const_bidirectionnal_iterator &operator++() {
				_ptr = _ptr->next();
				return (*this);
			}

			const_bidirectionnal_iterator operator++(int) {
				const_bidirectionnal_iterator tmp(*this);
				_ptr = _ptr->next();
				return (tmp);
			}

			const_bidirectionnal_iterator &operator--() {
				_ptr = _ptr->prev();
				return *this;
			}

			const_bidirectionnal_iterator operator--(int) {
				const_bidirectionnal_iterator tmp(*this);
				_ptr = _ptr->prev();
				return tmp;
			}
	};
}

#endif