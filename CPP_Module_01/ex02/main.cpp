/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:29:52 by asalniko          #+#    #+#             */
/*   Updated: 2026/03/23 13:34:07 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address of str:      " << &str << std::endl;
    std::cout << "Address in stringPTR:" << stringPTR << std::endl;
    std::cout << "Address of stringREF:" << &stringREF << std::endl;

    std::cout << "Value of str:        " << str << std::endl;
    std::cout << "Value via stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value via stringREF: " << stringREF << std::endl;

    return 0;
}


