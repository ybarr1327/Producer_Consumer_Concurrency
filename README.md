This program is an implementation of a solution to the Producer Consumer problem https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem
The soultion to the thread concurrency problem that occurs is solved by using semaphores and a mutex lock to ensure that the critical section that adds and removes from the buffer stays consistent throughout the programs runtime


This is a command line program which takes the following arguments
amount of time to run the program (in seconds, positive integer that is nonzero)
number of producer threads to create (positive integer or zero)
number of consumer threads to create (positive integer or zero)


example input:

./prog4 10 5 5

example output:

Producer Thread 0 created
Producer Thread 1 created
Producer Thread 2 created
Producer Thread 3 created
Producer Thread 4 created

Consumer Thread 0 created
Consumer Thread 1 created
Consumer Thread 2 created
Consumer Thread 3 created
Consumer Thread 4 created

item 29 inserted by a producer.
The current content of the buffer is [ 29 ]

item 8 inserted by a producer.
The current content of the buffer is [ 29 8 ]

item 9 inserted by a producer.
The current content of the buffer is [ 29 8 9 ]

item 12 inserted by a producer.
The current content of the buffer is [ 29 8 9 12 ]

item 89 inserted by a producer.
The current content of the buffer is [ 29 8 9 12 89 ]

item 29 removed by a consumer.
The current content of the buffer is [ 8 9 12 89 ]

item 8 removed by a consumer.
The current content of the buffer is [ 9 12 89 ]

item 9 removed by a consumer.
The current content of the buffer is [ 12 89 ]

item 12 removed by a consumer.
The current content of the buffer is [ 89 ]

item 89 removed by a consumer.
The current content of the buffer is [ ]

item 52 inserted by a producer.
The current content of the buffer is [ 52 ]

item 52 removed by a consumer.
The current content of the buffer is [ ]

item 68 inserted by a producer.
The current content of the buffer is [ 68 ]

item 68 removed by a consumer.
The current content of the buffer is [ ]

item 19 inserted by a producer.
The current content of the buffer is [ 19 ]

item 19 removed by a consumer.
The current content of the buffer is [ ]

item 42 inserted by a producer.
The current content of the buffer is [ 42 ]

item 42 removed by a consumer.
The current content of the buffer is [ ]

item 96 inserted by a producer.
The current content of the buffer is [ 96 ]

item 96 removed by a consumer.
The current content of the buffer is [ ]

item 83 inserted by a producer.
The current content of the buffer is [ 83 ]

item 83 removed by a consumer.
The current content of the buffer is [ ]

item 43 inserted by a producer.
The current content of the buffer is [ 43 ]

item 43 removed by a consumer.
The current content of the buffer is [ ]

item 75 inserted by a producer.
The current content of the buffer is [ 75 ]

item 75 removed by a consumer.
The current content of the buffer is [ ]

item 16 inserted by a producer.
The current content of the buffer is [ 16 ]

item 16 removed by a consumer.
The current content of the buffer is [ ]

item 2 inserted by a producer.
The current content of the buffer is [ 2 ]

item 46 inserted by a producer.
The current content of the buffer is [ 2 46 ]

item 2 removed by a consumer.
The current content of the buffer is [ 46 ]

item 4 inserted by a producer.
The current content of the buffer is [ 46 4 ]

item 46 removed by a consumer.
The current content of the buffer is [ 4 ]

item 4 removed by a consumer.
The current content of the buffer is [ ]

item 9 inserted by a producer.
The current content of the buffer is [ 9 ]

item 9 removed by a consumer.
The current content of the buffer is [ ]

item 48 inserted by a producer.
The current content of the buffer is [ 48 ]

item 48 removed by a consumer.
The current content of the buffer is [ ]

item 17 inserted by a producer.
The current content of the buffer is [ 17 ]

item 17 removed by a consumer.
The current content of the buffer is [ ]

item 55 inserted by a producer.
The current content of the buffer is [ 55 ]

item 55 removed by a consumer.
The current content of the buffer is [ ]

item 48 inserted by a producer.
The current content of the buffer is [ 48 ]

item 48 removed by a consumer.
The current content of the buffer is [ ]

item 50 inserted by a producer.
The current content of the buffer is [ 50 ]

item 50 removed by a consumer.
The current content of the buffer is [ ]

item 0 inserted by a producer.
The current content of the buffer is [ 0 ]

item 0 removed by a consumer.
The current content of the buffer is [ ]

item 9 inserted by a producer.
The current content of the buffer is [ 9 ]

item 9 removed by a consumer.
The current content of the buffer is [ ]

item 55 inserted by a producer.
The current content of the buffer is [ 55 ]

item 55 removed by a consumer.
The current content of the buffer is [ ]

item 11 inserted by a producer.
The current content of the buffer is [ 11 ]

item 11 removed by a consumer.
The current content of the buffer is [ ]

item 93 inserted by a producer.
The current content of the buffer is [ 93 ]

item 93 removed by a consumer.
The current content of the buffer is [ ]

item 93 inserted by a producer.
The current content of the buffer is [ 93 ]

item 80 inserted by a producer.
The current content of the buffer is [ 93 80 ]

item 93 removed by a consumer.
The current content of the buffer is [ 80 ]

item 80 removed by a consumer.
The current content of the buffer is [ ]

item 29 inserted by a producer.
The current content of the buffer is [ 29 ]

item 29 removed by a consumer.
The current content of the buffer is [ ]

item 14 inserted by a producer.
The current content of the buffer is [ 14 ]

item 14 removed by a consumer.
The current content of the buffer is [ ]

item 79 inserted by a producer.
The current content of the buffer is [ 79 ]

item 79 removed by a consumer.
The current content of the buffer is [ ]

item 35 inserted by a producer.
The current content of the buffer is [ 35 ]

item 35 removed by a consumer.
The current content of the buffer is [ ]

item 90 inserted by a producer.
The current content of the buffer is [ 90 ]

item 80 inserted by a producer.
The current content of the buffer is [ 90 80 ]

item 90 removed by a consumer.
The current content of the buffer is [ 80 ]

item 80 removed by a consumer.
The current content of the buffer is [ ]

item 25 inserted by a producer.
The current content of the buffer is [ 25 ]

item 25 removed by a consumer.
The current content of the buffer is [ ]

item 29 inserted by a producer.
The current content of the buffer is [ 29 ]

item 29 removed by a consumer.
The current content of the buffer is [ ]

item 50 inserted by a producer.
The current content of the buffer is [ 50 ]

item 50 removed by a consumer.
The current content of the buffer is [ ]

item 30 inserted by a producer.
The current content of the buffer is [ 30 ]

item 30 removed by a consumer.
The current content of the buffer is [ ]

item 17 inserted by a producer.
The current content of the buffer is [ 17 ]

item 17 removed by a consumer.
The current content of the buffer is [ ]

item 94 inserted by a producer.
The current content of the buffer is [ 94 ]

item 94 removed by a consumer.
The current content of the buffer is [ ]

item 6 inserted by a producer.
The current content of the buffer is [ 6 ]

item 6 removed by a consumer.
The current content of the buffer is [ ]

item 78 inserted by a producer.
The current content of the buffer is [ 78 ]

item 78 removed by a consumer.
The current content of the buffer is [ ]

item 80 inserted by a producer.
The current content of the buffer is [ 80 ]

item 80 removed by a consumer.
The current content of the buffer is [ ]

item 12 inserted by a producer.
The current content of the buffer is [ 12 ]

item 12 removed by a consumer.
The current content of the buffer is [ ]

item 4 inserted by a producer.
The current content of the buffer is [ 4 ]

item 4 removed by a consumer.
The current content of the buffer is [ ]

item 49 inserted by a producer.
The current content of the buffer is [ 49 ]

item 49 removed by a consumer.
The current content of the buffer is [ ]

item 56 inserted by a producer.
The current content of the buffer is [ 56 ]

item 56 removed by a consumer.
The current content of the buffer is [ ]

item 26 inserted by a producer.
The current content of the buffer is [ 26 ]

item 26 removed by a consumer.
The current content of the buffer is [ ]

item 23 inserted by a producer.
The current content of the buffer is [ 23 ]

item 23 removed by a consumer.
The current content of the buffer is [ ]

item 8 inserted by a producer.
The current content of the buffer is [ 8 ]

item 8 removed by a consumer.
The current content of the buffer is [ ]

item 27 inserted by a producer.
The current content of the buffer is [ 27 ]

item 27 removed by a consumer.
The current content of the buffer is [ ]

item 80 inserted by a producer.
The current content of the buffer is [ 80 ]

item 49 inserted by a producer.
The current content of the buffer is [ 80 49 ]

item 63 inserted by a producer.
The current content of the buffer is [ 80 49 63 ]

item 80 removed by a consumer.
The current content of the buffer is [ 49 63 ]

item 49 removed by a consumer.
The current content of the buffer is [ 63 ]

item 63 removed by a consumer.
The current content of the buffer is [ ]

item 5 inserted by a producer.
The current content of the buffer is [ 5 ]

item 39 inserted by a producer.
The current content of the buffer is [ 5 39 ]

item 82 inserted by a producer.
The current content of the buffer is [ 5 39 82 ]

item 5 removed by a consumer.
The current content of the buffer is [ 39 82 ]

item 39 removed by a consumer.
The current content of the buffer is [ 82 ]

item 92 inserted by a producer.
The current content of the buffer is [ 82 92 ]

item 16 inserted by a producer.
The current content of the buffer is [ 82 92 16 ]

item 14 inserted by a producer.
The current content of the buffer is [ 82 92 16 14 ]

item 82 removed by a consumer.
The current content of the buffer is [ 92 16 14 ]

item 92 removed by a consumer.
The current content of the buffer is [ 16 14 ]

item 0 inserted by a producer.
The current content of the buffer is [ 16 14 0 ]

item 16 removed by a consumer.
The current content of the buffer is [ 14 0 ]

item 14 removed by a consumer.
The current content of the buffer is [ 0 ]

item 28 inserted by a producer.
The current content of the buffer is [ 0 28 ]

item 0 removed by a consumer.
The current content of the buffer is [ 28 ]

item 28 removed by a consumer.
The current content of the buffer is [ ]

item 99 inserted by a producer.
The current content of the buffer is [ 99 ]

item 99 removed by a consumer.
The current content of the buffer is [ ]

item 23 inserted by a producer.
The current content of the buffer is [ 23 ]

item 23 removed by a consumer.
The current content of the buffer is [ ]

item 44 inserted by a producer.
The current content of the buffer is [ 44 ]

item 44 removed by a consumer.
The current content of the buffer is [ ]

item 83 inserted by a producer.
The current content of the buffer is [ 83 ]

item 83 removed by a consumer.
The current content of the buffer is [ ]

item 26 inserted by a producer.
The current content of the buffer is [ 26 ]

item 26 removed by a consumer.
The current content of the buffer is [ ]

item 71 inserted by a producer.
The current content of the buffer is [ 71 ]

item 71 removed by a consumer.
The current content of the buffer is [ ]

item 99 inserted by a producer.
The current content of the buffer is [ 99 ]

item 99 removed by a consumer.
The current content of the buffer is [ ]

item 27 inserted by a producer.
The current content of the buffer is [ 27 ]

item 27 removed by a consumer.
The current content of the buffer is [ ]

item 55 inserted by a producer.
The current content of the buffer is [ 55 ]

item 55 removed by a consumer.
The current content of the buffer is [ ]

item 83 inserted by a producer.
The current content of the buffer is [ 83 ]

item 83 removed by a consumer.
The current content of the buffer is [ ]

item 95 inserted by a producer.
The current content of the buffer is [ 95 ]

item 95 removed by a consumer.
The current content of the buffer is [ ]

item 19 inserted by a producer.
The current content of the buffer is [ 19 ]

item 19 removed by a consumer.
The current content of the buffer is [ ]

item 22 inserted by a producer.
The current content of the buffer is [ 22 ]

item 42 inserted by a producer.
The current content of the buffer is [ 22 42 ]

item 22 removed by a consumer.
The current content of the buffer is [ 42 ]

item 42 removed by a consumer.
The current content of the buffer is [ ]

item 24 inserted by a producer.
The current content of the buffer is [ 24 ]

item 74 inserted by a producer.
The current content of the buffer is [ 24 74 ]

item 90 inserted by a producer.
The current content of the buffer is [ 24 74 90 ]

item 24 removed by a consumer.
The current content of the buffer is [ 74 90 ]

item 74 removed by a consumer.
The current content of the buffer is [ 90 ]

item 90 removed by a consumer.
The current content of the buffer is [ ]

item 23 inserted by a producer.
The current content of the buffer is [ 23 ]

item 23 removed by a consumer.
The current content of the buffer is [ ]

item 92 inserted by a producer.
The current content of the buffer is [ 92 ]

item 92 removed by a consumer.
The current content of the buffer is [ ]

item 88 inserted by a producer.
The current content of the buffer is [ 88 ]

item 88 removed by a consumer.
The current content of the buffer is [ ]

item 44 inserted by a producer.
The current content of the buffer is [ 44 ]

item 14 inserted by a producer.
The current content of the buffer is [ 44 14 ]

item 73 inserted by a producer.
The current content of the buffer is [ 44 14 73 ]

item 44 removed by a consumer.
The current content of the buffer is [ 14 73 ]

item 14 removed by a consumer.
The current content of the buffer is [ 73 ]

item 84 inserted by a producer.
The current content of the buffer is [ 73 84 ]

item 73 removed by a consumer.
The current content of the buffer is [ 84 ]

item 84 removed by a consumer.
The current content of the buffer is [ ]

item 30 inserted by a producer.
The current content of the buffer is [ 30 ]

item 95 inserted by a producer.
The current content of the buffer is [ 30 95 ]

item 30 removed by a consumer.
The current content of the buffer is [ 95 ]

