<h1>GIT WORKFLOW:</h1>
<p> <ol>
<li>Fetch and merge changes from the remote;</li>
<li>Create a branch to work on a new project feature;</li>
<li>Develop the feature on your branch and commit your work;</li>
<li>Fetch and merge from the remote again (in case new commits were made while you were working);</li>
<li>Push your branch up to the remote for review;</li>
</ol> </p>



<h1> THE MOST FREQUENTLY USED GIT COMMANDS ARE:<h1>

<h3>to create a git a repository in an empty directory:</h3>
<code>git init</code>

<h3>tie the local repository to the remote repository:</h3>
<code>git remote add origin https://..</code>

<h3>add files or directories to the staging area:</h3>
<code>git add filename.txt directory_name</code>

<h3>see what is going to be commited:</h3>
<code>git status</code>

<h3>after adding the files to the staging area we can change the files and see the difference bw the staging area and files we changed:</h3>
<code>git diff</code>

<h3>commit changes to the local repository:</h3>
<code>git commit -m "message"</code>

<h3>see the history of commits</h3>
<code>git log</code>

<h3>commit to the remote repository:</h3>
<code>git push [origin master]</code>

<h3>after git command display everything the git log command displays for the HEAD commit, plus all the file changes that were committed:</h3>
<code>git show HEAD</code>

<h3>restore the file in your working directory to look exactly as it did when you last made a commit:</h3>
<code>git checkout HEAD filename</code>

<h3>resets the file in the staging area to be the same as the HEAD commit. It does not discard file changes from the working directory, it just removes them from the staging area:</h3>
<code>git reset HEAD filename</code>

<h3>rewind to the part before you made the wrong turn and create a new destiny for the project: </h3>
<code>git reset 5d69206</code>
 
<h3>find out what branch you are on:</h3>
<code>git branch</code>

<h3>create a new branch but stay ont the previous one:</h3>
<code>git branch branch_name</code>

<h3>switch to new branch:</h3>
<code>git checkout branch_name</code>

<h3>add changes from another branch to the current branch:</h3>
<code>git merge new_branch</code>

<h3>delete a branch:</h3>
<code>git branch -d branch_name</code>

<h3>show all the branches:</h3>
<code>git branch -a</code>

<h3>find out informaiton about all remote:</h3>
<code>git remote -v</code>


