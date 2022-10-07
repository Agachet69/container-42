/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:50:06 by agachet           #+#    #+#             */
/*   Updated: 2022/10/05 19:51:26 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <functional>
//#include "test.hpp"
//#include "stack.hpp"
//#include "reverse_iterator.hpp"

int main() {

        std::map<char,int> mymap;
      std::map<char,int>::iterator it;
        // insert some values:
        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;
        mymap['d']=40;
        mymap['e']=50;
        mymap['f']=60;
        it=mymap.find('b');
        mymap.erase (it);                   // erasing by iterator
        mymap.erase ('c');                  // erasing by key
        it=mymap.find ('e');
      std::map<char,int>::iterator it2 = mymap.find ('d');
        mymap.erase ( it, it2 );    // erasing by range
        // show content:
        for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
}
