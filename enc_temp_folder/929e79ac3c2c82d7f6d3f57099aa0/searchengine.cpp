#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class Node      //Node of a Binary Search Tree
{
private:
	Node* left; //left side pointer of node
	Node* right; //right side pointer of node
	int wordsize;
	string word;

public:

	Node()     //default constructor
	{
		left = right = nullptr;
		word = "null";

		wordsize = 0;
	}

	Node(int a,string b)      //parametrized or overloaded constructor
	{
		left = right = nullptr;
		word = b;
		wordsize = a;

	}

	void setword(string a)
	{
		word = a;
	}

	string getword()
	{
		return word;
	}

	void setwordsize(int a)
	{
		wordsize = a;
	}

	void setleft(Node* a)
	{
		left = a;
	}

	void setright(Node* b)
	{
		right = b;
	}

	Node* getleft()
	{
		return left;
	}

	Node* getright()
	{
		return right;
	}

	int getwordsize()
	{
		return wordsize;
	}

	~Node()    //Destructor
	{ 
	delete left;
	delete right;
	}
	

};



class Nodelink
{

	int word1count;
	int word2count;
	int word3count;
	int filesize;
	int docnum;
	string doc;
	string filetype;
	Nodelink* next;


public:

	Nodelink(int a, int b, int c, int docn,int size)
	{
		filesize = size;
		doc = "doc";
		filetype = ".txt";
		docnum = docn;
		word1count = a;
		word2count = b;
		word3count = c;
		next = nullptr;

	}

	void setnext(Nodelink* a)
	{
		next = a;
	}

	Nodelink* getnext()
	{
		return next;
	}

	int getword1count()
	{
		return word1count;

	}

	int getword2count()
	{
		return word2count;

	}


	int getword3count()
	{
		return word3count;

	}

	string getdoc()
	{
		return doc;
	}

	int getdocnum()
	{
		return docnum;
	}

	string getfiletype()
	{
		return filetype;
	}

};

class LinkedList
{
private:
	Nodelink* head;
	Nodelink* tail;
public:
	LinkedList()
	{
		head = NULL;
		tail = nullptr;
	}
	Nodelink* gethead()
	{
		return head;
	}

	void insert(int a,int b,int c,int docn,int size)
	{
		Nodelink* t = new Nodelink(a,b,c,docn,size);
		

		if (head == NULL)
		{
			head = t;
			tail = t;

			tail->setnext(nullptr);
		}
		else
		{
			tail->setnext(t);
			tail = t;
			tail->setnext(NULL);
		}


	}

	void deletelinked(int n)
	{
		if (n == 6)
		{
			return;
		}

		Nodelink* temp = head;
		while (temp != nullptr)
		{
			temp = temp->getnext();
			delete head;
			head = temp;

		}

	}
	void display()
	{
		if (head == NULL)
		{
			cout << "Your entered keyword is not found in any document\n";  //when not word/words not found according to the requirements
		}
		/*else
		{
			Nodelink* temp = head;
			while (temp != NULL)
			{
				cout << "Word 1 = "<<temp->getword1count() << endl;
				cout << "Word 2 = " << temp->getword2count() << endl;
				cout << "Word 3 = " << temp->getword3count() << endl;
				cout << temp->getdoc()<< temp->getdocnum()<< temp->getfiletype() << endl<<endl;
				temp = temp->getnext();

			}
		}*/
	}

};








class BST    // Class of Binary Search Tree
{

private:


	Node* root;		//root of the binary search tree


public:

	BST()    //Default Constructor
	{

		root = nullptr;

	}


	BST(Node* a)   //overloaded / parametrized Constructor
	{
		
		root = a;
			
	}
	Node* getroot()
	{
		return root;
	}

	void setroot(Node* a)
	{
		root=a;
	}


	
	Node* insert(Node* root, int size,string word)			//inserting word on to the tree
	{
		if (root == nullptr) 
		{
			return new Node(size,word);
		}

		if (size <= root->getwordsize())			// if word size is less or equal then size of word to be found then set left node
		{
			root->setleft ( insert(root->getleft(), size,word));
		}
		else 
		{
			root->setright( insert(root->getright(), size,word));   // if word size is more then size of word to be found set right node
		}

		return root;
	}
	

	void inorder(Node* temp)   // display nodes in format of Left-parent-Right
	{

		if (temp == nullptr)
		{
			return;
		}
		else
		{
		
			inorder(temp->getleft());
			cout << "word  = " << temp->getword() ;  

			cout << "	" << temp->getwordsize() << endl;
			
			inorder(temp->getright());


		}


	}


	int searchword(string find,int wordlen)   //bool function to search word from the tree
	{
		int count = 0;
		
		if (root == nullptr)  
		{

			return false;

		}
		else
		{
			Node* temp = root;
			while(temp != nullptr)
			{

				if (temp->getwordsize() == wordlen)  //when node word size is equal to size of word to be found then check both words 
				{
					if (find == temp->getword())
					{
						count++;
						temp = temp->getleft();   // move the temp (moving node ) to the left if word dosenot matches

					}
					else
					{

						temp = temp->getleft();   // move the temp (moving node ) to the left if word dosenot matches

					}

				}
				else if (temp->getwordsize() < wordlen)
				{
					temp = temp->getright();      // move the temp (moving node ) to the right if node word size is less then the size of word to be found

				}
				else
				{
					temp = temp->getleft();   // move the temp (moving node ) to the left if node word size is more then the size of word to be found

				}
			}
			return count;   // function returns false if word is not found in the tree
		}
	



	}

	~BST()  //Destructor
	{
		delete root;
	}
	


};
string small(string fileword)  //function to small alphabets which are capital so that it will be easier to match the words
{
	for (int j = 0; j < fileword.length(); j++)
	{
		if (fileword[j] >= 65 && fileword[j] <= 90)
		{
			fileword[j] = fileword[j] + 32;
		}
	}
	return fileword;

}

void heapify(Nodelink* head, int i, int n, int inp, int* filesizearr, string* docarr, int* docword)
{

	int size = 0;

	Nodelink* temp = head;

	while (temp != nullptr)
	{

		size++;
		temp = temp->getnext();
	}



	if (inp == 1)
	{
		temp = head;

		for (int i = 0; i < size; i++)
		{
			docarr[i] = temp->getdoc() + to_string(temp->getdocnum()) + temp->getfiletype();
			docword[i] = temp->getword1count();
			temp = temp->getnext();
		}


	}

	if (inp == 2)
	{
		temp = head;
		int index = 0;
		float v1, v2;
		float ans;
		while (temp != nullptr)
		{
			ans = temp->getword1count();
			v1 = (ans / filesizearr[index]);
			v1 = v1 * 100.0;
			ans = temp->getword2count();

			v2 = (ans / filesizearr[index]);
			v2 = v2 * 100.0;
			docarr[index] = temp->getdoc() + to_string(temp->getdocnum()) + temp->getfiletype();

			if (v1 > v2)
			{
				docword[index] = temp->getword1count();

			}
			else
			{
				docword[index] = temp->getword2count();

			}
			index++;
			temp = temp->getnext();
		}

	}


	else if (inp == 3)
	{

		temp = head;
		if (temp->getword1count() > 0 && temp->getword2count() > 0)
		{
			int index = 0;
			float v1, v2;
			float ans;
			while (temp != nullptr)
			{
				ans = temp->getword1count();
				v1 = (ans / filesizearr[index]);
				v1 = v1 * 100.0;
				ans = temp->getword2count();

				v2 = (ans / filesizearr[index]);
				v2 = v2 * 100.0;
				docarr[index] = temp->getdoc() + to_string(temp->getdocnum()) + temp->getfiletype();

				if (v1 > v2)
				{
					docword[index] = temp->getword1count();

				}
				else
				{
					docword[index] = temp->getword2count();

				}
				index++;
				temp = temp->getnext();
			}
		}




	}


	else if (inp == 4)
	{
	temp = head;
	int index = 0;
	float v1, v2,v3;
	float ans;
	while (temp != nullptr)
	{
		ans = temp->getword1count();
		v1 = (ans / filesizearr[index]);
		v1 = v1 * 100.0;
		ans = temp->getword2count();

		v2 = (ans / filesizearr[index]);
		v2 = v2 * 100.0;

		v3 = (ans / filesizearr[index]);
		v3 = v3 * 100.0;


		docarr[index] = temp->getdoc() + to_string(temp->getdocnum()) + temp->getfiletype();

		if (v1 > v2 && v1>v3)
		{
			docword[index] = temp->getword1count();

		}
		else if( v2>v1 && v2>v3)
		{
			docword[index] = temp->getword2count();

		}
		else
		{
			docword[index] = temp->getword3count();

		}
		index++;
		temp = temp->getnext();
	}




	}


	else if (inp == 5)
	{

		temp = head;
		if (temp->getword1count() > 0 && temp->getword2count() > 0 && temp->getword3count() > 0)
		{
			int index = 0;
			float v1, v2, v3;
			float ans;
			while (temp != nullptr)
			{
				ans = temp->getword1count();
				v1 = (ans / filesizearr[index]);
				v1 = v1 * 100.0;
				ans = temp->getword2count();

				v2 = (ans / filesizearr[index]);
				v2 = v2 * 100.0;

				v3 = (ans / filesizearr[index]);
				v3 = v3 * 100.0;

				docarr[index] = temp->getdoc() + to_string(temp->getdocnum()) + temp->getfiletype();

				if (v1 > v2 && v1 > v3)
				{
					docword[index] = temp->getword1count();

				}
				else if (v2 > v1 && v2 > v3)
				{
					docword[index] = temp->getword2count();

				}
				else
				{
					docword[index] = temp->getword3count();

				}
				index++;
				temp = temp->getnext();
			}
		}




	}

	
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < size && docword[l] > docword[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < size && docword[r] > docword[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(docword[i], docword[largest]);
		swap(docarr[i], docarr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(head, largest,n,inp,filesizearr,docarr,docword);
	}
}

// main function to do heap sort
void heapSort(Nodelink* head,int n,int inp,int *filesizearr)
{
	
	Nodelink* temp = head;
	int size = n;
	string* docarr = new string[n];
	int* docword = new int[n];

	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(head, i,n,inp,filesizearr,docarr,docword);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 1; i--)
	{
		// Move current root to end
		swap(docarr[0], docarr[i]);
		swap(docword[0], docword[i]);
		// call max heapify on the reduced heap

		if (i == 1)
		{
			cout << "**********CHECKING\n\n";

			for (int j = 0; j <size; j++)
			{
				cout << docarr[j] << "   " << endl;
			}
			break;
		}
		heapify(head, 0, i, inp, filesizearr, docarr, docword);

	}


}








int main()
{
	string filetype = ".txt";		//files extension

	string doc = "doc";


	ifstream fin;		//used to open the files



	string fileword;
	bool breakflag = false;
	cout << "Total files = 50\n\n";

	int filenum;
	while (true)
	{
		cout << "Please enter the number of files, you want to search\n\n";  //to how much files want to read
		cin >> filenum;

		if (filenum > 50 || filenum < 1)  //checking the valid input to document the user entered
		{

			cout << "Invalid Input try again\n\n";

		}
		else
		{
			break;
		}


	}
	
	
	
	string strarr[10];
	int count = 0;

	LinkedList linkobj;

	int inp;
	int filesize = 0;
	int w1count, w2count, w3count = 0;
	string word1, word2, word3;
	while (true)
	{


		while (true)
		{
			cout << "If you	want to search one word press 1\n";
			cout << "\nIf you want to search one word OR second word in document press 2\n";
			cout << "\nIf you want to search one word AND second word in document press 3\n";
			cout << "\nIf you want to search one word OR second word OR third word in document press 4\n";
			cout << "\nIf you want to search one word AND second word AND third word in document press 5\n";
			
			cout << "\nTo enter words in quotation press 6\n\n";

			cout << "\n\n To Exit press 7\n\n";

			cin >> inp;

			if (inp == 1)   //when only 1 word is to be searched
			{
				cout << "Please enter the word you want to search into the Documents\n";
				cin >> word1;
				word1 = small(word1);    //converting capital letters to small if any


				break;
			}
			else if (inp == 2 || inp == 3)  //when word 1 or/and word 2 is to be searched
			{
				cout << "Please enter the word1 \n";
				cin >> word1;
				word1 = small(word1);     //converting capital letters to small if any


				cout << "Please enter the word2 \n";
				cin >> word2;
				word2 = small(word2);    //converting capital letters to small if any


				break;

			}
			else if (inp == 4 || inp == 5)   //when word 1 or/and word 2 or/and word 3 is to be searched
			{

				cout << "Please enter the word1 \n";
				cin >> word1;

				word1 = small(word1);  //converting capital letters to small if any


				cout << "Please enter the word2 \n";
				cin >> word2;         //converting capital letters to small if any

				word2 = small(word2);

				cout << "Please enter the word3 \n"; 
				cin >> word3;           //converting capital letters to small if any

				word3 = small(word3);

				break;
			}


			else if (inp == 6)
			{

				count = 0;
				string str;
				cout << "\nEnter keywords\n";
				cin.ignore();
				getline(cin,str);
				int index = 0;
				for (int i = 0; i < 10; i++)
				{
					strarr[i] = "\0";
				}

				string word = "";
				for (auto x : str)
				{
					if (x == ' ')
					{
						word = small(word);

						strarr[index] = word;
						index++;
						word = "";
					}
					else 
					{
						word = word + x;
					}
				}
				word  = small(word);
				strarr[index] = word;
				
				for (int i = 0; strarr[i]!="\0"; i++)
				{
					
					count++;
				}
				
				

				break;


			}

			else if (inp == 7)
			{

				cout << "\n\n******	Exiting	******\n\n";   //to exit the program
				breakflag = true;
				break;
			}
			else
			{
				cout << "Wrong Input try again\n\n";
				continue;
			}
		}
		
		cout << endl;

		if (breakflag == true)
		{
			break;
		}
		int* filesizearr = new int[filenum];
		int ind = 0;

		bool flag = false;
		for (int i = 1; i <= filenum; i++)
		{

			BST* bstobj = new BST();
			filesize = 0;
			w1count = 0;
			w3count = 0;
			w2count = 0;

			fin.open(doc + to_string(i) + filetype, ios::in);   //opening file according to the iteration of the foor loop

			fin >> fileword;
			filesize++;
			fileword = small(fileword);  //converting capital letters to small if any

			bstobj->setroot(bstobj->insert(nullptr, fileword.length(), fileword));  //setting the root of tree as first input from the file


			if (inp == 6)
			{


				while (!fin.eof())  //read words till the end of the file
				{

					if (fileword == strarr[0])
					{
						int count2 = 1;
						for (int i = 1; i < count; i++)
						{
							fin >> fileword;
							fileword = small(fileword);
							if (fileword == strarr[0])
							{
								i = 0;
								count2 = 1;
								continue;
							}
							else if (fileword != strarr[i])
							{
								break;
							}
							else
							{
								count2++;
							}
						}
						if (count2 == count)
						{
							flag = true;
							cout << doc + to_string(i) + filetype << endl;
							break;

						}
					}
					fin >> fileword;

					fileword = small(fileword);   //converting capital letters to small if any


				}


			}
			else
			{




				while (!fin.eof())  //read words till the end of the file
				{

					fin >> fileword;

					fileword = small(fileword);   //converting capital letters to small if any


					bstobj->insert(bstobj->getroot(), fileword.length(), fileword);
					filesize++;
				}
				filesizearr[ind] = filesize;
				if (inp == 1)
				{

					w1count = bstobj->searchword(word1, word1.length());
						flag = true;
						
						/*cout << doc + to_string(i) + filetype << endl;*/

					

				}

				else if (inp == 2) //searching word1 or word2 from file tree of words

				{
						w1count = bstobj->searchword(word1, word1.length());
						w2count = bstobj->searchword(word2, word2.length());

						flag = true;
						/*cout << doc + to_string(i) + filetype << endl;*/

					//}

				}


				else if (inp == 3) //searching word1 and word2 from file tree of words

				{

						w1count = bstobj->searchword(word1, word1.length());
						w2count = bstobj->searchword(word2, word2.length());
						flag = true;
				}


				else if (inp == 4)//searching word1 or word2 or word3 from file tree of words

				{

					w1count = bstobj->searchword(word1, word1.length());
					w2count = bstobj->searchword(word2, word2.length());
					w3count = bstobj->searchword(word3, word3.length());

						flag = true;

				}


				else if (inp == 5)  //searching word1 and word2 and word3 from file tree of words
				{
					if (bstobj->searchword(word1, word1.length()) && bstobj->searchword(word2, word2.length()) && bstobj->searchword(word3, word3.length()))
					{

						w1count = bstobj->searchword(word1, word1.length());
						w2count = bstobj->searchword(word2, word2.length());
						w3count = bstobj->searchword(word3, word3.length());

						flag = true;
	
					}

				}
			}

			fin.close();
			ind = ind + 1;

	
			delete bstobj;  //deleting object after the completion of search from one file tree to avoid over riding


			if (w1count > 0 || w2count > 0 || w3count > 0)
			{

				linkobj.insert(w1count, w2count, w3count, i, filesize);

			}
			
		}
		if (flag == false)
		{

			cout << "Your entered keyword is not found in any document.....\n";  //when not word/words not found according to the requirements

		}
		else
		{
			if(inp!=6)
			linkobj.display();

		}
		cout << endl;

	
		int n = 0;
		Nodelink* temp = linkobj.gethead();
		while (temp != nullptr)
		{
			n++;
			temp = temp->getnext();
		}

		heapSort(linkobj.gethead(), n,inp, filesizearr);
		linkobj.deletelinked(inp);

		cout <<"\t *****************"<< endl;

	}
	
	return 0;

}