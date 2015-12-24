<h1><center>WEEK 3 LECTURE NOTES</center></h1>


<h2><u>FOR LOOPS</u></h2>
<h3>3 ways to write for loops</h3>
<ul>
<li><code>
for (var index = 0; index context.length; index++)
{
	//...
}
</code></li>
<li><code>
var person = {initials:"DR", age:40 job:"Salesperson"};
for (var property in person)
{
	//...
}
</code></li>
<li><code>
var continents = ["Australia", "Africa", "Eurasia"];
for (var continent in continents)
{
	//...
}
</code></li>
<li><code>
for (;;) // infinite loop
</code></li>
</ul>


<h2><u>ARRAYS</u></h2>
<code>var pets = ["Dog", "Cat", "Rabbit", "Hamster"]</code>
<ul>
<li><code>
pets.sort(); // sort an array
</code></li>

<li><code>
pets.reverse(); // reverse an unsorted array
</code></li>

<li><code>
pets.indexOf("Cat"); //-> 1
</code></li>

<li><code>
pets.indexOf("Rabbit", 3); // 3 means a posiiton where to start searching 
</code></li>

<li><code>
pets.lastIndexOf("Rabbit"); // starts searching from the end
</code></li>

<li><code>
pets.slice(1); //-> returns ["Cat", "Rabbit", "Hamster"]
</code></li>

<li><code>
pets.slice(1,3); //-> returns ["Cat", "Rabbit"]
</code></li>

<li><code>
pets.splice(1, 2); //-> removes 2 elements starting from position 1 and returns only removed elements
</code></li>

<li><code>
pets.splice(2, 0, "Rabbit"); //-> removes 0 elements starting from position 2, add "Rabbit" and returns only removed elements -> []
</code></li>

<li><code>
pets.splice(1, 1, "Cat", "Fish"); //-> removes 1 elements starting from position 1, add "Cat", "Fish" and returns only removed elements -> []
</code></li>

<li>This code: <br>
<code>
for(var i = 0; i < pets.length; i++) {alert(pets[i]);}
</code><br>
can be replaced with this:<br>
<code>
pets.forEach(alert);
</code><br>
or this<br>
<code>
var numbers = [1, 2, 3, 4, 5];
</code><br>
<code>
numbers.forEach(fuciton (elem, idx, arr) {arr[idx] = elem*elem});
</code>
</li>

<li>
<code>var square = function(el) {return el*el;}</code><br>
<code>var numbers = [1,2,3,4,5]</code><br>
<code>var result = numbers.map(square);</code>
</li>
</ul>


<h2><u>DOM STRUCTURE</u></h2>
<p>Document Object Model, each node in the DOM sctructure has the following properties</p>

<ul>
<li><code>nodeName</code></li>
<li><code>parentNode</code></li>
<li><code>childNodes[]</code></li>
<li><code>firstChild</code></li>
<li><code>lastChild</code></li>
<li><code>previousSibling</code></li>
<li><code>lastSibling</code></li>
</ul>

<p>How can we locate an exact node in the DOM structure</p>
<ul>
<li>
Use the exact path. But the DOM strutcture can be diffenrent depending on the browser <br>
<code>document.childNodes[0].childNodes[2].childNodes[1]
    .setAttribute("style", "color:red");</code>
</li>
<li>Get the element by the tag name. However, it is difficult to do if there are more than one element of the same type<br>
<code>
document.getElementsByTagName("h2")[0]
.setAttribute("style", "color:yellow");
</code>
</li>
<li><b>BEST WAY: </b>Find an element using its ID.<br>
<code>  document.getElementById("cute_text")
    .setAttribute("style", "color:blue");</code></li>
</ul>

<p>How to create nodes:</p>
<ul>
<li><code>newItem = document.createElement("hr");</code></li>
<li><code>result = document.createTextNode("Hello");</code></li>
</ul>
<p>How to add nodes:</p>
<ul>
<li><code>result=document.createTextNode("This is dynamically added Text!");</code><br><code>
document.getElementById("my_text").appendChild(result);</code></li>
</ul>

<p>How to delete a node (with all the children):</p>
<ul>
<li>
<code>this_node=getElementById("myPara");</code><br>
<code>this_node.parentNode.removeChild(this_node);</code><br>
</li>

<li>
<code>var the_node=document.getElementById("firstP");</code><br>
<code>the_node.parentNode.removeChild(the_node);</code><br>
</li>

<li>
<code>var the_node=document.getElementsByTagName("p")[0];</code><br>
<code>the_node.parentNode.removeChild(the_node);</code><br>
</li>

<li>
<code>var the_parent=document.getElementById("theBody");</code><br>
<code>the_parent.removeChild(the_parent.firstChild);</code><br>
</li>
</ul>
<p>How to delete all the children of a node:</p>
<ul>
<li>
<code>var theNode = document.getElementById("theBody");</code><br>
<code>while (theNode.firstChild) theNode.removeChild(theNode.firstChild);</code><br>
</li>
</ul>

<p>How to copy a node (without children):</p>
<code>var the_node=document.getElementById("myList").lastChild;</code><br>
<code> var the_clone=the_node.cloneNode();</code><br>
<code>document.getElementById("myList").appendChild(the_clone);</code><br>

<p>How to copy a node (with children):</p>
<code>var the_node=document.getElementById("myList").lastChild;</code><br>
<code> var the_clone=the_node.cloneNode(true);</code><br>
<code>document.getElementById("myList").appendChild(the_clone);</code><br>

<h2><u>MOUSE EVENTS</u></h2>
<ul>
<li><code>onclick </code> - when a user clicks on an object</li>
<li><code>onmousedown</code> - when a person pushes and holds the mosue button </li>
<li><code>onmouseup</code> - when a user unhilds the mouse  button</li>
<li><code>onmouseover</code> - when a user navigates a mouse over an object</li>

<li><code>onmouseout</code> - when a user moves the mouse out of an object</li>
</ul>

<p>Some examples:</p>
<code>function change_colour( new_colour ) {document.getElementById("myDiv").style.background=new_colour;}
onmouseover="change_colour('red')";
onmouseout="change_colour('yellow')";
</code>

<h2><u>TIMERS</u></h2>
<p>How to create and start a timer which execute a function only once (after 1 second):</p>
<code>var the_timer;</code><br>
<code>the_timer=setTimeout(do_something, 1000);</code><br>


<p>How to stop such timer:</p>
<code>clearTimeout(the_timer);</code>

<p>How to create and start a timer which execute the function repeeatedly over and over again:</p>
<code>var the_timer;</code>
<code>the_timer=setInterval(do_something, 2000);</code>

<p>How to stop such timer:</p>
<code>clearInterval(the_timer);</code>


<h2><u>EVENTS</u></h2>
<p>How to add an event handler:</p>
<code>function do_something() { alert("Page has loaded") }</code><br>
<code>window.onload = do_something;</code>

<p>or</p>
<code>function do_something() { alert("Page has loaded") }</code><br>
<code>window.addEventListener("load", do_something);</code>

<p>How to remove an event handler</p>
<code>var theBody = document.getElementById("theBody");</code><br>
<code>theBody.removeEventListener("load", do_something);</code>
