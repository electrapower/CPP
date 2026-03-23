/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:26:42 by asalniko          #+#    #+#             */
/*   Updated: 2026/03/23 13:26:43 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie* heapZombie = newZombie("Heapster");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Stacky");
	return 0;
}
