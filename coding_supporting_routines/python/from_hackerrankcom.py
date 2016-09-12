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
------------------------------------------------------------------------------------------------------------------

#.ljust(width)
#This method returns a left aligned string of length width.
>>> width = 20
>>> print 'HackerRank'.ljust(width,'-')
#HackerRank----------  

#.center(width)
#This method returns a centered string of length width.
>>> width = 20
>>> print 'HackerRank'.center(width,'-')
#-----HackerRank-----

#.rjust(width)
#This method returns a right aligned string of length width.
>>> width = 20
>>> print 'HackerRank'.rjust(width,'-')
#----------HackerRank

------------------------------------------------------------------------------------------------------------------
