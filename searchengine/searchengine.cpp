#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class DocumentAnalyzer {
public:
	void analyzeDocument(int docnum) {
		cout << "Analyzing document " << docnum << ".txt "<< endl;
		
	}
};

class Documentnum
{
public:
	void diplaydocnum(int docnum)
	{
		cout << "Checking Doc " << docnum << endl;

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
	DocumentAnalyzer docanalyzer;
	Documentnum docnum1;

public:

	Nodelink(int a, int b, int c, int docn,int size)
	{
		filesize = size;
		doc = "doc";
		filetype = ".txt";
		docnum = docn;
		docnum1.diplaydocnum(docn);
		docanalyzer.analyzeDocument(docn);

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
	}

};





class Nodehash
{

private:

	string data;

	Nodehash* next;

public:


	Nodehash()
	{

		data = "null";
		next = nullptr;

	}
	Nodehash(string a)
	{
		data = a;
		next = nullptr;

	}


	void setdata(string a)
	{

		data = a;

	}

	void setnext(Nodehash* a)
	{
		next = a;
	}


	Nodehash* getnext()
	{
		return next;
	}

	string getdata()
	{

		return data;
	}






};
class Hashtable
{

private:
	Nodehash** arr;

	int size;

public:

	Hashtable()
	{


		arr = nullptr;
		size = 0;

	}


	Hashtable(int a)
	{
		size = a;

		arr = new Nodehash * [size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = nullptr;

		}


	}


	void setsize(int a)
	{
		size = a;

	}
	int getsize()
	{
		return size;
	}



	int Hashkey(string a)
	{

		int total = 0;

		for (int i = 0; i < a.length(); i++)

		{
			if (a[i] == 'a')
			{
				total += 1;
			}
			else if (a[i] == 'b')
			{
				total += 2;
			}
			else if (a[i] == 'c')
			{
				total += 3;

			}
			else if (a[i] == 'd')
			{
				total += 4;
			}


			else if (a[i] == 'e')
			{
				total += 5;
			}

			else if (a[i] == 'f')
			{
				total += 6;
			}

			else if (a[i] == 'g')
			{
				total += 7;
			}


			else if (a[i] == 'h')
			{
				total += 8;
			}

			else if (a[i] == 'i')
			{
				total += 9;
			}

			else if (a[i] == 'j')
			{
				total += 10;
			}

			else if (a[i] == 'k')
			{
				total += 11;
			}

			else if (a[i] == 'l')
			{
				total += 12;
			}

			else if (a[i] == 'm')
			{
				total += 13;
			}


			else if (a[i] == 'n')
			{
				total += 14;
			}

			else if (a[i] == 'o')
			{
				total += 15;
			}

			else if (a[i] == 'p')
			{
				total += 16;
			}

			else if (a[i] == 'q')
			{
				total += 17;
			}

			else if (a[i] == 'r')
			{
				total += 18;
			}

			else if (a[i] == 's')
			{
				total += 19;
			}

			else if (a[i] == 't')
			{
				total += 20;
			}

			else if (a[i] == 'u')
			{
				total += 21;
			}

			else if (a[i] == 'v')
			{
				total += 22;
			}

			else if (a[i] == 'w')
			{
				total += 23;
			}

			else if (a[i] == 'x')
			{
				total += 24;
			}

			else if (a[i] == 'y')
			{
				total += 25;
			}

			else if (a[i] == 'z')
			{
				total += 26;
			}


		}
		int key = total % size;
		return key;

	}

	void insert(int key1, string value)
	{
		Nodehash* N = new Nodehash(value);

		if (arr[key1] == nullptr)
		{
			arr[key1] = N;


		}
		else
		{
			Nodehash* temp = arr[key1];

			while (temp->getnext() != nullptr)
			{
				temp = temp->getnext();
			}
			temp->setnext(N);

		}




	}


	void display()
	{
		Nodehash* temp;

		for (int i = 0; i < 26; i++)
		{
			cout << "arr [ " << i << " ] = ";

			temp = arr[i];
			while (temp != nullptr)
			{
				cout << temp->getdata() << " ";
				temp = temp->getnext();
			}

			cout << endl;


		}




	}



	int searchash(int key,string findstr)
	{
		int count = 0;

		if (arr[key] == nullptr)
		{

			return count;

		}
		else
		{
			Nodehash* temp = arr[key];
			while (temp != nullptr)
			{

				if (temp->getdata()==findstr)  //when node word size is equal to size of word to be found then check both words 
				{

					count++;
					

				}
				temp = temp->getnext();
			
			}
			return count;   // function returns false if word is not found in the tree
		}


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

	if (l < size && docword[l] > docword[largest])    	// If left child is larger than root

		largest = l;

	if (r < size && docword[r] > docword[largest])   	// If right child is larger than largest so far

		largest = r;

	if (largest != i) {
		swap(docword[i], docword[largest]);
		swap(docarr[i], docarr[largest]);

		heapify(head, largest,n,inp,filesizearr,docarr,docword);   // Recursively heapify the affected sub-tree
		
	}
}

void heapSort(Nodelink* head,int n,int inp,int *filesizearr)		// function to do heap sort

{
	
	Nodelink* temp = head;
	int size = n;
	string* docarr = new string[n];
	int* docword = new int[n];

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(head, i,n,inp,filesizearr,docarr,docword);

	for (int i = n - 1; i >= 1; i--)
	{
		// Move current root to end
		swap(docarr[0], docarr[i]);
		swap(docword[0], docword[i]);
		// call max heapify on the reduced heap

		if (i == 1)
		{
			cout << "**********CHECKING**********\n\n";

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
	
	
	
	string strarr[20];
	int count = 0;
	int key = 0;
	int key1, key2, key3 = 0;

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
				for (int i = 0; i < 20; i++)
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
			Hashtable* hashobj = new Hashtable(26);

			filesize = 0;
			w1count = 0;
			w3count = 0;
			w2count = 0;

			fin.open(doc + to_string(i) + filetype, ios::in);   //opening file according to the iteration of the foor loop

			fin >> fileword;
			filesize++;
			fileword = small(fileword);  //converting capital letters to small if any

			key = hashobj->Hashkey(fileword);


			hashobj->insert(key, fileword);

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


					//bstobj->insert(bstobj->getroot(), fileword.length(), fileword);

					key = hashobj->Hashkey(fileword);
					hashobj->insert(key, fileword);


					filesize++;
				}
				//hashobj->display();
				filesizearr[ind] = filesize;
				if (inp == 1)
				{

					
					key1 = hashobj->Hashkey(word1);

					w1count = hashobj->searchash(key1,word1);
					flag = true;
						
						/*cout << doc + to_string(i) + filetype << endl;*/

					

				}

				else if (inp == 2 || inp==3) //searching word1 or word2 from file tree of words

				{

					key1 = hashobj->Hashkey(word1);
					key2 = hashobj->Hashkey(word2);

					w1count = hashobj->searchash(key1, word1);
					w2count = hashobj->searchash(key2, word2);


						flag = true;
						/*cout << doc + to_string(i) + filetype << endl;*/

					//}

				}



				else if (inp == 4 || inp==5)//searching word1 or word2 or word3 from file tree of words

				{

					key1 = hashobj->Hashkey(word1);
					key2 = hashobj->Hashkey(word2);
					key3 = hashobj->Hashkey(word3);
					w1count = hashobj->searchash(key1, word1);
					w2count = hashobj->searchash(key2, word2);
					w3count = hashobj->searchash(key3, word3);

			
						flag = true;

				}


			}

			fin.close();
			ind = ind + 1;

	
			delete hashobj;  //deleting object after the completion of search from one file tree to avoid over riding


			if (w1count > 0 || w2count > 0 || w3count > 0)
			{
				if (inp == 3)
				{
				if(w1count>0 && w2count>0)
				linkobj.insert(w1count, w2count, w3count, i, filesize);
	
				}
				else if (inp == 5)
				{
					if (w1count > 0 && w2count > 0 && w3count>0)
						linkobj.insert(w1count, w2count, w3count, i, filesize);

				}
				else
				{
					linkobj.insert(w1count, w2count, w3count, i, filesize);

				}
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
		if(n!=1)
		heapSort(linkobj.gethead(), n,inp, filesizearr);
		
		else
		{
			Nodelink* temp = linkobj.gethead();
			while (temp != NULL)
			{
				cout << temp->getdoc() << temp->getdocnum() << temp->getfiletype() << endl << endl;
				temp = temp->getnext();

			}

		}
		linkobj.deletelinked(inp);

		cout <<"\t *****************"<< endl;

	}
	
	return 0;

}








//
//#include <iostream>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//class Nodelink {
//    int word1count;
//    int word2count;
//    int word3count;
//    int filesize;
//    int docnum;
//    string doc;
//    string filetype;
//    Nodelink* next;
//
//public:
//    Nodelink(int a, int b, int c, int docn, int size) {
//        filesize = size;
//        doc = "doc";
//        filetype = ".txt";
//        docnum = docn;
//        word1count = a;
//        word2count = b;
//        word3count = c;
//        next = nullptr;
//    }
//
//    void setnext(Nodelink* a) {
//        next = a;
//    }
//
//    Nodelink* getnext() {
//        return next;
//    }
//
//    int getword1count() {
//        return word1count;
//    }
//
//    int getword2count() {
//        return word2count;
//    }
//
//    int getword3count() {
//        return word3count;
//    }
//
//    string getdoc() {
//        return doc;
//    }
//
//    int getdocnum() {
//        return docnum;
//    }
//
//    string getfiletype() {
//        return filetype;
//    }
//};
//
//class LinkedList {
//private:
//    Nodelink* head;
//    Nodelink* tail;
//
//public:
//    LinkedList() {
//        head = nullptr;
//        tail = nullptr;
//    }
//
//    Nodelink* gethead() {
//        return head;
//    }
//
//    void insert(int a, int b, int c, int docn, int size) {
//        Nodelink* t = new Nodelink(a, b, c, docn, size);
//
//        if (head == nullptr) {
//            head = t;
//            tail = t;
//            tail->setnext(nullptr);
//        }
//        else {
//            tail->setnext(t);
//            tail = t;
//            tail->setnext(nullptr);
//        }
//    }
//
//    void deletelinked(int n) {
//        if (n == 6) {
//            return;
//        }
//
//        Nodelink* temp = head;
//        while (temp != nullptr) {
//            temp = temp->getnext();
//            delete head;
//            head = temp;
//        }
//    }
//
//    void display() {
//        if (head == nullptr) {
//            cout << "Your entered keyword is not found in any document\n";
//        }
//    }
//};
//
//class Nodehash {
//private:
//    string data;
//    Nodehash* next;
//
//public:
//    Nodehash() {
//        data = "null";
//        next = nullptr;
//    }
//
//    Nodehash(string a) {
//        data = a;
//        next = nullptr;
//    }
//
//    void setdata(string a) {
//        data = a;
//    }
//
//    void setnext(Nodehash* a) {
//        next = a;
//    }
//
//    Nodehash* getnext() {
//        return next;
//    }
//
//    string getdata() {
//        return data;
//    }
//};
//
//class Hashtable {
//private:
//    Nodehash** arr;
//    int size;
//
//public:
//    Hashtable() {
//        arr = nullptr;
//        size = 0;
//    }
//
//    Hashtable(int a) {
//        size = a;
//        arr = new Nodehash * [size];
//        for (int i = 0; i < size; i++) {
//            arr[i] = nullptr;
//        }
//    }
//
//    void setsize(int a) {
//        size = a;
//    }
//
//    int getsize() {
//        return size;
//    }
//
//    int Hashkey(string a) {
//        int total = 0;
//        for (int i = 0; i < a.length(); i++) {
//            if (a[i] >= 'a' && a[i] <= 'z') {
//                total += a[i] - 'a' + 1;
//            }
//        }
//        int key = total % size;
//        return key;
//    }
//
//    void insert(int key1, string value) {
//        Nodehash* N = new Nodehash(value);
//
//        if (arr[key1] == nullptr) {
//            arr[key1] = N;
//        }
//        else {
//            Nodehash* temp = arr[key1];
//            while (temp->getnext() != nullptr) {
//                temp = temp->getnext();
//            }
//            temp->setnext(N);
//        }
//    }
//
//    void display() {
//        Nodehash* temp;
//        for (int i = 0; i < 26; i++) {
//            cout << "arr [ " << i << " ] = ";
//            temp = arr[i];
//            while (temp != nullptr) {
//                cout << temp->getdata() << " ";
//                temp = temp->getnext();
//            }
//            cout << endl;
//        }
//    }
//
//    int searchash(int key, string findstr) {
//        int count = 0;
//        if (arr[key] == nullptr) {
//            return count;
//        }
//        else {
//            Nodehash* temp = arr[key];
//            while (temp != nullptr) {
//                if (temp->getdata() == findstr) {
//                    count++;
//                }
//                temp = temp->getnext();
//            }
//            return count;
//        }
//    }
//};
//
//string small(string fileword) {
//    for (int j = 0; j < fileword.length(); j++) {
//        if (fileword[j] >= 'A' && fileword[j] <= 'Z') {
//            fileword[j] = fileword[j] + 32;
//        }
//    }
//    return fileword;
//}
//
//void heapify(Nodelink* head, int i, int n, int inp, int* filesizearr, string* docarr, int* docword)
//{
//
//	int size = 0;
//
//	Nodelink* temp = head;
//
//	while (temp != nullptr)
//	{
//
//		size++;
//		temp = temp->getnext();
//	}
//
//
//
//	if (inp == 1)
//	{
//		temp = head;
//
//		for (int i = 0; i < size; i++)
//		{
//			docarr[i] = temp->getdoc() + to_string(temp->getdocnum()) + temp->getfiletype();
//			docword[i] = temp->getword1count();
//			temp = temp->getnext();
//		}
//
//
//	}
//
//	if (inp == 2)
//	{
//		temp = head;
//		int index = 0;
//		float v1, v2;
//		float ans;
//		while (temp != nullptr)
//		{
//			ans = temp->getword1count();
//			v1 = (ans / filesizearr[index]);
//			v1 = v1 * 100.0;
//			ans = temp->getword2count();
//
//			v2 = (ans / filesizearr[index]);
//			v2 = v2 * 100.0;
//			docarr[index] = temp->getdoc() + to_string(temp->getdocnum()) + temp->getfiletype();
//
//			if (v1 > v2)
//			{
//				docword[index] = temp->getword1count();
//
//			}
//			else
//			{
//				docword[index] = temp->getword2count();
//
//			}
//			index++;
//			temp = temp->getnext();
//		}
//
//	}
//
//
//	else if (inp == 3)
//	{
//
//		temp = head;
//		if (temp->getword1count() > 0 && temp->getword2count() > 0)
//		{
//			int index = 0;
//			float v1, v2;
//			float ans;
//			while (temp != nullptr)
//			{
//				ans = temp->getword1count();
//				v1 = (ans / filesizearr[index]);
//				v1 = v1 * 100.0;
//				ans = temp->getword2count();
//
//				v2 = (ans / filesizearr[index]);
//				v2 = v2 * 100.0;
//				docarr[index] = temp->getdoc() + to_string(temp->getdocnum()) + temp->getfiletype();
//
//				if (v1 > v2)
//				{
//					docword[index] = temp->getword1count();
//
//				}
//				else
//				{
//					docword[index] = temp->getword2count();
//
//				}
//				index++;
//				temp = temp->getnext();
//			}
//		}
//
//
//
//
//	}
//
//
//	else if (inp == 4)
//	{
//		temp = head;
//		int index = 0;
//		float v1, v2, v3;
//		float ans;
//		while (temp != nullptr)
//		{
//			ans = temp->getword1count();
//			v1 = (ans / filesizearr[index]);
//			v1 = v1 * 100.0;
//			ans = temp->getword2count();
//
//			v2 = (ans / filesizearr[index]);
//			v2 = v2 * 100.0;
//
//			v3 = (ans / filesizearr[index]);
//			v3 = v3 * 100.0;
//
//
//			docarr[index] = temp->getdoc() + to_string(temp->getdocnum()) + temp->getfiletype();
//
//			if (v1 > v2 && v1 > v3)
//			{
//				docword[index] = temp->getword1count();
//
//			}
//			else if (v2 > v1 && v2 > v3)
//			{
//				docword[index] = temp->getword2count();
//
//			}
//			else
//			{
//				docword[index] = temp->getword3count();
//
//			}
//			index++;
//			temp = temp->getnext();
//		}
//
//
//
//
//	}
//
//
//	else if (inp == 5)
//	{
//
//		temp = head;
//		if (temp->getword1count() > 0 && temp->getword2count() > 0 && temp->getword3count() > 0)
//		{
//			int index = 0;
//			float v1, v2, v3;
//			float ans;
//			while (temp != nullptr)
//			{
//				ans = temp->getword1count();
//				v1 = (ans / filesizearr[index]);
//				v1 = v1 * 100.0;
//				ans = temp->getword2count();
//
//				v2 = (ans / filesizearr[index]);
//				v2 = v2 * 100.0;
//
//				v3 = (ans / filesizearr[index]);
//				v3 = v3 * 100.0;
//
//				docarr[index] = temp->getdoc() + to_string(temp->getdocnum()) + temp->getfiletype();
//
//				if (v1 > v2 && v1 > v3)
//				{
//					docword[index] = temp->getword1count();
//
//				}
//				else if (v2 > v1 && v2 > v3)
//				{
//					docword[index] = temp->getword2count();
//
//				}
//				else
//				{
//					docword[index] = temp->getword3count();
//
//				}
//				index++;
//				temp = temp->getnext();
//			}
//		}
//
//
//
//
//	}
//
//
//	int largest = i; // Initialize largest as root
//	int l = 2 * i + 1; // left = 2*i + 1
//	int r = 2 * i + 2; // right = 2*i + 2
//
//	if (l < size && docword[l] > docword[largest])    	// If left child is larger than root
//
//		largest = l;
//
//	if (r < size && docword[r] > docword[largest])   	// If right child is larger than largest so far
//
//		largest = r;
//
//	if (largest != i) {
//		swap(docword[i], docword[largest]);
//		swap(docarr[i], docarr[largest]);
//
//		heapify(head, largest, n, inp, filesizearr, docarr, docword);   // Recursively heapify the affected sub-tree
//
//	}
//}
//
//void heapSort(Nodelink* head, int n, int inp, int* filesizearr)		// function to do heap sort
//
//{
//
//	Nodelink* temp = head;
//	int size = n;
//	string* docarr = new string[n];
//	int* docword = new int[n];
//
//	for (int i = n / 2 - 1; i >= 0; i--)
//		heapify(head, i, n, inp, filesizearr, docarr, docword);
//
//	for (int i = n - 1; i >= 1; i--)
//	{
//		// Move current root to end
//		swap(docarr[0], docarr[i]);
//		swap(docword[0], docword[i]);
//		// call max heapify on the reduced heap
//
//		if (i == 1)
//		{
//			cout << "**********CHECKING**********\n\n";
//
//			for (int j = 0; j < size; j++)
//			{
//				cout << docarr[j] << "   " << endl;
//			}
//			break;
//		}
//		heapify(head, 0, i, inp, filesizearr, docarr, docword);
//
//	}
//
//
//}
//
//
//class DocumentAnalyzer {
//public:
//    void analyzeDocument(string doc, int docnum, int filesize) {
//        cout << "Analyzing document " << doc << docnum << ".txt with size " << filesize << " bytes." << endl;
//        // Add additional logic for document analysis if needed
//    }
//};
//
//class KeywordSearch {
//public:
//    int searchKeywords(Hashtable& hashTable, string word1, string word2, string word3) {
//        int key1 = hashTable.Hashkey(word1);
//        int key2 = hashTable.Hashkey(word2);
//        int key3 = hashTable.Hashkey(word3);
//
//        int count1 = hashTable.searchash(key1, word1);
//        int count2 = hashTable.searchash(key2, word2);
//        int count3 = hashTable.searchash(key3, word3);
//
//        cout << "Occurrences of keywords:" << endl;
//        cout << word1 << ": " << count1 << " times." << endl;
//        cout << word2 << ": " << count2 << " times." << endl;
//        cout << word3 << ": " << count3 << " times." << endl;
//
//        return count1 + count2 + count3;
//    }
//};
//
//int main() {
//    
//	DocumentAnalyzer analyzer;
//	KeywordSearch keywordSearch;
//	string filetype = ".txt";   // files extension
//	string doc = "doc";
//
//	ifstream fin;               // used to open the files
//	string fileword;
//	bool breakflag = false;
//	cout << "Total files = 50\n\n";
//	Hashtable hashobj;
//	int filenum;
//	while (true)
//	{
//		cout << "Please enter the number of files, you want to search\n\n";  //to how much files want to read
//		cin >> filenum;
//
//		if (filenum > 50 || filenum < 1)  //checking the valid input to document the user entered
//		{
//
//			cout << "Invalid Input try again\n\n";
//
//		}
//		else
//		{
//			break;
//		}
//
//
//	}
//
//
//
//	string strarr[20];
//	int count = 0;
//	int key = 0;
//	int key1, key2, key3 = 0;
//
//	LinkedList linkobj;
//
//	int inp;
//	int filesize = 0;
//	int w1count, w2count, w3count = 0;
//	string word1, word2, word3;
//	while (true)
//	{
//
//
//		while (true)
//		{
//			cout << "If you	want to search one word press 1\n";
//			cout << "\nIf you want to search one word OR second word in document press 2\n";
//			cout << "\nIf you want to search one word AND second word in document press 3\n";
//			cout << "\nIf you want to search one word OR second word OR third word in document press 4\n";
//			cout << "\nIf you want to search one word AND second word AND third word in document press 5\n";
//
//			cout << "\nTo enter words in quotation press 6\n\n";
//
//			cout << "\n\n To Exit press 7\n\n";
//
//			cin >> inp;
//
//			if (inp == 1)   //when only 1 word is to be searched
//			{
//				cout << "Please enter the word you want to search into the Documents\n";
//				cin >> word1;
//				word1 = small(word1);    //converting capital letters to small if any
//
//
//				break;
//			}
//			else if (inp == 2 || inp == 3)  //when word 1 or/and word 2 is to be searched
//			{
//				cout << "Please enter the word1 \n";
//				cin >> word1;
//				word1 = small(word1);     //converting capital letters to small if any
//
//
//				cout << "Please enter the word2 \n";
//				cin >> word2;
//				word2 = small(word2);    //converting capital letters to small if any
//
//
//				break;
//
//			}
//			else if (inp == 4 || inp == 5)   //when word 1 or/and word 2 or/and word 3 is to be searched
//			{
//
//				cout << "Please enter the word1 \n";
//				cin >> word1;
//
//				word1 = small(word1);  //converting capital letters to small if any
//
//
//				cout << "Please enter the word2 \n";
//				cin >> word2;         //converting capital letters to small if any
//
//				word2 = small(word2);
//
//				cout << "Please enter the word3 \n";
//				cin >> word3;           //converting capital letters to small if any
//
//				word3 = small(word3);
//
//				break;
//			}
//
//
//			else if (inp == 6)
//			{
//
//				count = 0;
//				string str;
//				cout << "\nEnter keywords\n";
//				cin.ignore();
//				getline(cin, str);
//				int index = 0;
//				for (int i = 0; i < 20; i++)
//				{
//					strarr[i] = "\0";
//				}
//
//				string word = "";
//				for (auto x : str)
//				{
//					if (x == ' ')
//					{
//						word = small(word);
//
//						strarr[index] = word;
//						index++;
//						word = "";
//					}
//					else
//					{
//						word = word + x;
//					}
//				}
//				word = small(word);
//				strarr[index] = word;
//
//				for (int i = 0; strarr[i] != "\0"; i++)
//				{
//
//					count++;
//				}
//
//
//
//				break;
//
//
//			}
//
//			else if (inp == 7)
//			{
//
//				cout << "\n\n******	Exiting	******\n\n";   //to exit the program
//				breakflag = true;
//				break;
//			}
//			else
//			{
//				cout << "Wrong Input try again\n\n";
//				continue;
//			}
//		}
//
//		cout << endl;
//
//		if (breakflag == true)
//		{
//			break;
//		}
//		int* filesizearr = new int[filenum];
//		int ind = 0;
//
//		bool flag = false;
//		for (int i = 1; i <= filenum; i++)
//		{
//			analyzer.analyzeDocument("doc", i, filesize);
//			int keywordCount = keywordSearch.searchKeywords(hashobj, word1, word2, word3);
//
//			if (keywordCount > 0) {
//				cout << "Document contains relevant keywords." << endl;
//			}
//			else {
//				cout << "No relevant keywords found in the document." << endl;
//			}
//			Hashtable* hashobj = new Hashtable(26);
//
//			filesize = 0;
//			w1count = 0;
//			w3count = 0;
//			w2count = 0;
//
//			fin.open(doc + to_string(i) + filetype, ios::in);   //opening file according to the iteration of the foor loop
//
//			fin >> fileword;
//			filesize++;
//			fileword = small(fileword);  //converting capital letters to small if any
//
//			key = hashobj->Hashkey(fileword);
//
//
//			hashobj->insert(key, fileword);
//
//			if (inp == 6)
//			{
//
//
//				while (!fin.eof())  //read words till the end of the file
//				{
//
//					if (fileword == strarr[0])
//					{
//						int count2 = 1;
//						for (int i = 1; i < count; i++)
//						{
//							fin >> fileword;
//							fileword = small(fileword);
//							if (fileword == strarr[0])
//							{
//								i = 0;
//								count2 = 1;
//								continue;
//							}
//							else if (fileword != strarr[i])
//							{
//								break;
//							}
//							else
//							{
//								count2++;
//							}
//						}
//						if (count2 == count)
//						{
//							flag = true;
//							cout << doc + to_string(i) + filetype << endl;
//							break;
//
//						}
//					}
//					fin >> fileword;
//
//					fileword = small(fileword);   //converting capital letters to small if any
//
//
//				}
//
//
//			}
//			else
//			{
//
//
//
//
//				while (!fin.eof())  //read words till the end of the file
//				{
//
//					fin >> fileword;
//
//					fileword = small(fileword);   //converting capital letters to small if any
//
//
//					//bstobj->insert(bstobj->getroot(), fileword.length(), fileword);
//
//					key = hashobj->Hashkey(fileword);
//					hashobj->insert(key, fileword);
//
//
//					filesize++;
//				}
//				//hashobj->display();
//				filesizearr[ind] = filesize;
//				if (inp == 1)
//				{
//
//
//					key1 = hashobj->Hashkey(word1);
//
//					w1count = hashobj->searchash(key1, word1);
//					flag = true;
//
//					/*cout << doc + to_string(i) + filetype << endl;*/
//
//
//
//				}
//
//				else if (inp == 2 || inp == 3) //searching word1 or word2 from file tree of words
//
//				{
//
//					key1 = hashobj->Hashkey(word1);
//					key2 = hashobj->Hashkey(word2);
//
//					w1count = hashobj->searchash(key1, word1);
//					w2count = hashobj->searchash(key2, word2);
//
//
//					flag = true;
//					/*cout << doc + to_string(i) + filetype << endl;*/
//
//				//}
//
//				}
//
//
//
//				else if (inp == 4 || inp == 5)//searching word1 or word2 or word3 from file tree of words
//
//				{
//
//					key1 = hashobj->Hashkey(word1);
//					key2 = hashobj->Hashkey(word2);
//					key3 = hashobj->Hashkey(word3);
//					w1count = hashobj->searchash(key1, word1);
//					w2count = hashobj->searchash(key2, word2);
//					w3count = hashobj->searchash(key3, word3);
//
//
//					flag = true;
//
//				}
//
//
//			}
//
//			fin.close();
//			ind = ind + 1;
//
//
//			delete hashobj;  //deleting object after the completion of search from one file tree to avoid over riding
//
//
//			if (w1count > 0 || w2count > 0 || w3count > 0)
//			{
//				if (inp == 3)
//				{
//					if (w1count > 0 && w2count > 0)
//						linkobj.insert(w1count, w2count, w3count, i, filesize);
//
//				}
//				else if (inp == 5)
//				{
//					if (w1count > 0 && w2count > 0 && w3count > 0)
//						linkobj.insert(w1count, w2count, w3count, i, filesize);
//
//				}
//				else
//				{
//					linkobj.insert(w1count, w2count, w3count, i, filesize);
//
//				}
//			}
//
//		}
//		if (flag == false)
//		{
//
//			cout << "Your entered keyword is not found in any document.....\n";  //when not word/words not found according to the requirements
//
//		}
//		else
//		{
//			if (inp != 6)
//				linkobj.display();
//
//		}
//		cout << endl;
//
//
//		int n = 0;
//		Nodelink* temp = linkobj.gethead();
//		while (temp != nullptr)
//		{
//			n++;
//			temp = temp->getnext();
//		}
//		if (n != 1)
//			heapSort(linkobj.gethead(), n, inp, filesizearr);
//
//		else
//		{
//			Nodelink* temp = linkobj.gethead();
//			while (temp != NULL)
//			{
//				cout << temp->getdoc() << temp->getdocnum() << temp->getfiletype() << endl << endl;
//				temp = temp->getnext();
//
//			}
//
//		}
//		linkobj.deletelinked(inp);
//
//		cout << "\t *****************" << endl;
//
//	}
//
//	return 0;
//}
