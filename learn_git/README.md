<h1> the most frequnelty used gut commmands are:<h1>

<h3>to create a git a repository in an empty directory
git init

//tie the local repository to the remote repository
git remote add origin https://...

// add files or directories to the staging area
git add filename.txt directory_name

// see what is going to be commited
git status

//after adding the files to the staging area we can change the files and see the difference bw the staging area and files we changed
git diff

//commit changes to the local repository
git commit -m "message"

//see the history of commits
git log

//commit to the remote repository
git push [origin master]

//after git command
//display everything the git log command displays for the HEAD commit, 
//plus all the file changes that were committed.
git show HEAD

//restore the file in your working directory to look exactly as it 
//did when you last made a commit.
git checkout HEAD filename

//resets the file in the staging area to be the same as the HEAD commit.
//It does not discard file changes from the working directory, 
//it just removes them from the staging area.
git reset HEAD filename

//rewind to the part before you made the wrong turn and create a new 
/destiny for the project. 
git reset 5d69206
 
//find out what branch you are on
git branch

//create a new branch but stay ont the previous one
git branch branch_name

//switch to new branch
git checkout branch_name

//add changes from another branch to the current cbranch
git merge new_branch

//delete a branch
git branch -d branch_name

//show all the branches
git branch -a

//find out informaiton about all remote   
git remote -v

/*
The workflow for Git collaborations typically follows this order:
1. Fetch and merge changes from the remote
2. Create a branch to work on a new project feature
3. Develop the feature on your branch and commit your work
4. Fetch and merge from the remote again (in case new commits were made while you were working)
5. Push your branch up to the remote for review
*/
