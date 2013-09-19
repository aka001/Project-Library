import os
dir_name=raw_input()
b=os.getcwd()
os.system('ls > f')
fo=open("f","r+")
l=fo.readlines()
count=0
for i in l:
	if os.path.isfile(b+"/"+i[0:len(i)-1]):
	    	print b+"/"+i[0:len(i)-1]
	elif os.path.isdir(b+"/"+i[0:len(i)-1]):
	    	os.chdir(b+"/"+i[0:len(i)-1])
		os.system('ls >'+' '+b+'/'+'f')
		print fo.readlines()
print count

