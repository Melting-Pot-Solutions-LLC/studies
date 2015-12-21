<h1> the most frequnelty used gut commmands are:<h1>

<h3>to create a git a repository in an empty directory:</h3>
<p>git init</p>

<h3>tie the local repository to the remote repository:</h3>
<p>git remote add origin https://..</p>

<h3>add files or directories to the staging area:</h3>
<p>git add filename.txt directory_name</p>

<h3>see what is going to be commited:</h3>
<p>git status</p>

<h3>after adding the files to the staging area we can change the files and see the difference bw the staging area and files we changed:</h3>
<p>git diff</p>

<h3>commit changes to the local repository:</h3>
<p>git commit -m "message"<p>

<h3>see the history of commits</h3>
<p>git log<p>

<h3>commit to the remote repository:</h3>
<p>git push [origin master]<p>

<h3>after git command display everything the git log command displays for the HEAD commit, plus all the file changes that were committed:</h3>
<p>git show HEAD<p>

<h3>restore the file in your working directory to look exactly as it did when you last made a commit:</h3>
<p>git checkout HEAD filename<p>

<h3>resets the file in the staging area to be the same as the HEAD commit. It does not discard file changes from the working directory, it just removes them from the staging area:</h3>
<p>git reset HEAD filename<p>

<h3>rewind to the part before you made the wrong turn and create a new destiny for the project: </h3>
<p>git reset 5d69206<p>
 
<h3>find out what branch you are on:</h3>
<p>git branch<p>

<h3>create a new branch but stay ont the previous one:</h3>
<p>git branch branch_name<p>

<h3>switch to new branch:</h3>
<p>git checkout branch_name<p>

<h3>//add changes from another branch to the current branch:</h3>
<p>git merge new_branch<p>

<h3>//delete a branch:</h3>
<p>git branch -d branch_name<p>

<h3>//show all the branches:</h3>
<p>git branch -a<p>

<h3>//find out informaiton about all remote:<h3>
<p>git remote -v<p>s

/*
The workflow for Git collaborations typically follows this order:
1. Fetch and merge changes from the remote
2. Create a branch to work on a new project feature
3. Develop the feature on your branch and commit your work
4. Fetch and merge from the remote again (in case new commits were made while you were working)
5. Push your branch up to the remote for review
*/
