/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:16:44 by agachet           #+#    #+#             */
/*   Updated: 2022/10/06 20:43:36 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"
#include "pair.hpp"
#include "reverseIteratorMap.hpp"
#include "binarySearchTree.hpp"
#include "bidirectional_iterator.hpp"


namespace ft {
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map {

        public:
            typedef Key                                                                 	key_type;
            typedef T                                                                   	mapped_type;
            typedef ft::pair<const key_type,mapped_type>                                	value_type;
            typedef Compare                                                             	key_compare;
            typedef Alloc                                                               	allocator_type;
            typedef typename allocator_type::reference                                  	reference;
            typedef typename allocator_type::const_reference                            	const_reference;
            typedef typename allocator_type::pointer                                    	pointer;
            typedef typename allocator_type::const_pointer                              	const_pointer;
            typedef binarySearchTree<value_type>                                        	node;
            typedef ft::bidirectionnal_iterator<node, value_type>					    	iterator;
	    	typedef ft::const_bidirectionnal_iterator<node, const value_type, iterator> 	const_iterator;
	    	typedef ft::reverse_iterator_m<node, value_type>							    reverse_iterator;
	    	typedef ft::const_reverse_iterator<node, const value_type, reverse_iterator>	const_reverse_iterator;
	    	typedef std::ptrdiff_t 												        	difference_type;
	    	typedef size_t 														        	size_type;
            typedef typename Alloc::template rebind<node>::other                        	allocator_node;

        protected:
            node                *_root;
            node                *_end;
            node                *_revBegin;
            key_compare         _comp;
            allocator_type      _allocPair;
            allocator_node      _allocNode;
            size_t              _sizeMap;


        public:
            class value_compare {
                friend class map;
                protected:
                    key_compare comp;
                    value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator() (const value_type& x, const value_type& y) const {
                        return comp(x.first, y.first);
                    }
            };

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _sizeMap(0), _root(LEAF), _comp(comp), _allocPair(alloc), _allocNode(std::allocator<node>()) {
				_end = _allocNode.allocate(1);
				_allocNode.construct(_end, node());
                _revBegin = _allocNode.allocate(1);
			    _allocNode.construct(_revBegin, node());
                _revBegin->_end = _end;
                _revBegin->_parent = _end;
                _root = NULL;
            }

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _sizeMap(0), _comp(comp), _allocPair(alloc), _allocNode(std::allocator<node>()) {
                _end = _allocNode.allocate(1);
			    _allocNode.construct(_end, node());
                _revBegin = _allocNode.allocate(1);
			    _allocNode.construct(_revBegin, node());
                _revBegin->_end = _end;
                _revBegin->_parent = _end;
                _root = NULL;
				while (first != last) {
                    insert(*first);
					first++;
				}
            }

            map (const map& x) : _comp(x._comp), _allocPair(x._allocPair), _allocNode(x._allocNode), _root(NULL), _sizeMap(0) {
                _end = _allocNode.allocate(1);
    			_allocNode.construct(_end, node());
    			_revBegin = _allocNode.allocate(1);
    			_allocNode.construct(_revBegin, node());
                _revBegin->_end = _end;
                _revBegin->_parent = _end;
                _root = NULL;
    			clear(); /* verif */
    			this->insert(x.begin(), x.end());
            }

            //~map() {
            //    clear();
			//    _allocNode.destroy(_end);
			//    _allocNode.deallocate(_end, 1);
			//    _allocNode.destroy(_revBegin);
			//    _allocNode.deallocate(_revBegin, 1);
            //}

            map& operator= (const map& x) {
				//clear(); a verif
                _comp = x._comp;
                _sizeMap = 0;
                _allocPair = x._allocPair;
                _allocNode = x._allocNode;
                _end = x._end;
				const_iterator beg = x.begin();
				const_iterator endx = x.end();
				if (beg != endx)
                	insert(beg, endx);
                return (*this);
            }

            iterator begin() {
                node *tmp = _root;
                if (!tmp)
					return this->end();
				while (tmp && tmp->_left != LEAF) {
                   tmp = tmp->_left;
                }
                return iterator(tmp);
            }

            const_iterator begin() const {
                node *tmp = _root;
                if (!tmp)
					return this->end();
				while (tmp && tmp->_left != LEAF) {
                    tmp = tmp->_left;
                }
                return const_iterator(tmp);
            }

            iterator end() {
                return iterator(_end);
            }

            const_iterator end() const {
                return const_iterator(_end);
            }

            reverse_iterator rbegin() {
				node *tmp = _root;
        	    if (!tmp)
					return reverse_iterator(_end);
				while (tmp && tmp->_right != LEAF) {
        	        tmp = tmp->_right;
        	    }
        	    return reverse_iterator(tmp);
			    // return (reverse_iterator(_end));
		    }

            const_reverse_iterator rbegin() const {
    		 	node *tmp = _root;
        	    if (!tmp)
					return reverse_iterator(_end);
				while (tmp && tmp->_right != LEAF) {
        	        tmp = tmp->_right;
        	    }
				return (const_reverse_iterator(tmp));
    		}

    		reverse_iterator rend() {
    		 	return (reverse_iterator(_end));
    		}

    		const_reverse_iterator rend() const {
    			return (const_reverse_iterator(_end));
    		}

            bool empty() const {
                if (this->_sizeMap == 0)
                    return true;
                return false;
            }

            size_type size() const {
                return (this->_sizeMap);
            }

            size_type max_size() const {
                return (std::numeric_limits<size_type>::max() / sizeof(node));
            }

            mapped_type& operator[] (const key_type& k) {
			   return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
            }

            pair<iterator,bool> insert (const value_type& val) {
                iterator finded = this->find(val.first);

                if (finded == _end) {
                	node *new_node = _allocNode.allocate(1);
					_allocNode.construct(new_node, node(val));
                    if (recursiveInsert(this->_root, new_node) == 0) {
                		insertFixTree(new_node);
                    	this->_sizeMap++;
                    }
                	this->_root = getRoot(new_node);
                    new_node->_end = _end;
                    return (ft::make_pair(new_node, true));
                }
                return ft::make_pair(iterator(finded), false);
            }

            iterator insert (iterator position, const value_type& val) {
				(void) position;
			    return (insert(val).first);
            }

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last) {
				   while (first != last) {
                	insert (*first);
					first++;
			   	}
            }

            void erase (iterator position) {
                if (find(position._ptr->_value.first) == _end)
                    return;
                del(position._ptr);
                //_allocNode.destroy(position._ptr);
			    //_allocNode.deallocate(position._ptr, 1);
                this->_root = getRoot(_root);
                this->_sizeMap--;
            }

            size_type erase (const key_type& k) {
                iterator delNode = find(k);
                if (delNode == _end)
                    return 0;
                del(delNode._ptr);
                //_allocNode.destroy(delNode._ptr);
			    //_allocNode.deallocate(delNode._ptr, 1);
                this->_sizeMap--;
                this->_root = getRoot(_root);
                return 1;
            }

            void erase (iterator first, iterator last) {
                while (first != last) {
                    if (find(first._ptr->_value.first) != _end) {
                        del(first._ptr);
                        _allocNode.destroy(first._ptr);
			            _allocNode.deallocate(first._ptr, 1);
                        this->_sizeMap--;
                        this->_root = getRoot(_root);
						first++;
                    }
                }
            }

        void clear() {
            this->erase(this->begin(), this->end());
        }

        void swap (map& x) {
            node	    *tmp;
			size_type   size_tmp;

			tmp = x._root;
			x._root = _root;
			_root = tmp;

			tmp = x._end;
			x._end = _end;
			_end = tmp;

			tmp = x._revBegin;
			x._revBegin = _revBegin;
			_revBegin = tmp;

			size_tmp = x._sizeMap;
			x._sizeMap = _sizeMap;
			_sizeMap = size_tmp;
        }

        size_type count (const key_type& k) const {
                if ((find(k)) == iterator(_end))
                    return 0;
                return 1;
            }

        iterator find (const key_type& k) {
                node *tmp = _root;

                while (tmp != LEAF) {
                    if (_comp(tmp->_value.first, k))
                        tmp = tmp->_right;
                    else if (_comp(k, tmp->_value.first))
                        tmp = tmp->_left;
                    else
                        return iterator(tmp);
                }

                return iterator(_end);
            }

        const_iterator find (const key_type& k) const {
            node *tmp = _root;
            while (tmp != LEAF) {
                if (_comp(tmp->_value.first, k))
                    tmp = tmp->_right;
                else if (_comp(k, tmp->_value.first))
                    tmp = tmp->_left;
                else
                    return const_iterator(tmp);
            }
            return const_iterator(_end);
        }

        pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
            const_iterator first = lower_bound(k);
			const_iterator second = upper_bound(k);
			return (make_pair(first, second));
        }

        pair<iterator,iterator> equal_range (const key_type& k) {
	        iterator first = lower_bound(k);
			iterator second = upper_bound(k);
			return (make_pair(first, second));
        }

        iterator lower_bound (const key_type& k) {
            key_compare compare = key_compare();
			for (iterator i = begin(); i != end(); i++) {
				if (!compare(i->first, k))
					return (i);
			}
			return (end());
        }

        const_iterator lower_bound (const key_type& k) const {
            key_compare compare = key_compare();
			for (const_iterator i = begin(); i != end(); i++) {
				if (!compare(i->first, k))
					return (i);
			}
			return (end());
        }

        iterator upper_bound (const key_type& k) {
			key_compare compare = key_compare();
			for (iterator i = begin(); i != end(); i++) {
				if (compare(k, i->first))
					return (i);
			}
			return (end());
		}

		const_iterator upper_bound (const key_type& k) const {
			key_compare compare = key_compare();
			for (const_iterator i = begin(); i != end(); i++) {
				if (compare(k, i->first))
					return (i);
			}
			return (end());
		}

        allocator_type get_allocator() const {
            allocator_type allocator_copy(_allocPair);
			return (allocator_copy);
        }

        key_compare key_comp() const {
            return (key_compare(_comp));
        }

        value_compare value_comp() const {
            return (value_compare(_comp));
        }

        private:
            void del(node *delNode) {
				bool bothBlack = false;
				node *replaceNode = findReplaceNode(delNode);
				node *parent = delNode->_parent;

				if ((replaceNode == LEAF || replaceNode->color == BLACK) && delNode->color == BLACK)
					bothBlack = true;
				if (!replaceNode) {
					if (delNode == _root)
						_root = NULL;
					else {
						if (bothBlack)
							fixBothBlack(delNode);
						else
							if (ft_frere(delNode))
								ft_frere(delNode)->color = RED;
						if (delNode == delNode->_parent->_left)
							delNode->_parent->_left = LEAF;
						else
							delNode->_parent->_right = LEAF;
					}
					return;
				}
				if ((!delNode->_left) || (!delNode->_right)) {
					if (delNode == _root) {
						replaceNode->_parent = NULL;
						replaceNode->color = BLACK;
						_root = replaceNode;
					}
					else {
						if (delNode->_parent->_left == delNode)
							parent->_left = replaceNode;
						else
							parent->_right = replaceNode;
						replaceNode->_parent = parent;
						if (bothBlack)
							fixBothBlack(replaceNode);
						else
							replaceNode->color = BLACK;
					}
					return;
				}
				value_type tmp = replaceNode->_value;
				/*node *newReplace*/ replaceNode = swapValue(replaceNode, delNode->_value);
				/*node *newDelNode*/ delNode = swapValue(delNode, tmp);
				del(replaceNode);
            }

			node *findReplaceNode(node *delNode) {
				if (delNode->_right && delNode->_left)
					return findSuccesor(delNode->_right);
				else if (delNode->_right == LEAF && delNode->_left == LEAF)
					return NULL;
				else if (delNode->_right)
					return delNode->_right;
				else
					return delNode->_left;
			}

			node *findSuccesor(node *x) {
				node *tmp = x;

				while (tmp->_left)
					tmp = tmp->_left;
				return tmp;
			}

			void fixBothBlack(node *xNode) {
				if (xNode == _root)
					return;
				node *brother = ft_frere(xNode);
				node *parent = ft_parent(xNode);
				if (!brother)
					fixBothBlack(parent);
				else {
					if (brother->color == RED) {
						brother->color = BLACK;
						parent->color = RED;
						if (brother->_parent->_left == brother)
							rightRotation(parent);
						else
							leftRotation(parent);
						fixBothBlack(xNode);
					}
					else {
						if ((brother->_left && brother->_left->color == RED) || (brother->_right && brother->_right->color == RED)) {
							if (brother->_left && brother->_left->color == RED) {
								if (brother->_parent->_left == brother) {
									brother->_left->color = brother->color;
									brother->color = parent->color;
									rightRotation(parent);
								}
								else {
									brother->_left->color = parent->color;
									rightRotation(brother);
									leftRotation(parent);
								}
							}
							else {
								if (brother->_parent->_left == brother) {
									brother->_right->color = parent->color;
									leftRotation(brother);
									rightRotation(parent);
								}
								else {
									brother->_right->color = brother->color;
									brother->color = parent->color;
									leftRotation(parent);
								}
							}
							parent->color = BLACK;
						}
						else {
							brother->color = RED;
							if (parent->color == BLACK)
								fixBothBlack(parent);
							else
								parent->color = BLACK;

						}
					}
				}
			}

			node *swapValue(node *first, value_type value) {
				node *newFirst = _allocNode.allocate(1);
				_allocNode.construct(newFirst, node(value));
				newFirst->color = first->color;
				newFirst->_left = first->_left;
				newFirst->_right = first->_right;
				newFirst->_parent = first->_parent;
				if (newFirst->_left)
					newFirst->_left->_parent = newFirst;
				if (newFirst->_right)
					newFirst->_right->_parent = newFirst;
				if (first->_parent) {
					if (first == first->_parent->_left)
						first->_parent->_left = newFirst;
					else
						first->_parent->_right = newFirst;
				}
				_allocNode.destroy(first);
			    _allocNode.deallocate(first, 1);
				return newFirst;
			}

            node* ft_parent(node* n) {
                return n->_parent;
            }

            node* ft_grandparent(node* n) {
               node* parent = ft_parent(n);
                if (parent == NULL)
                    return NULL;
                return ft_parent(parent);
            }

            node* ft_frere(node* n) {
                node* parent = ft_parent(n);
                if (parent == NULL)
                    return NULL; // Un noeud sans parent n'a pas de frere
                if (n == parent->_left)
                    return parent->_right;
                else
                    return parent->_left;
            }

            node* ft_oncle(node* son) {
                node* parent = ft_parent(son);
                node* grandparent = ft_grandparent(son);
                if (grandparent == NULL)
                    return NULL; // Pas de grand parent, donc pas d'oncle
                return ft_frere(parent);
            }

            int recursiveInsert(node *root, node *new_node) {
                if (!_root) {
                	new_node->_parent = NULL;
                	new_node->_left = LEAF;
                	new_node->_right = LEAF;
                    this->_root = new_node;
				}
                else if (root != NULL && _comp(new_node->_value.first, root->_value.first)) {
                    if (root->_left != LEAF) {
                        if (recursiveInsert(root->_left, new_node) == -1)
                            return -1;
                        return 0;
                    }
                    else
                        root->_left = new_node;
                }
                else if (root != NULL && _comp(root->_value.first, new_node->_value.first)) {
                    if (root->_right != LEAF) {
                        if (recursiveInsert(root->_right, new_node) == -1)
                            return -1;
                        return 0;
                    }
                    else
                        root->_right = new_node;
                }
                else
                    return -1;
                new_node->_parent = root;
                new_node->_left = LEAF;
                new_node->_right = LEAF;
                new_node->color = RED;
                return (0);
            }

            void insertFixTree(node *new_node) {
                if (new_node->_parent == NULL)
                    newRootFixOne(new_node);
                else if (new_node->_parent->color == BLACK)
                    return;
                else if (ft_oncle(new_node) != NULL && ft_oncle(new_node)->color == RED)
                    changeColorFixTwo(new_node);
                else
                    rotationFixThree(new_node);
            }

            void newRootFixOne(node *new_node) {
                if (ft_parent(new_node) == NULL)
                new_node->color = BLACK;
            }

            void changeColorFixTwo(node *new_node) {
                ft_parent(new_node)->color = BLACK;
                ft_oncle(new_node)->color = BLACK;

                node *grandparent = ft_grandparent(new_node);
                grandparent->color = RED;
                insertFixTree(grandparent);
            }

            void rotationFixThree(node *new_node) {
                node *parent = ft_parent(new_node);
                node *grandparent = ft_grandparent(new_node);

                if (grandparent->_left != NULL && new_node == grandparent->_left->_right) {
                    leftRotation(parent);
                    new_node = new_node->_left;
                }
                else if (grandparent->_right != NULL && new_node == grandparent->_right->_left) {
                    rightRotation(parent);
                    new_node = new_node->_right;
                }
                rotationGparentFour(new_node);
            }

            void rotationGparentFour(node *new_node) {
                node *parent = ft_parent(new_node);
                node *grandparent = ft_grandparent(new_node);

                if (new_node == parent->_left)
                    rightRotation(grandparent);
                else
                    leftRotation(grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
            }

            void leftRotation(node* x) {
                node* y = x->_right;
                x->_right = y->_left;
                if (y->_left != LEAF)
                    y->_left->_parent = x;
                y->_parent = x->_parent;
                if (x->_parent == NULL) {
                    node *tmp = x;
                    x = y;
                    x->_left = tmp;
                    tmp->_parent = x;
                    return;
                }
                else if (x == x->_parent->_left)
                    x->_parent->_left = y;
                else
                    x->_parent->_right = y;
                y->_left = x;
                x->_parent = y;
            }

            void rightRotation(node* x) {
                node* y = x->_left;
                x->_left = y->_right;
                if (y->_right != LEAF)
                    y->_right->_parent = x;
                y->_parent = x->_parent;
                if (x->_parent == NULL)
                    x = y;
                else if (x == x->_parent->_right)
                    x->_parent->_right = y;
                else
                    x->_parent->_left = y;
                y->_right = x;
                x->_parent = y;
            }

            node* getRoot(node *new_node) {
            node *root = new_node;
			while (root && root->_parent)
				root = root->_parent;
            return root;
        }
    };
}

    template<class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs) {
		typename ft::map<Key, T>::const_iterator rit = rhs.begin();
		typename ft::map<Key, T>::const_iterator lit = lhs.begin();
		if (lhs.size() != rhs.size())
			return false;
		while (rit != rhs.end() && lit != lhs.end()) {
			if (*rit != *lit)
				return false;
			rit++;
			lit++;
		}
		return true;
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs) {
		return !(rhs == lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator< (const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs) {
		return !(lhs > rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator> (const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs) {
		return rhs < lhs;
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs) {
		return !(lhs < rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key,T,Compare,Alloc> &lhs, ft::map<Key,T,Compare,Alloc> &rhs) {
		return lhs.swap(rhs);
	}

#endif
