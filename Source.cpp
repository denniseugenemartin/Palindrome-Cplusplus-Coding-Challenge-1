
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

	using namespace std;



	void palindromeIterator(vector <int>& palindrome, int& leftPosition, int& rightPosition)
	{
	   // if vector comes in as one element and a 10 that will throw off the rest    
	   // of the logic, so fix that by changing it to a '1' and '' with two elemnts
	   // and move the indexes to the first and last elements.
	    if (palindrome.size()==1 && palindrome[rightPosition]==10)
	    {
	     palindrome[0]=1;
	      palindrome.push_back(1);
	      rightPosition=palindrome.size()-1;
	      return;
	        
	    }
		while (leftPosition < rightPosition)
		{
			// if the left position and right position values are equal move each index
			// in by one and  reloop.
			 if (palindrome[leftPosition] == palindrome[rightPosition])
			{
				leftPosition += 1;
				rightPosition -= 1;
				continue;
			}
			// if the right digit is a 10 digit we store our index positions before editing
		// and we loop as long as the digit being read is a 10. we are basically carrying
		// the one from arithmatic operations until we either reach the first digit and have
		// to add a new element to the vector or we no longer have to carry more digits over.
			else if (palindrome[rightPosition] == 10)
			{
				int originalRightPosition = rightPosition;
				int originalLeftPosition = leftPosition;
				while (palindrome[rightPosition] == 10)
				{
					// if we reach the first digit, then we need to add another digit to the
					// series. Since the first and last will be the same we can set them both
					// equal to one. We can also skip analzying the first and last digit since
					// we know they are equal. We then recall the function with these new values.
					if (rightPosition == 0)
					{
						palindrome[0] = 1;
						for (int i = 1; i < palindrome.size() - 1; ++i)
						{
							palindrome[i] = 0;
						}
						palindrome.push_back(1);
						leftPosition = 1;
						rightPosition = palindrome.size() - 2;
						palindromeIterator(palindrome, leftPosition, rightPosition);
						return;
					}

					// if we dont reach the first element, then we carry the one over until
					// we no longer have a digit to carry.
					else
					{
						palindrome[rightPosition] = 0;
						rightPosition -= 1;
						palindrome[rightPosition] += 1;

					}

				}

				// set both indexes back to their origninal position.
				rightPosition = originalRightPosition;
				leftPosition = originalLeftPosition;
			}

			// if we reach here that means that the two indexes are not equal and no digits
			// are being carried over. If the left digit is greater than the right we can
			// safetly set the right to the same value since we know it will be a greater
			// number.
			else if (palindrome[leftPosition]>palindrome[rightPosition])
			{
				palindrome[rightPosition] = palindrome[leftPosition];
				leftPosition += 1;
				rightPosition -= 1;
				continue;
			}

			// if all else fails, simply increment the right digit by one.
			else
			{
				palindrome[rightPosition] += 1;
			}

		}
	}






int main()
{
	vector <int> palindrome;
	string numberString;
	stringstream numberStream;
	int testCases;
	cin >> testCases;
	vector <string> numberOutputVector;
	for (int i = 0; i < testCases; ++i)
	{
		palindrome.clear();
		cin >> numberString;

		for (char c : numberString)
		{
			palindrome.push_back(c - '0');
		}
		int leftPosition = 0;
		int rightPosition = palindrome.size() - 1;
		palindrome[rightPosition] += 1;
		palindromeIterator(palindrome, leftPosition, rightPosition);
		string string1;
		for (int j = 0; j < palindrome.size(); ++j)
		{
			numberStream << palindrome[j];

		}
		numberOutputVector.push_back(numberStream.str());
		numberStream.str("");
	}
	for (int i = 0; i < testCases; ++i)
	{
		cout << numberOutputVector[i] <<endl;
	}
}
