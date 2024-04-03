#include "pch.h"
#include "CppUnitTest.h"
#include "../Set/set.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SetTest
{
	TEST_CLASS(SetTest)
	{
	public:
		TEST_METHOD(TestAddSingleElement1)
		{
			Set<int> set;
			set.add(5);
			Assert::IsTrue(set.getSize() == 1);
		}

		TEST_METHOD(TestAddSingleElement2)
		{
			Set<int> set;
			set.add(8);
			Assert::IsTrue(set.contain(8));
		}

		TEST_METHOD(TestAddMultipleElements1)
		{
			Set<int> set;
			int elements[] = { 1, 2, 3, 4, 5 };
			set.add(elements, 5);
			Assert::IsTrue(set.getSize() == 5);
		}

		TEST_METHOD(TestAddMultipleElements2)
		{
			Set<int> set;
			int elements[] = { 1, 2, 3, 4, 5, 6 };
			set.add(elements, 6);
			Assert::IsTrue(set.contain(1));
			Assert::IsTrue(set.contain(2));
			Assert::IsTrue(set.contain(3));
			Assert::IsTrue(set.contain(4));
			Assert::IsTrue(set.contain(5));
			Assert::IsTrue(set.contain(6));
		}

		TEST_METHOD(TestRemoveElement1)
		{
			Set<int> set;
			set.add(5).add(10);
			set.remove(5);
			Assert::IsTrue(set.getSize() == 1);
			Assert::IsFalse(set.contain(5));
			Assert::IsTrue(set.contain(10));
		}

		TEST_METHOD(TestRemoveElement2)
		{
			Set<int> set;
			int elements[] = { 1, 2, 3, 4, 5, 6 };
			set.add(elements, 6);
			set.remove(3);
			Assert::IsTrue(set.getSize() == 5);
			Assert::IsFalse(set.contain(3));
			Assert::IsTrue(set.contain(1));
			Assert::IsTrue(set.contain(2));
			Assert::IsTrue(set.contain(4));
			Assert::IsTrue(set.contain(5));
			Assert::IsTrue(set.contain(6));
		}

		TEST_METHOD(TestUnionSet1)
		{
			Set<int> set1, set2, result;
			set1.add(1).add(2).add(3);
			set2.add(3).add(4).add(5);
			result = set1.unionSet(set2);
			Assert::IsTrue(result.getSize() == 5);
			Assert::IsTrue(result.contain(1));
			Assert::IsTrue(result.contain(2));
			Assert::IsTrue(result.contain(3));
			Assert::IsTrue(result.contain(4));
			Assert::IsTrue(result.contain(5));
		}

		TEST_METHOD(TestUnionSet2)
		{
			Set<int> set1, set2, result;
			int elements1[] = {  4, 5, 6 };
			int elements2[] = { 1, 5, 6 };
			set1.add(elements1, 3);
			set2.add(elements2, 3);
			result = set1.unionSet(set2);
			Assert::IsTrue(result.getSize() == 4);
			Assert::IsTrue(result.contain(1));
			Assert::IsFalse(result.contain(2));
			Assert::IsTrue(result.contain(6));
			Assert::IsTrue(result.contain(4));
			Assert::IsTrue(result.contain(5));
		}

		TEST_METHOD(TestIntersect1)
		{
			Set<int> set1, set2, result;
			set1.add(1).add(2).add(3);
			set2.add(3).add(4).add(5);
			result = set1.intersect(set2);
			Assert::IsTrue(result.getSize() == 1);
			Assert::IsTrue(result.contain(3));
			Assert::IsFalse(result.contain(1));
			Assert::IsFalse(result.contain(2));
			Assert::IsFalse(result.contain(4));
			Assert::IsFalse(result.contain(5));
		}

		TEST_METHOD(TestIntersect2)
		{
			Set<int> set1, set2, result;
			int elements1[] = { 1, 2, 3, 7 };
			int elements2[] = { 3, 4, 5, 7 };
			set1.add(elements1, 4);
			set2.add(elements2, 4);
			result = set1.intersect(set2);
			Assert::IsTrue(result.getSize() == 2);
			Assert::IsTrue(result.contain(3));
			Assert::IsTrue(result.contain(7));
		}

		TEST_METHOD(TestDifference1)
		{
			Set<int> set1, set2, result;
			set1.add(1).add(2).add(3);
			set2.add(3).add(4).add(5);
			result = set1.difference(set2);
			Assert::IsTrue(result.getSize() == 2);
			Assert::IsTrue(result.contain(1));
			Assert::IsTrue(result.contain(2));
			Assert::IsFalse(result.contain(3));
			Assert::IsFalse(result.contain(4));
			Assert::IsFalse(result.contain(5));
		}

		TEST_METHOD(TestDifference2)
		{
			Set<int> set1, set2, result;
			int elements1[] = { 1, 2, 3, 7 };
			int elements2[] = { 2, 7 };
			set1.add(elements1, 4);
			set2.add(elements2, 2);
			result = set1.difference(set2);
			Assert::IsTrue(result.getSize() == 2);
			Assert::IsTrue(result.contain(1));
			Assert::IsTrue(result.contain(3));
		}

		TEST_METHOD(TestSymDifference1)
		{
			Set<int> set1, set2, result;
			set1.add(1).add(2).add(3);
			set2.add(3).add(4).add(5);
			result = set1.sym_difference(set2);
			Assert::IsTrue(result.getSize() == 4);
			Assert::IsTrue(result.contain(1));
			Assert::IsTrue(result.contain(2));
			Assert::IsTrue(result.contain(4));
			Assert::IsTrue(result.contain(5));
			Assert::IsFalse(result.contain(3));
		}

		TEST_METHOD(TestSymDifference2)
		{
			Set<int> set1, set2, result;
			int elements1[] = { 1, 2, 3 };
			int elements2[] = { 3, 4, 5 };
			set1.add(elements1, 3);
			set2.add(elements2, 3);
			result = set1.sym_difference(set2);
			Assert::IsTrue(result.getSize() == 4);
			Assert::IsTrue(result.contain(1));
			Assert::IsTrue(result.contain(2));
			Assert::IsTrue(result.contain(4));
			Assert::IsTrue(result.contain(5));
		}

		TEST_METHOD(TestCopyConstructor)
		{
			Set<int> set1;
			set1.add(1).add(2).add(3);
			Set<int> set2(set1);
			Assert::IsTrue(set2.getSize() == 3);
			Assert::IsTrue(set2.contain(1));
			Assert::IsTrue(set2.contain(2));
			Assert::IsTrue(set2.contain(3));
		}

		TEST_METHOD(TestCopyConstructor2)
		{
			Set<int> original;
			original.add(5).add(10).add(15);
			Set<int> copy(original);
			Assert::IsTrue(copy.getSize() == 3);
			Assert::IsTrue(copy.contain(5));
			Assert::IsTrue(copy.contain(10));
			Assert::IsTrue(copy.contain(15));

			original.add(20);
			Assert::IsTrue(original.getSize() == 4);
			Assert::IsFalse(copy.contain(20));
		}

		TEST_METHOD(TestAssignmentOperator1)
		{
			Set<int> set1, set2;
			set1.add(1).add(2).add(3);
			set2 = set1;
			Assert::IsTrue(set2.getSize() == 3);
			Assert::IsTrue(set2.contain(1));
			Assert::IsTrue(set2.contain(2));
			Assert::IsTrue(set2.contain(3));
		}

		TEST_METHOD(TestAssignmentOperator2)
		{
			Set<int> set1;
			set1.add(100).add(200).add(300);
			Set<int> set2;
			set2 = set1;
			Assert::IsTrue(set2.getSize() == 3);
			Assert::IsTrue(set2.contain(100));
			Assert::IsTrue(set2.contain(200));
			Assert::IsTrue(set2.contain(300));

		
			set1.remove(100);
			Assert::IsTrue(set1.getSize() == 2);
			Assert::IsFalse(set1.contain(100));
			Assert::IsTrue(set2.getSize() == 3);
			Assert::IsTrue(set2.contain(100));
		}
	};
}
