/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:52:11 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/08 15:52:21 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_HPP
# define FT_NODE_HPP

# include <iostream>

#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif


namespace ft	{

	template< typename T>
	class node	{

		// private:
		public:

			node<T>	*next;
			node<T>	*prev;
			T		data;


			node( void ) : next(this), prev(this) {

				if (DEBUG_MODE >= 2)
					std::cout << "CONSTRUCTOR --> default " << __func__ << std::endl;

			}
			node( T const & val ) : next(this), prev(this), data(val) {

				if (DEBUG_MODE >= 3)
				{
					std::cout << "CONSTRUCTOR with Param--> " << __func__ << std::endl;
					std::cout << __func__ << " this: " << this << std::endl;
					std::cout << __func__ << " prev: " << prev << std::endl;
					std::cout << __func__ << " next: " << next << std::endl;
				}
			}

			~node( void )	{
				if (DEBUG_MODE >= 2)
					std::cout << "DESTRUCTOR --> " << __func__ << std::endl;
			}

			static void
			swap(node& x, node& y)	{

				if (&x != &y)	{
					node*	posx = (&y != x.next) ? x.next : &x;
					node*	posy = y.next;
					y.unhook();
					y.hook(posx);
					x.unhook();
					x.hook(posy);
				}
			}

			void
			transfer(node * const first, node * const last)	{

				if (first != last)	{
					node *	beforeLast = last->prev;
					if (first->prev != first)	{
						first->prev->next = last;
						last->prev = first->prev;
						first->prev = first;
					}
					else
						last->prev = last;
					beforeLast->next = beforeLast;
				}
			}

			void
			hook(node * const position)	{

				if (position != NULL)	{

					if (position->prev != position)
					{
						this->prev = position->prev;
						this->prev->next = this;
					}
					if (this->next == this)
					{
						this->next = position;
						position->prev = this;
					}
					else	{
						node * cursor = this;
						while (cursor->next != cursor)
							cursor = cursor->next;
						cursor->next = position;
						position->prev = cursor;
					}
				}
			}

			void
			unhook( void )	{

				if (prev != this && next != this)	{
					next->prev = prev;
					prev->next = next;
				}
				else if (prev == this)
					next->prev = next;
				else if (next == this)
					prev->next = prev;
				this->next = this;
				this->prev = this;
			}

		}; // ----------------- Class node

} // ----------------- ft namespace

#endif
