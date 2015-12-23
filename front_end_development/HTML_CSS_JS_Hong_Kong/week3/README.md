<h1>WEEK 3 LECTURE NOTES</h1>


<h2><u>FOR loops:</u></h2>
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


<h2><u>DOM structure:</u></h2>
<p>Document Object Model, each node in the DOm sctructure has the following properties</p>

<ul>
<li><code>nodeName</code></li>

<li><code>parentNode</code></li>

<li><code>childNodes[]</code></li>

<li><code>firstChild</code></li>

<li><code>lastChild</code></li>

<li><code>previousSibling</code></li>

<li><code>lastSibling</code></li>

</ul>