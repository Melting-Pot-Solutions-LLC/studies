//: Playground - noun: a place where people can play

import UIKit

//declare a variable not specifying the type
var str = "Hello, playground"

//changing the variable value
str = "Yo-yo"

//declare a variable specifying the type
var name:String = "Steve Rubin"
var integer:Int = 4

//declaring a double
var c:Double = 5/2

//cast an integer to a double
c * Double(integer)

//concatinating a string
var new_string = "My son is " + String(integer) + " years old"

//excercise
var x = 3.5
var y = 4
var z = 3.5*4

//arrays
var arr = [1, 2, 3, 4, 5, 6, 7]

//indexing starts with 0
arr[0]

//append an element at the end of an array
arr.append(8)

//remove
arr.removeAtIndex(0)
arr.removeLast()
arr.removeRange(1...3)

//craete an emoty array
var emptyArray:[Int]

//dictionary
var dict = ["first name": "Steve", "last name": "Rubin", "age": 24]
print(dict["last name"])

// ! means unwrap - the programmer is sure the value for "last name" exists
print(dict["last name"]!)

//add to a dictionary
dict["favorite color"] = "orange"

//remove a value from a key 
dict["age"] = nil

//how to use an element of an dictionary
//var sentence = "My name is " + dict["first name"] // won't work
var first_name = "first name"
var sentence = "My name is \(dict[first_name]!)"

//some practice with arrays
var some_number = [2, 4, 6, 8]
some_number.removeFirst()
some_number.append(10)


//some practice with dictionaries
var my_info = ["name": "Steve Rubin", "age": 24]
var my_name = "name"
var my_age = "age"

var my_info_sentence = "my name is \(my_info[my_name]!) and my I am \(my_info[my_age]!) years old"


//IF statement
my_name = "Rob"
var time = 2

if(my_name == "Steve Rubin" && time < 12)
{
    print("yo-yo")
}
else
{
    print("oh, shit!")
}
