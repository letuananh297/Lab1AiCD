#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_at) 
		{
			List list1, list2;
			bool check1 = 0, check2 = 0, check3 = 0;

			//When list is empty
			try
			{
				list1.at(1);
			}
			catch(std::logic_error)
			{
				check1 = 1;
			}
			Assert::IsTrue(check1);

			for (int i = 1; i < 5; i++)
				list2.push_back(2 * i);  
			//list2: 2 4 6 8
			Assert::AreEqual(list2.at(1), 2);
			Assert::AreEqual(list2.at(2), 4);
			Assert::AreEqual(list2.at(3), 6);
			Assert::AreEqual(list2.at(4), 8);

			//When index < 1
			try
			{
				list2.at(0);
			}
			catch (std::invalid_argument)
			{
				check2 = 1;
			}
			Assert::IsTrue(check2);

			//When index > size
			try
			{
				list2.at(10);
			}
			catch (std::invalid_argument)
			{
				check3 = 1;
			}
			Assert::IsTrue(check3);
		}

		TEST_METHOD(Test_getsize) 
		{
			List list1, list2;

			//list1 is empty
			Assert::IsTrue(list1.get_size() == 0);

			for (int i = 100; i > 0; i--)
				list2.push_back(i);
			//list2: 100 elements from 100 to 1
			Assert::IsTrue(list2.get_size() == 100);
		}
		
		TEST_METHOD(Test_pushback)
		{
			List list1, list2;

			list1.push_back(2);
			//list1: 2
			Assert::AreEqual(list1.at(1), 2);
			Assert::IsTrue(list1.get_size() == 1);

			list2.push_back(9);
			list2.push_back(0);
			list2.push_back(7);
			//list2: 9 0 7
			Assert::AreEqual(list2.at(1), 9);
			Assert::AreEqual(list2.at(2), 0);
			Assert::AreEqual(list2.at(3), 7);
			Assert::IsTrue(list2.get_size() == 3);
		}

		TEST_METHOD(Test_pushfront)
		{
			List list1, list2;

			list1.push_front(10);
			//list1: 10
			Assert::AreEqual(list1.at(1), 10);
			Assert::IsTrue(list1.get_size() == 1);

			list2.push_front(0);
			list2.push_front(6);
			list2.push_front(0);
			list2.push_front(4);
			//list2: 4 0 6 0
			Assert::AreEqual(list2.at(1), 4);
			Assert::AreEqual(list2.at(2), 0);
			Assert::AreEqual(list2.at(3), 6);
			Assert::AreEqual(list2.at(4), 0);
			Assert::IsTrue(list2.get_size() == 4);
		}

		TEST_METHOD(Test_popback) 
		{
			List list1, list2, list3;

			list1.push_back(29);
			//list1: 29

			list1.pop_back();
			//list1 is empty

			Assert::IsTrue(list1.isEmpty());
			Assert::IsTrue(list1.get_size() == 0);

			for (int i = 4; i > 0; i--)
				list2.push_back(i);
			//list2: 4 3 2 1

			list2.pop_back();
			//list2: 4 3 2

			Assert::IsTrue(list2.get_size() == 3);
			Assert::AreEqual(list2.at(1), 4);
			Assert::AreEqual(list2.at(2), 3);
			Assert::AreEqual(list2.at(3), 2);

			//When list3 is empty
			bool check = 0;
			try
			{
				list3.pop_back();
			}
			catch (std::logic_error)
			{
				check = 1;
			}
			Assert::IsTrue(check);
		}

		TEST_METHOD(Test_popfront) 
		{
			List list1, list2, list3;

			list1.push_front(6);
			//list1: 6

			list1.pop_front();
			//list1 is empty

			Assert::IsTrue(list1.isEmpty());
			Assert::IsTrue(list1.get_size() == 0);

			for (int i = 1; i < 5; i++)
				list2.push_back(2 * i + 1);
			//list2: 3 5 7 9

			list2.pop_front();
			//list2: 5 7 9

			Assert::IsTrue(list2.get_size() == 3);
			Assert::AreEqual(list2.at(1), 5);
			Assert::AreEqual(list2.at(2), 7);
			Assert::AreEqual(list2.at(3), 9);

			bool check = 0;

			//When list3 is empty
			try
			{
				list3.pop_front();
			}
			catch (std::logic_error)
			{
				check = 1;
			}
			Assert::IsTrue(check);
		}

		TEST_METHOD(Test_insert)
		{
			List list1, list2, list3, list4;
			bool check1 = 0, check2 = 0, check3 = 0, check4 = 0;

			//When list1 is empty and index = 1
			list1.insert(2, 1);
			//list1: 2

			Assert::AreEqual(list1.at(1), 2);
			Assert::IsTrue(list1.get_size() == 1);

			//When list2 is empty but index > 1
			try
			{
				list2.insert(6, 4);
			}
			catch (std::invalid_argument)
			{
				check1 = 1;
			}
			Assert::IsTrue(check1);

			//When list 3 is empty but index < 1
			try
			{
				list3.insert(6, 0);
			}
			catch (std::invalid_argument)
			{
				check2 = 1;
			}
			Assert::IsTrue(check2);

			list4.push_back(9);
			list4.push_back(0);
			list4.push_back(7);
			//list4: 9 0 7

			list4.insert(1, 3); 
			//list4: 9 0 1 7

			Assert::IsTrue(list4.get_size() == 4);
			Assert::AreEqual(list4.at(4), 7);
			Assert::AreEqual(list4.at(3), 1);
			Assert::AreEqual(list4.at(2), 0);
			Assert::AreEqual(list4.at(1), 9);

			//When index < 1
			try
			{
				list4.insert(6, 0);
			}
			catch (std::invalid_argument)
			{
				check3 = 1;
			}
			Assert::IsTrue(check3);

			//When index > size + 1
			try
			{
				list4.insert(6, 10);
			}
			catch (std::invalid_argument)
			{
				check4 = 1;
			}
			Assert::IsTrue(check4);
		}

		TEST_METHOD(Test_remove)
		{
			List list1, list2, list3;

			list1.push_back(7);
			//list1: 7

			list1.remove(1);
			//list1 is empty

			Assert::IsTrue(list1.isEmpty());
			Assert::IsTrue(list1.get_size() == 0);

			for (int i = 5; i > 0; i--)
				list2.push_back(2 * i);
			//list2: 10 8 6 4 2

			list2.remove(4);
			//list2: 10 8 6 2

			Assert::IsTrue(list2.get_size() ==  4);
			Assert::AreEqual(list2.at(1), 10);
			Assert::AreEqual(list2.at(2), 8);
			Assert::AreEqual(list2.at(3), 6);
			Assert::AreEqual(list2.at(4), 2);

			bool check1 = 0, check2 = 0, check3 = 0;

			//When list 3 is empty
			try
			{
				list3.remove(1);
			}
			catch (std::logic_error)
			{
				check1 = 1;
			}
			Assert::IsTrue(check1);

			//When index < 1
			try
			{
				list2.remove(0);
			}
			catch (std::invalid_argument)
			{
				check2 = 1;
			}
			Assert::IsTrue(check2);

			//When index > size
			try
			{
				list2.remove(10);
			}
			catch (std::invalid_argument)
			{
				check3 = 1;
			}
			Assert::IsTrue(check3);
		}

		TEST_METHOD(Test_set)
		{
			List list1, list2;

			for (int i = 4; i > 0; i--)
				list1.push_back(i);
			//list1: 4 3 2 1

			list1.set(2, 9);
			//list1: 4 9 2 1

			Assert::IsTrue(list1.get_size() == 4);
			Assert::AreEqual(list1.at(4), 1);
			Assert::AreEqual(list1.at(3), 2);
			Assert::AreEqual(list1.at(2), 9);
			Assert::AreEqual(list1.at(1), 4);

			bool check1 = 0, check2 = 0, check3 = 0;

			//When list2 is empty
			try
			{
				list2.set(1, 1);
			}
			catch (std::logic_error)
			{
				check1 = 1;
			}
			Assert::IsTrue(check1);

			//When index < 1
			try
			{
				list1.set(0, 1);
			}
			catch (std::invalid_argument)
			{
				check2 = 1;
			}
			Assert::IsTrue(check2);

			//When index > size
			try
			{
				list1.set(10, 1);
			}
			catch (std::invalid_argument)
			{
				check3 = 1;
			}
			Assert::IsTrue(check3);
		}

		TEST_METHOD(Test_clear)
		{
			List list;

			for (int i = 1; i < 10; i++)
				list.push_back(i);
			//list: 1 2 3 4 5 6 7 8 9

			list.clear();
			//list is empty

			Assert::IsTrue(list.isEmpty());
			Assert::IsTrue(list.get_size() == 0);
		}

		TEST_METHOD(Test_isEmpty)
		{
			List list1, list2;

			list2.push_back(64);
			//list1 is empty
			//list2: 64

			Assert::IsTrue(list1.isEmpty());
			Assert::IsTrue(list1.get_size() == 0);

			Assert::IsFalse(list2.isEmpty());
			Assert::IsFalse(list2.get_size() == 0);
		}

		TEST_METHOD(Test_contains)
		{
			List list1, list2, list3, list4;

			for (int i = 1; i < 10; i++)
				list1.push_back(i);
			//list1: 1 2 3 4 5 6 7 8 9

			for (int i = 3; i < 7; i++)
				list2.push_back(i);
			//list2: 3 4 5 6

			for (int i = 4; i < 7; i++)
				list3.push_back(2 * i);
			//list3: 8 10 12

			Assert::IsTrue(list1.contains(list2));
			Assert::IsFalse(list2.contains(list1));
			Assert::IsFalse(list1.contains(list3));

			bool check = 0;

			//When list4 is empty
			try 
			{
				list1.contains(list4);
			}
			catch (std::logic_error) 
			{
				check = 1;
			}
			Assert::IsTrue(check);
		}
	};
}