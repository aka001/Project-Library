import re
import os
print "enter the file name"
file_name=raw_input()
print "enter the pattern:"
pattern=raw_input()
f=open(file_name,"r")
d=f.read();
match=re.search(pattern,d)
if match:
	print match.group()
else :
	print "Not found"
