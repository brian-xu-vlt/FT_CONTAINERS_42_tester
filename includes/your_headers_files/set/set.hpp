/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:28:02 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 10:45:23 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "../map/map.hpp"
# include "../utils/ft_pair.hpp"
# include "../utils/ft_algo.hpp"
# include "set_iterator.hpp"

# include <iostream>
# include <limits>
# include <cstddef>

#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif

namespace ft	{

/*############################################################################*/
/*############################################################################*/
/*###########################                             ####################*/
/*###########################                             ####################*/
/*###########################           SET CLASS         ####################*/
/*###########################                             ####################*/
/*###########################                             ####################*/
/*############################################################################*/
/*############################################################################*/

	template< 	class T,
				class Compare = std::less<T>,
				class Allocator = std::allocator<map_node<T> > >
	class set {


/******************************************************************************.
.******************************************************************************.
.*********** MEMBER TYPES            ******************************************.
.******************************************************************************.
.******************************************************************************/

		public:

			typedef T										value_type;
			typedef	Compare									key_compare;
			typedef	Compare									value_compare;

			typedef size_t									size_type;
			typedef std::ptrdiff_t							difference_type;

			typedef Allocator								allocator_type;
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;

			typedef typename ft::set_iterator<T, Compare, ft::map_node<value_type>, true>	iterator;
			typedef typename ft::set_iterator<T, Compare, ft::map_node<value_type>, true>	const_iterator;

            typedef typename ft::reverse_iterator<set_iterator<T, Compare, ft::map_node<value_type>, true> > reverse_iterator;
            typedef typename ft::reverse_iterator<set_iterator<T, Compare, ft::map_node<value_type>, true> >  const_reverse_iterator;

		private:

			typedef typename ft::map_node<value_type>		node_type;

/******************************************************************************.
.******************************************************************************.
.*********** CONSTRUCTORS DESTRUCTOR           ********************************.
.******************************************************************************.
.******************************************************************************/


		public:
			/**
			 * @brief Default Constructor
			*/
			explicit
			set( const Compare& comp = key_compare(),
			const allocator_type & userAlloc = allocator_type() )	: 	_head(NULL),
																		_dumbNode(NULL),
																		_size(0),
																		_allocNode(userAlloc),
																		_comp(comp)				{
				if (DEBUG_MODE == 1)
					std::cout << "CONSTRUCTOR --> DEFAULT explicit " << __func__ << std::endl;

				btree_init_dumbNode();
			}


			/**
			 * @brief Range Constructor
			*/
			template <class InputIterator>
			set (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& userAlloc = allocator_type() ) :	_head(NULL),
																		_dumbNode(NULL),
																		_size(0),
																		_allocNode(userAlloc),
																		_comp(comp)				{

				if (DEBUG_MODE == 1)
					std::cout << "CONSTRUCTOR --> Range ! " << __func__ << std::endl;
				insert(first, last);
			}

			/**
			 * @brief Copy Constructor
			*/
			set( set const & src ) :	_head(NULL),
												_dumbNode(NULL),
												_size(0),
												_allocNode(src._allocNode),
												_comp(src._comp)				{

				if (DEBUG_MODE == 1)
					std::cout << "CONSTRUCTOR --> copy " << __func__ << std::endl;

				insert(src.begin(), src.end());
			}


			~set( void )	{

				if (DEBUG_MODE == 1) std::cout << "DESTRUCTOR --> " << __func__ << std::endl;
				clear();
			}

/******************************************************************************.
.******************************************************************************.
.*********** PRIVATE VARIABLES  ***********************************************.
.******************************************************************************.
.******************************************************************************/

			protected:
				node_type*				_head;
				node_type*				_dumbNode; // allow to point to element after last.
				size_type				_size;
				allocator_type		 	_allocNode;
				Compare	const			_comp;

/******************************************************************************.
.******************************************************************************.
.*********** PUBLIC MEMBER FUNCTIONS ******************************************.
.******************************************************************************.
.******************************************************************************/

		public:

			bool		empty( void ) const		{ return (_size == 0); }
			size_type	size( void ) const 		{ return (_size); }
			size_type	max_size( void ) const	{ return this->_allocNode.max_size(); }

			iterator
			begin( void ) 			{
				if (empty() == false && _dumbNode != NULL)
					return (iterator(_dumbNode->left, _dumbNode, _comp));
				return (iterator(_dumbNode, _dumbNode, _comp));
			}

			const_iterator
			begin( void ) const		{
				if (empty() == false && _dumbNode != NULL)
					return (const_iterator(_dumbNode->left, _dumbNode, _comp));
				return (const_iterator(_dumbNode, _dumbNode, _comp));
			}

			iterator
			end( void ) 	 		{
				return (iterator(_dumbNode, _dumbNode, _comp));
			}

			const_iterator
			end( void ) const 		{
				return (const_iterator(_dumbNode, _dumbNode, _comp));
			}

			reverse_iterator		rbegin( void ) 			{	return reverse_iterator(end()); }
			const_reverse_iterator	rbegin( void ) 	const	{	return const_reverse_iterator(end()); }
			reverse_iterator		rend( void ) 			{	return reverse_iterator(begin()); }
			const_reverse_iterator	rend( void ) 	const	{	return const_reverse_iterator(begin()); }

			iterator
			find (const value_type& k)	{

				if (empty() == true)
					return(iterator());
				node_type*	nodeFound = locateNode(_head, k);
				if (nodeFound == NULL)
					return (end());
				return (iterator(nodeFound, _dumbNode, _comp));
			}

			const_iterator
			find (const value_type& k) const	{

				if (empty() == true)
					return(const_iterator());
				node_type* const	nodeFound = locateNode(_head, k);
				if (nodeFound == NULL)
					return (end());
				return (const_iterator(nodeFound, _dumbNode, _comp));
			}

			size_type
			count (const value_type& k) const	{
				return (find(k) != end() ? 1 : 0);
			}

			iterator
			lower_bound (const value_type& k) {

				if (empty() == true)
					return(iterator());

				node_type* const	nodeFound = locateBound(_head, k, isLowerBoundNode);

				if (nodeFound == NULL)
					return (end());
				else
					return (iterator(nodeFound, _dumbNode, _comp));
			}

			const_iterator
			lower_bound (const value_type& k) const	{

				if (empty() == true)
					return(const_iterator());

				node_type* const	nodeFound = locateBound(_head, k, isLowerBoundNode);

				if (nodeFound == NULL)
					return (end());
				else
					return (const_iterator(nodeFound, _dumbNode, _comp));
			}


			iterator
			upper_bound (const value_type& k) {

				if (empty() == true)
					return(iterator());

				node_type* const	nodeFound = locateBound(_head, k, isUpperBoundNode);

				if (nodeFound == NULL)
					return (end());
				else
					return (iterator(nodeFound, _dumbNode, _comp));
			}

			const_iterator
			upper_bound (const value_type& k) const	{

				if (empty() == true)
					return(const_iterator());

				node_type* const	nodeFound = locateBound(_head, k, isUpperBoundNode);

				if (nodeFound == NULL)
					return (end());
				else
					return (const_iterator(nodeFound, _dumbNode, _comp));
			}


			ft::pair<iterator,iterator>
			equal_range (const value_type& k)	{

				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			ft::pair<const_iterator, const_iterator>
			equal_range (const value_type& k) const	{

				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			/**
			 * @brief insert single element
			*/
			ft::pair<iterator, bool>
			insert(const value_type& val)	{
				return(btree_insert_data(NULL, &_head, val));
			}


			/**
			 * @brief insert single element with hint to determine a closer
			 * insertion point
			*/
			iterator
			insert (iterator position, const value_type& val)	{

				node_type*	posPtr = position.getPtr();
				if (posPtr == NULL)
					return (iterator());
				if (position != end() && lower_bound(val) == position)	{
					if (DEBUG_MODE >= 2) std::cout << __func__ << ":	 Insert with optimization." << std::endl;
					return (btree_insert_data(posPtr->parent, &posPtr, val).first);
				}
				else
					return (btree_insert_data(NULL, &_head, val).first);
			}

			/**
			 * @brief Range insert from first to last element
			*/
			template <class InputIterator>
 			void
			insert (InputIterator first, InputIterator last)	{

				for (; first != last; first++)
					btree_insert_data(NULL, &_head, *first);
			}

			void
			erase( iterator position )	{

				node_type*	deadNode = position.getPtr();
				node_type*	deadNodeLeft = deadNode->left;
				node_type*	deadNodeRight = deadNode->right;
				node_type*	singleChild = getSingleChild(deadNode);

				if (deadNode == NULL)
					return;
				if (isLeaf(deadNode) == true)
					detachFromParent(deadNode);
				else if (singleChild != NULL)
					detachFromParent(deadNode, singleChild);
				else	{
					detachFromParent(deadNode, deadNodeLeft);
					node_type*	farRight = getFarRight(deadNodeLeft);
					deadNodeRight->parent = farRight;
					farRight->right = deadNodeRight;
				}
				decSize();
				btree_update_dumbNode();
				freeNode(deadNode);
			}

			size_type
			erase( const value_type& k )	{

				node_type*	target = btree_search_key(_head, k);
				if (target == NULL)
					return 0;
				else	{
					erase(iterator(target, _dumbNode, _comp));
					return 1;
				}
			}

			void
			erase (iterator first, iterator last)	{

				iterator next;
				while (first != last)	{
					next = first;
					next++;
					erase(first);
					first = next;
				}
			}

			void
			swap (set& src)	{

				if (this->_head != src._head)	{
					node_type*				tmp_head = src._head;
					node_type*				tmp_dumbNode = src._dumbNode;
					size_t					tmp_size = src._size;
					allocator_type 			tmp_allocNode = src._allocNode;

					src._head = this->_head;
					src._dumbNode = this->_dumbNode;
					src._size = this->_size;
					src._allocNode = this->_allocNode;

					this->_head = tmp_head;
					this->_dumbNode = tmp_dumbNode;
					this->_size = tmp_size;
					this->_allocNode = tmp_allocNode;
				}
			}

			set&
			operator= (const set& src)	{

				if (this->_head != src._head)	{

					clear();

					if (src.empty() == false)	{
						if (src.size() > 2)	{
							const_iterator	half = src.begin();
							for (size_t i = 0; i < src.size() / 2; i++)
								half++;
							insert(*half);
						}
						insert(src.begin(), src.end());
					}
				}
				return *this;
			}

			void
			clear( void )			{

				if (DEBUG_MODE >= 3) std::cout << __func__ << std::endl;
				freeAllNodes(_head);
				freeNode(_dumbNode);
				_size = 0;
				_head = NULL;
				_dumbNode = NULL;
			}

            value_compare	value_comp( void ) const	{ return value_compare(_comp); }
            key_compare		key_comp( void ) const		{ return key_compare(_comp); }

/******************************************************************************.
.******************************************************************************.
.*********** PRIVATE MEMBER FUNCTIONS AND HELPERS  ****************************.
.******************************************************************************.
.******************************************************************************/

 		private:

			void
			detachFromParent( node_type* node, node_type* newChild = NULL )	{
				node_type* parent = node->parent;
				if (parent != NULL)	{
					if (parent->left == node)
						parent->left = newChild;
					else if (parent->right == node)
						parent->right = newChild;
				}
				else if (node == _head)
					_head = newChild;
				if (newChild != NULL)
					newChild->parent = parent;
				node->parent = NULL;
			}

			static node_type*
			getSingleChild( node_type* node )	{

				if (node->right != NULL && node->left == NULL)
					return (node->right);
				else if (node->right == NULL && node->left != NULL)
					return (node->left);
				else
					return (NULL);
			}

			node_type*
			locateBound( node_type* root, const value_type& key, bool (*isBound)(node_type*, const value_type&) ) const	{

				if (root == _head && isBound(_dumbNode->left, key) == true)
					return (_dumbNode->left);
				else if (root == _head && isBound(_dumbNode->right, key) == false)
					return (NULL);

				node_type* candidate = root;
				node_type* bestCandidate = NULL;
				while (candidate != NULL)	{
					if (isBound(candidate, key) == true)	{
						bestCandidate = candidate;
						candidate = candidate->left;
					}
					else
						candidate = candidate->right;
				}
				return (bestCandidate);
			}

			node_type*
			locateNode( node_type* root, const value_type& key ) const	{

				if (root != NULL)	{
					if (_comp(key, root->item) == true)
						return (locateNode(root->left, key));
					else if (isEqualKey(key, root->item) == false)
						return (locateNode(root->right, key));
					else
						return (root);
				}
				else
					return (NULL);
			}

			static bool
			isLowerBoundNode( node_type* node, const value_type& key ) {

			typename ft::set< T, Compare> tmpObj;
			typename ft::set< T, Compare>::key_compare cmpFunc = tmpObj.key_comp();

				return (node != NULL
					&& (cmpFunc(node->item, key) == false
						|| isEqualKey(node->item, key) == true));
			}

			static bool
			isUpperBoundNode( node_type* node, const value_type& key ) {
				typename ft::set< T, Compare> tmpObj;
				typename ft::set< T, Compare>::key_compare cmpFunc = tmpObj.key_comp();
				return (node != NULL && cmpFunc(key, node->item) == true);
			}

			void
			btree_update_dumbNode( void )	{
				if (_dumbNode == NULL)
					btree_init_dumbNode();
				if (empty() == true)	{
					_dumbNode->left = _head;
					_dumbNode->right = _head;
				}
				else	{
					_dumbNode->left = getFarLeft(_head);
					_dumbNode->right = getFarRight(_head);
				}
			}

			void
			btree_init_dumbNode( void )	{

				if (_dumbNode == NULL)	{
					_dumbNode = _allocNode.allocate(1);
					_allocNode.construct(_dumbNode, node_type(value_type()));
					_dumbNode->left = _head;
					_dumbNode->right = _head;
				}
			}

			node_type*
			btree_create_node(node_type* parent, value_type k)	{

				node_type*	newNode = _allocNode.allocate(1);
				_allocNode.construct(newNode, node_type(value_type(k)));
				newNode->parent = parent;
				return (newNode);
			}

				/**
				 * @brief Actual function inserting new data in the tree.
				 * @param parent shall be NULL to insert anywhere from the head.
				 * @param root starting point in the tree to look for a suitable potision.
				 * @param valSrc value to be inserted.
				*/

			ft::pair<iterator, bool>
			btree_insert_data(node_type* parent, node_type **root, value_type valSrc)	{

				if (*root != NULL)	{
					node_type* tree = *root;
					if (_comp(valSrc, tree->item) == true)
						return (btree_insert_data(tree, &tree->left, valSrc));
					else if (isEqualKey(valSrc, tree->item) == false)
						return (btree_insert_data(tree, &tree->right, valSrc));
					else
						return (ft::pair<iterator, bool>(iterator(*root, _dumbNode, _comp), false));
				}
				else	{
					*root = btree_create_node(parent, valSrc);
					incSize();
					btree_update_dumbNode();
					return (ft::pair<iterator, bool>(iterator(*root, _dumbNode, _comp), true));
				}
			}

			node_type*
			btree_search_key(node_type* root, const value_type& targetKey)	{

				if (root != NULL)	{
					if (_comp(targetKey, root->item) == true)
						return (btree_search_key(root->left, targetKey));
					else if (_comp(root->item, targetKey) == true)
						return (btree_search_key(root->right, targetKey));
				}
				return (root);
			}

			static node_type*
			getFarLeft( node_type* cursor )  {

				while (cursor != NULL && cursor->left != NULL)
					cursor = cursor->left;
				return (cursor);
			}

			static node_type*
			getFarRight( node_type* cursor )  {

				while (cursor != NULL && cursor->right != NULL)
					cursor = cursor->right;
				return (cursor);
			}

			static bool
			isLeaf(node_type* node)  {
				return (node->left == NULL && node->right == NULL);
			}

			static bool
			isEqualKey(const value_type& existingKey, const value_type& newKey) {
				typename ft::set< T, Compare> tmpObj;
				typename ft::set< T, Compare>::key_compare cmpFunc = tmpObj.key_comp();
				return (cmpFunc(existingKey, newKey) == false
				&& cmpFunc(newKey, existingKey) == false);
			}

			size_t
			incSize( size_t inc = 1 ) { _size += inc; return(_size); }

			size_t
			decSize( size_t inc = 1 ) { _size -= inc; return(_size); }

			void
			freeNode( node_type* node)	{
				if (node != NULL)	{
					_allocNode.destroy(node);
					_allocNode.deallocate(node, 1);
				}
			}

			void
			freeAllNodes( node_type* root )	{

				if (root == NULL)
					return;
				freeAllNodes(root->left);
				freeAllNodes(root->right);
				freeNode(root);
			}

			allocator_type
			get_allocator() const	{
				return _allocNode();
			}

		}; // -------------------------------------------------------- Class set

/******************************************************************************.
.******************************************************************************.
.*********** PUBLIC NON MEMBER FUNCTIONS     **********************************.
.******************************************************************************.
.******************************************************************************/

		template <class T, class Compare, class Alloc>
		void
		swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)	{

			x.swap(y);
		};

		template< class T, class Compare, class Alloc >
		bool operator==( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )	{

			if (lhs.size() != rhs.size())
				return false;

			typename ft::set<T,Compare,Alloc>::const_iterator lhs_it = lhs.begin();
			typename ft::set<T,Compare,Alloc>::const_iterator rhs_it = rhs.begin();

			for (;lhs_it != lhs.end() && rhs_it != rhs.end(); lhs_it++, rhs_it++)	{
				if (*lhs_it != *rhs_it)
					return false;
			}
			if (lhs_it != lhs.end() || rhs_it != rhs.end())
				return false;
			return true;

		}

		template< class T, class Compare, class Alloc >
		bool operator!=( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )	{
			return !(lhs == rhs);
		}

		template< class T, class Compare, class Alloc >
		bool operator<( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )	{

			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		template< class T, class Compare, class Alloc >
		bool operator>=( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )	{

			return !(lhs < rhs);
		}

		template< class T, class Compare, class Alloc >
		bool operator<=( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )	{
			return (lhs < rhs || lhs == rhs);
		}

		template< class T, class Compare, class Alloc >
		bool operator>( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )	{

			return !(lhs <= rhs);

		}

} // -------------------------------------------------------------- ft namespace

#endif /* *****BVALETTE****** SET_HPP */
