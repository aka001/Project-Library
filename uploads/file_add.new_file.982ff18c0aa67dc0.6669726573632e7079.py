test=input()
while test!=0:
	eandf=raw_input()
        eandf=eandf.split(' ')
	e=int(eandf[0])
        f=int(eandf[1])
        a=[]
    	while f!=0:
		flag=0
		frnd=raw_input()
    		frnd=frnd.split(' ')
    		for i in a:
			if frnd[0] in i:
				if frnd[1] not in i:
					i.append(frnd[1])
    				flag=1
				break
		if flag==0:
			a.append(frnd)
		f-=1
	l=len(a)
	for i in range(1,e+1):
	    fl=0
	    j=0
	    while j<l:
	    	if str(i) in a[j]:
	    		fl=1
	    		break
	    	j+=1
	    if fl==0:
	    	a.append(str(i))
	l=len(a)
   	m=1
    	for i in range(0,l):
	    m=(m*len(a[i]))%1000000007
	print l,m
	test-=1
