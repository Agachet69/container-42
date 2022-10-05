/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:16:44 by agachet           #+#    #+#             */
/*   Updated: 2022/09/24 18:16:44 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "binarySearchTree.hpp"
#include "bidirectional_iterator.hpp"


namespace ft {
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> >> 
    class map {

        public:
            typedef Key                                                                 key_type;
            typedef T                                                                   mapped_type;
            typedef ft::pair<const key_type,mapped_type>                                value_type;
            typedef Compare                                                             key_compare;
            typedef Alloc                                                               allocator_type;
            typedef typename allocator_type::reference                                  reference;
            typedef typename allocator_type::const_reference                            const_reference;
            typedef typename allocator_type::pointer                                    pointer;
            typedef typename allocator_type::const_pointer                              const_pointer;
            typedef binarySearchTree<value_type>                                        node;
            typedef ft::bidirectionnal_iterator<node, value_type>					    iterator;
	    	typedef ft::const_bidirectionnal_iterator<node, const value_type, iterator> const_iterator;
	    	typedef ft::reverse_iterator<iterator> 							            reverse_iterator;
	    	typedef ft::reverse_iterator<const_iterator>					            const_reverse_iterator;
	    	typedef std::ptrdiff_t 												        difference_type;
	    	typedef size_t 														        size_type;
            typedef typename Alloc::template rebind<node>::other                        allocator_node;

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
            }

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _sizeMap(0), _comp(comp), _allocPair(alloc), _allocNode(std::allocator<node>()) {
                _end = _allocNode.allocate(1);
			    _allocNode.construct(_end, node());
                _revBegin = _allocNode.allocate(1);
			    _allocNode.construct(_revBegin, node());
                _revBegin->_end = _end;
                _revBegin->_parent = _end;
                for (first; first != last; first++)
                    insert (*first);
            }

            map (const map& x) : _comp(x._comp), _allocPair(x._allocPair), _allocNode(x._allocNode), _root(NULL), _sizeMap(0) {
                _end = _allocNode.allocate(1);
    			_allocNode.construct(_end, node());
    			_revBegin = _allocNode.allocate(1);
    			_allocNode.construct(_revBegin, node());
                _revBegin->_end = _end;
                _revBegin->_parent = _end;

    			clear();
    			this->insert(x.begin(), x.end());
            }
       
            ~map() {
                clear();
			    _allocNode.destroy(_end);
			    _allocNode.deallocate(_end, 1);
			    _allocNode.destroy(_revBegin);
			    _allocNode.deallocate(_revBegin, 1);
            }

            map& operator= (const map& x) {
                clear();
                _comp = x._compare;
                _sizeMap = 0;
                _allocPair = x._allocPair;
                _allocNode = x._allocNode;
                _end = x._end;
                insert(x.begin(), x.end());
                return (*this);
            }

            iterator begin() {
                node *tmp = _root;
                while (tmp && tmp->_left != LEAF) {
                   tmp = tmp->_left;
                }
                return iterator(tmp);
            }
            
            const_iterator begin() const {
                node *tmp = _root;
                while (tmp && tmp->_left != LEAF) {
                    tmp = tmp->_left;
                }
                return const_iterator(tmp);
            }

            iterator end() {
                return iterator(_end);
            }
            
            // const_iterator end() const {
            //     return const_iterator(this->_revBegin->_end); 
            // }
		    
            // reverse_iterator rbegin() {
			//     return (reverse_iterator(_end));
		    // }
            // const_reverse_iterator rbegin() const {
    		// 	return (const_reverse_iterator(_end));
    		// }

    		// reverse_iterator rend() {
    		// 	return (reverse_iterator(_begin->parent));
    		// }

    		// const_reverse_iterator rend() const {
    		// 	return (const_reverse_iterator(_begin->parent));
    		// }

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
               return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
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
               for (first; first != last; first++)
                   insert (*first);
            }

            void erase (iterator position) {
                if (find(position._ptr->_value.first) == _end)
                    return;
                del(position._ptr);
                _allocNode.destroy(position._ptr);
			    _allocNode.deallocate(position._ptr, 1);
                this->_root = getRoot(_root);
                this->_sizeMap--;
            }

            size_type erase (const key_type& k) {
                iterator delNode = find(k);
                if (delNode == _end)
                    return 0;
                del(delNode._ptr);
                _allocNode.destroy(delNode._ptr);
			    _allocNode.deallocate(delNode._ptr, 1);
                this->_sizeMap--;
                this->_root = getRoot(_root);
                return 1;
            }

            void erase (iterator first, iterator last) {
                for (first; first != last; first++) {
                    if (find(first._ptr->_value.first) != _end) {
                        std::cout << "izzzz << "<<first._ptr->_value.first << std::endl;
                        del(first._ptr);
                        //_allocNode.destroy(first._ptr);
			            //_allocNode.deallocate(first._ptr, 1);
                        this->_sizeMap--;
                        this->_root = getRoot(_root);
                    }
                }

            }

        void clear() {
            this->erase(this->begin(), this->end());
        }

        void swap (map& x) {
            node	    *tmp;
			size_type   size_tmp;

			if (x == *this)
				return ;

			tmp = x._root;
			x._root = _root;
			_root = tmp;

			tmp = x._end;
			x._end = _end;
			_end = tmp;

			tmp = x._begin;
			x._revBegin = _revBegin;
			_revBegin = tmp;

			size_tmp = x._size;
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
            node *del(node *delNode) {
                node *x;
                node *tmp = delNode;
                node *min;
                int colorSupr = delNode->color;

                if (delNode->_left == LEAF && delNode->_right == LEAF) {
                    if (delNode->_parent != LEAF && delNode == delNode->_parent->_right)
                        delNode->_parent->_right = LEAF;
                    else if (delNode->_parent != LEAF)
                        delNode->_parent->_left = LEAF;
                    else {
                        _root = LEAF;
                        return NULL;
                    }
                    x = delNode->_parent;
                }
                else if ((delNode->_left == LEAF && delNode->_right != LEAF) || (delNode->_left != LEAF && delNode->_right == LEAF)) {
                    if (delNode->_right) {
                        if (delNode->_parent) {
                            delNode->_right->_parent = delNode->_parent;
                            delNode->_parent = delNode->_right;
                            x = delNode->_right;
                        }
                        else {
                            _root = delNode->_right;
                            delNode->_right->_parent = NULL;
                            x = _root;
                        }
                    }
                    else {
                        if (delNode->_parent) {
                            delNode->_left->_parent = delNode->_parent;
                            delNode->_parent = delNode->_left;
                            x = delNode->_left;
                        }
                        else {
                            _root = delNode->_left;
                            delNode->_left->_parent = NULL;
                            x = _root;
                        }
                    }
                }
                else {
                    min =  delNode->findMin(delNode->_right);
                    x = min->_right;
                    min->_left = delNode->_left;
                    min->_left->_parent = min;
                    if (min != delNode->_right) {
                        min->_parent->_left = min->_right;
                        if (min->_right)
                            min->_right->_parent = min->_parent;
                        delNode->_right->_parent = min;
                        min->_right = delNode->_right;
                    }
                    if (delNode->_parent) {
                        min->_parent = delNode->_parent;
                        if (delNode->_parent->_right == delNode)
                            delNode->_parent->_right = min;
                        else
                            delNode->_parent->_left = min;
                    }
                    else {
                        min->_parent = NULL;
                        _root = min;
                    }
                    x = delNode->findMin(delNode->_right);
                }
                if (min->color == BLACK)
                   reorganizeDelete(x);
                return min;
            }

            void reorganizeDelete(node *delNode) {
                std::cout << " root = " << _root->_value.first << std::endl;
                while (delNode != _root && delNode->color == BLACK) {
                    if (delNode == delNode->_parent->_left) {
                        node *y = delNode->_parent->_right;
                        if (y && y->color == RED) {
                            y->color = BLACK;
                            delNode->_parent->color = RED;
                            leftRotation(delNode->_parent);
                            y = delNode->_parent->_right;
                        }
                        if (y && y->_left && y->_left->color == BLACK && y->_right && y->_right->color == BLACK) {
                            y->color = RED;
                            delNode = delNode->_parent;
                        }
                        else {
                            if (y && y->_right && y->_right->color == BLACK) {
                                if (y->_left)
                                    y->_left->color = BLACK;
                                y->color = RED;
                                rightRotation(y);
                                y = delNode->_parent->_right;
                            }
                            if (y)
                                y->color = delNode->_parent->color;
                            delNode->_parent->color = BLACK;
                            if (y && y->_right)
                                y->_right->color = BLACK;
                            leftRotation(delNode->_parent);
                    std::cout << "cc "  << std::endl;
                            break;
                        }
                    }
                    else {
                        node *y = delNode->_parent->_left;
                        if (y && y->color == RED ) {
                            y->color = BLACK;
                            delNode->_parent->color = RED;
                            rightRotation(delNode->_parent);
                            y = delNode->_parent->_left;
                        }
                        if (y && y->_right && y->_right->color == BLACK && y->_left && y->_left->color == BLACK) {
                            y->color = RED;
                            delNode = delNode->_parent;
                        }
                        else {
                            if (y && y->_left && y->_left->color == BLACK) {
                                if (y->_right)
                                    y->_right->color = BLACK;
                                y->color = RED;
                                leftRotation(y);
                                y = delNode->_parent->_left;
                            }
                            y->color = delNode->_parent->color;
                            delNode->_parent->color = BLACK;
                            if (y && y->_left)
                                y->_left->color = BLACK;
                            rightRotation(delNode->_parent);
                            break;
                        }
                    }
                }
                delNode->color = BLACK;
            }

        // void RBdelete2(node * N) {  // -> node to be deleted
        //     int dir; // side of P on which N is located (∈ { LEFT, RIGHT })
        //     node* S; // -> sibling of N
        //     node* P = N->_parent;  // -> parent node of N
        //     node* C;  // -> close   nephew
        //     node* D;  // -> distant nephew
        //     if (N == P->_left) {
        //         dir = 0;
        //         S = P->_right;
        //         D = S->_right;
        //         C = S->_left;
        //         P->_left = LEAF;
        //     }
        //     else {
        //         dir = 1;
        //         S = P->_left;
        //         D = S->_left;
        //         C = S->_right;
        //         P->_right = LEAF;
        //     }   
        //     do {
        //         dir = childDir(N);   // side of parent P on which node N is located
        //         S = P->child[1-dir]; // sibling of N (has black height >= 1)
        //         D = S->child[1-dir]; // distant nephew
        //         C = S->child[  dir]; // close   nephew
                
        //         if (P->color == BLACK && C->color == BLACK && S->color == BLACK && D->color == BLACK) {
        //                 while ((P = N->_parent) != NULL) {
        //                     S->color = RED;
        //                     N = P;
        //                 }
        //         }
        //         else if (P == NULL)
        //             return;
        //         else if (S->color == RED) {
        //             RotateDirRoot(T,P,dir); // P may be the root
        //             P->color = RED;
        //             S->color = BLACK;
        //             S = C; // != NIL
        //             // now: P red && S black
        //             D = S->child[1-dir]; // distant nephew
        //             if (D != LEAF && D->color == RED)
        //                 goto Case_D6;      // D red && S black
        //             C = S->child[  dir]; // close   nephew
        //             if (C != LEAF && C->color == RED)
        //                 goto Case_D5;      // C red && S+D black
        //             // Otherwise C+D considered black.
        //             // fall through to Case_D4
        //         }
        //         // S is black:
        //         else if (D != LEAF && D->color == RED) { // not considered black
        //             RotateDirRoot(T,P,dir); // P may be the root
        //             S->color = P->color;
        //             P->color = BLACK;
        //             D->color = BLACK;
        //             return;
        //         }
        //         else if (C != LEAF && C->color == RED)  {// not considered black
        //             RotateDirRoot(T,S,1-dir); // S is never the root
        //             S->color = RED;
        //             C->color = BLACK;
        //             D = S;
        //             S = C;
        //         }
        //         // Here both nephews are == NIL (first iteration) or black (later).
        //         else if (P->color == RED) {
        //             S->color = RED;
        //             P->color = BLACK;
        //             return;
        //         }
        //     }
        // }

        // node* RotateDirRoot(RBtree* T,   /* red–black tree*/RBnode* P,   /* root of subtree (may be the root of T)*/int dir) {   // dir ∈ { LEFT, RIGHT }
        // RBnode* G = P->parent;
        // RBnode* S = P->child[1-dir];
        // RBnode* C;
        // assert(S != NIL); // pointer to true node required
        // C = S->child[dir];
        // P->child[1-dir] = C; if (C != NIL) C->parent = P;
        // S->child[  dir] = P; P->parent = S;
        // S->parent = G;
        // if (G != NULL)
        //     G->child[ P == G->right ? RIGHT : LEFT ] = S;
        // else
        //     _root = S;
        // return S; // new root of subtree
        // }

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
                if (this->_root == NULL)
                    this->_root = new_node;
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
                //le fils droit de x devient le fils gauche de y
                x->_right = y->_left;
                if (y->_left != LEAF)
                    y->_left->_parent = x;
                y->_parent = x->_parent;
                //Si x est la racine, y devient la racine
                if (x->_parent == NULL) {
                    node *tmp = x;
                    x = y;
                    x->_left = tmp;
                    tmp->_parent = x;
                    return;
                }
                //Sinon, on remplace x par y
                else if (x == x->_parent->_left)
                    x->_parent->_left = y;
                else
                    x->_parent->_right = y;
                //On attache x à gauche de y
                y->_left = x;
                x->_parent = y;
            }

            void rightRotation(node* x) {
                node* y = x->_left;
                //le fils gauche de x devient le fils droit de y
                x->_left = y->_right;
                if (y->_right != LEAF)
                    y->_right->_parent = x;
                y->_parent = x->_parent;
                //Si x est la racine, y devient la racine
                if (x->_parent == NULL)
                    x = y;
                //Sinon, on remplace x par y
                else if (x == x->_parent->_right)
                    x->_parent->_right = y;
                else
                    x->_parent->_left = y;
                //On attache x à droite de y
                y->_right = x;
                x->_parent = y;
            }
        
            node* getRoot(node *new_node) {
            node *root = new_node;
            while (root->_parent != NULL)
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