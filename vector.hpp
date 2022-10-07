/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:50:06 by agachet           #+#    #+#             */
/*   Updated: 2022/10/05 16:18:06 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <stdexcept>
#include "reverse_iterator.hpp"
#include "vectorIterator.hpp"
#include "iterator_trait.hpp"
#include "utils.hpp"

namespace ft {
    template < class T, class Alloc = std::allocator<T> >
    class vector {

    public:
        typedef T												value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::size_type				size_type;
		typedef typename allocator_type::difference_type		difference_type;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef VectorIterator<pointer>					    	iterator;
		typedef VectorIterator<const_pointer>			    	const_iterator;
		typedef ft::reverse_iterator<iterator>				    reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		    const_reverse_iterator;

        explicit vector (const allocator_type& myAlloc = allocator_type()) : _myAlloc(myAlloc), _vecSize(0) , _capacity(0) {}

        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& myAlloc = allocator_type()) : _myAlloc(myAlloc), _vecSize(n), _capacity(n) {
            _array = _myAlloc.allocate(n);
            for (unsigned int i = 0; i < n; i++)
                _array[i] = val;
        }

       template <class InputIterator>
       vector (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()) : _vecSize(0), _myAlloc(alloc) {
            InputIterator tmpFirst = first;

            for (first; first != last; first++) {
                this->_vecSize++;
                this->_capacity = this->_vecSize;
            }
            _array = this->_myAlloc.allocate(this->_vecSize);
            for (size_t i = 0; i < this->_vecSize; i++) {
                _array[i] = tmpFirst;
                tmpFirst++;
            }
       }

        vector (const vector& x) {
            this->_capacity = x._capacity;
            this->_vecSize = x._vecSize;
            this->_myAlloc = x._myAlloc;
            for (size_t i = 0; i < x._vecSize; i++)
                this->_array[i] = x._array[i];
        }

        ~vector() {
            _myAlloc.destroy(_array);
            _myAlloc.deallocate(_array, _vecSize);
        }

        vector& operator= (const vector& x) {
            _myAlloc.destroy(_array);
            _myAlloc.deallocate(_array, _vecSize);
            _array = _myAlloc.allocate(x.size());
            _vecSize = x._vecSize;
            _capacity = x._vecSize;
            for (unsigned int i = 0; i < _vecSize; i++)
                _array[i] = x._array[i];
        }

        iterator begin() {
            return (this->_array);
        }

        const_iterator begin() const {
            return this->_array;
        }

        iterator end() {
            return this->_array + _vecSize;
        }

        const_iterator end() const {
            return this->_array + _vecSize;
        }

        reverse_iterator rbegin() {
            return this->_array + _vecSize;
        }

        const_reverse_iterator rbegin() const {
            return this->_array + _vecSize;
        }

        reverse_iterator rend() {
            return this->_array;
        }

        const_reverse_iterator rend() const {
            return this->_array;
        }

        size_type size() const {
            return this->_vecSize;
        }

        size_type max_size() const {
            return this->_myAlloc.max_size();
        }

        bool empty() const {
            if (_vecSize <= 0)
                return true;
            return false;
        }

        void resize (size_type n, value_type val = value_type()) {
            pointer tmp = _myAlloc.allocate(n);
            size_t i;

            this->_vecSize = n;
            for (i = 0; i < n || i < this->_vecSize; i++)
                tmp[i] = this->_array[i];
            if (n > this->_capacity * 2)
                this->_capacity = n;
            else if (n > this->_capacity)
                this->_capacity *= 2;
            reallocArray(this->_capacity);
            i = 0;
            for (i = 0; i < n || i < this->_vecSize; i++)
                this->_array[i] = tmp[i];
            for (i = 0; i < n; i++)
                this->_array[i] = val;
            this->_array[i] = NULL;
            _myAlloc.destroy(tmp);
            _myAlloc.deallocate(tmp, n);
        }

        size_type capacity() const {
            return this->_capacity;
        }

        void reserve (size_type n) {
            pointer tmp = _myAlloc.allocate(n);

            if (n > this->_capacity) {
                this->_capacity = n;
                for (size_t i = 0; i < this->_vecSize; i++)
                    tmp[i] = this->_array[i];
                reallocArray(n);
                for (size_t i = 0; i < this->_vecSize; i++)
                    this->_array[i] = tmp[i];
            }
            _myAlloc.destroy(tmp);
            _myAlloc.deallocate(tmp, n);
        }

        reference front() {
            return _array[0];
        }

        const_reference front() const {
            return _array[0];
        }

        reference back() {
            return _array[this->_vecSize - 1];
        }

        const_reference back() const {
            return _array[this->_vecSize - 1];
        }

        reference operator[] (size_type n) {
            return _array[n];
        }

        const_reference operator[] (size_type n) const {
            return _array[n];
        }

        reference at (size_type n) {
            if (n >= this->_vecSize)
                throw std::out_of_range("n too high.");
            else
                return _array[n];
        }

        const_reference at (size_type n) const {
            if (n >= this->_vecSize)
                throw std::out_of_range("n too high.");
            else
                return _array[n];
        }

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = 0) {
            InputIterator tmpFirst = first;
            size_t newSize = 0;

            for (first; first != last; first++) {
                newSize++;
            }
            first = tmpFirst;
            if (newSize > _capacity) {
                reallocArray(newSize);
                this->_capacity = newSize;
                this->_vecSize = newSize;
            }
            std::cout << *first << std::endl;
            for (size_t i = 0; first != last; first++) {
                this->_array[i] = *first;
                i++;
            }
        }

        void assign (size_type n, const value_type& val) {
            if (n > _capacity) {
                reallocArray(n);
                this->_capacity = n;
                this->_vecSize = n;
            }
            for (size_t i = 0; i < n; i++)
                this->_array[i] = val;
        }

        iterator insert (iterator position, const value_type& val) {
     		size_type pos = position - this->begin();
			if (this->_vecSize == this->_capacity)
				realloc(this->_capacity * 2);
			for (size_type i = this->_vecSize; i > pos; i--) {
				this->_myAlloc.construct(this->_array + i, *(this->_array + i - 1));
			}
			this->_myAlloc.construct(this->_array + pos, val);
			this->_vecSize += 1;
			return (this->begin() + pos);
        }

        void insert (iterator position, size_type n, const value_type& val) {
            size_type pos = position - this->begin();
			if (this->_vecSize + n > this->_capacity) {
				if (n > this->_vecSize) {
					if (n <= (this->_capacity * 2))
						realloc(this->_capacity * 2);
					else
						realloc(this->_vecSize + n);
				}
			}
			position = iterator(this->_array + pos);
			for (size_type i = 0; i < n; i++)
			position = this->insert(position, val);
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = 0) {
            size_type index = position - begin();
			if (index <= _capacity) {
				value_type *tmp = _array;
				size_type	size_tmp = _vecSize;
				size_type	capacity_tmp = _capacity;
				_array = _myAlloc.allocate(_capacity);
				for (size_type i = 0; i < index; i++) {
					_myAlloc.construct(&_array[i], tmp[i]);
					_myAlloc.destroy(&tmp[i]);
				}
				_vecSize = index;
				for (first; first != last; first++)
					push_back(*first);
				for (size_type i = index; i < size_tmp; i++) {
					push_back(tmp[i]);
					_myAlloc.destroy(&tmp[i]);
				}
				_myAlloc.deallocate(tmp, capacity_tmp);
			}
        }

        iterator erase (iterator position) {
            pointer tmp = _myAlloc.allocate(this->_capacity);
            size_type pos = position - this->begin();
            size_type j = 0;

            for (size_t i = 0; i < this->_vecSize; i++)
                tmp[i] = this->_array[i];
            for (size_t i = 0; i < this->_vecSize; i++) {
                if (i == pos)
                    i++;
                this->_array[j] = tmp[i];
                j++;
            }
            this->_vecSize--;
            _myAlloc.destroy(tmp);
            _myAlloc.deallocate(tmp, _capacity);
            return this->_array[pos];
        }

        iterator erase (iterator first, iterator last) {
            pointer tmp = _myAlloc.allocate(this->_capacity);
            size_type posFirst = first - this->begin();
            size_type posLast = last - this->begin();
            size_t j = 0;

            for (size_t i = 0; i < this->_vecSize; i++)
                tmp[i] = this->_array[i];
            for (size_t i = 0; i < this->_vecSize; i++) {
                if (i == posFirst)
                    for (posFirst; posFirst < posLast; posFirst++)
                        i++;
                this->_array[j] = tmp[i];
                j++;
            }
            this->_vecSize -= (posLast - posFirst);
            _myAlloc.destroy(tmp);
            _myAlloc.deallocate(tmp, _capacity);
            return this->_array[pos];
        }

        void push_back (const value_type& val) {
            pointer tmp = _myAlloc.allocate(this->_capacity);
            size_type tmpSize = this->_capacity;

            if (this->_vecSize + 1 > this->_capacity) {
                for (size_t i = 0; i < this->_vecSize; i++)
                    tmp[i] = this->_array[i];
                if (this->_capacity == 0) {
                    reallocArray(1);
                    this->_capacity = 1;
                }
                else {
                    reallocArray(this->_capacity * 2);
                    this->_capacity *= 2;
                }
                for (size_t i = 0; i < this->_vecSize; i++)
                    this->_array[i] = tmp[i];
            }
            this->_array[_vecSize] = val;
            this->_vecSize++;
            _myAlloc.destroy(tmp);
            _myAlloc.deallocate(tmp, tmpSize);
        }

        void pop_back() {
           // this->_myAlloc.destroy(_array);
            this->_vecSize--;
        }

        void clear() {
            _myAlloc.destroy(_array);
            this->_vecSize = 0;
        }

        void swap (vector& x) {
            pointer tmp = this->_array;
            size_t tmpSize = this->_vecSize;
            size_t tmpCapacity = this->_capacity;

            this->_array = x._array;
            this->_vecSize = x.size();
            this->_capacity = x.capacity();

            x._array = tmp;
            x._vecSize = tmpSize;
            x._capacity = tmpCapacity;
        }

        allocator_type get_allocator() const {
            return this->_myAlloc;
        }

        template <class _T, class _Alloc>
        friend bool operator== (const vector<_T,_Alloc>& lhs, const vector<_T,_Alloc>& rhs);

        private:

        void cutInsert(size_type n) {
            if (this->_vecSize + n > this->_capacity) {
                if (this->_capacity == 0) {
                    reallocArray(n);
                    this->_capacity = n;
                }
                else if (this->_capacity * 2 < this->_vecSize + n) {
                    reallocArray(this->_vecSize + n);
                    this->_capacity = this->_vecSize + n;
                }
                else {
                    reallocArray(this->_capacity * 2);
                    this->_capacity *= 2;
            std::cout << "size: " << this->size() << " capacity: " << this->capacity() << std::endl;
                }
            }
        }

    	void realloc(size_type n) {
			value_type *new_i = _myAlloc.allocate(n);
			for (size_type i = 0; i < _vecSize; i++)
				_myAlloc.construct(&new_i[i], _array[i]);
			deallocate();
			_array = new_i;
			_capacity = n;
		}

        void deallocate(void) {
			for (size_t i = 0; i < this->_vecSize; i++) {
				this->_myAlloc.destroy(this->_array + i);
			}
			this->_myAlloc.deallocate(this->_array, this->_capacity);
		}

        void reallocArray(size_type new_size) {
            if (this->_capacity > 0) {
                _myAlloc.destroy(_array);
                _myAlloc.deallocate(_array, this->_capacity);
            }
            _array = _myAlloc.allocate(new_size);
        }

        protected:
            pointer         _array;
            allocator_type  _myAlloc;
            size_t	        _vecSize;
            size_t          _capacity;

    };

    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        if (lhs.size() == rhs.size()) {
            for (size_t i = 0; i < lhs.size(); i++) {
                if (lhs._array[i] != rhs._array[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
            if (lhs == rhs)
                return false;
            return true;
    }

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (!(lhs < rhs));
	}

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
        x.swap(y);
    }
}

#endif
