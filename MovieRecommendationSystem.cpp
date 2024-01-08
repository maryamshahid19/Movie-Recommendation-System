//Movie Recommendation System 
//Made By 21k-4676 Maryam Shahid, 21k-3170 Shaheer Badar, 21k-4620 Laiba Tabraiz Khan
#include<iostream>
#include<string>
#include<vector>
#include <sstream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include  <bits/stdc++.h>
#include<dos.h> 
#include<conio.h>
#include<windows.h>
#include <iomanip>
using namespace std;

bool flag;
string displayed_mtitle[25];
string displayed_mgenre[25];
string rec_genre[25];
int gcount[25] = {0};
int gindex= 0;
static int displayed_mcount;
static int displayed_mcount2;
static int displayed_mcount3;
static int cc;
static int i;

class Movie {
private:
	string rating;
	string genre;
	string title;
	string contentRating;
	string year;
	string duration;

public:
	Movie() {
	}
	Movie(string rating, string genre, string title, string contentRating, string year, string duration) {
		this->rating = rating;
		this->genre = genre;
		this->title = title;
		this->contentRating = contentRating;
		this->year = year;
		this->duration = duration;
	}
	inline void set_rating(string rating) {
		this->rating = rating;
	}
	inline void set_genre(string genre) {
		this->genre = genre;
	}
	inline void set_title(string title) {
		this->title = title;
	}
	inline void set_contentRating(string contentRating) {
		this->contentRating = contentRating;
	}
	inline void set_year(string year) {
		this->year = year;
	}
	inline void set_duration(string duration) {
		this->duration = duration;
	}
	string get_rating() {
		return rating;
	}
	string get_genre() {
		return genre;
	}
	string get_title() {
		return title;
	}
	string get_contentRating() {
		return contentRating;
	}
	string get_year() {
		return year;
	}
	string get_duration() {
		return duration;
	}
	void printTest() {
		cout << rating << " ";
		cout << genre << " ";
		cout << title << " ";
		cout << contentRating << " ";
		cout << year << " ";
		cout << duration << endl << endl;
	}
};
class LLNode {
public:
	Movie llobj;
	LLNode* next;
	LLNode() {
		next = NULL;
	}

};
class SinglyLinkedList {
public:
	LLNode* head;
	SinglyLinkedList() {
		head = NULL;
	}
	SinglyLinkedList(LLNode* n) {
		head = n;
	}

	void appendNode(LLNode* newNode) {
		if (head == NULL) {
			head = newNode;
		}
		else {
			LLNode* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = newNode;
		}
	}

	void printList() {
		if (head == NULL) {
		}
		else {
			LLNode* temp = head;
			while (temp != NULL) {
				temp = temp->next;
			}
		}
	}
};
class TreeNode {

public:
	Movie tobj;
	SinglyLinkedList linkedlistobj;
	TreeNode* left;
	TreeNode* right;

	TreeNode() {
		left = NULL;
		right = NULL;
	}
};
static int c = 0;
class MovieTree {
public:
	TreeNode* root;

	MovieTree() {
		root = NULL;
	}
	bool isTreeEmpty() {
		if (root == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	
	void insertNode(TreeNode* new_node, Movie mobj) {
		LLNode* newNode = new LLNode();
		if (root == NULL) {
			root = new_node;
			newNode->llobj = mobj;
			new_node->linkedlistobj.appendNode(newNode);
		}
		else {
			TreeNode* temp = root;
			while (temp != NULL) {
				if (new_node->tobj.get_rating() == temp->tobj.get_rating()) {
					newNode->llobj = mobj;
					temp->linkedlistobj.appendNode(newNode);
					break;
				}
				if ((new_node->tobj.get_rating() < temp->tobj.get_rating()) && (temp->left == NULL)) {
					temp->left = new_node;
					newNode->llobj = mobj;
					new_node->linkedlistobj.appendNode(newNode);
					break;
				}
				else if (new_node->tobj.get_rating() < temp->tobj.get_rating()) {
					temp = temp->left;
				}
				else if ((new_node->tobj.get_rating() > temp->tobj.get_rating()) && (temp->right == NULL)) {
					temp->right = new_node;
					newNode->llobj = mobj;
					new_node->linkedlistobj.appendNode(newNode);
					break;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
	
	void ratingsearch(TreeNode* root, string rat) {
		int i = 1;
		if (root == NULL) {
			cout << "Not Found!\n";
		}
		else {
			TreeNode* temp = root;
			while (temp != NULL) {
				if (rat == temp->linkedlistobj.head->llobj.get_rating()) {
					cout << "\t\t\tFollowing are the movies with the RATING you searched for\n";
					LLNode* lltemp = temp->linkedlistobj.head;
					
					while (lltemp != NULL) {
						
						cout << "\t\t\t\t#" << i <<endl;
						cout << "\t\t\t\tMovie Name: " << lltemp->llobj.get_title() << endl;
						cout << "\t\t\t\tRating: " << lltemp->llobj.get_rating() << endl;
						cout << "\t\t\t\tGenre: " << lltemp->llobj.get_genre() << endl;
						cout << "\t\t\t\tContent Rating: " << lltemp->llobj.get_contentRating() << endl;
						cout << "\t\t\t\tRelease Data: " << lltemp->llobj.get_year() << endl;
						cout << "\t\t\t\tDuration(in minutes): " << lltemp->llobj.get_duration() << endl;
						lltemp = lltemp->next;
						cout << endl;
						i++;
					}
					break;
				}
				else if (rat < temp->linkedlistobj.head->llobj.get_rating()) {
					temp = temp->left;
				}
				else if (rat > temp->linkedlistobj.head->llobj.get_rating()) {
					temp = temp->right;
				}
			}
		}
	}
	
	void yearsearch(TreeNode* root, string year) {

		if (root == NULL) {
			return;
		}

		yearsearch(root->right, year);
		LLNode* lltemp = root->linkedlistobj.head;
		while (lltemp->next != NULL) {
			if (year == lltemp->llobj.get_year()) {
				cout << "\t\t\t\t#" << i  <<endl;
				cout << "\t\t\t\tMovie Name: " << lltemp->llobj.get_title() << endl;
				cout << "\t\t\t\tRating: " << lltemp->llobj.get_rating() << endl;
				cout << "\t\t\t\tGenre: " << lltemp->llobj.get_genre() << endl;
				cout << "\t\t\t\tContent Rating: " << lltemp->llobj.get_contentRating() << endl;
				cout << "\t\t\t\tRelease Data: " << lltemp->llobj.get_year() << endl;
				cout << "\t\t\t\tDuration(in minutes): " << lltemp->llobj.get_duration() << endl<<endl;
				flag = true;
				i++;
			}
			lltemp = lltemp->next;
		}
		yearsearch(root->left, year);
	}
	
	void genresearch(TreeNode* r, string genre) {
		
		if (r == NULL) {
			return;
		}
		genresearch(r->right, genre);
		LLNode* lltemp = r->linkedlistobj.head;
		while (lltemp->next != NULL) {
			string str = lltemp->llobj.get_genre();
			string::size_type pos = str.find(genre);
			while (pos != string::npos) {
				if(cc==15){
					break;	
				}
				cout << "\t\t\t\t#" << i <<endl;
				cout << "\t\t\t\tMovie Name: " << lltemp->llobj.get_title() << endl;
				cout << "\t\t\t\tRating: " << lltemp->llobj.get_rating() << endl;
				cout << "\t\t\t\tGenre: " << lltemp->llobj.get_genre() << endl;
				cout << "\t\t\t\tContent Rating: " << lltemp->llobj.get_contentRating() << endl;
				cout << "\t\t\t\tRelease Data: " << lltemp->llobj.get_year() << endl;
				cout << "\t\t\t\tDuration(in minutes): " << lltemp->llobj.get_duration() << endl<<endl;
				cc++;
				i++;
				break;
			}

			lltemp = lltemp->next;

		}
		genresearch(r->left, genre);

	}
	
	void titlesearch(TreeNode* r, string title, fstream& searchfile, fstream& tempfile) {
		if (r == NULL) {
			return;
		}
		titlesearch(r->right, title, searchfile, tempfile);
		LLNode* lltemp = r->linkedlistobj.head;
		searchfile.open("searchdata.csv", ios::in | ios::app | ios::out);
		tempfile.open("tempfile.txt", ios::in | ios::out | ios::app);
		while (lltemp->next != NULL) {
			string str = lltemp->llobj.get_title();
			string::size_type pos = str.find(title);
			while (pos != string::npos) {
			    cout << "\t\t\t\t#" << i<<endl;
				cout << "\t\t\t\tMovie Name: " << lltemp->llobj.get_title() << endl;
				cout << "\t\t\t\tRating: " << lltemp->llobj.get_rating() << endl;
				cout << "\t\t\t\tGenre: " << lltemp->llobj.get_genre() << endl;
				flag = true;
				searchfile << lltemp->llobj.get_title();
				searchfile << '\n';				
				searchfile << lltemp->llobj.get_genre();
				searchfile << '\n';
				searchfile << lltemp->llobj.get_rating();
				searchfile << '\n';			
				searchfile << '\n';		
				tempfile << lltemp->llobj.get_genre();
				tempfile << '|';
				cout << "\t\t\t\tContent Rating: " << lltemp->llobj.get_contentRating() << endl;
				cout << "\t\t\t\tRelease Data: " << lltemp->llobj.get_year() << endl;
				cout << "\t\t\t\tDuration(in minutes): " << lltemp->llobj.get_duration() << endl <<endl;
				i++;
				break;
			}
			lltemp = lltemp->next;
		}
		tempfile.close();
		searchfile.close();
		titlesearch(r->left, title, searchfile, tempfile);
	}
	
	void top50rated(TreeNode* root) {
		int count = 0;

		stack<TreeNode*> stack;

		TreeNode* temp = root;
		while (!stack.empty() || temp != NULL) {
			if (temp != NULL) {
				stack.push(temp);
				temp = temp->right;

			}
			else {

				temp = stack.top();
				stack.pop();
				LLNode* lltemp = temp->linkedlistobj.head;
				
				while (lltemp != NULL) {
					cout <<count+1<<". ";
					cout
		                << left
		                << setw(70)
		                << lltemp->llobj.get_title()
		                << left
		                << setw(15)
		                << lltemp->llobj.get_rating()
		                << left
		                << setw(60)
		                << lltemp->llobj.get_genre()
		                << left
		                << setw(15)
		                << lltemp->llobj.get_year() 
		                << left
		                << setw(25)
		                << lltemp->llobj.get_duration()
		                <<endl;
		                count++;
		            lltemp = lltemp->next;
		                
					if (count == 50) {
						return;
					}
				}
				temp = temp->left;
			}
		}
	}
	void displayMovieToSelect(TreeNode* root, string genre) {
		int count = 0;
		bool displayed = false;

		stack<TreeNode*> stack;

		TreeNode* temp = root;
		while (!stack.empty() || temp != NULL) {
			if (temp != NULL) {
				stack.push(temp);
				temp = temp->right;

			}
			else {
				temp = stack.top();
				stack.pop();
				LLNode* lltemp = temp->linkedlistobj.head;
				while (lltemp != NULL) {
					string str = lltemp->llobj.get_genre();
					string::size_type pos = str.find(genre);
					while (pos != string::npos) {
						
						for(int i = 0; i < displayed_mcount; i++){
					
							if(lltemp->llobj.get_title() == displayed_mtitle[i]){
								displayed = true;
								break;	
							}
							else{
								displayed = false;
							}			
					    }
					    
					    if(displayed == true){
					    	break;
						}
						else{
							displayed_mtitle[ displayed_mcount ] = lltemp->llobj.get_title();
							displayed_mgenre[ displayed_mcount ] = lltemp->llobj.get_genre();
							
							displayed_mcount++;
							
							cout<<endl<<"\t\t\t"<<displayed_mcount<<".";
							cout << "Movie Name: " << lltemp->llobj.get_title() << endl;
							cout << "\t\t\t  Rating: " << lltemp->llobj.get_rating() << endl;
							cout << "\t\t\t  Genre: " << lltemp->llobj.get_genre() << endl;
							count++;
					
							break;
					    }
					}
	
					lltemp = lltemp->next;
					if (count == 4) {
						return;
					}
				}
				temp = temp->left;
			}
		}
	}
	
	void pickupMovie(fstream &tempfile){
		
	    int pmovie[5];
	    gindex = 0;
		bool exists = false;
		string g1;

		cout<<"\n\nYour top5 favourtie movies from displayed screen.(Enter number only): "<<endl;
		for(int i = 0; i < 5; i++){                    //stores the display no of top5 user entered movies in array
			cout<<i+1<<". ";
			cin>>pmovie[i];
		}
		
		for(int i = 0; i < 5; i++){                    //stores genre of picked movies separately to recommend
		
	        stringstream X(displayed_mgenre[pmovie[i]-1]);
	   
	        while (getline(X, g1, '|')) {  
	          
	        	for(int i = 0; i < gindex; i++){
	            	if(rec_genre[i] == g1){
	            		
	            		gcount[i]++;
	            		exists = true;	
	            		break;
	            		
					}
					else{
						exists = false;
					}
			    }
			    
			    if(exists == false){
			        rec_genre[gindex] = g1;
			        gcount[gindex]++;
					gindex++;
	           	   
				}
	        } 
        }
		tempfile.open("gindexkivalue.txt",ios::in | ios::app| ios::out); 																	  
		tempfile<<gindex;										
		tempfile.close();
			
		tempfile.open("userstop5picks.txt",ios::in | ios::app | ios::out);													 
		for(int i = 0; i < gindex; i++){
			tempfile<<rec_genre[i];
			tempfile<<'\n';
			tempfile<<gcount[i];
			tempfile<<'\n';
		}
		tempfile.close();
	}	  
	
	
	void recommend(TreeNode *root, string genre, int fcount, string displayed_mtitle2[]){             
	    
	    int count = 0;          
		bool displayed = false;
		
	
		stack<TreeNode*> stack;
		

		TreeNode* temp = root;
		while (!stack.empty() || temp != NULL) {
			
			if (temp != NULL) {
				
				stack.push(temp);
				temp = temp->right;

			}
			else {
				
				temp = stack.top();
				stack.pop();
				LLNode* lltemp = temp->linkedlistobj.head;
				while (lltemp != NULL){
					string str = lltemp->llobj.get_genre();
					string::size_type pos = str.find(genre);
					while (pos != string::npos) {
						for(int i = 0; i < displayed_mcount2; i++){
					
							if(lltemp->llobj.get_title() == displayed_mtitle2[i]){
								displayed = true;
								break;	
							}
							else{
								displayed = false;
							}			
					    }
					    
					    if(displayed == true){
					    	break;
						}
						else{
							displayed_mtitle2[displayed_mcount2] = lltemp->llobj.get_title();
							displayed_mcount2++;
							
							cout<<endl<<displayed_mcount2<<". ";
							cout
				                << left
				                << setw(70)
				                << lltemp->llobj.get_title()
				                << left
				                << setw(15)
				                << lltemp->llobj.get_rating()
				                << left
				                << setw(60)
				                << lltemp->llobj.get_genre()
				                << left
				                << setw(20)
				                << lltemp->llobj.get_contentRating()
				                << left
				                << setw(15)
				                << lltemp->llobj.get_year() 
				                << left
				                << setw(25)
				                << lltemp->llobj.get_duration()
				                <<endl;
				   
							count++;
							break;
					    }
					}
	
					lltemp = lltemp->next;
					if (count == fcount) {
						return;
					}
				}
				temp = temp->left;
			}
		}
	}


};


TreeNode* readFileData(MovieTree treeobj) {
	fstream file;
	string rating;
	string genre;
	string title;
	string contentRating;
	string year;
	string duration;

	file.open("moviedataset.csv", ios::in);

	if (file.is_open()) {
		TreeNode* new_node = new TreeNode();
		getline(file, rating, ',');
		getline(file, genre, ',');
		getline(file, title, ',');
		getline(file, contentRating, ',');
		getline(file, year, ',');
		getline(file, duration, '\n');


		Movie mobj(rating, genre, title, contentRating, year, duration);

		while (file.good()) {

			TreeNode* new_node = new TreeNode();
			getline(file, rating, ',');
			getline(file, genre, ',');
			getline(file, title, ',');
			getline(file, contentRating, ',');
			getline(file, year, ',');
			getline(file, duration, '\n');


			Movie mobj(rating, genre, title, contentRating, year, duration);


			new_node->tobj = mobj;
			treeobj.insertNode(new_node, mobj);

		}
	}

	file.close();
	return treeobj.root;
}

void frontend(TreeNode* root, MovieTree treeobj) {
	
	string member1 = "Maryam Shahid";
	string member2 = "Shaheer Badar";
	string member3 = "Laiba Tabraiz";
	int option1, option2 = 1;
	string username, pass, tempu, tempp, temptitle, tempgenre[5], tempg,genrearray[8]={"Action","Adventure","Romance","Comedy","Animation","Drama","Fantasy","Documentary"};
	bool duplicate;
	fstream userfile, searchfile, tempfile,top5picksfile,watchlist;
	int length1, length2;
	
	cout << endl<<endl<< endl<<endl<<endl;
	cout << "\t\t\t\t\t\t\t\t\t                         -----Welcome To Our----           " << endl;
	cout << "\t\t\t\t\t\t\t\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\t                                 MOVIE                    " << endl;
	cout << "\t\t\t\t\t\t\t\t\t                          |RECOMMENDATION SYSTEM|          " << endl;
	cout << "\t\t\t\t\t\t\t\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------" << endl<<endl;
	
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t MEMBERS:       " << endl;
	cout << "\t\t\t\t\t\t\t\t\t 1)Maryam Shahid" << endl;
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t 2)Shaheer Badar" << endl;
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t 3)Laiba Tabraiz" << endl<<endl<<endl<<endl<<endl;

	Sleep(2000);
	system("CLS");
	
	cout << endl<<endl<< endl<<endl<<endl;
	cout << "\t\t\t\t\t\t\t\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\t        YOU WILL BE RECOMMENDED MOVIES ACCORDING TO YOUR INTERESTS! :)         " << endl;
	cout << "\t\t\t\t\t\t\t\t\t_______________________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------" << endl<<endl;
	cout << "\t\t\t\t\t\t\t\t\t MEMBERS:       " << endl;
	cout << "\t\t\t\t\t\t\t\t\t 1)Maryam Shahid" << endl;
	cout << "\t\t\t\t\t\t\t\t\t 2)Shaheer Badar" << endl;
	cout << "\t\t\t\t\t\t\t\t\t 3)Laiba Tabraiz" << endl<<endl<<endl<<endl<<endl;


	userfile.open("userid2.txt", ios::in | ios::app | ios::out);
	if (userfile.is_open()) {
		userfile.seekg(0, ios::end);
		int length = userfile.tellg();
		if (length == 0) {
			cout << "There are no accounts!" << endl << "Create a new account!\nEnter a username and passowrd to progress." << endl << endl;
			cout << "Enter Username: ";
			cin >> username;
			userfile << username;
			userfile << ",";
			cout << "Enter Password: ";
			cin >> pass;
			userfile << pass;
			cout << endl << "\nACCOUNT CREATED SUCCESSFULLY!" << endl<<endl;
		}
	}
	userfile.close();
	system("pause");
	system("CLS");
	cout << "Please login to continue :)"<<endl;
	cout << "\nEnter:\n1)Login" << endl << "2)Exit the program: ";
	cin >> option1;
	string temp;
	userfile.open("userid2.txt", ios::in);
	
	if (option1 == 1){
		while(1){
			getline(userfile,tempu,',');
			getline(userfile,tempp,'\n');
			cout << "\n\nEnter Username: ";
			cin >> username;
			cout << "Enter Password: ";
			cin >> pass;
			if(tempu==username && tempp==pass){
				cout<<"\n\nLOGGED IN SUCCESSFULLY!";
				break;
			}				
			else{
				cout<<"\n\nFAILED TO LOGIN! Incorrect username or password :(\n";		
			}				
		}
		userfile.close();
		cout<<endl<<endl<<endl;
		system("pause");
		system("CLS");
		
		top5picksfile.open("userstop5picks.txt",ios::in | ios::app | ios::out);
		top5picksfile.seekg(0, ios::end);
		length1 = top5picksfile.tellg();
		top5picksfile.close();
		
		if(length1 == 0){
		cout<<"\t\t\tLooks like you're a new user! Choose your top 5 movies from the following:\n";
					
			cout << "\n\t\t\t\t\t\tCOMEDY FILMS";
			treeobj.displayMovieToSelect(root, "Comedy");
	        cout<<endl;
	        
			cout << "\n\t\t\t\t\t\tHORROR FILMS" << endl;
			treeobj.displayMovieToSelect(root, "Horror");
			cout<<endl;
			
			cout << "\n\t\t\t\t\t\tACTION FILMS" << endl;                           
			treeobj.displayMovieToSelect(root, "Action");		
			cout<<endl;
			
			cout << "\n\t\t\t\t\t\tSCI-FI FILMS" << endl;
			treeobj.displayMovieToSelect(root, "Sci-Fi");
	        cout<<endl;
	        
			cout << "\n\t\t\t\t\t\tTHRILLER FILMS" << endl;
			treeobj.displayMovieToSelect(root, "Thriller");
			cout<<endl;
			
			displayed_mcount2 = 0;
			treeobj.pickupMovie(top5picksfile);
					
			int torecommend = 0;                                       
			for(int i = 0; i < gindex; i++){
				torecommend = torecommend + (gcount[i] * 2);
			}
			string displayed_mtitle2[torecommend];
			
			system("pause");
			system("CLS");
			
			cout<<"------------------RECOMMENDED MOVIES------------------"<<endl<<endl;
			cout<<"   ";
			cout
                << left
                << setw(70)
                << "Movie Name"
                << left
                << setw(15)
                << "Rating"
                << left
                << setw(60)
                << "Genre"
                << left
                << setw(20)
                << "Content Rating"
                << left
                << setw(15)
                << "Year"
                << left
                << setw(25)
                << "Duration(in min)"
                <<endl;
                
			for(int i = 0; i < gindex; i++){
				int counttodisplay = (gcount[i]*2);
				string genre = rec_genre[i];
				treeobj.recommend(root, genre, counttodisplay, displayed_mtitle2);	
			}
			
			cout<<endl<<endl;
			system("pause");
			system("CLS");
		}
		
		while(option2!=0){		
					
			cout << "Enter: "<<endl;
			cout << "1. To Search Movie by Title " << endl;
			cout << "2. To Search Movie by Genre"<< endl;
			cout << "3. To Search Movie by Year"<< endl;
			cout << "4. To Search Movie by Rating"<< endl;
			cout << "5. To see the Top 50 Rated"<< endl;
			cout << "6. Top Picks for you" << endl;                                //recommended movies
			cout << "7. To add a movie to your watchlist"<<endl;                   //watch later
			cout << "8. To lookup watchlist" <<endl;                  
			cout << "0. to Exit Program: ";
			cin >> option2;
			
			if (option2 == 1) {
				flag = false;
				tempfile.open("tempfile.txt", ios::out);
				tempfile << "";
				tempfile.close();
				cout << "\nEnter movie name : ";
				getline(cin >> ws, temptitle);
				
				cout << "You searched: " << temptitle << endl <<endl;
			
				i = 1;
				treeobj.titlesearch(root, temptitle, searchfile, tempfile);
				if(flag == false){
					cout<<"The title you entered does not exist in our database or an incorrect name\n";
				}	
				cout<<endl<<endl;	
				system("pause");
				system("CLS");
			}
			else if (option2 == 2){
				cc = 0;
				int no;
				cout<<endl<<"Choose from the following genres\n";
				for(int i=0;i<8;i++){
					cout<<i+1<<". "<<genrearray[i]<<"\t";
				}
				cout<<"\n\nEnter the no. of the respective genre: ";
				cin>>no;
				cout<<"You searched: "<<genrearray[no-1];
				
                i = 1;
                cout<<endl<<"\nFollowing are the top rated movies of the genre: "<<genrearray[no-1]<<": \n";
				treeobj.genresearch(root,genrearray[no-1]);
				
				cout<<endl<<endl;
				system("pause");
				system("CLS");
			}
			
			else if (option2 == 3){
				flag = false;
				string year;
				cout<<"\nEnter the year you want to search from: ";
				cin>>year;
				
				cout<<"\n\nYou searched: "<<year;
				i = 1;
				cout<<endl<<"\n\nFollowing are the top rated movies Released in the year "<<year<<": \n";
				treeobj.yearsearch(root,year);
				if(flag == false){
					cout<<"The year you entered is either incorrect or greater then 2016 please enter year before 2016 :)\n";
				}

				cout<<endl <<endl;
				system("pause");
				system("CLS");				
			}
			else if (option2 == 4){
				string rat;
				float temprat;
				cout<<"\nEnter the rating you want to search with: ";
				cin>>rat;
				temprat = stof(rat);
				if(temprat>10 || temprat<1){
					cout<<"You entered an incorrect range of rating. Please enter between 1 and 10. Thank you :)\n";
				}
				else{					
					treeobj.ratingsearch(root,rat);
					cout<<endl<<"\n\nFollowing are the  Movies Rated: "<<rat<<": \n";
				}
				system("pause");
				system("CLS");									
			}
			else if (option2 == 5){
				
				int no;
				
				cout<<endl<<"----------Top 50 HIGH RATED MOVIES-----------";
				cout<<endl;
				cout<<"   ";
				cout
                << left
                << setw(70)
                << "Movie Name"
                << left
                << setw(15)
                << "Rating"
                << left
                << setw(60)
                << "Genre"
                << left
                << setw(15)
                << "Year"
                << left
                << setw(25)
                << "Duration(in min)"
                <<endl;
				treeobj.top50rated(root);
			
		
				cout<<endl<<"\n\nEnter the no. of the movie you want to watch trailer of, 0 if you want to skip: ";
				cin>>no;
				switch(no){
					case 0:
						break;
					case 1:
						system("START youtube.com/watch?v=Kr6l87i9oAI");
						break;
					case 2:
						system("START https://www.youtube.com/watch?v=NmzuHjWmXOc");
						break;
					case 3:
						system("START https://www.youtube.com/watch?v=rqGJyUB1Q3s");
						break;
					case 4:
						system("START https://www.youtube.com/watch?v=cYio8DB-4T8");
						break;
					case 5:
						system("START https://www.youtube.com/watch?v=cYio8DB-4T8");
						break;
					case 6:
						system("START https://www.youtube.com/watch?v=5WpXw_0UU8U");
						break;
					case 7:
						system("START https://www.youtube.com/watch?v=EXeTwQWrcwY");
						break;
					case 8:
						system("START https://www.youtube.com/watch?v=9O1Iy9od7-A");
						break;
					case 9:
						system("START https://www.youtube.com/watch?v=ju75Sd4yAZw");
						break;
					case 10:
						system("START https://www.youtube.com/watch?v=r5X-hFf6Bwo");
						break;
					case 11:
						system("START https://www.youtube.com/watch?v=gG22XNhtnoY");
						break;
					case 12:
						system("START https://www.youtube.com/watch?v=tGpTpVyI_OQ");
						break;
					case 13:
						system("START https://www.youtube.com/watch?v=WCN5JJY_wiA");
						break;
					case 14:
						system("START https://www.youtube.com/watch?v=_13J_9B5jEk");
						break;
					case 15:
						system("START https://www.youtube.com/watch?v=YoHD9XEInc0");
						break;
					case 16:
						system("START https://www.youtube.com/watch?v=V75dMMIW2B4");
						break;
					case 17:
						system("START https://www.youtube.com/watch?v=jAy6NJ_D5vU");
						break;
					case 18:
						system("START https://www.youtube.com/watch?v=qtRKdVHc-cE");
						break;
					case 19:
						system("START https://www.youtube.com/watch?v=bLvqoHBptjg");
						break;
					case 20:
						system("START https://www.youtube.com/watch?v=VnXC3BAGR5s");
						break;
					case 21:
						system("START https://www.youtube.com/watch?v=JNwNXF9Y6kY");
						break;
					case 22:
						system("START https://www.youtube.com/watch?v=LbfMDwc4azU");
						break;
					case 23:
						system("START https://www.youtube.com/watch?v=vKQi3bBA1y8");
						break;
					case 24:
						system("START https://www.youtube.com/watch?v=O-mI9GajrBc");
						break;
					case 25:
						system("START https://www.youtube.com/watch?v=eOQY1HvR3Ho");
						break;
					case 26:
						system("START https://www.youtube.com/watch?v=2ilzidi_J8Q");
						break;
					case 27:
						system("START https://www.youtube.com/watch?v=vZ734NWnAHA");
						break;
					case 28:
						system("START https://www.youtube.com/watch?v=-4QORgagblU");
						break;
					case 29:
						system("START https://www.youtube.com/watch?v=OXrcDonY-B8");
						break;
					case 30:
						system("START https://www.youtube.com/watch?v=dcUOO4Itgmw");
						break;
					case 31:
						system("START https://www.youtube.com/watch?v=_BC66vQR-ls");
						break;
					case 32:
						system("START https://www.youtube.com/watch?v=I_zRjSYkaTc");
						break;						
					case 33:
						system("START https://www.youtube.com/watch?v=wJ1TOratCTo");
						break;
					case 34:
						system("START https://www.youtube.com/watch?v=B8_dgqfPXFg");
						break;
					case 35:
						system("START https://www.youtube.com/watch?v=zSWdZVtXT7E");
						break;
					case 36:
						system("START https://www.youtube.com/watch?v=Lr3OavheNu0");
						break;
					case 37:
						system("START https://www.youtube.com/watch?v=9CiW_DgxCnQ");
						break;
					case 38:
						system("START https://www.youtube.com/watch?v=qRcizKbrsws");
						break;
					case 39:
						system("START https://www.youtube.com/watch?v=znmZoVkCjpI");
						break;
					case 40:
						system("START https://www.youtube.com/watch?v=W6Mm8Sbe__o");
						break;
					case 41:
						system("START https://www.youtube.com/watch?v=ByXuk9QqQkk");
						break;
					case 42:
						system("START https://www.youtube.com/watch?v=ptX_pjz5s2k");
						break;
					case 43:
						system("START https://www.youtube.com/watch?v=XfQYHqsiN5g");
						break;
					case 44:
						system("START https://www.youtube.com/watch?v=oiXdPolca5w");
						break;
					case 45:
						system("START https://www.youtube.com/watch?v=c8CJ6L0I6W8");
						break;
					case 46:
						system("START https://www.youtube.com/watch?v=rDXiafPjLNw");
						break;
					case 47:
						system("START https://www.youtube.com/watch?v=iLR3gZrU2Xo");
						break;
					case 48:
						system("START https://www.youtube.com/watch?v=GLeDdzGUTq0");
						break;	
					case 49:
						system("START https://www.youtube.com/watch?v=MF7JH_54d8c");
						break;
					case 50:
						system("START https://www.youtube.com/watch?v=GokKUqLcvD8");
						break;
					default:
						cout<<"\nInvalid input!\n";
						break;																																																																																																				
				}
				
				cout<<endl <<endl;
				system("pause");
				system("CLS");				
			}
			else if (option2 == 6) {
				
				tempfile.open("tempfile.txt",ios::in | ios::app | ios::out);
				tempfile.seekg(0, ios::end);
				length2 = tempfile.tellg();
				tempfile.close();
				int gindex1;
				
				if(length2==0){
					
					tempfile.open("gindexkivalue.txt",ios::in );
					tempfile>>gindex1;
					tempfile.close();

					string tempgenre[gindex1];
					string tempstr;
					int tempgcount[gindex1];
					
					int c = 0;
					tempfile.open("userstop5picks.txt",ios::in);

					while(!tempfile.eof()){
						
						getline(tempfile,tempgenre[c],'\n');
						cout<<tempgenre[c]<<endl;
						getline(tempfile,tempstr,'\n');
						tempgcount[c] = stoi(tempstr);
						cout<<tempgcount[c];
						c++;
						if(c==gindex1){
							break;
						}
					}
					tempfile.close();

					int torecommend;
						
					for(int i = 0; i < gindex1; i++){
						torecommend = torecommend + (tempgcount[i] * 2);
					}
						
					string displayed_mtitle2[torecommend];
			    	displayed_mcount2 = 0;
			    	
			    	cout<<"------------------RECOMMENDED MOVIES------------------"<<endl<<endl;
					cout<<"   ";
					cout
				        << left
				        << setw(70)
				        << "Movie Name"
				        << left
				        << setw(15)
				        << "Rating"
				        << left
				        << setw(60)
				        << "Genre"
				        << left
				        << setw(20)
				        << "Content Rating"
				        << left
				        << setw(15)
				        << "Year"
				        << left
				        << setw(25)
				        << "Duration(in min)"
				        <<endl;
			            
					for(int i=0;i < gindex1;i++){
						string genre=tempgenre[i];
						int counttodisplay = (tempgcount[i]*2);
						treeobj.recommend(root, genre, counttodisplay, displayed_mtitle2);
					}
				}
				
				else if(length2 != 0){   
		
					string genre;
					int gindex = -1;	
					
					tempfile.open("tempfile.txt", ios::in);		
					while(!tempfile.eof()){
						
						if(gindex==10){
							break;
						}
						getline(tempfile,genre ,'|');
						gindex++;
					}
					tempfile.close();				
					
					string tempgenre[gindex];
					int c = 0;
					tempfile.open("tempfile.txt", ios::in);	
					
					while(!tempfile.eof()){
						getline(tempfile, tempgenre[c] ,'|');
						c++;
						if(c==gindex||c==10){
							break;
						}
					}
					tempfile.close();

					int torecommend = gindex * 3;
				
					string displayed_mtitle2[torecommend];	
					displayed_mcount2 = 0;	
					
					cout<<"------------------RECOMMENDED MOVIES------------------"<<endl<<endl;
					cout<<"   ";
					cout
				        << left
				        << setw(70)
				        << "Movie Name"
				        << left
				        << setw(15)
				        << "Rating"
				        << left
				        << setw(60)
				        << "Genre"
				        << left
				        << setw(20)
				        << "Content Rating"
				        << left
				        << setw(15)
				        << "Year"
				        << left
				        << setw(25)
				        << "Duration(in min)"
				        <<endl;
					    
					for(int i = 0; i < gindex ; i++){
						string genre = tempgenre[i];
						treeobj.recommend(root, genre, 3, displayed_mtitle2);
					}
				}
				
				cout<<endl <<endl;
				system("pause");
				system("CLS");
			}
			else if(option2 == 7){
				
				string tempname;
				watchlist.open("watchlist.txt",ios :: in |ios::out | ios::app);
				cout<<"\nEnter the name of movie you want to add to your search list\n";
				getline(cin>>ws,tempname);
				watchlist<<tempname;
				watchlist<<'\n';
				watchlist.close();
				cout<<"\nSUCCESSFULLY ADDED!";
				
				cout<<endl <<endl;
				system("pause");
				system("CLS");				
			}
			else if(option2 == 8){
				
				cout<<"\n\n-----------TO WATCHLIST----------"<<endl<<endl;
				watchlist.open("watchlist.txt", ios::in);
				while(!watchlist.eof()){
					getline(watchlist, temptitle, '\n');
					cout<<"-->"<<temptitle<<endl;
				}
				watchlist.close();
				cout<<endl<<endl;
				system("pause");
				system("CLS");	
			}
			else if(option2 == 0){
				
				system("CLS");
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tThank you for using our program :)";
				cout << "\n\n\n\n\t\t\t\t\tExiting Program";
				
				for (int i = 0; i < 10; i++) {
					cout << ".";
					Sleep(300);
				}			
			}
			else{
				cout<<"\n\nInvalid Input please enter again :)\n";
				system("pause");
				system("CLS");				
			}
		}
	}
	else{
		system("CLS");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tThank you for using our program :)";
		cout << "\n\n\n\n\t\t\t\t\tExiting Program";
		for (int i = 0; i < 10; i++) {
			cout << ".";
			Sleep(300);
		}
	}
	cout << endl << endl << endl << endl << endl;
}
int main() {
	MovieTree treeobj;
	TreeNode* root;
	root = readFileData(treeobj);
	system("Color B0");
	frontend(root, treeobj);

	return 0;
}