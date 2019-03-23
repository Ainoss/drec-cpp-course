#include "test_runner.h"
#include "queue.h"

#include<algorithm>

using namespace std;

void ListQueueTest() {
	{
		ListQueue<int> q;
		try {
			q.enqueue(5);
			Assert(q.dequeue(), 5, "Basic test with one adding");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Basic test with one adding");
		}
	}

	{
		ListQueue<int> q;
		try {
			q.enqueue(5);
			q.enqueue(6);
			Assert(q.dequeue(), 5, "Basic test with two adds");
			Assert(q.dequeue(), 6, "Basic test with two adds");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Basic test with two adds");
		}
	}

	{
		ListQueue<int> q;
		try {
			q.dequeue();
			throw runtime_error("Assertion failed: expected exception wasn't thrown in empty queue test");
		} catch( range_error& er) {
		}
	}

	{
		ListQueue<int> q;
		try {
			q.enqueue(1);
			Assert(q.dequeue(), 1, "Empty queue test with adding");
			q.dequeue();
			throw runtime_error("Assertion failed: expected exception wasn't thrown in empty queue test with adding");
		} catch( range_error& er) {
		}
	}

	{
		ListQueue<int> q;
		try {
			q.enqueue(5);
			Assert(q.dequeue(), 5, "Add - del - Add - del");
			q.enqueue(6);
			Assert(q.dequeue(), 6, "Add - del - Add - del");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Add - del - Add - del");
		}
	}

	{
		ListQueue<int> q;
		try {
			Assert(q.getLength(), 0u, "Length test for empty queue");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Length test for empty queue");
		}
	}

	{
		ListQueue<int> q;
		try {
			q.enqueue(1);
			Assert(q.getLength(), 1u, "Length test for queue with one element");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Length test for queue with one element");
		}
	}

	{
		ListQueue<int> q;
		try {
			q.enqueue(1);
			q.enqueue(2);
			Assert(q.getLength(), 2u, "Length test for queue with two elements");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Length test for queue with two elements");
		}
	}

	{
		ListQueue<string> q;
		try {
			q.enqueue("one");
			q.enqueue("two");
			Assert(q.getLength(), 2u, "Length test for queue with two string elements");
			Assert(q.dequeue(), "one", "Basic test for strings");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Basic test for strings");
		}
	}
}

void ArrayQueueTest() {
	{
		try {
			ArrayQueue<int, 4> q;
			q.dequeue();
			throw runtime_error("Assertion failed: expected exception wasn't thrown in empty queue test");
		} catch( range_error& er) {
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			Assert(q.dequeue(), 1, "Del of one element");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Del of one element");
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			q.dequeue();
			q.enqueue(2);
			Assert(q.dequeue(), 2, "add - del - add - del");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in add - del - add -del");
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			q.dequeue();
			q.dequeue();
			throw runtime_error("Assertion failed: expected exception wasn't thrown in one element queue test");
		} catch( range_error& er) {
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(3);
			Assert(q.dequeue(), 1, "Three of Four elements test");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Three of Four elements test");
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(3);
			q.enqueue(4);
			Assert(q.dequeue(), 1, "Four of Four elements test");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Four of Four elements test");
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(3);
			q.enqueue(4);
			q.enqueue(5);
			throw runtime_error("Assertion failed: expected exception wasn't thrown in full queue test");
		} catch( range_error& er) {
		}
	}
	{
		try {
			ArrayQueue<int> q;
			for(int i = 1; i <= 64; i++){
				q.enqueue(i);
			}
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in 64/64 test");
		}
	}

	{
		try {
			ArrayQueue<int> q;
			for(int i = 1; i <= 65; i++){
				q.enqueue(i);
			}
			throw runtime_error("Assertion failed: expected exception wasn't thrown in 65/64 test");
		} catch( range_error& er) {
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			Assert(q.getLength(), 0u, "Length test for empty queue");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Length test for empty queue");
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			Assert(q.getLength(), 1u, "Length test for one element queue");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Length test for one element queue");
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			q.enqueue(2);
			Assert(q.getLength(), 2u, "Length test for two elements queue");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Length test for two elements queue");
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			q.enqueue(2);
			q.dequeue();
			Assert(q.getLength(), 1u, "Length test for del");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Length test for del");
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			q.enqueue(2);
			q.dequeue();
			q.dequeue();
			Assert(q.getLength(), 0u, "Length test for all queue del");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Length test for all queue del");
		}
	}

	{
		try {
			ArrayQueue<int, 4> q;
			q.enqueue(1);
			q.enqueue(2);
			q.dequeue();
			q.dequeue(); // first = 2 = last
			q.enqueue(3);
			q.enqueue(4); // first = 2, last = 0
			Assert(q.getLength(), 2u, "Length test for last < first");
		} catch( range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in Length test for last < first");
		}
	}
}

void BasicQueueTest() {
	string testName;
	{
		try {
			testName = "First Basic Queue test {List based}";
			ListQueue<int> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			pq->enqueue(2);
			Assert(pq->dequeue(), 1, testName);
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}

	{
		try {
			testName = "Second Basic Queue test {List based}";
			ListQueue<int> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			Assert(pq->dequeue(), 1, testName);
			pq->dequeue();
			throw runtime_error("Assertion failed: expected exception wasn't thrown in " + testName);
		} catch(range_error& er) {
		}
	}

	{
		try {
			testName = "Third Basic Queue test {List based}";
			ListQueue<int> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			pq->enqueue(2);
			Assert(pq->dequeue(), 1, testName);
			Assert(pq->dequeue(), 2, testName);
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}

	{
		try {
			testName = "Fourth Basic Queue test {List based}";
			ListQueue<int> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			pq->enqueue(2);
			Assert(pq->dequeue(), 1, testName);
			Assert(pq->dequeue(), 2, testName);
			pq->dequeue();
			throw runtime_error("Assertion failed: expected exception wasn't thrown in " + testName);
		} catch(range_error& er) {
		}
	}

	{
		try {
			testName = "First Basic Queue test {Array based}";
			ArrayQueue<int, 4> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			pq->enqueue(2);
			Assert(pq->dequeue(), 1, testName);
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}

	{
		try {
			testName = "Second Basic Queue test {Array based}";
			ArrayQueue<int, 4> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			pq->enqueue(2);
			Assert(pq->dequeue(), 1, testName);
			Assert(pq->dequeue(), 2, testName);
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}

	{
		try {
			testName = "Third Basic Queue test {Array based}";
			ArrayQueue<int, 4> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			pq->enqueue(2);
			Assert(pq->dequeue(), 1, testName);
			Assert(pq->dequeue(), 2, testName);
			pq->dequeue();
			throw runtime_error("Assertion failed: expected exception wasn't thrown in " + testName);
		} catch(range_error& er) {
		}
	}

	{
		try {
			testName = "Fourth Basic Queue test {Array based}";
			ArrayQueue<int, 4> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			pq->enqueue(2);
			pq->enqueue(3);
			pq->enqueue(4);
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}

	{
		try {
			testName = "Fiveth Basic Queue test {Array based}";
			ArrayQueue<int, 4> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			pq->enqueue(2);
			pq->enqueue(3);
			pq->enqueue(4);
			pq->enqueue(5);
			throw runtime_error("Assertion failed: expected exception wasn't thrown in " + testName);
		} catch(range_error& er) {
		}
	}

	{
		try {
			testName = "Sixth Basic Queue test {Array based}";
			ArrayQueue<int> q;
			BasicQueue<int>* pq = &q;
			for(int i = 1; i <= 64; i++){
				pq->enqueue(i);
			}
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}

	{
		try {
			testName = "Seventh Basic Queue test {Array based}";
			ArrayQueue<int> q;
			BasicQueue<int>* pq = &q;
			for(int i = 1; i <= 65; i++){
				pq->enqueue(i);
			}
			throw runtime_error("Assertion failed: expected exception wasn't thrown in " + testName);
		} catch(range_error& er) {
		}
	}

	{
		try {
			testName = "First Basic Queue test {Length}";
			ListQueue<int> q;
			BasicQueue<int>* pq = &q;
			Assert(pq->getLength(), 0u, testName);
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}

	{
		try {
			testName = "Second Basic Queue test {Length}";
			ListQueue<int> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			Assert(pq->getLength(), 1u, testName);
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}

	{
		try {
			testName = "Third Basic Queue test {Length}";
			ArrayQueue<int> q;
			BasicQueue<int>* pq = &q;
			Assert(pq->getLength(), 0u, testName);
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}

	{
		try {
			testName = "Fourth Basic Queue test {Length}";
			ArrayQueue<int> q;
			BasicQueue<int>* pq = &q;
			pq->enqueue(1);
			Assert(pq->getLength(), 1u, testName);
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}

	{
		try {
			testName = "Fiveth Basic Queue test {Length}";
			ArrayQueue<int> q1;
			ListQueue<int> q2;
			BasicQueue<int>* pq1 = &q1;
			BasicQueue<int>* pq2 = &q2;
			pq1->enqueue(1);
			pq2->enqueue(2);
			Assert(pq1->getLength(), pq2->getLength(), testName);
		} catch(range_error& er) {
			throw runtime_error("Assertion failed: thrown unexpected exception in " + testName);
		}
	}
}