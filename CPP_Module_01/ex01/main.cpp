/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:28:34 by asalniko          #+#    #+#             */
/*   Updated: 2026/03/23 13:28:35 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int count = 5;
    Zombie* horde = zombieHorde(count, "Walker");
    
    if (!horde)
    {
        std::cout << "No zombies created" << std::endl;
        return 1;
    }

    for (int i = 0; i < count; i++)
        horde[i].announce();

    delete[] horde;
    return 0;
}
