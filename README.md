# hw3
CSCI-104 HW3

Notes on recursion problems
- It passed valgrind when I deallocated the heads of the new lists created by the recursive functions in my main tester method using the 
  given deallocate function. If I did not deallocate the list with this function, it said that the heap still had memory blocks in use at exit.
- to run it, type make
- then type ./llrec-test <name of input file>

Notes on logic sim
To run the logic simulator:
1. Navigate to the logicsim folder
2. Type make
3. Type "./logicsim <name of txt file> > <name of uml file>"
4. Type "java -jar plantuml.jar <name of uml file from step 3>"
5. A png file with the same name as uml should have been created

Note on .png's:
Since my docker terminal couldn't run the java code, I had to make the .png files in Codio.
I downloaded the .png files from Codio, put them into my local desktop hw3 repository and pushed
them to Github from there.
