//This is the header file for the functions of the seperate chaining
//                         USING  LINKED  LIST
//                        =====================

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>

///////////////////////////////////////////////////////////////////////////////////////////

typedef struct LL_NODE      //Structure for a NODE
{
 int key;
 char value[5];
 struct LL_NODE *next;
}ll_node;

///////////////////////////////////////////////////////////////////////////////////////////

typedef struct ll_ttable    //Structure for a hashtable
{
 int tblsize;
 struct LL_NODE **lists;
}ll_table;


typedef struct ll_ttable *ll_hashtable;

///////////////////////////////////////////////////////////////////////////////////////////

int hashfunc(int,int); //Function for finding hash value | address
//------------------------------------------------------------------
ll_hashtable hashing_by_lists(ll_hashtable,int); //Function for hashing key to the hashtable
//-----------------------------------------------------------------------------
void skewed_data(int,int,int); //Function for generating skewed data
//-----------------------------------------
void generate_data(int); //Function for generating data in a file
//-----------------------------------------------------------------
ll_hashtable insertion_of_data_in_ll(ll_hashtable); //Function inserting data in table
//--------------------------------------------------------------------------
int next_prime(int); //Function for finding next prime of given number
//---------------------------------------------------------------------------
void ll_output(ll_hashtable); //Function for writng table in a file
//-------------------------------------------------------------
ll_hashtable ll_initialize(int); //Function to initialize hashtable
//-------------------------------------------------------------
ll_node *ll_look_up(int,ll_hashtable); //Function for searching a key
//------------------------------------------------------------
void ll_insert(ll_node*,ll_hashtable); //Function for inserting a key in table
//---------------------------------------------------------------------
ll_node *delete_list(ll_node*); //Function to delete linked lists
//----------------------------------------------------------
ll_hashtable ll_destroy(ll_hashtable); //Function for destroying the table
//------------------------------------------------------------
ll_hashtable ll_delet(int,ll_hashtable); //Function for deleting a key in table
//----------------------------------------------------------------------
int length(ll_hashtable,int); //Function for finding length of a bucket
//------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                           USING  BINARY  SEARCH  TREE
//                          =============================

typedef struct BST_NODE    //Structure for a NODE
{
 int key;
 char value[5];
 struct BST_NODE *left;
 struct BST_NODE *right;
}bst_node;

///////////////////////////////////////////////////////////////////////////////////////////

typedef struct bst_ttable    //Structure for a hashtable
{
 int tblsize;
 struct BST_NODE **lists;
}bst_table;


typedef struct bst_ttable *bst_hashtable;

///////////////////////////////////////////////////////////////////////////////////////////

bst_node *bst_insert(bst_node*,bst_node*); //Function for inserting a key in table
//------------------------------------------------------------------
int minimum(bst_node*); //Function for finding minimum in a bucket
//--------------------------------------------------------------
bst_node *search(bst_node*,int); //Function for seaching a key in table
//---------------------------------------------------------------
bst_hashtable delete_a_key(int,bst_hashtable); //Function to delete a key
//-----------------------------------------------------------------
bst_node *bst_delet(bst_node*,int); //Function for deleting a key in tree
//-------------------------------------------------------------
void inorder(FILE**,bst_node*); //Function to write table in a file
//---------------------------------------------------------------
int hashfunc(int,int); //Function for finding hash value | address
//------------------------------------------------------------------
bst_hashtable hashing_by_bst(bst_hashtable,int); //Function to hash a key to it's address
//--------------------------------------------------------------------------
bst_hashtable insertion_of_data_in_bst(bst_hashtable); //Function to insert data in table
//--------------------------------------------------------------------------
bst_hashtable bst_initialize(int); //Function to initialize table
//---------------------------------------------------------
bst_node *bst_look_up(int,bst_hashtable); //Function to search a key in a tree
//------------------------------------------------------------------
int maximum(int,int); //Function to find maximum of 2 no.'s
//-----------------------------------------------------------
int depth(bst_node*,int); //Function to find depth of a bucket
//-------------------------------------------------------------
void compare(ll_hashtable,bst_hashtable); //Function to compare lists & bst performances
//---------------------------------------------------------------------------------------
