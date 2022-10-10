/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:59:55 by agachet           #+#    #+#             */
/*   Updated: 2022/10/10 19:35:06 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <vector>
#include <deque>
#include <stack>

int main() {
    //////////////////////////////////////////////////////// TEST VECTOR ////////////////////////////////////////////////////////
    /*                                                vector::operator=                                                        */
        // ft::vector<int> foo (3,0);
        // ft::vector<int> bar (5,0);
        // bar = foo;
        // foo = ft::vector<int>();
        // std::cout << "Size of foo: " << int(foo.size()) << '\n';
        // std::cout << "Size of bar: " << int(bar.size()) << '\n';
        // ft::vector<int> test(5,6);

    /*                                               ft::vector::begin                                                         */

        // ft::vector<int> myvector;
        // for (int i=1; i<=5; i++) myvector.push_back(i);
        // std::cout << "myvector contains:";
        // for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        //    std::cout << ' ' << *it;
        // std::cout << '\n';

    /*                                                ft::vector::end                                                          */

        // ft::vector<int> myvector;
        // for (int i=1; i<=5; i++) myvector.push_back(i);
        // std::cout << "myvector contains:";
        // for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        //     std::cout << ' ' << *it;
        // std::cout << '\n';
    /*                                                ft::vector::rbegin                                                       */

        // ft::vector<int> myvector (5);  // 5 default-constructed ints
        //   int i=0;
        //   ft::vector<int>::reverse_iterator rit = myvector.rbegin();
        //   for (; rit!= myvector.rend(); ++rit)
        //     *rit = ++i;
        //   std::cout << "myvector contains:";
        //   for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        //     std::cout << ' ' << *it;
        //   std::cout << '\n';
        //   return 0;

    /*                                             ft::vector::rend                                                            */

        // ft::vector<int> myvector (5);  // 5 default-constructed ints
        // ft::vector<int>::reverse_iterator rit = myvector.rbegin();
        // int i=0;
        // for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
        //   *rit = ++i;
        // std::cout << "myvector contains:";
        // for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        //   std::cout << ' ' << *it;
        // std::cout << '\n';

    /*                                                ft::vector::size                                                         */

        // ft::vector<int> myints;
        // std::cout << "0. size: " << myints.size() << '\n';
        // for (int i=0; i<10; i++) myints.push_back(i);
        // std::cout << "1. size: " << myints.size() << '\n';
        // myints.insert (myints.end(),10,100);
        // std::cout << "2. size: " << myints.size() << '\n';
        // myints.pop_back();
        // std::cout << "3. size: " << myints.size() << '\n';

    /*                                               ft::vector::max_size                                                      */

        // ft::vector<int> myvector;
        // for (int i=0; i<100; i++) myvector.push_back(i);
        // std::cout << "size: " << myvector.size() << "\n";
        // std::cout << "capacity: " << myvector.capacity() << "\n";
        // std::cout << "max_size: " << myvector.max_size() << "\n";

    /*                                                ft::vector::empty                                                        */

        // std::cout << std::boolalpha;
        // ft::vector<int> numbers;
        // std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
        // numbers.push_back(42);
        // std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';

    /*                                                ft::vector::resize                                                       */

        //  ft::vector<int> myvector;
        // //set some initial content:
        //  for (int i=1;i<10;i++) myvector.push_back(i);

        //  myvector.resize(5);
        //  myvector.resize(8,100);
        //  myvector.resize(12);

        //  std::cout << "myvector contains:";
        //  for (int i=0;i<(int)myvector.size();i++)
        //    std::cout << ' ' << myvector[i];
        //  std::cout << '\n';

    /*                                                ft::vector::capacity                                                     */

		//int sz = 100;
		//ft::vector<int> v;
		//uint cap = v.capacity();
		//std::cout << "Initial size: " << v.size() << ", capacity: " << cap << '\n';
		//std::cout << "\nDemonstrate the capacity's growth policy."
		//			"\nSize:  Capacity:  Ratio:\n" << std::left;
		//while (sz-- > 0) {
		//	v.push_back(sz);
		//	if (cap != v.capacity()) {
		//		std::cout << std::setw( 7) << v.size()
		//				<< std::setw(11) << v.capacity()
		//				<< std::setw(10) << v.capacity() / static_cast<float>(cap) << '\n';
		//		cap = v.capacity();
		//	}
		//}
		//std::cout << "\nFinal size: " << v.size() << ", capacity: " << v.capacity() << '\n';

    /*                                                ft::vector::reserve                                                      */

        // ft::vector<int>::size_type sz;
        //   ft::vector<int> foo;
        //   sz = foo.capacity();
        //   std::cout << "making foo grow:\n";
        //   for (int i=0; i<100; ++i) {
        //     foo.push_back(i);
        //     if (sz!=foo.capacity()) {
        //       sz = foo.capacity();
        //       std::cout << "capacity changed: " << sz << '\n';
        //     }
        //   }
        //   ft::vector<int> bar;
        //   sz = bar.capacity();
        //   bar.reserve(100);   // this is the only difference with foo above
        //   std::cout << "making bar grow:\n";
        //   for (int i=0; i<100; ++i) {
        //     bar.push_back(i);
        //     if (sz!=bar.capacity()) {
        //       sz = bar.capacity();
        //       std::cout << "capacity changed: " << sz << '\n';
        //     }
        //   }

    /*                                                ft::vector::front                                                        */

        // ft::vector<int> myvector;
        // myvector.push_back(78);
        // myvector.push_back(16);
        // //now front equals 78, and back 16
        // myvector.front() -= myvector.back();
        // std::cout << "myvector.front() is now " << myvector.front() << '\n';

    /*                                                ft::vector::back                                                         */

        // ft::vector<int> myvector;
        //   myvector.push_back(10);
        //   while (myvector.back() != 0)
        //   {
        //     myvector.push_back ( myvector.back() -1 );
        //   }
        //   std::cout << "myvector contains:";
        //   for (unsigned i=0; i<myvector.size() ; i++)
        //     std::cout << ' ' << myvector[i];
        //   std::cout << '\n';

    /*                                                ft::vector::operator[]                                                   */

        // ft::vector<int> myvector (10);   // 10 zero-initialized elements
        // ft::vector<int>::size_type sz = myvector.size();
        // // assign some values:
        // for (unsigned i=0; i<sz; i++) myvector[i]=i;
        // // reverse vector using operator[]:
        // for (unsigned i=0; i<sz/2; i++)
        // {
        //     int temp;
        //     temp = myvector[sz-1-i];
        //     myvector[sz-1-i]=myvector[i];
        //     myvector[i]=temp;
        // }
        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<sz; i++)
        //     std::cout << ' ' << myvector[i];
        // std::cout << '\n';

    /*                                                ft::vector::at                                                           */

        //   ft::vector<int> myvector (10);   // 10 zero-initialized ints
        //   // assign some values:
        //   try {
        //   for (unsigned i=0; i<myvector.size() + 1; i++)
        //     myvector.at(i)=i;
        //   }
        //   catch (const std::out_of_range& oor) {
        //     std::cerr << "Out of Range error: " << oor.what() << '\n';
        //   }
        //   std::cout << "myvector contains:";
        //   for (unsigned i=0; i<myvector.size(); i++)
        //     std::cout << ' ' << myvector.at(i);
        //   std::cout << '\n';

    /*                                                ft::vector::assign                                                       */

        // ft::vector<int> first;
        // ft::vector<int> second;
        // ft::vector<int> third;
        // first.assign (7,100);             // 7 ints with a value of 100
        // ft::vector<int>::iterator it;
        // it=first.begin() + 1;
        // second.assign (it,first.end()-1); // the 5 central values of first
        // int myints[] = {1776,7,4};
        // third.assign (myints,myints+3);   // assigning from array.
        // std::cout << "Size of first: " << int (first.size()) << '\n';
        // std::cout << "Size of second: " << int (second.size()) << '\n';
        // std::cout << "Size of third: " << int (third.size()) << '\n';

    /*                                                ft::vector::insert                                                       */

        // ft::vector<int> myvector (3,100);
        // ft::vector<int>::iterator it;
        // it = myvector.begin();
        // it = myvector.insert ( it , 200 );
        // myvector.insert (it,2,300);
        // // "it" no longer valid, get a new one:
        // it = myvector.begin();
        // ft::vector<int> anothervector (2,400);
        // myvector.insert (it+2,anothervector.begin(),anothervector.end());
        // int myarray [] = { 501,502,503 };
        // myvector.insert (myvector.begin(), myarray, myarray+3);
        // std::cout << "myvector contains:";
        // for (it=myvector.begin(); it<myvector.end(); it++)
        //     std::cout << ' ' << *it;
        // std::cout << '\n';

    /*                                                ft::vector::erase                                                        */

        //ft::vector<int> myvector;
        //// set some values (from 1 to 10)
        //for (int i=1; i<=10; i++) myvector.push_back(i);
        //// erase the 6th element
        //myvector.erase (myvector.begin()+5);
        //// erase the first 3 elements:
        //myvector.erase (myvector.begin(),myvector.begin()+3);
        //std::cout << "myvector contains:";
        //for (unsigned i=0; i<myvector.size(); ++i)
        //    std::cout << ' ' << myvector[i];
        //std::cout << '\n';

    /*                                                ft::vector::push_back                                                    */

    //   ft::vector<int> myvector;
    //   int myint;
    //   std::cout << "Please enter some integers (enter 0 to end):\n";
    //   do {
    //     std::cin >> myint;
    //     myvector.push_back (myint);
    //   } while (myint);
    //   std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    //    for (unsigned i=0; i<myvector.size(); ++i)
    //        std::cout << ' ' << myvector[i];
    //    std::cout << '\n';

    /*                                                ft::vector::pop_back                                                     */

        // ft::vector<int> myvector;
        // int sum (0);
        // myvector.push_back (100);
        // myvector.push_back (200);
        // myvector.push_back (300);
        // while (!myvector.empty())
        // {
        //     sum+=myvector.back();
        //     myvector.pop_back();
        // }
        // std::cout << "The elements of myvector add up to " << sum << '\n';

    /*                                                ft::vector::clear                                                        */

        // ft::vector<int> myvector;
        // myvector.push_back (100);
        // myvector.push_back (200);
        // myvector.push_back (300);
        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<myvector.size(); i++)
        //     std::cout << ' ' << myvector[i];
        // std::cout << '\n';
        // myvector.clear();
        // myvector.push_back (1101);
        // myvector.push_back (2202);
        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<myvector.size(); i++)
        //     std::cout << ' ' << myvector[i];
        // std::cout << '\n';

    /*                                                ft::vector::swap                                                         */

        // ft::vector<int> foo (3,100);   // three ints with a value of 100
        // ft::vector<int> bar (5,200);   // five ints with a value of 200
        // foo.swap(bar);
        // std::cout << "foo contains:";
        // for (unsigned i=0; i<foo.size(); i++)
        // std::cout << ' ' << foo[i];
        // std::cout << '\n';
        // std::cout << "bar contains:";
        // for (unsigned i=0; i<bar.size(); i++)
        // std::cout << ' ' << bar[i];
        // std::cout << '\n';
        // std::cout << foo.capacity() << std::endl;
        // std::cout << bar.capacity() << std::endl;

    /*                                                ft::vector::get_allocator                                                */

        // ft::vector<int> myvector;
        // int * p;
        // unsigned int i;
        // // allocate an array with space for 5 elements using vector's allocator:
        // p = myvector.get_allocator().allocate(5);
        // // construct values in-place on the array:
        // for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
        // std::cout << "The allocated array contains:";
        // for (i=0; i<5; i++) std::cout << ' ' << p[i];
        // std::cout << '\n';
        // // destroy and deallocate:
        // for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
        // myvector.get_allocator().deallocate(p,5);

    /*                                           Non-member function overloads ft::operators                                   */

        //  ft::vector<int> alice(1, 1);
        // alice.push_back(2);
        // alice.push_back(3);
        // ft::vector<int> bob(1, 7);
        // bob.push_back(8);
        // bob.push_back(9);
        // bob.push_back(10);
        // ft::vector<int> eve (1, 1);
        // eve.push_back(2);
        // eve.push_back(3);
        // std::cout << std::boolalpha;
        // // Compare non equal containers
        // std::cout << "alice == bob returns " << (alice == bob) << '\n';
        // std::cout << "alice != bob returns " << (alice != bob) << '\n';
        // std::cout << "alice <  bob returns " << (alice < bob) << '\n';
        // std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
        // std::cout << "alice >  bob returns " << (alice > bob) << '\n';
        // std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
        // std::cout << '\n';
        // // Compare equal containers
        // std::cout << "alice == eve returns " << (alice == eve) << '\n';
        // std::cout << "alice != eve returns " << (alice != eve) << '\n';
        // std::cout << "alice <  eve returns " << (alice < eve) << '\n';
        // std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
        // std::cout << "alice >  eve returns " << (alice > eve) << '\n';
        // std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
        // ft::vector<int> foo (3,100);   // three ints with a value of 100
        // ft::vector<int> bar (2,200);   // two ints with a value of 200
        // if (foo==bar) std::cout << "foo and bar are equal\n";
        // if (foo!=bar) std::cout << "foo and bar are not equal\n";
        // if (foo< bar) std::cout << "foo is less than bar\n";
        // if (foo> bar) std::cout << "foo is greater than bar\n";
        // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
        // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

    /*                                           Non-member function overloads ft::swap                                        */

        // ft::vector<int> foo (3,100);   // three ints with a value of 100
        // ft::vector<int> bar (5,200);   // five ints with a value of 200
        // foo.swap(bar);
        // std::cout << "foo contains:";
        // for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
        //     std::cout << ' ' << *it;
        // std::cout << '\n';
        // std::cout << "bar contains:";
        // for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
        //     std::cout << ' ' << *it;
        // std::cout << '\n';

    //////////////////////////////////////////////////////// TEST STACK /////////////////////////////////////////////////////////
    /*                                                  ft::stack::constructor                                                 */

		//std::deque<int> mydeque (3,100);          // deque with 3 elements
        //ft::vector<int> myvector (2,200);        // vector with 2 elements
        //ft::stack<int> first;                    // empty stack
        //ft::stack<int> second (myvector);         // stack initialized to copy of deque
        //ft::stack<int,ft::vector<int> > third;  // empty stack using vector
        //ft::stack<int,ft::vector<int> > fourth (myvector);
    	//std::cout << "size of first: " << first.size() << '\n';
    	//std::cout << "size of second: " << second.size() << '\n';
    	//std::cout << "size of third: " << third.size() << '\n';
    	//std::cout << "size of fourth: " << fourth.size() << '\n';

    /*                                                      ft::stack::empty                                                   */

        // ft::stack<int> mystack;
        // int sum (0);
        // for (int i=1;i<=10;i++) mystack.push(i);
        // while (!mystack.empty())
        // {
        //     sum += mystack.top();
        //     mystack.pop();
        // }
        // std::cout << "total: " << sum << '\n';

    /*                                                      ft::stack::size                                                    */

        // ft::stack<int> myints;
        // std::cout << "0. size: " << myints.size() << '\n';
        // for (int i=0; i<5; i++) myints.push(i);
        // std::cout << "1. size: " << myints.size() << '\n';
        // myints.pop();
        // std::cout << "2. size: " << myints.size() << '\n';

    /*                                                      ft::stack::top                                                     */

        // ft::stack<int> mystack;
        // mystack.push(10);
        // mystack.push(20);
        // mystack.top() -= 5;
        // std::cout << "mystack.top() is now " << mystack.top() << '\n';

    /*                                                      ft::stack::push                                                    */

        // ft::stack<int> mystack;
        // for (int i=0; i<5; ++i) mystack.push(i);
        // std::cout << "Popping out elements...";
        // while (!mystack.empty())
        // {
        //     std::cout << ' ' << mystack.top();
        //     mystack.pop();
        // }
        // std::cout << '\n';

    /*                                                      ft::stack::pop                                                     */

        // ft::stack<int> mystack;
        // for (int i=0; i<5; ++i) mystack.push(i);
        // std::cout << "Popping out elements...";
        // while (!mystack.empty())
        // {
        //     std::cout << ' ' << mystack.top();
        //     mystack.pop();
        // }
        // std::cout << '\n';

    /*                                                      ft::stack::operators                                               */

        //std::cout << " \n MY STACK" << '\n';
		//ft::stack<int> alice;
        //ft::stack<int> bob;
        //ft::stack<int> eve;
        //alice.push(1);
        //alice.push(2);
        //alice.push(3);
        //bob.push(7);
        //bob.push(8);
        //bob.push(9);
        //bob.push(10);
        //eve.push(1);
        //eve.push(2);
        //eve.push(3);
        //std::cout << std::boolalpha;
        //// Compare non equal containers
        //std::cout << "alice == bob returns " << (alice == bob) << '\n';
        //std::cout << "alice != bob returns " << (alice != bob) << '\n';
        //std::cout << "alice <  bob returns " << (alice < bob) << '\n';
        //std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
        //std::cout << "alice >  bob returns " << (alice > bob) << '\n';
        //std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
        //std::cout << '\n';
        //// Compare equal containers
        //std::cout << "alice == eve returns " << (alice == eve) << '\n';
        //std::cout << "alice != eve returns " << (alice != eve) << '\n';
        //std::cout << "alice <  eve returns " << (alice < eve) << '\n';
        //std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
        //std::cout << "alice >  eve returns " << (alice > eve) << '\n';
        //std::cout << "alice >= eve returns " << (alice >= eve) << '\n';

        //std::cout << " \n TRUE STACK" << '\n';


		//std::stack<int> alices;
        //std::stack<int> bobs;
        //std::stack<int> eves;
        //alices.push(1);
        //alices.push(2);
        //alices.push(3);
        //bobs.push(7);
        //bobs.push(8);
        //bobs.push(9);
        //bobs.push(10);
        //eves.push(1);
        //eves.push(2);
        //eves.push(3);
        //std::cout << std::boolalpha;
        //// Compare non equal containers
        //std::cout << "alice == bob returns " << (alices == bobs) << '\n';
        //std::cout << "alice != bob returns " << (alices != bobs) << '\n';
        //std::cout << "alice <  bob returns " << (alices < bobs) << '\n';
        //std::cout << "alice <= bob returns " << (alices <= bobs) << '\n';
        //std::cout << "alice >  bob returns " << (alices > bobs) << '\n';
        //std::cout << "alice >= bob returns " << (alices >= bobs) << '\n';
        //std::cout << '\n';
        //// Compare equal containers
        //std::cout << "alice == eve returns " << (alices == eves) << '\n';
        //std::cout << "alice != eve returns " << (alices != eves) << '\n';
        //std::cout << "alice <  eve returns " << (alices < eves) << '\n';
        //std::cout << "alice <= eve returns " << (alices <= eves) << '\n';
        //std::cout << "alice >  eve returns " << (alices > eves) << '\n';
        //std::cout << "alice >= eve returns " << (alices >= eves) << '\n';

    ////////////////////////////////////////////////////////// TEST PAIR ////////////////////////////////////////////////////////
    /*                                                      ft::make_pair                                                      */

    //   ft::pair <int,int> foo;
    //   ft::pair <int,int> bar;
    //   foo = ft::make_pair (10,20);
    //   bar = ft::make_pair (10.5,'A');
    //   std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
    //   std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

    /*                                                      ft::pair constructor                                               */

        // ft::pair <std::string,double> product1;                     // default constructor
        // ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
        // ft::pair <std::string,double> product3 (product2);          // copy constructor
        // product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
        // product2.first = "shoes";                  // the type of first is string
        // product2.second = 39.90;                   // the type of second is double
        // std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
        // std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
        // std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

    /*                                                      ft::pair::operator=                                                */

    // ft::pair <std::string,int> planet, homeplanet;
    // planet = ft::make_pair("Earth",6371);
    // homeplanet = planet;
    // std::cout << "Home planet: " << homeplanet.first << '\n';
    // std::cout << "Planet size: " << homeplanet.second << '\n';

    /*                                                      ft::pair::relational operators                                     */

    //   ft::pair<int,char> foo (10,'z');
    //   ft::pair<int,char> bar (90,'a');
    //   if (foo==bar) std::cout << "foo and bar are equal\n";
    //   if (foo!=bar) std::cout << "foo and bar are not equal\n";
    //   if (foo< bar) std::cout << "foo is less than bar\n";
    //   if (foo> bar) std::cout << "foo is greater than bar\n";
    //   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    //   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

    ////////////////////////////////////////////////////////// TEST MAP /////////////////////////////////////////////////////////
    /*                                                      ft::map::constructor                                               */

		//ft::map<char,int> first;

		//first['a']=10;
		//first['b']=30;
		//first['c']=50;
		//first['d']=70;

		//ft::map<char,int> second (first.begin(),first.end());

		//ft::map<char,int> third (second);


    /*                                                      ft::map::operator=                                                 */

		// ft::map<char,int> first;
		// ft::map<char,int> second;
		// first['x']=8;
		// first['y']=16;
		// first['z']=32;
        // second=first;                // second now contains 3 ints
        // first=ft::map<char,int>();  // and first is now empty

		// std::cout << "Size of first: " << first.size() << '\n';
		// std::cout << "Size of second: " << second.size() << '\n';

    /*                                                      ft::map::begin                                                     */

		//ft::map<char,int> mymap;
		//mymap['b'] = 100;
		//mymap['a'] = 200;
		//mymap['c'] = 300;
		//// show content:
		//for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		//	std::cout << it->first << " => " << it->second << '\n';

    /*                                                      ft::map::end                                                       */

		//ft::map<char,int> mymap;
		//mymap['b'] = 100;
		//mymap['a'] = 200;
		//mymap['c'] = 300;
		//mymap['j'] = 400;
		//// show content:
		//for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		//	std::cout << it->first << " => " << it->second << '\n';

    /*                                                      ft::map::rbegin                                                    */

		//ft::map<char,int> mymap;
		//mymap['x'] = 100;
		//mymap['y'] = 200;
		//mymap['z'] = 300;
		//// show content:
		//ft::map<char,int>::reverse_iterator rit;
		//for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		//	std::cout << rit->first << " => " << rit->second << '\n';

    /*                                                      ft::map::rend                                                      */

		//ft::map<char,int> mymap;
		//mymap['x'] = 100;
		//mymap['y'] = 200;
		//mymap['z'] = 300;
		//mymap['h'] = 50;
		//mymap['o'] = 75;
		//// show content:
		//ft::map<char,int>::reverse_iterator rit;
		//for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		//	std::cout << rit->first << " => " << rit->second << '\n';

    /*                                                      ft::map::size                                                      */

		//ft::map<char,int> mymap;
		//mymap['a']=101;
		//mymap['b']=202;
		//mymap['c']=302;
		//std::cout << "mymap.size() is " << mymap.size() << '\n';

    /*                                                      ft::map::max_size                                                  */

		//int i;
		//ft::map<int,int> mymap;
		//if (mymap.max_size()>1000) {
		//	for (i=0; i<1000; i++) mymap[i]=0;
		//	std::cout << "The map contains 1000 elements.\n";
		//}
		//else std::cout << "The map could not hold 1000 elements.\n";

    /*                                                      ft::map::empty                                                     */

		// ft::map<char,int> mymap;
		// mymap['a']=10;
		// mymap['b']=20;
		// mymap['c']=30;
		// while (!mymap.empty())
		// {
		// 	std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		// 	mymap.erase(mymap.begin());
		// }

    /*                                                      ft::map::operator[]                                                */

		//ft::map<char,std::string> mymap;
		//mymap['a']="an element";
		//mymap['b']="another element";
		//mymap['c']=mymap['b'];
		//std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		//std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		//std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		//std::cout << "mymap['d'] is " << mymap['d'] << '\n';
		//std::cout << "mymap now contains " << mymap.size() << " elements.\n";

    /*                                                      ft::map::insert                                                    */

	//ft::map<char,int> mymap;
	//// first insert function version (single parameter):
	//mymap.insert ( ft::pair<char,int>('a',100) );
	//mymap.insert ( ft::pair<char,int>('z',200) );
	//ft::pair<ft::map<char,int>::iterator,bool> ret;
	//ret = mymap.insert ( ft::pair<char,int>('z',500) );
	//if (ret.second==false) {
	//	std::cout << "element 'z' already existed";
	//	std::cout << " with a value of " << ret.first->second << '\n';
	//}
	//// second insert function version (with hint position):
	//ft::map<char,int>::iterator it = mymap.begin();
	//mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
	//mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
	//// third insert function version (range insertion):
	//ft::map<char,int> anothermap;
	//anothermap.insert(mymap.begin(),mymap.find('c'));
	//// showing contents:
	//std::cout << "mymap contains:\n";
	//for (it=mymap.begin(); it!=mymap.end(); ++it)
	//	std::cout << it->first << " => " << it->second << '\n';
	//std::cout << "anothermap contains:\n";
	//for (it=anothermap.begin(); it!=anothermap.end(); ++it)
	//	std::cout << it->first << " => " << it->second << '\n';

    /*                                                      ft::map::erase                                                     */
        // ft::map<char,int> mymap;
        // ft::map<char,int>::iterator it;
        // mymap['a']=10;
        // mymap['b']=20;
        // mymap['c']=30;
        // mymap['d']=40;
        // mymap['e']=50;
        // mymap['f']=60;
        // it=mymap.find('b');
        // mymap.erase (it);                   // erasing by iterator
        // mymap.erase ('c');                  // erasing by key
        // it=mymap.find ('e');
        // mymap.erase ( it, mymap.end() );    // erasing by range
        // for (it=mymap.begin(); it!=mymap.end(); ++it)
        //     std::cout << it->first << " => " << it->second << '\n';

    /*                                                      ft::map::clear                                                     */

        // ft::map<char,int> mymap;
        // mymap['x']=100;
        // mymap['y']=200;
        // mymap['z']=300;
        // std::cout << "mymap contains:\n";
        // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        //     std::cout << it->first << " => " << it->second << '\n';
        // mymap.clear();
        // mymap['a']=1101;
        // mymap['b']=2202;
        // std::cout << "mymap contains:\n";
        // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        //     std::cout << it->first << " => " << it->second << '\n';

    /*                                                      ft::map::swap                                                      */

		//ft::map<char,int> foo,bar;
		//foo['x']=100;
		//foo['y']=200;
		//bar['a']=11;
		//bar['b']=22;
		//bar['c']=33;
		//foo.swap(bar);
		//std::cout << "foo contains:\n";
		//for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		//	std::cout << it->first << " => " << it->second << '\n';
		//std::cout << "bar contains:\n";
		//for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		//	std::cout << it->first << " => " << it->second << '\n';

    /*                                                      ft::map::count                                                     */

		//ft::map<char,int> mymap;
		//char c;
		//mymap ['a']=101;
		//mymap ['c']=202;
		//mymap ['f']=303;
		//for (c='a'; c<'h'; c++)
		//{
		//	std::cout << c;
		//	if (mymap.count(c)>0)
		//		std::cout << " is an element of mymap.\n";
		//	else
		//		std::cout << " is not an element of mymap.\n";
		//}

    /*                                                      ft::map::find                                                      */

	// ft::map<char,int> mymap;
	// ft::map<char,int>::iterator it;
	// mymap['a']=50;
	// mymap['b']=100;
	// mymap['c']=150;
	// mymap['d']=200;
	// it = mymap.find('b');
	// //if (it != mymap.end())
	// //	mymap.erase (it);
	// // print content:
	// std::cout << "elements in mymap:" << '\n';
	// std::cout << "a => " << mymap.find('a')->second << '\n';
	// std::cout << "c => " << mymap.find('c')->second << '\n';
	// std::cout << "d => " << mymap.find('d')->second << '\n';

    /*                                                      ft::map::equal_range                                               */

    // ft::map<char,int> mymap;
    // mymap['a']=10;
    // mymap['b']=20;
    // mymap['c']=30;
    // ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    // ret = mymap.equal_range('b');
    // std::cout << "lower bound points to: ";
    // std::cout << ret.first->first << " => " << ret.first->second << '\n';
    // std::cout << "upper bound points to: ";
    // std::cout << ret.second->first << " => " << ret.second->second << '\n';

    /*                                       ft::map::lower_bound & ft::map::upper_bound                                       */

    // ft::map<char,int> mymap;
    // ft::map<char,int>::iterator itlow,itup;
    // mymap['a']=20;
    // mymap['b']=40;
    // mymap['c']=60;
    // mymap['d']=80;
    // mymap['e']=100;
    // itlow=mymap.lower_bound ('b');  // itlow points to b
    // itup=mymap.upper_bound ('d');   // itup points to e (not d!)
    // mymap.erase(itlow,itup);        // erases [itlow,itup)
    // // print content:
    // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';

    /*                                                      ft::map::get_allocator                                             */

        // int psize;
        // ft::map<char,int> mymap;
        // ft::pair<const char,int>* p;
        // // allocate an array of 5 elements using mymap's allocator:
        // p=mymap.get_allocator().allocate(5);
        // // assign some values to array
        // psize = sizeof(ft::map<char,int>::value_type)*5;
        // std::cout << "The allocated array has a size of " << psize << " bytes.\n";
        // mymap.get_allocator().deallocate(p,5);

    /*                                                      ft::map::key_comp                                                  */

        // ft::map<char,int> mymap;
        // ft::map<char,int>::key_compare mycomp = mymap.key_comp();
        // mymap['a']=100;
        // mymap['b']=200;
        // mymap['c']=300;
        // std::cout << "mymap contains:\n";
        // char highest = mymap.rbegin()->first;     // key value of last element
        // ft::map<char,int>::iterator it = mymap.begin();
        // do {
        //     std::cout << it->first << " => " << it->second << '\n';
        // } while ( mycomp((*it++).first, highest) );

    /*                                                      ft::map::value_comp                                                */

        // ft::map<char,int> mymap;
        // mymap['x']=1001;
        // mymap['y']=2002;
        // mymap['z']=3003;
        // std::cout << "mymap contains:\n";
        // ft::pair<char,int> highest = *mymap.rbegin();          // last element
        // ft::map<char,int>::iterator it = mymap.begin();
        // do {
        //     std::cout << it->first << " => " << it->second << '\n';
        // } while ( mymap.value_comp()(*it++, highest) );

    return 0;
};
