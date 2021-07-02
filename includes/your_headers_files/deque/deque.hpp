/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:48:54 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/08 14:52:57 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif

# include "../utils/ft_algo.hpp"
# include "../utils/ft_is_integer.hpp"
#include "../vector/vector_iterator.hpp"

namespace ft	{

		template< typename T, typename T_alloc>
		class deque_base	{

		public:

			typedef T_alloc								allocator_type;
			typedef typename T_alloc::pointer			pointer;

			deque_base( void ) : _headStorage(NULL), _head(NULL), _tail(NULL), _tailStorage(NULL), _alloc(allocator_type()) {

				if (DEBUG_MODE >= 2) std::cout << "CONSTRUCTOR --> default " << __func__ << std::endl;
			}

			deque_base( allocator_type const & userAlloc ) : _headStorage(NULL), _head(NULL), _tail(NULL), _tailStorage(NULL), _alloc(userAlloc) {

				if (DEBUG_MODE >= 2) std::cout << "CONSTRUCTOR --> defaut with _alloc " << __func__ << std::endl;
			}

			deque_base( size_t n ) : _headStorage(NULL), _head(NULL), _tail(NULL), _tailStorage(NULL), _alloc(allocator_type()) {

				initStorage(n + (n>>1));
				if (DEBUG_MODE >= 2) std::cout << "CONSTRUCTOR --> fill " << __func__ << std::endl;
			}

			deque_base( size_t n, allocator_type const & userAlloc ) : _headStorage(NULL), _head(NULL), _tail(NULL), _tailStorage(NULL), _alloc(userAlloc) {

				initStorage(n + (n>>1));
				if (DEBUG_MODE >= 2) std::cout << "CONSTRUCTOR --> fill with _alloc " << __func__ << std::endl;
			}

			~deque_base( void )	{

				deleteStorage();
				if (DEBUG_MODE >= 2) std::cout << "DESTRUCTOR --> " << __func__ << std::endl;
			}

			pointer			_headStorage;
			pointer			_head;
			pointer			_tail;
			pointer			_tailStorage;
			allocator_type	_alloc;

		protected:

			void
			initStorage( size_t n = 1 )	{

				size_t	initSize = n * 2;
				if (n > 0)	{
					pointer tmp_mem_alloc = this->_alloc.allocate(initSize);
					this->_headStorage = tmp_mem_alloc;
					this->_tail = this->_head = this->_headStorage + n;
					this->_tailStorage = this->_headStorage + initSize;
					if (DEBUG_MODE >= 2) {
						std::cout << __func__ << "with n = " << n << std::endl;
						std::cout << "Infos: _headStorage (" <<_headStorage << ") _head (" <<_head << "), _tail(" <<_tail << "), _tailStorage(" <<_tailStorage << ")" << std::endl;
						for (size_t i = 0; _head + i != _tailStorage; ++i)	{
							std::cout << "[" << i << "] uninitialized ";
							std::cout << " @ " << _head + i << std::endl;
						}
					}
				}
			}

		private:

			void
			deleteStorage( void )	{
				if (DEBUG_MODE >= 2) std::cout << __func__ << std::endl;
				this->_alloc.deallocate(_headStorage, _tailStorage - _headStorage);
			}

		}; // ----------------- ClassDeque_base

	template < class T, class Allocator = std::allocator<T> >
	class deque	: protected deque_base<T, Allocator> {

/******************************************************************************.
.******************************************************************************.
.*********** MEMBER TYPES            ******************************************.
.******************************************************************************.
.******************************************************************************/

		private:

			typedef deque_base<T, Allocator>				deque_base;

		public:

			typedef T										value_type;

			typedef size_t									size_type;
			typedef std::ptrdiff_t							difference_type;

   			typedef Allocator								allocator_type;
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;

			typedef typename ft::vector_iterator<T, false>	iterator;
			typedef typename ft::vector_iterator<T, true>	const_iterator;

            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>  const_reverse_iterator;

/******************************************************************************.
.******************************************************************************.
.*********** CONSTRUCTORS DESTRUCTOR ******************************************.
.******************************************************************************.
.******************************************************************************/

		public:
			/**
			 * @brief Default Constructor
			*/
			explicit deque( allocator_type const & userAlloc = allocator_type() ) : deque_base(userAlloc) {

				if (DEBUG_MODE >= 1) std::cout << "CONSTRUCTOR --> DEFAULT " << __func__ << std::endl;
			}

			/**
			 * @brief fill Constructor, allocate at least n memory blocks and
			 * construct n objects val.
			*/
			explicit deque( size_type n, value_type const & val = value_type(),
				allocator_type const & userAlloc = allocator_type() ) : deque_base(n, userAlloc)	{

				if (DEBUG_MODE >= 1) std::cout << "CONSTRUCTOR --> fill " << __func__ << std::endl;
				initFillDeque(n, val);
			}

			/**
			 * @brief Range Constructor
			*/
			template <class InputIterator>
			deque (InputIterator first, InputIterator last,
				 allocator_type const & userAlloc = allocator_type() )
				 : deque_base(userAlloc)	{

				if (DEBUG_MODE >= 1) std::cout << "CONSTRUCTOR --> range pre dispatcher ! " << __func__ << std::endl;

				typename ft::__is_integer<InputIterator>::__type	integer;
				deque_constructor_dispatch(first, last, userAlloc, integer);
			}

			/**
			 * @brief Copy Constructor
			*/
			deque( deque const & src ) : deque_base(src.size()) {

				if (DEBUG_MODE >= 1) std::cout << "CONSTRUCTOR --> copy " << __func__ << std::endl;

				fillDeque(src.begin(), src.end());
			}

			~deque( void )	{

				if (size() > 0)
					clearObject();
				if (DEBUG_MODE >= 1)
					std::cout << "DESTRUCTOR --> " << __func__ << std::endl;
			}

/******************************************************************************.
.******************************************************************************.
.*********** PUBLIC MEMBER FUNCTIONS ******************************************.
.******************************************************************************.
.******************************************************************************/

			size_type
			max_size( void ) const	{ return this->_alloc.max_size();  }

			bool
			empty( void ) const		{ return (size() == 0); }

			size_type
			size( void ) const 		{ return (this->_tail - this->_head); }

			iterator
			begin( void ) 			{ return (this->_head); }

			const_iterator
			begin( void ) const		{ return (this->_head); }

			iterator
			end( void ) 	 		{ return (this->_tail); }

			const_iterator
			end( void ) const 		{ return (this->_tail); }

			reverse_iterator
			rbegin( void ) 			{ return reverse_iterator(end()); }

			const_reverse_iterator
			rbegin( void ) const	{ return const_reverse_iterator(end()); }

			reverse_iterator
			rend( void ) 	 		{ return reverse_iterator(begin()); }

			const_reverse_iterator
			rend( void ) const 		{ return const_reverse_iterator(begin()); }

			reference
			front( void ) 			{ return (*(this->_head)); }

			const_reference
			front( void ) const		{ return (*(this->_head)); }

			reference
			back( void ) 	 		{ return (*(this->_tail - 1)); }

			const_reference
			back( void ) const 		{ return (*(this->_tail - 1)); }

			void
			pop_back( void )		{ if (size() > 0) eraseAtBack(); }

			void
			push_back( value_type const & val)	{ insertAtBack(1, val); }

			void
			pop_front( void )		{ if (size() > 0) eraseAtFront(); }

			void
			push_front( value_type const & val)	{ insertAtFront(1, val); }

			void
			clear( void )			{ erase(begin(), end()); }

			/**
			 * @brief insert single element
			*/
			iterator insert(iterator position, const value_type& val)	{

				difference_type indexPos = position - begin();
				insert(position, 1, val);
				return begin() + indexPos;
			}

			/**
			 * @brief insert n elements of val
			*/
			void insert (iterator position, size_type n, const value_type& val)	{

				if (this->_head == NULL)	{
					this->initStorage();
					position = begin();
				}

				if (position == begin())
					return insertAtFront(n, val);
				else if (position == end())
					return insertAtBack(n, val);

				difference_type indexPos = position - begin();

				if (size() + n >= capacityAfterTail())
					doReserve(capacity() + (n * 2) + (capacity()>>1));

				memMoveRight(begin() + indexPos, end(), n);
				destroyObjects(this->_head + indexPos, size() - indexPos);
				constructObjects(this->_head + indexPos, n, val);
				this->_tail += n;
			}

			reference
			at (size_type n)	{
				checkRange(n);
				return ((*this)[n]);
			}

			const_reference
			at (size_type n) const	{
				checkRange(n);
				return ((*this)[n]);
			}

			/**
			 * @brief insert range of elements
			 * check here if arguments of type InputIterator are integer
			 * or iterators and dispatch to the right overload.
			 * Cf. /usr/include/c++/7/bits/cpp_type_traits.h line 136
			 * for implementation. Basicly __is_integer is a template function
			 * which, by default containts __false_type as __type, unless
			 * it is one of the integer types so it contains __true_type
			 * Here we create integer wich will be of type __true_type
			 * or __false_type, and by calling insert_dispatch with it, the right
			 * overload is called.
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

				if (position == begin())
					return eraseAtFront();
				else	{
					destroyObjects(&(*position), 1);
					memMoveLeft(position + 1, end(), 1);
					this->_tail -= 1;
					return position;
				}
			}

			iterator
			erase (iterator first, iterator last)	{

				if (first == begin() && last == end())
					return eraseAll();
				else if (first == begin())	{
					for (; first != last; ++first)
						eraseAtFront();
					return (last + 1);
				}
				else	{
					size_type			offset = first - begin();
					difference_type		len = last - first;

					destroyObjects(&(*first), len);
					memMoveLeft(last, end(), len);
					this->_tail -= len;

					return begin() + offset;
				}
			}

			void
			resize (size_type n, value_type val = value_type())	{

				if (n < size())
					erase(end() - (size() - n), end());
				else if (n > size())
					insert(end(), n - size(), val);
			}

			void
			swap (deque& src)	{

				pointer 	headStorageTmp = src._headStorage;
				pointer 	headTmp = src._head;
				pointer 	tailTmp = src._tail;
				pointer		tailStorageTmp = src._tailStorage;

				src._headStorage = this->_headStorage;
				src._head = this->_head;
				src._tail = this->_tail;
				src._tailStorage = this->_tailStorage;

				this->_headStorage = headStorageTmp;
				this->_head = headTmp;
				this->_tail = tailTmp;
				this->_tailStorage = tailStorageTmp;
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

		private:

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

		public:

			deque&
			operator= (const deque& x)	{

				if (*this != x)
					assign(x.begin(), x.end());
				return *this;
			}

			reference
			operator[] (size_type n)	{
				return (*(this->_head + n));
			}

			const_reference
			operator[] (size_type n) const	{
				return (*(this->_head + n));
			}

			allocator_type get_allocator() const { return allocator_type(); }

/******************************************************************************.
.******************************************************************************.
.*********** PRIVATE MEMBER FUNCTIONS AND HELPERS  ****************************.
.******************************************************************************.
.******************************************************************************/

		private:

			size_type
			capacity( void ) const	{ return (this->_tailStorage - this->_headStorage); }

			iterator
			eraseAtFront( void )	{

				destroyObjects(&front(), 1);
				this->_head++;
				return (begin());
			}

			void
			eraseAtBack( void )	{

				destroyObjects(&back(), 1);
				this->_tail--;
			}

			iterator
			eraseAll( void )	{

				destroyObjects(&front(), size());
				this->_tail = this->_head;
				return (end());
			}

			void
			insertAtFront(size_t n, const value_type& val)	{

				if (n > capacityBeforeHead())
					doReserve(n * 2);
				this->_head -= n;
				constructObjects(this->_head, n, val);
			}

			void
			insertAtBack(size_t n, const value_type& val)	{

				if (n > capacityAfterTail())
					doReserve(capacity() + (n * 4));
				constructObjects(this->_tail, n, val);
				this->_tail += n;
			}

			size_type
			capacityBeforeHead( void ) const	{ return (this->_head - this->_headStorage); }

			size_type
			capacityAfterTail( void ) const		{ return (this->_tailStorage - this->_tail); }
			template <class integer>
			void
			deque_constructor_dispatch (integer n, integer const & val,
				allocator_type const &, ft::__true_type)	{

				if (DEBUG_MODE >= 1)	{
					std::cout << "dispatch --> __true_type " << __func__ << std::endl;
					std::cout << "CONSTRUCTOR --> fill " << __func__ << std::endl;
				}
				this->initStorage(n);
				initFillDeque(n, val);
			}

			/**
			 * @brief Range Constructor actual function
			*/
			template <class InputIterator>
			void
			deque_constructor_dispatch (InputIterator first, InputIterator last,
				 allocator_type const &, ft::__false_type)	{

				if (DEBUG_MODE >= 1) std::cout << "CONSTRUCTOR --> range : " << __func__ << std::endl;

				size_type	rangeSize = 0;
				for (InputIterator cursor = first; cursor != last; cursor++)
					rangeSize++;
				this->initStorage(rangeSize * 2);
				fillDeque(first, last);
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

				difference_type offset = position - begin();
				size_type	rangeSize = 0;
				for (InputIterator cursor = first; cursor != last; cursor++)
					rangeSize++;
				insert(position, rangeSize, value_type());
				position = begin() + offset;
				for (difference_type n = 0; first != last; ++first, n++)
					position[n] = *first;
			}

			/**
			 * @brief Construct objects at alocated memory, to be used by
			 * constructors
			*/

			template<typename InputIterator>
			void
			fillDeque(InputIterator first, InputIterator last)	{

				for (;first != last; first++)	{
					this->_alloc.construct(this->_tail, *first);
					this->_tail++;
				}
			}

			/**
			 * @brief Construct objects at alocated memory, to be used by
			 * constructors
			*/
			void
			initFillDeque(size_type n, value_type const & val)	{

				this->_tail = this->_head + n;
				for (size_t i = 0; i < n; i++){
					this->_alloc.construct(this->_head + i, val);
				}
			}



			/**
			 * @brief doReserve: No throw version of Reserve.
			*/
			void
			doReserve (size_type n) {

				pointer		oldHead = this->_head;
				pointer		oldHeadStorage = this->_headStorage;
				size_type	oldSize = this->size();
				size_type	oldCapacity = this->capacity();

				reallocateBigger(n);

				destroyObjects(oldHead, oldSize);
				this->_alloc.deallocate(oldHeadStorage, oldCapacity);
			}

			void
			reallocateBigger(size_type n)	{

				iterator	oldHeadIt = begin();
				iterator	oldTailIt = end();

				this->initStorage(n);
				constructObjects(this->_head, oldHeadIt, oldTailIt);
				this->_tail += oldTailIt - oldHeadIt;
			}

			template<typename InputIterator>
			void
			constructObjects(pointer p, InputIterator first, InputIterator last)	{

				typename ft::__is_integer<InputIterator>::__type	integer;
				constructObject_dispatch(integer, p, first, last);
			}

			void
			constructObjects(pointer p, size_type n, value_type val = value_type())	{
				for (size_t i = 0; i < n; i++)	{
					this->_alloc.construct(p + i, val);
				}
			}

			template <class InputIterator>
			void
			constructObject_dispatch (ft::__false_type, pointer p, InputIterator first, InputIterator last)	{

				for (size_t i = 0; first != last; i++, first++)	{
					this->_alloc.construct(p + i, *first);
				}
			}

			template<typename integer>
			void
			constructObject_dispatch (ft::__true_type, pointer p, integer n, value_type val = value_type())	{

				constructObjects(static_cast<pointer>(p),
					static_cast<size_type>(n), static_cast<value_type>(val));
			}

			void
			destroyObjects(pointer p, size_t n)	{
				for (size_t i = 0; i < n; ++i)	{
					this->_alloc.destroy(p + i);
				}
			}

			void
			clearObject( void )	{

				if (DEBUG_MODE >= 3) std::cout << __func__ << std::endl;
				destroyObjects(this->_head, this->size());
			}

			template<typename InputIterator>
			void
			memMoveLeft(iterator first, InputIterator last, size_t n)	{

				while (first != last)	{
					constructObjects(&(*first) - n, static_cast<size_type>(1), *first);
					destroyObjects(&(*first), 1);
					first++;
				}
			}


			/**
			 * @brief Move [first, last] range by n memory blocks to the right
			*/
			void
			memMoveRight(iterator first, iterator last, size_t n)	{
				while (last != first)	{
					last--;
					constructObjects(&(*last) + n, 1, *last);
					destroyObjects(&(*last), 1);
				}
			}

			void
			checkRange(size_type n)	const {
				if (n > size())	{
					throw std::out_of_range("Out of deque's range");
				}
			}

		}; // ----------------- Class Deque

	template <class T, class Alloc >
	void
	swap (deque<T,Alloc>& x, deque<T,Alloc>& y)	{

		x.swap(y);
	};

	template <class T, class Alloc>
	bool
	operator== (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)	{

		if (lhs.size() != rhs.size())
			return false;
		if (lhs.front() != rhs.front() || lhs.back() != rhs.back())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};

	template <class T, class Alloc>
	bool
	operator!= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)	{ return(!(lhs == rhs)); };


	template <class T, class Alloc>
	bool
	operator<  (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)	{

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T, class Alloc>
	bool
	operator<= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)	{ return(!(lhs > rhs)); };

	template <class T, class Alloc>
	bool
	operator>  (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)	{

		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	};

	template <class T, class Alloc>
	bool
	operator>= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)	{ return(!(lhs < rhs)); };

} //-----------------namespace ft

#endif
