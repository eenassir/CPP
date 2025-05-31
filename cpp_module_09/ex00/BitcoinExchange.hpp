/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:20:52 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/30 09:48:30 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

class BitcoinExchange
{
    private:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
    public:
        static double parce_input(std::string &buffer);
        static std::map<std::string, double> load_data(std::ifstream &infile);
        static int Btc(char *av);
};

#endif