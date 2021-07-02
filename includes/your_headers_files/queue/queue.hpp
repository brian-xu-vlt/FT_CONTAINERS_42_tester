/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:28:25 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/08 15:48:38 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif

#include "../deque/deque.hpp"

namespace ft	{

	template <class T, class Container = ft::deque<T> >
	class queue 	{

/******************************************************************************.
.******************************************************************************.
.*********** MEMBER TYPES            ******************************************.
.******************************************************************************.
.******************************************************************************/

		public:

			typedef	T									value_type;
			typedef	Container							container_type;
			typedef	typename container_type::size_type	size_type;

			explicit
			queue (const container_type& ctnr = container_type()) : _container(ctnr) {}

			bool
			empty( void )	const	{
				return _container.empty();
			}

			size_type
			size( void )	const	{
				return _container.size();
			}

			value_type&
			front()	{
				return (_container.front());
			}

			const value_type&
			front() const	{
				return (_container.front());
			}

			value_type&
			back()	{
				return (_container.back());
			}

			const value_type&
			back() const	{
				return (_container.back());
			}

			void
			push (const value_type& val)	{
				_container.push_back(val);
			}

			void
			pop ( void )	{
				_container.pop_front();
			}

			template <class Type, class _Cntnr>
			friend
			bool
			operator==(const queue<Type, _Cntnr>& lhs, const queue<Type, _Cntnr>& rhs);

			template <class Type, class _Cntnr>
			friend
			bool
			operator!=(const queue<Type, _Cntnr>& lhs, const queue<Type, _Cntnr>& rhs);

			template <class Type, class _Cntnr>
			friend
			bool
			operator<(const queue<Type, _Cntnr>& lhs, const queue<Type, _Cntnr>& rhs);

			template <class Type, class _Cntnr>
			friend
			bool
			operator<=(const queue<Type, _Cntnr>& lhs, const queue<Type, _Cntnr>& rhs);

			template <class Type, class _Cntnr>
			friend
			bool
			operator>(const queue<Type, _Cntnr>& lhs, const queue<Type, _Cntnr>& rhs);

			template <class Type, class _Cntnr>
			friend
			bool
			operator>=(const queue<Type, _Cntnr>& lhs, const queue<Type, _Cntnr>& rhs);

		private:

			Container	_container;

	}; //------------------queue class

	template <class T, class Container>
	bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)	{
		return lhs._container == rhs._container;
	}

	template <class T, class Container>
	bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)	{
		return lhs._container != rhs._container;
	}

	template <class T, class Container>
	bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)	{
		return lhs._container < rhs._container;
	}

	template <class T, class Container>
	bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)	{
		return lhs._container <= rhs._container;
	}

	template <class T, class Container>
	bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)	{
		return lhs._container > rhs._container;
	}

	template <class T, class Container>
	bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)	{
		return lhs._container >= rhs._container;
	}

} //-----------------namespace ft

#endif
