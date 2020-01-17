//These are the functions using for the HASH TABLE


//                             USING  LINKED  LIST
//                            =====================


# include "hash.h"
# include <math.h>


///////////////////////////////////////////////////////////////////////////////////////////

//----->This is the hash function for the data to hash the key
int hashfunc(int key,int size)
{

 return key%size;    //returns the address of the given key

}//End of 'hashfunc'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for hashing the node to the HASH-TABLE
ll_hashtable hashing_by_lists(ll_hashtable h,int k)
{

 int i,j,size;
 char ch;
 ll_node *head=NULL,*s;
 printf("Do u want to give skewed data to bucket[linked list](y|n): \n");
 getchar();
 scanf("%c",&ch);
 while(1)
      {
       printf("Enter the table size [for linked list](size should be >= 10(minimum)):\n");
       scanf("%d",&size);
       if(size<10)
         {
          printf("The size of the table is too small\n");
          printf("PLEASE !!! Give the table size of >=10\n");
         }
       else
           break;
      }//End of while loop
 size=next_prime(size);     //returns next prime of 'size' variable
 h=ll_initialize(size);      //initilizes the hash table
 if(ch=='y'||ch=='Y')
   {
    printf("Enter a bucket no. that u want to have skewed data in a linked list: \n");
    scanf("%d",&j);
    skewed_data(j,size,k);
   }
 else if(ch=='n'||ch=='N')
         generate_data(k);    //generates the data in "in.dat" file
 h=insertion_of_data_in_ll(h);  //reads the data from "in.dat" & inserts in hashtable
 return h;

}//End of 'hashing_by_lists'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for generating skewed data in the given bucket
void skewed_data(int j,int size,int n)
{
 int i,l,k,m,p;
 FILE *fp1;
 char ch;
 fp1=fopen("in.dat","w");   //opens the file "in.dat"
 if(fp1==NULL)
   {
    printf("Could not open the file \n");
    exit(0);
   }
 fprintf(fp1,"KEY\tVALUE\n");
 fprintf(fp1,"===\t=====");
 for(i=0;i<(n/9);i++)           //writes the data in "in.dat"
    {
     m=random()%500000;
     fprintf(fp1,"\n%d\t",m);
     for(k=0;k<4;k++)
        {
         l=random()%26;
         ch='a'+l;
         fprintf(fp1,"%c",ch);
        }//end of for loop
    }//End of for loop
 for(p=i;p<n;p++)
    {
     j=j+size;
     fprintf(fp1,"\n%d\t",j);
     for(k=0;k<4;k++)
        {
         l=random()%26;
         ch='a'+l;
         fprintf(fp1,"%c",ch);
        }//end of for loop
    }//End of for loop
 fclose(fp1);

}//End of 'skewed_data'
                                                                                           ///////////////////////////////////////////////////////////////////////////////////////////
                                                                                           //----->This function is for generating data in a file
void generate_data(int n)
{
 int i,j,l,k;
 FILE *fp1;
 char ch;
 fp1=fopen("in.dat","w");   //opens the file "in.dat"
 if(fp1==NULL)
   {
    printf("Could not open the file \n");
    exit(0);
   }
 fprintf(fp1,"KEY\tVALUE\n");
 fprintf(fp1,"===\t=====");
 for(i=1;i<=n;i++)           //writes the data in "in.dat"
    {
     j=random()%500000;
     fprintf(fp1,"\n%d\t",j);
     for(k=0;k<4;k++)
        {
         l=random()%26;
         ch='a'+l;
         fprintf(fp1,"%c",ch);
        }//end of for loop
    }//End of for loop
 fclose(fp1);               //closes the file

}//End of 'generate_data'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for forming a node from each data of a file
ll_hashtable insertion_of_data_in_ll(ll_hashtable h)
{

 int a,i;
 char c,h1,ch,str[100];
 FILE *fp;
 ll_node *t;
 fp=fopen("in.dat","r");     //opens the "in.dat" file in 'read' mode
 if(fp==NULL)
   {
    printf("Could not open the file\n");
    exit(0);
   }
 i=0;
 while(i<2)
      {
       ch=fgetc(fp);
       if(ch=='\n')
          i++;
      }//end of while loop
 while((h1=fgetc(fp))!=EOF)
      {
       t=(ll_node*)calloc(1,sizeof(ll_node));
       fscanf(fp,"%d\t",&a);
       fscanf(fp,"%[^\n]s",str);
       t->key=a;
       strcpy(t->value,str);
       t->next=NULL;
       ll_insert(t,h);        //inserts the node 't' in hashtable
      }//End of while loop
 fclose(fp);            //closes the file "in.dat"
 return h;

}//End of 'insertion_of_data_in_ll'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for writing the HASH-TABLE in a file
void ll_output(ll_hashtable h)
{

 int a;
 FILE *fp;
 ll_node *p,*q;
 fp=fopen("out_ll.dat","w");    //opens the file "out.dat" in 'write' mode
 if(fp==NULL)
   {
    printf("Could not open the file \n");
    exit(0);
   }
 fprintf(fp,"BUCKET\tKEY\tVALUE\n");
 fprintf(fp,"======\t===\t=====");
 for(a=0;a<(h->tblsize);a++)
    {
     fprintf(fp,"\n  %d  \t",a);
     p=h->lists[a];
     q=p->next;
     while(q!=NULL)
          {
      	   fprintf(fp,"%d\t",q->key);
           fprintf(fp,"%s\n",q->value);
           fprintf(fp,"\t");
           q=q->next;
          }//end of while loop
     fprintf(fp,"\n");
    }//End of for loop
 fclose(fp);      //closes the file "out.dat"

}//End of 'll_output'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for finding the length of the given bucket
int length(ll_hashtable h,int n)
{
 int len=0;
 ll_node *t;
 t=h->lists[n];
 while(t!=NULL)
      {
       t=t->next;
       len++;
      }//end of while loop
 return len-1;

}//End of 'length'


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//                          SEPARATE  CHAINING
//                         ====================


//----->This function is for finding the next prime of the given number & to return
int next_prime(int n)
{
 int i,j,k;
 for(j=n ; ; j++)
    {
     for(i=2,k=0 ; i<=sqrt(j) ; i++)
         if(j%i==0)
           {
            k=1;
            break;
           }
         if(k==0)
            return j;
    }//end of for loop

}//End of 'next_prime'

///////////////////////////////////////////////////////////////////////////////////////////
//----->This function is for initializing the HASH TABLE for use
ll_hashtable ll_initialize(int size)
{

 ll_hashtable h;
 int i;
 h=calloc(1,sizeof(struct ll_ttable));
 if(h==NULL)
    printf("OUT OF SPACE !!!\n");           
 h->tblsize = size;       //creates an array of size "size" variable
 h->lists = calloc(h->tblsize,sizeof(struct LL_NODE*));
 if(h->lists==NULL)
    printf("OUT OF SPACE !!!\n");
 for(i=0;i<h->tblsize;i++)
    {
     h->lists[i]=(ll_node*)calloc(1,sizeof(ll_node));
     if(h->lists[i]==NULL)
        printf("OUT OF SPACE !!!\n");
    }
 return h;

}//End of 'll_initialize'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for finding the given element in the HASH-TABLE
ll_node *ll_look_up(int a,ll_hashtable h)
{

 ll_node *t1,*t2;
 int hash;
 if(h==NULL)
    printf("Sorry !!! HASHTABLE is empty\n");
 else
     {
      hash=hashfunc(a,h->tblsize);  //finds the hash value or address of the key
      printf("BUCKET----->%d\n",hash);
      t1=h->lists[hash];
      t2=t1->next;
      while(t2!=NULL)
           {
            if((t2->key)==a)  
                return t2;      //returning the node (means search is succcessful)
            else
                 t2=t2->next;
           }//end of while loop
    }//End of for loop
 return NULL;    //search is unsuccessful

}//End of 'll_look_up'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for inserting the elements in the HASH-TABLE
void ll_insert(ll_node *a,ll_hashtable h)
{

 ll_node *t;
 t=h->lists[hashfunc(a->key,h->tblsize)];
 a->next=t->next;
 t->next=a;

}//End of 'll_insert'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for destroying the HASH-TABLE
ll_hashtable ll_destroy(ll_hashtable h)
{

 int i;
 if(h==NULL)
   {
    printf("SORRY!!!Hashtable is empty\n");
    return;
   }
 for(i=0;i<h->tblsize;i++)
 h->lists[i]=delete_list(h->lists[i]);          //destroys the chains
 free(h->lists);             //destroys the array(BUCKET) 
 free(h);        //destroys the hashtable
 return NULL;

}//End of 'll_destroy'

///////////////////////////////////////////////////////////////////////////////////////////

//This function is for destroying the linked lists in the hashtable
ll_node *delete_list(ll_node *head)
{

 while(head!=NULL)
      {
       head=head->next;
       free(head);
      }
 return NULL;

}//End of 'delete_list'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for deleting a record for the given key in the hashtable
ll_hashtable ll_delet(int a,ll_hashtable h)
{

 ll_node *pre=NULL,*cur;
 int hash;
 hash=hashfunc(a,h->tblsize);
 cur=h->lists[hash];
 if(cur!=NULL)
    if(cur->key==a)
      {
       cur=cur->next;
       free(cur);
      }
 while(cur!=NULL)
      {
       if(cur->key==a)
         {
          pre->next=cur->next;
          free(cur);
         }
       pre=cur;
       cur=cur->next;
      }//end of while loop
 if(cur!=NULL)
    printf("YES!!!The given key is deleted from the hashtable\n");
 else
     printf("SORRY!!! The given key is not there in the hashtable\n");
 return h;

}//End of 'll_delet'



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//                            USING  BINARY  SEARCH  TREE
//                           =============================


//----->This function is for hashing the node to the HASH-TABLE
bst_hashtable hashing_by_bst(bst_hashtable h,int k)
{
 
 int i,j,size;
 char ch;
 ll_node *head=NULL,*s;
 printf("Do u want to give skewed data to bucket[for bst](y|n): \n");
 getchar();
 scanf("%c",&ch);
 while(1)
      {
       printf("Enter table size [for bst](size should be >= 10(minimum)):\n");
       scanf("%d",&size);
       if(size<10)
         {
          printf("The size of the table is too small\n");
          printf("PLEASE !!! Give the table size of >=10\n");
         }
       else
            break;
      }//End of while loop
 size=next_prime(size);     //returns next prime of 'size' variable
 h=bst_initialize(size);      //initilizes the hash table
 if(ch=='y'||ch=='Y')
   {
    printf("Enter a bucket no. that u want to have skewed data in a bst: \n");
    scanf("%d",&j);
    skewed_data(j,size,k);
   }
 else if(ch=='n'||ch=='N')
         generate_data(k);    //generates the data in "in.dat" file
 h=insertion_of_data_in_bst(h);  //reads the data from "in.dat" & inserts in hashtable
 return h;
 
}//End of 'hashing_by_bst'

//////////////////////////////////////////////////////////////////////////////////////////

//This function is for forming a node from each data of a file
bst_hashtable insertion_of_data_in_bst(bst_hashtable h)
{

 int a,i,val;
 char c,h1,ch,str[100];
 FILE *fp;
 bst_node *t,*p;
 fp=fopen("in.dat","r");         //opens the file "in.dat"
 if(fp==NULL)
   {
    printf("Could not open the file\n");
    exit(0);
   }
 i=0;
 while(i<2)
      {
       ch=fgetc(fp);
       if(ch=='\n')
          i++;
      }
 while((h1=fgetc(fp))!=EOF)
      {
       t=(bst_node*)calloc(1,sizeof(bst_node));
       fscanf(fp,"%d\t",&a);
       fscanf(fp,"%[^\n]s",&str);
       t->key=a;
       strcpy(t->value,str);
       t->left=t->right=NULL;
       val=hashfunc(t->key,h->tblsize);
       h->lists[val]=bst_insert(h->lists[val],t);    //inserts the node 't' in bucket "val"
      }
 fclose(fp);      //closes the file "in.dat"
 return h;

}//End of 'insertion_of_data_in_bst'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for initializing the HASH TABLE for use
bst_hashtable bst_initialize(int size)
{

 bst_hashtable h;
 int i;
 h=calloc(1,sizeof(struct bst_ttable));
 if(h==NULL)
    printf("OUT OF SPACE !!!\n");
 h->tblsize = size;       //creates an array of size "size" variable
 h->lists = calloc(h->tblsize,sizeof(struct  BST_NODE*));
 if(h->lists==NULL)
    printf("OUT OF SPACE !!!\n");
 return h;

}//End of 'bst_initialize'

///////////////////////////////////////////////////////////////////////////////////////////

//---->This function is for inserting a node in the binary search tree
bst_node *bst_insert(bst_node *root,bst_node *x)
{

 if(root==NULL)      //if ROOT is null
    root=x;
 else if(root->key>x->key)
         root->left=bst_insert(root->left,x);   //inserts in the left subtree
      else if(root->key<x->key)
              root->right=bst_insert(root->right,x);    //inserts in the right subtree
 return root;

}//End of 'bst_insert'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for finding the minimum in the given tree
int minimum(bst_node *root)
{

 if(root==NULL)       //if ROOT is NULL
    return 0;
 while(root->left!=NULL)     //traverses to the leftmost key(minimum)
       root=root->left;
 return root->key;

}//End of 'minimum'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for searching the given element in the given tree
bst_node *search(bst_node *r,int x)
{

 if(r==NULL)       //if ROOT is null
    return NULL;
 if(x<r->key)
    return search(r->left,x);          //searches in the left subtree
 else if(x>r->key)
         return search(r->right,x);    //searches in the right subtree
 else
      return r;

}//End of 'search'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This recursive function is for deleting given element from the given tree
bst_node *bst_delet(bst_node *r,int a)
{

 bst_node *k;
 if(r==NULL)       //if ROOT is null
    return NULL;
 if(a<r->key)
    r->left=bst_delet(r->left,a);
 else if(a>r->key)
         r->right=bst_delet(r->right,a);
      else
          {
           if(r->right==NULL && r->left==NULL)     //if key is a leaf node
             {
              free(r);
              return NULL;
             }
           else if(r->right!=NULL && r->left==NULL)  //if key is having right subtree
                  {                                  //                   but not left
                   k=r->right;
                   free(r);
                   r=k;
                  }
           else if(r->right==NULL && r->left!=NULL)  //if key is having left subtree
                  {                                  //                      but not right
                   k=r->left;
                   free(r);
                   r=k;
                  }
           else if(r->right!=NULL && r->left!=NULL)  //if key is in the middle of the tree
                  {
                   r->key=minimum(r->right);
                   r->right=bst_delet(r->right,r->key);
                  }
          }
 return r;

}//End of 'bst_delet'

///////////////////////////////////////////////////////////////////////////////////////////

//----->This function is for deleting the given key from the hashtable
bst_hashtable delete_a_key(int a,bst_hashtable h)
{
 bst_node *r;
 int hash;
 hash=hashfunc(a,h->tblsize);    //returns the address of 'a'
 r=h->lists[hash];
 r=bst_delet(r,a);      //deletes the key in the tree of the hash table           
 return h;

}//End of 'delete_a_key'

///////////////////////////////////////////////////////////////////////////////////////////

//This function is for printing the elements in the given tree
void inorder(FILE** fp,bst_node* r)
{

 bst_node *t;
 t=r;
 while(t!=NULL)
      {
       inorder(fp,t->left);
       fprintf(*fp," %d\t",t->key);     
       fprintf(*fp,"%s\n",t->value);
       fprintf(*fp,"\t");
       inorder(fp,t->right);
       break;
      }

}//End of 'inorder'

///////////////////////////////////////////////////////////////////////////////////////////

//This function is for writing the HASH-TABLE in a file
void bst_output(bst_hashtable h)
{

 int a;
 FILE *fp;
 bst_node *p,*q,*r;
 fp=fopen("out_bst.dat","w");     //opens the file "out.dat"
 if(fp==NULL)
   {
    printf("Could not open the file \n");
    exit(0);
   }
 fprintf(fp,"BUCKET\tKEY\tVALUE\n");
 fprintf(fp,"======\t===\t=====");
 for(a=0;a<(h->tblsize);a++)
    {
     fprintf(fp,"\n  %d  \t",a);
     p=h->lists[a];
     inorder(&fp,p);    //writes the trees in the file "out.dat"
     fprintf(fp,"\n");
    }
 fclose(fp);         //closes the file "out.dat"

}//End of 'bst_output'

///////////////////////////////////////////////////////////////////////////////////////////

//This function is for finding the maximum of the given 2 numbers
int maximum(int a,int b)
{

 if(a<b)
    return b;
 else
    return a;

}//End of 'maximum'

///////////////////////////////////////////////////////////////////////////////////////////

int depth(bst_node *root,int dep)
{

 if(root==NULL)
    return dep;
 else
    return maximum(depth(root->left,dep+1),depth(root->right,dep+1));

}//End of 'depth'

///////////////////////////////////////////////////////////////////////////////////////////

//This function is for searching a key in the HASH-TABLE
void retrieve(int k,bst_hashtable h)
{

 int hash;
 bst_node *t;
 if(h==NULL)
   {
    printf("Sorry !!! HASHTABLE is empty\n");
    return;
   }
 hash=hashfunc(k,h->tblsize);
 printf("BUCKET----->'%d'\n",hash);
 t=h->lists[hash];
 t=search(t,k);         //searches in the bucket "k"
 if(t==NULL)
    printf("Sorry!!! %d is not there in the hash table\n",k);
 else
     printf("KEY-----> '%d'\nVALUE----->'%s'\n",t->key,t->value);

}//End of 'retrieve'

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---->This function is for comparing linked list performance & binary search tree performance in a hashtable by lengths vs depths
void compare(ll_hashtable h1,bst_hashtable h2)
{

 int k,a,i,d;
 FILE *fp;
 fp=fopen("compare.dat","w");   //opens the file "compare.dat"
 if(fp==NULL)
   {
    printf("Out Of Space!!!");
    exit(0);
   }
 fprintf(fp,"BUCKET NO.\tLENGTH(LL)\tDEPTH(BST)\n");
 fprintf(fp,"==========\t==========\t==========\n");
 for(i=0;i<(h1->tblsize);i++)
    {
     fprintf(fp,"%-4d\t\t",i);
     fprintf(fp,"%-4d\t\t",length(h1,i));    //prints the length of the bucket in file
     d=depth(h2->lists[i],0);      //finds depth of a bucket
     fprintf(fp,"%-4d \n",d-1);    //prints depth in file
    }//End of for loop
 fclose(fp);     //closes the file "compare.dat"

}//End of 'compare'


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////       THE     END       //////////////////////////////////////////////////////////////////=========================/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
