#include <vector>
#include <math.h> // may need to use pow( )
#include <iostream>
using namespace std;

template <class Comparable>
void mergesortImproved( vector<Comparable> &a ) {
	int size = a.size( );

	//Creating the empty temporary vector
	vector<Comparable> b;

	//Assigning a vector pointer to the incoming vector
	vector<Comparable> * vecPtr1 = &a;
	//Assigning a vector pointer to the 
	vector<Comparable> * vecPtr2 = &b;

	//Saying whether or not the original pointer in pointing the original input vector or not
	bool vecPtr1IsOriginal = true;
  
	int partition_sz = 1;

	
	while (partition_sz <= (int)ceil((float)size / 2.0)) {
    
		// Single merge run
		//cout << "partition_sz=" << partition_sz << endl;
		//cout << "vecPtr1IsOriginal=" << vecPtr1IsOriginal << endl;
    
		for (int i=0; i<size; i += 2 * partition_sz) {
      
			//cout << "i=" << i << endl;
			//Two variables keeping track of the partitions
			int j1 = i;
			int j2 = i + partition_sz;
      
			while ((j1 < i + partition_sz) && (j2 < min(size, i + 2 * partition_sz))) {
        
				//cout << "j1=" << j1 << ", j2=" << j2 << endl;

				//If the vector pointer1 at index j1 is less then vector pointer 2 at index j2, then push the value of the vector pointer 2 to the back of the vector 1 and increment j1 
				if ( (*vecPtr1)[j1] < (*vecPtr1)[j2] ) {
					vecPtr2->push_back( (*vecPtr1)[j1] );
					j1++;
				}else {
					//If the vector pointer2 at index j2 is less then vector pointer 1 at index j1, then push the value of the vector pointer 2 to the back of the vector 1 and increment j1 
					vecPtr2->push_back( (*vecPtr1)[j2] );
					j2++;
				}
			}

			//While loops that clean out the remaining values it one side of the two partitions is cleared out of values
			while (j1 < i + partition_sz) {
				vecPtr2->push_back((*vecPtr1)[j1]);
				j1++;
			}
			while (j2 < min(size, i + 2 * partition_sz)) {
				vecPtr2->push_back((*vecPtr1)[j2]);
				j2++;
			}
		}

		// Flush the first vector pointer
		vecPtr1->clear();
		//if the first pointer is pointing at the original input vector then switch the two pointers between the two arrays
		if (vecPtr1IsOriginal) {
			vecPtr1 = &b;
			vecPtr2 = &a;
		} else {
			vecPtr1 = &a;
			vecPtr2 = &b;
		}

		//reassign the first pointer to be false
		vecPtr1IsOriginal = ! vecPtr1IsOriginal;
		//expand the partition size times 2
		partition_sz *= 2;
	}

	//move all of the values that are in the temporary array and move it back over to the original array
	if (! vecPtr1IsOriginal) {
		for (int i=0; i<size; i++) {
			vecPtr2->push_back((*vecPtr1)[i]);
		}
	}
}



