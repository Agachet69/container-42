/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:57:26 by agachet           #+#    #+#             */
/*   Updated: 2022/09/14 19:57:26 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

# include <memory>
#include "iterator_trait.hpp"

namespace ft {
    template <class Iterator> class reverse_iterator {
    public:
        typedef Iterator                                                    iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category  iterator_category;
        typedef typename iterator_traits<Iterator>::value_type              value_type;
        typedef typename iterator_traits<Iterator>::difference_type         difference_type;
        typedef typename iterator_traits<Iterator>::pointer                 pointer;
        typedef typename iterator_traits<Iterator>::reference               reference;
    
        reverse_iterator() : _ourIt(), _copyIt() {}
            
        explicit reverse_iterator (iterator_type it) : _ourIt(it), _copyIt(it) {}

        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it) :  _ourIt(rev_it), _copyIt(rev_it) {}

        ~reverse_iterator() {}

        iterator_type base() const {
            return (_ourIt + 1); // à tester si sa renvoi bien la position +1 et pas le resultat +1
        }

        reference operator*() const {
            return(*_ourIt);
        }

        reverse_iterator operator+ (difference_type n) const {
            return reverse_iterator(_ourIt - n);
        }
        
        reverse_iterator& operator++() {
            _ourIt--;
            return *this;
        }

        reverse_iterator  operator++(int) {
            reverse_iterator Tmp = *this;
            --_ourIt;
            return Tmp;
        }

        reverse_iterator& operator+= (difference_type n) {
            _ourIt -= n;
            return *_ourIt;
        }

        reverse_iterator operator- (difference_type n) const {
            return _ourIt - n;
        }

        reverse_iterator& operator--() {
            _ourIt++;
            return *this;
        }

        reverse_iterator  operator--(int) {
            reverse_iterator Tmp = *this;
            ++_ourIt;
            return Tmp;
        }

        reverse_iterator& operator-= (difference_type n) {
            _ourIt -= n;
            return *_ourIt;
        }

        pointer operator->() const {
            return &(operator*());
        }

        reference operator[] (difference_type n) const {
            return _ourIt[static_cast<difference_type>(-n - 1)];
        }
        
        iterator_type get_ourIt() const {
            return (_ourIt);
        }

        private:
            iterator_type _ourIt;
            iterator_type _copyIt;

    };

    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        if (lhs.base() == rhs.base())
            return true;
        return false;
    }

    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        if (lhs.base() != rhs.base())
            return true;
        return false;
    }

    template <class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        if (lhs.get_ourIt() < rhs.get_ourIt())
            return false;
        return true;
    }

    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        if (lhs.get_ourIt() >= rhs.get_ourIt())
            return true;
        return false;
    }

    template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            if (lhs.get_ourIt() > rhs.get_ourIt())
            return false;
        return true;
    }

    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        if (lhs.get_ourIt() <= rhs.get_ourIt())
            return true;
        return false;
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
        return rev_it.base() + n;
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        return lhs.base() - rhs.base();
    }
}

#endif