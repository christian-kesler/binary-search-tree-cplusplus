<html>
<h2><a target='blank' href="https://github.com/christian-kesler/junit-testing-java">Contact Service on GitHub</a></h2>
<hr>
<p>
The artifact I have chosen to showcase my Software Engineering and Design capabilities is the Contact Service Java application, which involves a group of Java classes and comprehensive Junit test cases that ensure class attributes abide by the specifications.  This artifact serves to showcase my competency with the Java programming language, the Eclipse IDE, object oriented programming, automated testing technical principles, and observation of programming best practices such as naming conventions and comment etiquette.  Considering that Java, Eclipse, and JUnit are widely used in software development, I find this artifact to be extremely worthy of inclusion in my portfolio.  
</p>

<h3>Description</h3>
<p>
This is a series of Java classes with various attributes that were designed around the specifications of the client.  There are three types of classes, each with constructors, getters, and setters as appropriate.  Each class type also has a corresponding Service class, which is designed to handle instances of the base class in a list format with a scaling ID number.  The classes communicate with each other in a variety of complex ways, and I incorporated JUnit tests that comprehensively ensure all interactions are handled properly.  Each of the six classes have a corresponding Junit test file, which have been run as coverage tests throughout development to ensure comprehensive testing is present.  The JUnit testing is thorough, offering multiple types of input and verifying expected behavior, both in nominal and exceptional cases.  The JUnit tests have been verified to cover all relevant lines of code with nearly 100% coverage project wide.  
</p>

<h4>Enhancement Progress</h4>

<p>
I have added a variety of consistent and descriptive comments throughout the Contact Service java classes and JUnit tests.  I also replaced many (if not all) of the hard coded strings and integers used in comparisons with descriptive variables that can be changed from one accessible location near the top of each file.  I found repeating error statements for incorrect input both in the constructor and setters quite troublesome.  While the client did not request such functionality, I chose to streamline this by creating a series of verifier methods that are passed input, check the validity of the input for a specific object attribute, and return true or false along with an error statement if applicable.  This allowed me to greatly simplify the constructor and setters by using this method as the condition within an if statement, assigning the value to the object if true.  
<br><br>

I did hope to create a loop that would run all the JUnit tests rather than listing them out individually, but that proved to be less efficient or practical than the current layout.  I was successful in condensing the class functions using the input verifier methods, and in improving the readability of all files with improved commenting strategies.  I am quite pleased with the progress that has been made thus far, but will likely continue to make small improvements should I have leftover time in later modules.  
</p>

<h4>Enhancement Reflection</h4>

<p>           
While enhancing this artifact for my ePortfolio, I realized that there was a surprising amount of variation regarding the format of the JUnit tests.  The service class tests had up to ten filler entries to test the constructor and manipulate in later tests, which was more than necessary.  Meanwhile, the regular class tests operated a single instance of the constructor each time, only handling a single object at a time.  This shouldn't be surprising given the nature of the service classes, which are meant to hold the appointment, task, and contact objects in lists.  It does make me wonder if a redesign for the service tests might be in order, so that the general pacing of the JUnit tests are similar across all files.  
<br><br>

I also noticed that some of the things I wanted to improve were already near their ideal state.  The class constructors, for example, had a series of if else branches that checked each input value for validity before creating the object and assigning the attributes.  I thought that was inefficient at a glance, hoping to streamline the input screening process.  While I was able to do so from a readability perspective, the actual program performance was not nearly as suboptimal as I thought.  The input must be checked for validity before being using to instantiate an object, else erroneous entries would not be handled.  Realizing this, I instead focused on improving readability and code compactness while minimizing repeated statements, which proved quite rewarding.  
</p>

<h3>Getting Started</h3>
<h4>Dependencies</h4>
<ul>
<li>
Windows 10* || <a target='blank' href='https://www.microsoft.com/en-us/software-download/windows10'>Link to Download Windows</a>
</li>
<li>
Eclipse IDE for Java Developers 2021-12 || <a target='blank' href='https://www.eclipse.org/downloads/packages/release/2021-03/r/eclipse-ide-java-developers'>Link to Download Eclipse</a>
</li>
<li>
JUnit 4 Library || <a target='blank' href='https://qualitestgroup.com/insights/technical-hub/how-to-set-up-junit-in-eclipse/'>Setup Guide</a>
</li>
</ul>
<p><i>*potentially not required, but it is what I used and therefore know for certain that it works</i></p>

<h4>Installing</h4>
<ul>
<li>
Download the Project Files from the SNHU_CS-320_JUnit-Testing Repository on GitHub || <a target='blank' href='https://github.com/christian-kesler/junit-testing-java'>Link to Repository</a>
</li>
<li>
Cloning the Repository via Git is ideal, but downloading a zip and extracting it will also work || <a target='blank' href='https://git-scm.com/downloads'>Link to Download Git</a>
</li>
</ul>

<h4>Executing Program</h4>
<ul>
<li>You can create a new Java project in Eclipse using existing project files, create an empty project and move the project files into the new directory, manually, or create an empty project and clone directly to that folder using Git</li>
<li>Compile and Build the project; there should be no errors</li>
<li>Right click on the Test folder under src > contact > services and select "Run as Coverage Tests"</li>
<li>The Coverage tab will highlight the lines of code that were executed in green, while the lines that were not executed will be highlighted in red</li>
</ul>

<h3>Help</h3>
<p>
Most of the issues I ran into with this program involve setting up the JUnit library and getting the first tests laid out.  This video goes over JUnit in Eclipse and general setup, which I found helpful.  The information I found most relevant starts at the 9:00 timestamp.  
<ul>
<li>
<a target='blank' href='https://www.youtube.com/watch?v=BOHs67tC-QE&ab_channel=Simplilearn'>JUnit Installation & Eclipse Environement Setup How To Install JUnit JUnit Tutorial Simplilearn</a>
</li>
</ul>
</p>

<h3>Authors</h3>
<p>
Christian Kesler (a.k.a. KnowOne), who can be found on <a target='blank' href='https://github.com/christian-kesler'>GitHub</a> and <a target='blank' href='https://www.linkedin.com/in/christian-kesler/'>LinkedIn</a>
</p>

<h3>Version History</h3>
<ul>
<li>
v1.0.0
<ul>
<li>
Initial Release upon completion of the CS-320 course at Southern New Hampshire University
</li>
<li>
See commit change or See release history
</li>
</ul>
</li>
<li>
v1.1.0
<ul>
<li>
Enhanced Revision created during the CS-499 course at Southern New Hampshire University
</li>
</ul>
</li>
</ul>

<h3>License</h3>
<p>
This project is licensed under the MIT License - see the LICENSE.md file for details
</p>

<h3>Acknowledgements</h3>
Inspiration, code snippets, etc.
<ul>
<li>
Southern New Hampshire University, Computer Science 320:  Software Test, Automation, & Quality Assurance
</li>
<li>
<a target='blank' href='https://gist.github.com/DomPizzie/7a5ff55ffa9081f2de27c315f5018afc'>README Template</a>
</li>
</ul>
</html>
