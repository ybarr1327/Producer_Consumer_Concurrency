

#include <stdlib.h> /* required for rand() */
#include <time.h>
#include<pthread.h>
#include<semaphore.h>
#include<iostream>
#include<string>
#include<stdio.h>
#include <unistd.h>

using namespace std;

#define BUFFER_SIZE 5
typedef int buffer_item;

buffer_item B[BUFFER_SIZE]; //this creates a buffer (circular queue implementation) of size BUFFER_SIZE

//these indexes keep track of where to insert and remove from the circular queue B
int in = 0;//insert at this index
int out = 0;//remove from this index
int count = 0;//keeps track of the number of items currently in the buffer

sem_t empty,full;//declare the semaphores, empty correlates with the number of empty spaces in the buffer, full correlates with the number of used spots in the buffer
pthread_mutex_t mutex; //declare the mutex lock to ensure mutal exclusivity
int status; //variable to keep track of any errors 

//function prototypes
void initialize();
void *producer(void *param);
void *consumer(void *param);
int insert_item(buffer_item item);
int remove_item(buffer_item& item);
void printContentsOfBuffer();

/*********************************************
 Function Name: printContentsOfBuffer
 Purpose: this prints the contents of the buffer to the console output in brackets, each item separated by a space
 Input Parameters: N/A
 Output: the contents of the buffer are printed to the console formated
*********************************************/
void printContentsOfBuffer()
{
    cout<<"The current content of the buffer is [";
    if(count != 0)
    {
        int i = out;//starting from the out index
        do 
        {
            //print the value in the buffer
            cout<<" "<<B[i];
            i = (i+1)%BUFFER_SIZE;//move to next index circularly
        }while (i != in);//print until getting to the in index
    }
    cout<<" ]"<<endl;
}

/*********************************************
 Function Name: initialize
 Purpose: This function initializes the semaphores and the lock for use
 Input Parameters:N/A
 Output:N/A
*********************************************/
void initialize()
{
    //for each semaphore and lock: 
    //if status is set to negative it will go into the if statements, so show error message and exit

    status = sem_init(&empty,0, BUFFER_SIZE); //empty starts with initial value of BUFFER_SIZE meaning the buffer has BUFFER_SIZE empty spots at the start

    if(status)
    {
        cerr<<"Empty semaphore could not be initialized: "<<status<<endl;
        exit(1);
    }
    
    status = sem_init(&full,0,0);//full starts with initial value of 0 meaning the buffer has no items in it at the start

    if(status)
    {
        cerr<<"Full semaphore could not be initialized: "<<status<<endl;
        exit(1);
    }

    status = pthread_mutex_init(&mutex,NULL); 

    if(status)
    {
        cerr<<"Mutex lock could not be initialized: "<<status<<endl;
        exit(1);
    }
    
}

/*********************************************
 Function Name: producer
 Purpose: This function will be the thread function for the producer threads, this function will wait until there is a free space and add an item into the buffer
 Input Parameters:void* param, this parameter is used so that the producer can accept arguments from the pthread_create call, but in this case it is not used
 Output:N/A
*********************************************/
void *producer(void *param)
{
    srand(time(NULL));//seed the randomness
    buffer_item item;

    while (true)
    {
        // usleep for a random period of time 
        unsigned int randomTime = rand()%1000000;
        usleep(randomTime);

        status = sem_wait(&empty);//wait for an empty space to exist in the buffer
        if(status)
        {
            cerr<<"There was a problem with waiting for the empty semaphore: "<<status<<endl;
            exit(1);
        }
        status = pthread_mutex_lock(&mutex); //wait to get access to the mutex lock
        if(status)
        {
            cerr<<"There was a problem with getting the mutex lock: "<<status<<endl;
            exit(1);
        }

        //------------------------------------------
        // generate a random number and insert it
        item = rand()%100;
        if(insert_item(item))//if here then insert item returned -1 so there was too many items trying to be inserted 
            printf("There was an error with overflow.");
        else
        {
            //show sucess message and print contents of buffer
            printf("item %d inserted by a producer.\n", item); 
            printContentsOfBuffer();
            cout<<endl;
        }
            
        //------------------------------------------

        status = pthread_mutex_unlock(&mutex); //give up the lock
        if(status)
        {
            cerr<<"There was a problem with releasing the mutex lock: "<<status<<endl;
            exit(1);
        }

        status = sem_post(&full); //signal full that the space is now being used
        if(status)
        {
            cerr<<"There was a problem with signaling the full semaphore: "<<status<<endl;
            exit(1);
        }

    }
}
/*********************************************
 Function Name: consumer
 Purpose: This function will be the thread function for the consumer threads, this function will wait until there is an item in the buffer and it will remove it from the buffer
 Input Parameters: void* param, this parameter is used so that the consumer can accept arguments from the pthread_create call, but in this case it is not used
 Output:N/A
*********************************************/
void *consumer(void *param)
{
    srand(time(NULL));//seed the randomness
    buffer_item item;
    while (true)
    {
        // usleep for a random period of time 
        unsigned int randomTime = rand()%1000000;
        usleep(randomTime);

        status = sem_wait(&full);//wait for there to be an item in the buffer
        if(status)
        {
            cerr<<"There was a problem with waiting for the full semaphore: "<<status<<endl;
            exit(1);
        }
        status = pthread_mutex_lock(&mutex);//wait for access to the lock
        if(status)
        {
            cerr<<"There was a problem with getting the mutex lock: "<<status<<endl;
            exit(1);
        }
        

        //------------------------------------------

        if(remove_item(item)) //if here then remove_item returned -1 so there was too few items and something could not be removed 
            printf("There was an underflow problem");
        else
        {
            //show sucess message and print contents of buffer
            printf("item %d removed by a consumer.\n", item);
            printContentsOfBuffer();
            cout<<endl;
        }
            

        //------------------------------------------

        status = pthread_mutex_unlock(&mutex);//release the lock
        if(status)
        {
            cerr<<"There was a problem with releasing the mutex lock: "<<status<<endl;
            exit(1);
        }

        status = sem_post(&empty); //signal that there is now an empty space
        if(status)
        {
            cerr<<"There was a problem with signaling the empty semaphore: "<<status<<endl;
            exit(1);
        }

    }                
}   
/*********************************************
 Function Name: insert_item
 Purpose: this function will add the item to the array and move the indexs appropriately
 Input Parameters: buffer_item item, this is the item to be added to the buffer
 Output: this returns 0 if the add was successful and -1 if the add was not
*********************************************/
int insert_item(buffer_item item)
{
    count += 1;//increase the count

    if (count > BUFFER_SIZE)//if the counter is bigger that BUFFER_SIZE, the buffer is overflowed for the array, so return -1
    {
        //there was an overflow so return error condition
        return -1;
    }
    else
    {
        B[in] = item;//store item
        in = (in+1)%BUFFER_SIZE;//move the index circularly
        return 0;
    }
    
    /* insert item into buffer
   return 0 if successful, otherwise
   return -1 indicating an error condition */
}
/*********************************************
 Function Name: removed_item
 Purpose: this function get the item from the buffer and removes it
 Input Parameters: buffer_item& item, this is a variable that is passed by reference so that the item can be returned back to the main
 Output: N/A
*********************************************/
int remove_item(buffer_item& item)
{
    count -=1 ;
    if(count < 0) //if there then there is an underflow problem, so return -1
    {
        //there was an underflow so return error condition
        return -1;
    }
    else
    {
        item = B[out];//store item
        out = (out+1)%BUFFER_SIZE;//move the index circularly
        return 0;
    }
    
    /* remove an object from buffer
   placing it in item
   return 0 if successful, otherwise
   return -1 indicating an error condition */
}     

int main(int argc, char *argv[])
{
    //preface 
    std::cout << "=================================" << std::endl;
    std::cout << "CS 433 Programming assignment 4" << std::endl;
    std::cout << "Author: Gabriel Ybarra, Ryan Lochrane" << std::endl;
    std::cout << "Date: 11/17/2020" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : This program is an implementation of a solution to the Producer Consumer problem seen in the book";
    std::cout << "The soultion to the thread concurrency problem that occurs is solved by using semaphores and a mutex lock to ensure"; 
    std::cout << "That the critical section that adds and removes from the buffer stays consistent throughout the programs runtime."<< std::endl;
    std::cout << "=================================" << std::endl;

    //Error checking
    

    if(argc < 4) //check if the user entered too little arguments, if so show message below and exit
    {
        cout << "*** You have entered too few parameters to run the program.  You must enter three command-line arguments:"<<endl;
        cout << "- amount of time to run the program (in seconds, positive integer that is nonzero)"<<endl;
        cout << "- number of producer threads to create (positive integer or zero)"<<endl;
        cout << "- number of consumer threads to create (positive integer or zero)"<<endl;
        exit(1);
    }
    else if (argc > 4) //check if the user entered too many arguments, if so show message below and exit
    {
        cerr << "*** You have entered too many parameters to run the program. you must enter three command-line arguments:"<<endl;
        cerr << "- amount of time to run the program (in seconds, positive integer that is nonzero)"<<endl;
        cerr << "- number of producer threads to create (positive integer or zero)"<<endl;
        cerr << "- number of consumer threads to create (positive integer or zero)"<<endl;
        exit(1);

    }

    bool notNum = 0;//flag enabled when a user argument is not numerical
    bool isZero = 0; //flag to check if the argument is zero 
    bool isNegative = 0; //flag to check if the argument is negative


    //first argument must be time to run so, it has to be positive and non zero and numerical
    string timeTemp = argv[1];
    for(int i = 0; i < timeTemp.size();i++)
    {
        if(!isdigit(timeTemp[i]))
        {
            notNum = 1;
            break;
        }
    }
    if(atoi(argv[1])==0)
        isZero = 1;
    if(atoi(argv[1])<0)
        isNegative = 1;

    //second argument must be the number of producers, it has to be numerical and not negative
    string numProd = argv[2];
    for(int i = 0; i < numProd.size();i++)
    {
        if(!isdigit(numProd[i]))
        {
            notNum = 1;
            break;
        }    
    }
    if(atoi(argv[2])<0)
        isNegative = 1;

    //third argument must be the number of consumers, it has to be numerical and not negative
    string numConsum = argv[3];
    for(int i = 0; i < numConsum.size();i++)
    {
        if(!isdigit(numConsum[i]))
        {
            notNum = 1;
            break;
        }
    }
    if(atoi(argv[3])<0)
        isNegative = 1;


    //here check if an error flag was enabled, if so there was an error with the inputs so exit and show a message
    if(notNum)
    {
        cerr<<"One or more of your arguments were not numerical. Run the  program again with numerical inputs."<<endl;
        exit(1);
    }
    if(isZero||isNegative)
    {
        cerr<<"One or more of your arguments was not in the correct format, Here are the appropriate formats:"<<endl;
        cerr << "- amount of time to run the program (in seconds, positive integer that is nonzero)"<<endl;
        cerr << "- number of producer threads to create (positive integer or zero)"<<endl;
        cerr << "- number of consumer threads to create (positive integer or zero)"<<endl;
        exit(1);
    }

    //finally store the three values into variables
    unsigned int timeToRun  = atoi(argv[1]);
    unsigned int numOfProducerThreads = atoi(argv[2]);
    unsigned int numOfConsumerThreads = atoi(argv[3]);


    initialize();//initializes the semaphores and the mutex lock

    //create an array of producer threads and start them, also check for errors
    pthread_t producers[numOfProducerThreads];

    for(int i =0; i < numOfProducerThreads; i++)
    {
        int threadError;
        
        threadError = pthread_create(&producers[i],NULL,producer, NULL); 

        if(threadError)
        {
            cout<<"There was an error creating the thread: "<<threadError<<endl;
            exit(-1);
        }
        cout<<"Producer Thread "<<i<<" created"<<endl;
    }
    
    cout<<endl;

    //create an array of consumer threads and start them, also check for errors
    pthread_t consumers[numOfConsumerThreads];

    for(int i =0; i < numOfConsumerThreads; i++)
    {
        int threadError;
        
        threadError = pthread_create(&consumers[i],NULL,consumer, NULL); 

        if(threadError)
        {
            cout<<"There was an error creating the thread: "<<threadError<<endl;
            exit(-1);
        }
        cout<<"Consumer Thread "<<i<<" created"<<endl;
    }

    cout<<endl;

    sleep(timeToRun);//dont end the process until the timeToRun expires
 
    return 0;
}

