/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:50:06 by agachet           #+#    #+#             */
/*   Updated: 2022/01/21 18:26:27 by agachet          ###   ########.fr       */
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

template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& os, std::map<Key, Value> const& m)
{
   os << "{ ";
   for(auto const& p: m)
        os << '(' << p.first << ':' << p.second << ") ";
   return os << "}\n";
}
 
struct Point { double x, y; };
struct PointCmp {
    bool operator()(const Point& lhs, const Point& rhs) const {
        return lhs.x < rhs.x; // NB. intentionally ignores y
    }
};

int main() {

      // std::map<std::string, char> m = {
      //   { "k", 'B' },
      //   { "a", 'A' },
      //   { "v", 'D' },
      //   { "d", 'A' },
      //   { "a", 'E' },
      // };

      // std::pair <std::string, char> foo = std::make_pair ("d",'2');;
      // //std::pair <std::map<std::string, char>::iterator, bool> test = m.insert(foo);
      
      // std::map<std::string, char>::iterator test = m.insert(m.begin(),foo);

      // std::cout << test->first << std::endl;
      // *test++;
      // std::cout << test->first << std::endl;

  std::map<std::string, int> map1;
  map1["something"] = 69;
  map1["anything"] = 199;
  map1["that thing"] = 50;
  std::cout << "map1 = " << map1;
 
  // (4) Range constructor
  std::map<std::string, int> iter(map1.find("anything"), map1.end());
  std::cout << "\niter = " << iter;
  std::cout << "map1 = " << map1;

  //     std::map<std::string, char>::iterator it = m.begin();
  //     std::map<std::string, char>::iterator ita = m.end();

  // while (it != ita) {
  //   std::cout << it->first << " = " << it->second << std::endl;
  //   it++;
  // } 

  // std::cout
  //     << std::boolalpha
  //     << std::less<std::string>{}("kfdghfdbdfdfh", "kaeshterhteh")    << ' ' // false: 5 < 5 (warn: implicit conversion)
  //     << std::less<double>{}(5, 5.6) << ' ' // true: 5.0 < 5.6
  //     << std::less<int>{}(5.6, 5.7)  << ' ' // false: 5 < 5 (warn: implicit conversion)
  //    // << std::less{}(5, 5.6)         << ' ' // true: less<void>: 5.0 < 5.6
  //     << a.max_size() << " '" << it->first << " " 
      
  //     << '\n';


    // auto last = *m.rbegin();
    // auto i = m.begin();
  
    // std::cout << "Map contains "
    //      << "following elements"
    //      << std::endl;
  
    // do {
  
    //     std::cout << i->first
    //          << " = "
    //          << i->second
    //          << std::endl;
    // } while (m.value_comp()(*i++, last));
  return 0;
}