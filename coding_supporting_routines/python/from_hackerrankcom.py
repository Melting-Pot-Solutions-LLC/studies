# textwrap.wrap() 
# The wrap() function wraps a single paragraph in text (a string) so that every line is width characters long at most. 
# It returns a list of output lines.

>>> import textwrap
>>> string = "This is a very very very very very long string."
>>> print textwrap.wrap(string,8)
['This is', 'a very', 'very', 'very', 'very', 'very', 'long', 'string.'] 
# textwrap.fill() 
# The fill() function wraps a single paragraph in text and returns a single string containing the wrapped paragraph.
#
>>> import textwrap
>>> string = "This is a very very very very very long string."
>>> print textwrap.fill(string,8)
# This is
# a very
# very
# very
# very
# very
# long
# string.
