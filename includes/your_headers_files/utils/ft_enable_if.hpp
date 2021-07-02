/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enable_if.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:51:05 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/08 15:51:14 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENABLE_IF_HPP
# define FT_ENABLE_IF_HPP

#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif


namespace ft	{

    /**********
     * used to create typedef of const / non const reference or pointer:

typedef typename ft_enable_if<B, value_type&, const value_type&>::type       reference;
typedef typename ft_enable_if<B, value_type*, const value_type*>::type       pointer;

     * if B (from the class template) is true, the type will be from the second argument, so reference will be non const,
     * if B (from the class template) is false, the type will be from the third argument, so reference will be const.
    **********/


    /**
     * @brief base template struc for enable if
    */
    template <bool isConst, typename isFalse, typename isTrue>
    struct ft_enable_if {};

    /**
     * @brief defines a type corresponding the last template member for isConst == true
    */
    template <typename isFalse, typename isTrue>
    struct ft_enable_if<false, isFalse, isTrue>
    {
        typedef isFalse type;
    };

    /**
     * @brief defines a type corresponding the first template member for isConst == false
    */
    template <typename isFalse, typename isTrue>
    struct ft_enable_if<true, isFalse, isTrue>
    {
        typedef isTrue type;
    };

} // ----------------- ft namespace

#endif
