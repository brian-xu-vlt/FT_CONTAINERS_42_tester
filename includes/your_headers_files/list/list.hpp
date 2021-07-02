/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:47:50 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/08 15:47:51 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "../utils/ft_is_integer.hpp"
# include "./list_iterator.hpp"
# include "../utils/ft_node.hpp"
# include "../utils/ft_rev_iterator.hpp"
# include "../utils/ft_algo.hpp"

# include <iostream>
# include <cstddef>
# include <limits>

#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif

namespace ft	{

	template< typename T, typename Allocator = std::allocator<T> >
	class list {

/******************************************************************************.
.******************************************************************************.
.*********** MEMBER TYPES            ******************************************.
.******************************************************************************.
.******************************************************************************/

		private:

			typedef node<T>												node;

		public:

			typedef T													value_type;

			typedef size_t												size_type;
			typedef std::ptrdiff_t										difference_type;

			typedef typename Allocator::template rebind<node>::other	allocator_type;
			typedef typename Allocator::reference						reference;
			typedef typename Allocator::const_reference					const_reference;
			typedef typename Allocator::pointer							pointer;
			typedef typename Allocator::const_pointer					const_pointer;

			typedef typename ft::list_iterator<T, false>						iterator;
			typedef typename ft::list_iterator<T, true>							const_iterator;

			typedef typename ft::reverse_iterator<list_iterator<T, false> >		reverse_iterator;
			typedef typename ft::reverse_iterator<list_iterator<T, true> >		const_reverse_iterator;

/******************************************************************************.
.******************************************************************************.
.*********** CONSTRUCTORS DESTRUCTOR ******************************************.
.******************************************************************************.
.******************************************************************************/

			/**
			 * @brief Default Constructor
			*/
			explicit list( allocator_type const & userAlloc = allocator_type() ) : _size(0), _alloc(userAlloc) {

				if (DEBUG_MODE >= 1)
					std::cout << "CONSTRUCTOR --> DEFAULT " << __func__ << std::endl;
				initFillList(0, value_type());
			}

			/**
			 * @brief fill Constructor
			*/
			explicit list( size_type n, value_type const & val = value_type(),
				allocator_type const & userAlloc = allocator_type() ) : _size(0), _alloc(userAlloc)	{

				if (DEBUG_MODE >= 1)
					std::cout << "CONSTRUCTOR --> fill " << __func__ << std::endl;
				initFillList(n, val);
			}


			/**
			 * @brief Range Constructor
			*/
			template <class InputIterator>
			list (InputIterator first, InputIterator last,
				 allocator_type const & userAlloc = allocator_type() ) : _size(0), _alloc(userAlloc)	{

				typename ft::__is_integer<InputIterator>::__type	integer;
				if (DEBUG_MODE >= 1)
					std::cout << "CONSTRUCTOR --> range pre dispatcher ! " << __func__ << std::endl;
				list_constructor_dispatch(first, last, userAlloc, integer);
			}

			/**
			 * @brief Copy Constructor
			*/
			list( const list & src ) : _head(NULL), _tail(NULL), _size(0) {

				if (DEBUG_MODE >= 1)
					std::cout << "CONSTRUCTOR --> copy " << __func__ << std::endl;

				initFillList(0, value_type());
				if (src.size() > 0)
					assign(src.begin(), src.end());
			}

			~list( void )	{

				clearObject();
				if (DEBUG_MODE >= 1)
					std::cout << "DESTRUCTOR --> " << __func__ << std::endl;
			}

			size_type			max_size( void ) const	{ return _alloc.max_size();  }
			bool				empty( void ) const		{ return (_size == 0); }
			size_type			size( void ) const 		{ return (_size); }
			iterator			begin( void ) 			{ return (_head); }
			iterator			end( void ) 	 		{ return (_tail); }
			const_iterator		begin( void ) const		{ return (_head); }
			const_iterator		end( void ) const 		{ return (_tail); }
			reverse_iterator		rbegin( void ) 			{ return reverse_iterator(end()); }
			const_reverse_iterator	rbegin( void ) const	{ return const_reverse_iterator(end()); }
			reverse_iterator		rend( void )  			{ return reverse_iterator(begin()); }
			const_reverse_iterator	rend( void ) const 		{ return const_reverse_iterator(begin()); }
			reference			front( void ) 			{ return (_head->data); }
			reference			back( void ) 	 		{ return (_tail->prev->data); }
			const_reference		front( void ) const		{ return (_head->data); }
			const_reference		back( void ) const 		{ return (_tail->prev->data); }

			list&
			operator= (const list& x)	{

				if (*this != x)
					assign(x.begin(), x.end());
				return *this;
			}

			void
			pop_back( void )						{ erase(--end()); }
			void
			push_back (value_type const & val)		{ insert(end(), val); }
			void
			pop_front( void )						{ erase(begin()); }
			void
			push_front (value_type const & val)		{ insert(begin(), val); }

			void
			clear( void )	{ erase(begin(), end()); }


			/**
			 * @brief insert single element
			*/
			iterator
			insert(iterator position, const value_type& val)	{

				node *	newNode = getNode(val);
				if (_size < max_size())	{
					if (_head == _tail || position == begin())	{
						_head = newNode;
						newNode->hook(position.getPtr());
						_tail->next = _head;
						_head->prev = _tail;
					}
					else
						newNode->hook(position.getPtr());
					incSize();
				}
				return newNode;
			}

			/**
			 * @brief insert n elements of val
			*/
			void
			insert (iterator position, size_type n, const value_type& val)	{

				if (n + _size <= max_size())
				{
					for(; n > 0; --n)	{
						insert(position, val);
					}
				}
			}

			/**
			 * @brief insert range of elements
			 * check here if arguments of type InputIterator are integer
			 * or iterators and dispatch to the right overload.
			 * Cf. /usr/include/c++/7/bits/cpp_type_traits.h line 136
			 * for implementation. Basicly __is_integer is a template function
			 * which, by default containts __false_type as __type, unless
			 * it is one of the integer types so it contains __true_type
			 * Here we create integet wich will be of type __true_type
			 * or __false_type, and by calling inster_dispatch with it, the right
			 * overload is called.
			 * insert_dispatch taking __true_type will execute code for
			*/
			template <class InputIterator>
			void
			insert (iterator position, InputIterator first,
			InputIterator last)	{

				typename ft::__is_integer<InputIterator>::__type	integer;
				insert_dispatch(position, first, last, integer);
			}

			iterator
			erase (iterator position)	{

				node * cursor = position.getPtr();
				node * returnCursor = cursor->next;
				if (_size > 0)	{
					if (cursor == _head)	{
						_head = _head->next;
						_tail->next = _head;
					}
					cursor->unhook();
					_alloc.destroy(cursor);
					_alloc.deallocate(cursor, 1);
					decSize();
				}
				return returnCursor;
			}

			iterator
			erase (iterator first, iterator last)	{

				iterator tmpCursor = first;
				while (first != last)
				{
					tmpCursor = first;
					first++;
					erase(tmpCursor);
				}
				return last;
			}

			void
			resize (size_type n, value_type val = value_type())	{

				if (n < _size)	{
					typename ft::list<T>::iterator it = begin();
					for(size_type i = 0; i < n; i++)
						it++;
					erase(it, end());
				}
				else if (n > _size)
					insert(end(), n - _size, val);
			}

			void
			swap (list& src)	{

				node *		_headTmp = src._head;
				node *		_tailTmp = src._tail;
				size_type	_sizeTmp = src._size;

				src._head = _head;
				src._tail = _tail;
				src._size = _size;

				_head = _headTmp;
				_tail = _tailTmp;
				_size = _sizeTmp;
			}

			/**
			 * @brief Here we use the same technic as for insert : the type
			 *  integer is  used to call the right overload.
			*/
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)	{

				typename ft::__is_integer<InputIterator>::__type	integer;
				assign_dispatch(first, last, integer);
			}

			void assign(size_type n, const value_type& val)	{

				clear();
				insert(begin(), n, val);
			}

		/**
		 *	@brief entire list (1)
		*/
			void
			splice (iterator position, list& x)	{

				splice(position, x, x.begin(), x.end());
			}

		/**
		 *	@brief single element (2)
		*/
			void
			splice (iterator position, list& x, iterator it)	{

				splice(position, x, it, ++it);
			}	// splice

		/**
		 *	@brief element range (3)
		*/
			void
			splice (iterator position, list& x, iterator first, iterator last)	{

				if (first != last && x.size() > 0)	{

					difference_type sizeSplice = 0;
					for (iterator cursor = first; cursor != last; cursor++)
						sizeSplice++;

					first.getPtr()->transfer(first.getPtr(), last.getPtr());
					first.getPtr()->hook(position.getPtr());
					if (position.getPtr() == _head)
						_head = first.getPtr();
					if (this != &x)	{
						if (first.getPtr() == x._head)
							x._head = last.getPtr();
						this->incSize(sizeSplice);
						x.decSize(sizeSplice);
						if (x.size() == 0)
							x._head = x._tail;
					}
				}
			}

			void remove (const value_type& val)	{

				iterator	itFind = begin();

				while ((itFind = ft::find(itFind, end(), val)) != end())
					itFind = erase(itFind);
			}

			template <class Predicate>
			void
			remove_if (Predicate pred)	{

				iterator	itFind = begin();

				while ((itFind = ft::find_if(itFind, end(), pred)) != end())
					itFind = erase(itFind);
			}

			void
			unique( void )	{ unique(equality()); }

			template <class BinaryPredicate>
			void
			unique (BinaryPredicate binary_pred)	{

				iterator	itFind = begin();
				iterator	itEndGroup = begin();

				while ((itFind = ft::adjacent_find(itEndGroup, end(), binary_pred)) != end())	{
					itEndGroup = itFind;
					while (binary_pred(*itFind, *itEndGroup) == true && itEndGroup != end())
						itEndGroup++;
				 	erase(++itFind, itEndGroup);
				}

			} // unique

			void merge (list& x)	{ merge(x, smaller_than()); }

			template <class Compare>
			void
			merge (list& x, Compare comp)	{

				if (*this == x)
					return ;
				iterator	thisCursor = this->begin();
				while (x.empty() == false)	{
					while (thisCursor != this->end() && comp(*x.begin(), *thisCursor) == false)	{
						thisCursor++;
					}
					this->splice(thisCursor, x, x.begin());
				}
				if (x.empty() == false)
					this->splice(this->end(), x);
			} // merge

			void sort() { sort(smaller_than()); }

			template <class Compare>
			void
			sort (Compare comp)	{

				iterator	cursorSrc;
				list		tmpList;
				iterator	cursorTmp;

				while (this->empty() == false)	{
					cursorSrc = this->begin();
					if (tmpList.empty() == true)
						tmpList.splice(tmpList.begin(), *this, cursorSrc);
					else {
						cursorTmp = tmpList.begin();
						while (cursorTmp != tmpList.end() && comp(*cursorTmp, *cursorSrc) == true)
							cursorTmp++;
						tmpList.splice(cursorTmp, *this, cursorSrc);
					}
				}
				this->splice(this->begin(), tmpList);
			}

			void
			reverse( void )	{

				iterator	cursorBase;
				list		tmpList;

				while (this->empty() == false)	{
					cursorBase = this->begin();
					tmpList.splice(tmpList.begin(), *this, cursorBase);
				}
				this->splice(this->begin(), tmpList);
			}

			allocator_type
			get_allocator() const	{
				return allocator_type();
			}

		private:

			node *			_head;
			node *			_tail;
			size_type		_size;
			allocator_type	_alloc;


			void	incSize( size_type n = 1 )	{ _size += n; }
			void	decSize( size_type n = 1 )	{ _size -= n; }

			struct smaller_than {
				bool operator() (value_type const & a, value_type const & b) const
				{ return (a<b); }
			};

			struct equality {
				bool operator() (value_type const & a, value_type const & b) const
				{ return (a==b); }
			};

			template <class InputIterator>
			void
			assign_dispatch (InputIterator first, InputIterator last, ft::__false_type)	{

				clear();
				insert(begin(), first, last);
			}

			template<typename integer>
			void
			assign_dispatch (integer n, integer val, ft::__true_type)	{

				assign(static_cast<size_type>(n), static_cast<value_type>(val));
			}

			/**
			 * @brief Fill Constructor actual function
			*/
			template <class integer>
			void
			list_constructor_dispatch (integer n, integer const & val,
				allocator_type const &, ft::__true_type)	{

				if (DEBUG_MODE >= 1)	{
					std::cout << "dispatch --> __true_type " << __func__ << std::endl;
					std::cout << "CONSTRUCTOR --> fill " << __func__ << std::endl;
				}
				initFillList(n, val);
			}

			/**
			 * @brief Range Constructor actual function
			*/
			template <class InputIterator>
			void
			list_constructor_dispatch (InputIterator first, InputIterator last,
				 allocator_type const & userAlloc, ft::__false_type)	{

				if (DEBUG_MODE >= 1)
					std::cout << "CONSTRUCTOR --> range " << __func__ << std::endl;
				_alloc = userAlloc;
				initFillList(0, value_type());
				insert(begin(), first, last);
			}


			template<typename integer>
			void
			insert_dispatch(iterator position, integer n, integer val,
			ft::__true_type)	{
				insert(position, static_cast<size_type>(n),
					static_cast<value_type>(val));
			}

			template<typename InputIterator>
			void
			insert_dispatch(iterator position, InputIterator first,
			InputIterator last, ft::__false_type)	{
				for (; first != last; first++)	{
					insert(position, *first);
				}
			}

			/**
			 * @brief initialize the head and tail of a new list, to be
			 * used only by constructors.
			*/
			void
			initFillList(size_type n, value_type const & val)	{

				_size = 0;
				_head = _tail = NULL;
				_tail = getNode(value_type());
				_head = _tail;
				insert(begin(), n, val);
			}

			void
			clearObject( void )	{
				clear();
				if (_head != NULL)	{
					_alloc.destroy(_head);
					_alloc.deallocate(_head, 1);
				}
			}

			node*
			getNode(value_type const & val)	{

				node * newNode = NULL;
				try	{
					newNode = _alloc.allocate(1);
					_alloc.construct(newNode, val);
					newNode->next = newNode;
					newNode->prev = newNode;
				}
				catch(const std::exception& e) {
					clearObject();
					throw std::exception();
				}
				return newNode;
			}

		}; // ----------------- Class list

	template <class T, class Alloc >
	void
	swap (list<T,Alloc>& x, list<T,Alloc>& y)	{

		x.swap(y);
	};

	template <class T, class Alloc>
	bool
	operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)	{

		if (lhs.size() != rhs.size())
			return false;
		if (lhs.front() != rhs.front() || lhs.back() != rhs.back())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};

	template <class T, class Alloc>
	bool
	operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)	{ return(!(lhs == rhs)); };


	template <class T, class Alloc>
	bool
	operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)	{

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));

	};

	template <class T, class Alloc>
	bool
	operator<=( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)	{ return(!(lhs > rhs)); };

	template <class T, class Alloc>
	bool
	operator>( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)	{

		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));

	};

	template <class T, class Alloc>
	bool
	operator>=( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)	{ return(!(lhs < rhs)); };


} // ----------------- ft namespace

#endif /* *****BVALETTE****** LIST_H */
