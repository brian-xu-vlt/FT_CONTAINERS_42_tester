/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:53:04 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/08 15:53:06 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "../utils/ft_iterator_base.hpp"
# include "../utils/ft_rev_iterator.hpp"
# include "../utils/ft_enable_if.hpp"

# include <iostream>
# include <cstddef>
# include <limits>
# include <stdexcept>

#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif

namespace ft	{

	template< typename T, bool B>
	class vector_iterator : public ft::iterator< ft::random_access_iterator_tag, T, B>
	{

		friend class vector_iterator<T, !B>;

		private:

            typedef T				base_type;
            typedef base_type&		base_reference;
            typedef base_type*		base_pointer;

		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T, B>	iterator;
			typedef typename iterator::size_type								size_type;
			typedef typename iterator::difference_type							difference_type;
			typedef typename iterator::reference								reference;
            typedef typename iterator::pointer									pointer;

			vector_iterator( const base_pointer src = NULL ) :_ptr(src) {}
			vector_iterator( const vector_iterator<T, false>& itSrc )  :_ptr(itSrc.getPtr()) {}

			~vector_iterator( void ) {}

			vector_iterator&
			operator=( const vector_iterator& src )	{
				_ptr = src.getPtr();
				return (*this);
			}

			vector_iterator&
			operator++( void ) {
				_ptr++;
				return *this;
			}

			vector_iterator
			operator++( int ) {
				vector_iterator tmp(*this);
				operator++();
				return tmp;
			}

			vector_iterator&
			operator--( void ) {
				_ptr--;
				return *this;
			}

			vector_iterator
			operator--( int ) {
				vector_iterator tmp(*this);
				operator--();
				return tmp;
			}

			difference_type
			operator- ( const vector_iterator<T, true> rhs ) const	{ return this->_ptr - rhs.getPtr(); }
			difference_type
			operator- ( const vector_iterator<T, false> rhs ) const	{ return this->_ptr - rhs.getPtr(); }

			vector_iterator
			operator- ( difference_type n ) {

				vector_iterator tmpIt = *this;

				while ( n > 0 )	{
					tmpIt--;
					n--;
				}
				return tmpIt;
			}

			vector_iterator
			operator- ( difference_type n ) const {

				vector_iterator tmpIt = *this;
				while ( n > 0 )	{
					tmpIt--;
					n--;
				}
				return tmpIt;
			}

			vector_iterator
			operator+ ( difference_type n ) {

				vector_iterator tmpIt = *this;

				while ( n > 0 )	{
					tmpIt++;
					n--;
				}
				return tmpIt;
			}

			vector_iterator
			operator+ ( difference_type n ) const {

				vector_iterator tmpIt = *this;

				while ( n > 0 )	{
					tmpIt++;
					n--;
				}
				return tmpIt;
			}


			vector_iterator&	operator-=( difference_type n )		{ *this = *this - n; return *this;}
			vector_iterator&	operator+=( difference_type n )		{ *this = *this + n; return *this;}

			bool		operator==(const vector_iterator<T, true>& rhs) const	{ return _ptr==rhs.getPtr(); }
			bool		operator!=(const vector_iterator<T, true>& rhs) const	{ return _ptr!=rhs.getPtr(); }
			bool		operator<(const vector_iterator<T, true>& rhs) const	{ return _ptr < rhs.getPtr(); }
			bool		operator>(const vector_iterator<T, true>& rhs) const	{ return _ptr > rhs.getPtr(); }
			bool		operator<=(const vector_iterator<T, true>& rhs) const	{ return _ptr <= rhs.getPtr(); }
			bool		operator>=(const vector_iterator<T, true>& rhs) const	{ return _ptr >= rhs.getPtr(); }

			bool		operator==(const vector_iterator<T, false>& rhs) const	{ return _ptr==rhs.getPtr(); }
			bool		operator!=(const vector_iterator<T, false>& rhs) const	{ return _ptr!=rhs.getPtr(); }
			bool		operator<(const vector_iterator<T, false>& rhs) const	{ return _ptr < rhs.getPtr(); }
			bool		operator>(const vector_iterator<T, false>& rhs) const	{ return _ptr > rhs.getPtr(); }
			bool		operator<=(const vector_iterator<T, false>& rhs) const	{ return _ptr <= rhs.getPtr(); }
			bool		operator>=(const vector_iterator<T, false>& rhs) const	{ return _ptr >= rhs.getPtr(); }

			reference	operator[]( difference_type n )	const	{ return _ptr[n]; }

			pointer		operator->()	const				{ return _ptr; }
			reference	operator*()		const				{ return *_ptr; }

		private:

			base_pointer	getPtr( void )	const 	{ return _ptr; }

			/**
			 * @brief Pointer holding the address of the vector_iterator element.
			*/
			base_pointer	_ptr;

	}; //----------------- Class iterator

	template<class T, bool B>
	vector_iterator<T, B>
	operator+ ( size_t n, vector_iterator<T, B>rhs ) {

		ft::vector_iterator<T,B> tmpIt = rhs;
		while ( n > 0 )	{
			tmpIt++;
			n--;
		}
		return tmpIt;
	}

} // ----------------- ft namespace

#endif /* *****BVALETTE****** VECTOR_H */
