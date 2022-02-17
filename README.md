<html>
<h2><a target='blank' href="https://github.com/christian-kesler/binary-search-tree-cplusplus">Binary Search Tree on GitHub</a></h2>
<hr>
<p>
The artifact I have chosen to showcase my Algorithms and Data Structure capabilities is the Binary Search Tree C++ program, which involves a series of algorithms that import data from a CSV file and store the entries in a binary search tree data structure.  This artifact serves to showcase my competency with the C++ programming language, the Microsoft Visual Studio IDE, object oriented programming, data structure and algorithm principles, and observation of programming best practices such as naming conventions and comment etiquette.  Considering that C++ is a challenging language with relatively unique syntax and technical complexity used in a variety of mathemtically demanding programs, and that data structures and algorithms are used in staggeringly large number of applications, I would say with confidence that this project is worthy of inclusion in my portfolio.  
</p>

<h3>Description</h3>
<p>
This project was created during my Bachelor's of Science (Computer Science) degree program at Southern New Hampshire University.  There are two main files involved, one of which is a CSV Parser that allows us to easily pull data from a CSV file (I did not develop this program, it was provided by my university), and the other is an algorithm that utilizes the CSV Parser to import the data into a binary search tree data structure.  The program includes a command prompt line that executes different functions based on user input, which include importing all the data in a sample CSV file, printing all the entries loaded in the data structure, searching the data structure for a specific entry based on a preset identifier, deleting a specific entry based on a preset identifier, deleting all the entries in the data structure, and exiting the program.  This program was developed by me throughout a course titled "Data Structures and Algorithms", which was a notably memorable course of mine.  I've given a fair bit of thought to the concept of binary search trees, their relationship to linked lists, and how to mathematically calculate their performance.            
</p>

<h4>Enhancement Progress</h4>
<p>
As with my other artifacts, the first element of this project that I tended to was the comment etiquette.  The comments were vague, inconsistent, and sometimes entirely absent throughout this program.  I began by adding descriptions for each of the methods, including input clarification and recursive designation.  In the main method, I included comments that describe the nature of the clock computations so that the exact functionality of each case might be easier to discern.  
<br><br>
After improving the comments throughout, I turned to expanding or improving on the functionality of the program.  I began by including the clock statements across all cases, and improving the readability of said satatements.  I then created a destructor for the binary search tree, which is a recursive function that deletes every node in the tree before creating a new empty tree to avoid reading errors.  The destructor serves only to pass the root to the method that destroys the entire tree.  While I could have simply made a function that destroys the tree from the root and called that, I wanted to leave my methods open ended so that I might use them to delete portions of the tree later on should I need to do so.  
</p>

<h4>Enhancement Reflection</h4>
<p>
While enhancing this artifact, I realized that the binary search tree is remarkably simple to manipulate and interact with once the recursive functions are handled.  The most complex thing that I might try to do besides creating a more dynamic menu interface would be a function that rebalances the tree.  This would not be an insurmountable task, but I intend to only focus on something so difficult to develop and test after all my artifacts are in an acceptable state.  The other thing that I noticed while enhancing this artifact involved the file that the default data is loaded from.  I began to wonder how I might be able to load from a specific file through the menu after program execution, and doubt it would be remarkably complicated.  The ability to pass in a file path upon command line execution of the program serves that purpose for now, but I do have ideas regarding future enhancements.  
</p>

<h3>Getting Started</h3>
<h4>Dependencies</h4>
<ul>
<li>
Windows 10* || <a target='blank' href='https://www.microsoft.com/en-us/software-download/windows10'>Link to Download Windows</a>
</li>
<li>
Visual Studio 2019 || <a target='blank' href='https://visualstudio.microsoft.com/downloads/'>Link to Download Visual Studio</a>
</li>
</ul>
<p><i>*potentially not required, but it is what I used and therefore know for certain that it works</i></p>

<h4>Installing</h4>
<ul>
<li>
Download the Project Files from the Project Repository on GitHub || <a target='blank' href='https://github.com/christian-kesler/binary-search-tree-cplusplus'>Link to Repository</a>
</li>
<li>
Cloning the Repository via Git is ideal, but downloading a zip and extracting it will also work || <a target='blank' href='https://git-scm.com/downloads'>Link to Download Git</a>
</li>
</ul>

<h4>Executing Program</h4>
<ul>
<li>You can create a new project in Visual Studio using existing project files, create an empty project and move the project files into the new directory, manually, or create an empty project and clone directly to that folder using Git</li>
<li>Navigate to and open the BinarySearchTree.cpp file from within Visual Studio</li>
<li>Pressing f5 will compile and run the program, showing a command prompt window with an input menu</li>
<li>Follow the menu options by typing the number corresponding to the command you want to execute and pressing enter to load, print, find, delete, or exit the program
<ul>
<li>For example, press "9" followed by "Enter" to close the command prompt window</li>
</ul>
</li>
</ul>

<h3>Help</h3>
<p>
Most of the issues I ran into with this program involve creating the actual binary search tree, but I also had some issues with Visual Studio since I find it to be the least intuitive IDE I've used thus far.  This video helps go over Visual Studio basics and familiarity, which helped me a great deal.  
<ul>
<li>
<a target='blank' href='https://www.youtube.com/watch?v=u2mExOej_DE&ab_channel=Hacked'>Visual Studio 2019 (Full Download and Installation) Getting Started</a>
</li>
</ul>
</p>

<h3>Authors</h3>
<p>
Christian Kesler (a.k.a. KnowOne), who can be found on <a target='blank' href='https://github.com/christian-kesler'>GitHub</a> and <a target='blank' href='https://www.linkedin.com/in/christian-kesler/'>LinkedIn</a>.  
</p>

<h3>Version History</h3>
<ul>
<li>
<a target='blank' href='https://github.com/christian-kesler/binary-search-tree-cplusplus/releases/tag/v1.0.0'>v1.0.0</a>
<ul>
<li>
Initial Release upon completion of the CS-260 course at Southern New Hampshire University
</li>
</ul>
</li>
<li>
<a target='blank' href='https://github.com/christian-kesler/binary-search-tree-cplusplus/releases/tag/v1.1.0'>v1.1.0</a>
<ul>
<li>
Enhanced Revision created during the CS-499 course at Southern New Hampshire University
</li>
</ul>
</li>
<li>
<a target='blank' href='https://github.com/christian-kesler/binary-search-tree-cplusplus/releases/tag/v1.2.1'>v1.2.1</a>
<ul>
<li>
ePortfolio Release containing my final enhancements for use within the CS-499 Computer Science Capstone course
</li>
</ul>
</li>
</ul>

<h3>License</h3>
<p>
This project is licensed under the MIT License - see the LICENSE.md file for details.  
</p>

<h3>Acknowledgements</h3>
Inspiration, code snippets, etc.
<ul>
<li>
Southern New Hampshire University, Computer Science 260:  Data Structures and Algorithms
</li>
<li>
<a target='blank' href='https://gist.github.com/DomPizzie/7a5ff55ffa9081f2de27c315f5018afc'>README Template</a>
</li>
</ul>
</html>
