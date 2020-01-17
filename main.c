//This is the main program for testing the HASH-TABLE functions

# include "hash.h"


int main()
{


 int k,a,b,n;
 ll_node *t1;
 bst_node *t2;
 ll_hashtable h1=NULL;
 bst_hashtable h2=NULL;

 system("clear");

 printf("\t\t\tWELCOME  TO  THE  WORLD  OF  HASHTABLE\n");
 printf("\t\t\t--------------------------------------\n");
 printf("\tIn this,the user can do  following by choosing either linked list or binary search tree for the hashtable:\n");
 printf("1)Creating a hashtable by generating data in a file\n");
 printf("2)Searching a key in the hashtable\n");
 printf("3)Deleting a key in the hashtable\n4)Destroying the hashtable\n");
 printf("5)Finding the length or depth of a particular bucket\n");
 printf("6)Comparing both linked list & binary search trees performance by their lengths and depths\n");
 printf("\nNOTE  : In this,'key' is an integer and 'value' is a string\n");
 printf("\nSo,now you can use the hashtable--------->\n\n");
 printf("Do u want to construct the hashtable by linked list or binary search tree\n");
 printf("If linked list,enter '1' or if binary search tree,enter '2'   :\n");
 printf("OR if u want to compare both performance,enter '3'");

 scanf("%d",&b);

 if(b==1)
    while(1)
         {
          printf("\n\nChoose the appropriate option of ur choice from the following :\n");
          printf("1)Generation of data in a file & insertion of data in a hashtable\n");
          printf("2)Searching a key(integer) in the hashtable\n");
          printf("3)Deleting a key(integer) in the hashtable\n");
          printf("4)Length of a bucket in the hashtable\n");
          printf("5)Destroying the HASHTABLE\n");
          printf("6)Exiting the program\n");

          scanf("%d",&a);

          switch(a)
           {
            case 1 : printf("Enter number of keys to be generated :\n");
                     scanf("%d",&k);
                     h1=hashing_by_lists(h1,k);    //generates the data & inserts in the hash table
                     ll_output(h1);      //writes the hashtable in "out.dat" file
                     break;

            case 2 : if(h1==NULL)
                        printf("SORRY!!!Hashtable is empty\n");
                     else
                         {
                          printf("Enter a key to search in the hashtable: \n");
                          scanf("%d",&k);
                          t1=ll_look_up(k,h1);  //searches the key 'k'
                          if(t1==NULL)
                             printf("The given key is not there in the hashtable\n");
                          else
                              printf("KEY---->%d\nVALUE---->%s\n",t1->key,t1->value);
                         }
                     break;

            case 3 : if(h1==NULL)
                        printf("Sorry!!!HASHTABLE is empty\n");
                     else
                         {
                          printf("Enter a key to delete from the hashtable: \n");
                          scanf("%d",&k);
                          h1=ll_delet(k,h1);   //deletes the key k from hashtable
                          ll_output(h1);      //removes the key from 'out.dat' file
                         }
                     break;

            case 4 : if(h1==NULL)
                        printf("Sorry!!!HASHTABLE is empty\n");
                     else
                         {
                          printf("Enter a bucket no. to find it's depth: \n");
                          scanf("%d",&k);
                          n=length(h1,k);
                          printf("The length of '%d' bucket is '%d'\n",k,n);
                         }
                     break;

            case 5 : if(h1!=NULL)
                        ll_destroy(h1);
                     else
                         printf("HASHTABLE is already empty\n");
                     break;

            case 6 : exit(0);      //exits the program
                     break;

            default: printf("SORRY !!! This case is not there\n");
                     break;
           }//End of switch case
         }//End of while loop
 if(b==2)
    while(1)
         {
          printf("\n\nChoose the appropriate option of ur choice from the following :\n");
          printf("1)Generation of data in a file & insertion of data in a hashtable\n");
          printf("2)Searching a key(integer) in the hashtable\n");
          printf("3)Deleting a key(integer) in the hashtable\n");
          printf("4)Depth of a bucket in the hashtable\n");
          printf("5)Exiting the program\n");
          scanf("%d",&a);
          switch(a)
           {
            case 1 : printf("Enter number of keys to be generated :\n");
                     scanf("%d",&k);
                     h2=hashing_by_bst(h2,k);    //generates the data & inserts in the hash table
                     bst_output(h2);      //writes the hashtable in "out.dat" file
                     break;

            case 2 : if(h2==NULL)
                        printf("SORRY!!!Hashtable is empty\n");
                     else
                         {
                          printf("Enter a key to search in the hashtable: \n");
                          scanf("%d",&k);
                          retrieve(k,h2);  //searches the key 'k'
                         }
                     break;

            case 3 : if(h2==NULL)
                        printf("SORRY!!!Hashtable is empty\n");
                     else
                         {
                          printf("Enter a key to delete from the hashtable: \n");
                          scanf("%d",&k);
                          h2=delete_a_key(k,h2);   //deletes the key k from hashtable
                          bst_output(h2);      //removes the key from 'out.dat' file
                         }
                     break;

            case 4 : if(h2==NULL)
                        printf("SORRY!!!Hashtable is empty\n");
                     else
                         {
                          printf("Enter a bucket no. to find it's depth: \n");
                          scanf("%d",&k);
                          t2=h2->lists[k];
                          n=depth(t2,0);
                          printf("The depth of '%d' bucket is '%d'\n",k,n);
                         }
                     break;

            case 5 : exit(0);      //exits the program
                     break;

            default: printf("SORRY !!! This case is not there\n");
                     break;
           }//End of switch case
         }//End of while loop
 if(b==3)
   {

    printf("Enter number of keys to be generated :\n");
    scanf("%d",&k);

    h1=hashing_by_lists(h1,k);    //generates the data & inserts in the hash table
    ll_output(h1);      //writes the hashtable in "out.dat" file
    printf("\nGive the same input as given above\n\n");
    h2=hashing_by_bst(h2,k);    //generates the data & inserts in the hash table
    bst_output(h2);      //writes the hashtable in "out.dat" file
    while(h1->tblsize!=h2->tblsize)
      {
       printf("SORRY!U have given wrong tablesize \n");
       printf("PLEASE! Give the table size as given above \n");
       h2=hashing_by_bst(h2,k);    //generates the data & inserts in the hash table
       bst_output(h2);      //writes the hashtable in "out.dat" file
      }
    compare(h1,h2);
    printf("Now,open the file 'compare.dat' for seeing the comparision\n");
   }
 else;
 return 0;


}//End of main
