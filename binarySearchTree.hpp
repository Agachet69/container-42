/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 04:11:44 by agachet           #+#    #+#             */
/*   Updated: 2022/09/28 04:11:44 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#define BLACK 0
#define RED 1
#define LEAF NULL

#include "pair.hpp"

template<class Pair>
struct binarySearchTree {
    struct binarySearchTree *_left; //Pointeur vers fils gauche
    struct binarySearchTree *_right; //Pointeur vers fils droit 
    struct binarySearchTree *_parent; //Pointeur vers père
    Pair _value; // Peut être n'importe quel type, tant que les opérations de comparaison (<, = , > ) sont définies
    int color; // ROUGE ou NOIR

    struct binarySearchTree *_end;

    binarySearchTree() : _left(LEAF), _right(LEAF), _parent(LEAF), _value() {}

    binarySearchTree(const Pair & val) : _left(LEAF), _right(LEAF), _parent(LEAF), _value(val) {}
		
    binarySearchTree(const binarySearchTree &cpy) : _parent(cpy._parent), _left(cpy._left), _right(cpy._right), _value(cpy._value), color(cpy.color) {}

    ~binarySearchTree() {}

    binarySearchTree &operator=(const binarySearchTree &x) {
		if (this != &x) {
			_parent = x.parent;
			_left = x.left;
			_right = x.right;
			_value = x.value;
		}
		return (*this);
	}

	binarySearchTree *findMin(binarySearchTree *node) {
		if (!node)
			return LEAF;
        while (node->_left)
			node = node->_left;
		return (node);
	}

	binarySearchTree *findMax(binarySearchTree *node) {
		if (!node)
			return NULL;
		while (node->_right)
			node = node->_right;
		return (node);
	}

	binarySearchTree *next() {
		binarySearchTree* tmp = this;
		if (tmp->_right)
			return (findMin(tmp->_right));
		binarySearchTree* parent = tmp->_parent;
		while ((parent) && tmp == parent->_right) {
            tmp = parent;
            parent = tmp->_parent;
        }
		if (parent)
			return parent;
		return _end;
	}

	binarySearchTree *prev() {
    	binarySearchTree* tmp = this;
    	if (tmp->_left)
    		return findMax(tmp->_left);
    	binarySearchTree* parent = tmp->_parent;
    	while ((parent) && tmp == parent->_left){
            tmp = parent;
            parent = tmp->_parent;
        }
        return parent;
    }
};

#endif