/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:28:11 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/09 17:44:44 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP

# include "../map/map_iterator.hpp"
# include "../utils/ft_enable_if.hpp"
# include "../utils/ft_iterator_base.hpp"
# include "../utils/ft_rev_iterator.hpp"
# include <iostream>
# include <cstddef>

#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif

namespace ft	{

	template<	class T,
				class Compare,
				typename map_node, bool B>
	class set_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T, B > {

		template< typename _t, typename _c, typename _a>
		friend class set;

		friend class set_iterator<T, Compare, map_node, !B>;

		public:

			typedef	Compare																key_compare;

			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T, B>			iterator;
			typedef typename iterator::value_type										value_type;
			typedef typename iterator::difference_type									difference_type;
			typedef typename iterator::reference										reference;
            typedef typename iterator::pointer											pointer;

			set_iterator( map_node* ptr = NULL, map_node* dumbNode = NULL,
				const key_compare& comp = key_compare() ) :	_ptr(ptr),
															_btreeDumdNode(dumbNode),
															_comp(comp)		{}

			set_iterator(const set_iterator<T, Compare, map_node, false>& itSrc) :	_ptr(itSrc.getPtr()),
														_btreeDumdNode(itSrc.getDumbNode()),
														_comp(itSrc.getComp())		{}

			~set_iterator( void )	{}

			set_iterator&
			operator=( const set_iterator& src )	{
				if (*this != src)	{
					_ptr = src.getPtr();
					_btreeDumdNode = src.getDumbNode();
					_comp = src.getComp();
				}
				return (*this);
			}

			set_iterator&
			operator++( void ) {

				if (_ptr == _btreeDumdNode)
					_ptr = _btreeDumdNode->left;
				else if (isLastNode(_ptr) == true)
					_ptr = _btreeDumdNode;
				else if (isLeaf(_ptr) == true)	{
					if (_ptr == _ptr->parent->left)
						_ptr = _ptr->parent;
					else
						getNextBranch();
				}
				else	{
					if (_ptr->right != NULL)
						_ptr = getFarLeft(_ptr->right);
					else
						getNextBranch();
				}
				return *this;
			}

		set_iterator
			operator++( int ) {
				set_iterator tmp(*this);
				operator++();
				return tmp;
			}

			set_iterator&
			operator--( void ) {

				if (_ptr == _btreeDumdNode)
					_ptr = _btreeDumdNode->right;
				else if (isFirstNode(_ptr) == true)
					_ptr = _btreeDumdNode;
				else if (isLeaf(_ptr) == true)	{
					if (_ptr == _ptr->parent->right)
						_ptr = _ptr->parent;
					else
						getPreviousBranch();
				}
				else	{
					if (_ptr->left != NULL)
						_ptr = getFarRight(_ptr->left);
					else
						getPreviousBranch();
				}
				return *this;
			}

		set_iterator
			operator--( int ) {
				set_iterator tmp(*this);
				operator--();
				return tmp;
			}

			bool
			operator==(const set_iterator<T, Compare, map_node, true>& rhs) const	{ return _ptr==rhs.getPtr(); }
			bool
			operator==(const set_iterator<T, Compare, map_node, false>& rhs) const	{ return _ptr==rhs.getPtr(); }

			bool
			operator!=(const set_iterator<T, Compare, map_node, true>& rhs) const	{ return _ptr!=rhs.getPtr(); }
			bool
			operator!=(const set_iterator<T, Compare, map_node, false>& rhs) const	{ return _ptr!=rhs.getPtr(); }

			pointer
			operator->()	const		{ return (&_ptr->item); }

			reference
			operator*()	const			{ return (_ptr->item); }

		private:

			/**
			 * @brief Pointer holding the address of the set_iterator element.
			*/
			map_node*			_ptr;
			map_node*			_btreeDumdNode;
			Compare				_comp;

			map_node*			getDumbNode(void) const { return (_btreeDumdNode);	}
			Compare				getComp(void) const 	{ return (_comp);	}
			map_node*			getPtr(void) const 		{ return (_ptr);	}
			map_node*			getPosParent(void) const	{

				if (_ptr != NULL)
					return (_ptr->parent);
				return (NULL);
			}


			void
			getNextBranch( void )	{

				value_type		startKey = _ptr->item;
				map_node*		cursor = _ptr->parent;

				while (cursor != NULL && _comp(cursor->item, startKey) == true)
					cursor = cursor->parent;
				_ptr = cursor;
			}

			void
			getPreviousBranch( void )	{

				value_type		startKey = _ptr->item;
				map_node*		cursor = _ptr->parent;

				while (cursor != NULL && _comp(startKey, cursor->item) == true)
					cursor = cursor->parent;
				_ptr = cursor;
			}

			static	map_node*
			getFarLeft( map_node* cursor )	{

				while (cursor != NULL && cursor->left != NULL)
					cursor = cursor->left;
				return (cursor);
			}

			static	map_node*
			getFarRight( map_node* cursor )	{

				while (cursor != NULL && cursor->right != NULL)
					cursor = cursor->right;
				return (cursor);
			}

			bool
			isFirstNode( map_node* p )	{
				return (p == _btreeDumdNode->left);
			}

			bool
			isLastNode( map_node* p )	{
				return (p == _btreeDumdNode->right);
			}

			static	bool
			isLeaf(map_node* node)	{
				return (node->left == NULL && node->right == NULL);
			}


		}; //----------------- Classset_iterator


} // ----------------- ft namespace

#endif
