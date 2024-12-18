# Final Project
 Our Final Project

Introduction to Board Quest

Our journey begins with you ,The Player, and the most wonderful place in the world, Newark Liberty Airport. Your journey will not be an easy one, but I have faith that you will have the strength and courage to make it through this dastardly dungeon in one piece. Be safe and be swift ... because you have a plane to catch!!

To run on Windows:
1: Download the repository as a .zip file
2: Extract into any directory
3: Using CMake, for "Where is the source code", select the Final-Project-main as the source directory. (If this folder is layered with more Final-Project-main folders inside of one another, use the inner-most one)
4: Using CMake, for "Where to build binaries", create a new folder named "build" inside of the Final-Project-main folder that you chose for the previous step. Use this new build folder
5: Using CMake, bottom left corner, select "configure". Do not chose anything in the popup windows and just select "Finish".
5.5: If there is an error. Delete the build folder, close CMake, and start over from step 3. Instead of not chosing anything, in "Optional platform", select Win32
6: When configure is finished select "Generate" 
7: When Generate is finishged, select "open project"
8: If you have Visual Studio installed it will open it, if not install visual Studio.
9: In Visual Studio, press the hollow green arrow (not the filled-in one), and enjoy the game!

Unix (Mac/Linux): 
1: Unzip the file 
2: Open Cmake
3: Add the folder as the source
4: click the browse build option and create a build folder inside of the project folder 
5: Configure for Unix Makefiles
6: Open Terminal and cd into the build folder ex. cd /Users/RestOfPathname
6.5: The path can be found by opening the finder and holding option and right clicking the folder on mac
7: Input the make command and hit enter
8: This will create a unix exicutable file inside of the build file, find it and run
9: Enjoy our game
