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


<h1>YouTube <a href="https://www.youtube.com/channel/UCLwG2LUXE5-o5q-8uvlV1ig">class</a> on git</h1>

<h2>Edit .gitignore</h2>

<h3>ignore folders</h3>
<code>logs/</code>

<h3>ignore particular files in a folder</h3>
<code>logs/*.txt</code>

<h3>show which files/folders are chagned but not commited</h3>
<code>git status</code>

<h3>show which files (only files, not folders) are chagned but not commited </h3>
<code>git status --untracked-files=all</code>

<h3><b>ALWAYS RUN GIT STATUS</b></h3>

<h3>recursively add all files in the current folder</h3>
<code>git add .</code>

<h3>commit added files</h3>
<code>git commit -m "comment"</code>

<h3>commit all files (added, and ones were changed but not added)</h3>
<code>git commit -a -m "comment"</code>

<h3><b>if a file was modified incorrectly, get back to last indexed version</b></h3>
<code>git checkout file.txt</code>

<h3>changing logs</h3>
<code>git log</code>

<h3>changing logs (formatted version)</h3>
<code>git log --pretty=format:" %h - %an, %ar: %s"</code>
<p>%h - last 8 letters of a commit; %an - author; %ar - time, %s - comment</p>

<h3>show commits within last 2 weeks</h3>
<code>git log --since=2.weeks</code>


<h3>show changes along with the commits</h3>
<code>git log -p -2</code>

<h2>Branhces</h2>
<h3>create a new branch and switchto it:</h3>
<code>git checkout -b new_branch_name</code>

<h3>create a new branch, but do not switch to it:</h3>
<code>git branch new_branch_name</code>

<h3>switch to an existing branch:</h3>
<code>git checkout existing_branch_name </code>

<h2>Merging branches</h2>
<h3>set up the merge conflict resolving tool to use (kdiff3)</h3>
<code>git config --global merge.tool kdiff3 </code>

<h3>merge some_branch to your currecnt branch</h3>
<code>git merge some_branch</code>

<h3>run merge problems resolution tool</h3>
<code>git mergetool</code>
