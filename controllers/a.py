import re
# -*- coding: utf-8 -*-
# this file is released under public domain and you can use without limitations

#########################################################################
## This is a samples controller
## - index is the default action of any application
## - user is required for authentication and authorization
## - download is for downloading files uploaded in the db (does streaming)
## - call exposes all registered services (none by default)
#########################################################################


def index():
    """
    example action using the internationalization operator T and flash
    rendered by views/default/index.html or views/generic.html

    if you need a simple wiki simple replace the two lines below with:
    return auth.wiki()
    """
#response.flash = T("Welcome to web2py!")
#   return dict(message=T('Hello World'))
    redirect(URL('first'))

def user():
    """
    exposes:
    http://..../[app]/default/user/login
    http://..../[app]/default/user/logout
    http://..../[app]/default/user/register
    http://..../[app]/default/user/profile
    http://..../[app]/default/user/retrieve_password
    http://..../[app]/default/user/change_password
    use @auth.requires_login()
        @auth.requires_membership('group name')
        @auth.requires_permission('read','table name',record_id)
    to decorate functions that need access control
    """
    return dict(form=auth())


def download():
    """
    allows downloading of uploaded files
    http://..../[app]/default/download/[filename]
    """
    return response.download(request, db)


def call():
    """
    exposes services. for example:
    http://..../[app]/default/call/jsonrpc
    decorate with @services.jsonrpc the functions to expose
    supports xml, json, xmlrpc, jsonrpc, amfrpc, rss, csv
    """
    return service()

@auth.requires_signature()
def data():
    """
    http://..../[app]/default/data/tables
    http://..../[app]/default/data/create/[table]
    http://..../[app]/default/data/read/[table]/[id]
    http://..../[app]/default/data/update/[table]/[id]
    http://..../[app]/default/data/delete/[table]/[id]
    http://..../[app]/default/data/select/[table]
    http://..../[app]/default/data/search/[table]
    but URLs must be signed, i.e. linked with
      A('table',_href=URL('data/tables',user_signature=True))
    or with the signed load operator
      LOAD('default','data.load',args='tables',ajax=True,user_signature=True)
    """
    return dict(form=crud())

@auth.requires_login()
def upload():
    		db.project.fl.default=0
		form=SQLFORM(db.project)
		if form.process().accepted:
			response.flash='your project is added'
		return dict(form=form)
def first():
#   	flag=0
#	if request.args(0,cast=int)==1:
#		flag=1
    	d={}
    	if auth.user:
		redirect('users')
	us=db(db.auth_user.id>0).select(db.auth_user.id)
    	for i in range(0,len(us)):
	    	p=db(db.project.created_by==us[i]['id']).select(db.project.ALL)
		d[us[i]['id']]=len(p)
	d=sorted(d.keys(),key=lambda x:d[x])
	d.reverse()
	r=[]
	cat=db(db.project.id>0).select(db.project.ALL)
	l=db(db.project.id>0).select(db.project.ALL,orderby=~db.project.count_download)
    	co=db(db.project.id>0).select(db.project.ALL,orderby=~db.project.count_comment)
	rt=db(db.project.id>0).select(db.project.ALL,orderby=~db.project.count_rate)
	return dict(d=d,r=r,cat=cat,l=l,co=co,rt=rt)
def users():
    	p_share={}
    	share=db(db.collaborators.collaborator==db.auth_user[auth.user_id].email).select(db.collaborators.ALL)
	for i in range(0,len(share)):
	    r=db(db.project.id==share[i]['project_id']).select(db.project.ALL)
	    l=db(db.auth_user.id==r[0]['created_by']).select(db.auth_user.first_name)
	    p_share[l[0]['first_name']]=r
    	shw={}
    	grid={}
	lis={}
	frequest=db(db.friend.send_to==auth.user_id).select(db.friend.ALL)
	ffrequest=db(db.friend.send_by==auth.user_id).select(db.friend.ALL)
    	for i in frequest:
		if i['confirm']==0:
			name=db(db.auth_user.id==i['send_by']).select(db.auth_user.username)
			lis[name[0]['username']]=i['send_by']
		else:
			toshow=db(db.auth_user.id==i['send_by']).select(db.auth_user.ALL)
#shw.append(toshow[0]['username'])
			shw[i['send_by']]=toshow[0]['username']
	for i in ffrequest:
		if i['confirm']==1:
			tosh=db(db.auth_user.id==i['send_to']).select(db.auth_user.ALL)
#			shw.append(tosh[0])
			shw[i['send_to']]=tosh[0]['username']
    	if auth.user:
		flag=1
#grid=SQLFORM.smartgrid(db.project,a,csv=False,field_id=None)
		grid=db(db.project.created_by==auth.user_id).select(db.project.ALL)
	if request.vars.upload:
		redirect(URL('upload'))
    	r=[]
	return dict(shw=shw,lis=lis,frequest=frequest,grid=grid,r=r,p_share=p_share)

def show():
    temp=request.args(0,cast=int)
    l=db(db.project.id==temp).select(db.project.category)
    projct=db(db.project.category==l[0]['category']).select(db.project.ALL)
    return dict(l=l,projct=projct)

def user1():
    temp=request.args(0,cast=int)
    frm={}
#   downl=db(db.project.id==temp).select(db.project.project)
#down=downl[0]['project']
    nae=db(db.project.id==temp).select(db.project.Name)
    name=nae[0]['Name']
    if auth.user:	
	   db.ratecomment.email.readable=False
	   db.ratecomment.email.writable=False
    	   r=db(db.project.id==temp).select(db.project.created_by)
    	   l=r[0]['created_by']
    	   if l!=auth.user_id:
   			flag=1
   	   else:
          		flag=2
    else:
    	flag=0
    if flag==1:
    	db.ratecomment.created_by.default=auth.user_id
    form=SQLFORM(db.ratecomment)
    db.ratecomment.project_id.default=temp
    if form.process().accepted:
	response.flash='your comment is posted'
    	if flag!=2:
		myset2=db(db.project.id==temp)	
		com=db(db.project.id==temp).select(db.project.count_comment)
		cont=com[0]['count_comment']
		r=db(db.project.id==temp).select(db.project.count_rate)
		rt=r[0]['count_rate']
    		rat=((rt*(cont-1))+int(request.vars.rate))/(cont)
		myset2.update(count_rate=rat)
		myset2.update(count_comment=cont+1)
    comment=db(db.ratecomment.project_id==temp).select(db.ratecomment.ALL)
    return dict(temp=temp,name=name,flag=flag,form=form,comment=comment)
def download():
	myset=db(db.project.id==request.args[1])
	c=db(db.project.id==request.args[1]).select(db.project.count_download)
    	cn=c[0]['count_download']
	myset.update(count_download=cn+1)
    	redirect(URL('down',args=request.args[0]))
def down():
    	return response.download(request,db)
def profile():
    	return dict(form=auth.profile())
def search():
    	a=request.vars.search
	lis=[]
	nam=db(db.project.id>0).select(db.project.ALL)
	for i in range(0,len(nam)):
	    l=re.search(a,nam[i]['Name'])
	    lp=re.search(a,nam[i]['description'])
	    if l:
	    	lis.append(nam[i])
	    if lp:
		lis.append(nam[i])
	return dict(lis=lis)
def search2():
    a=request.vars.search
    nam=[]
    name=db(db.auth_user.id>0).select(db.auth_user.ALL)
    l=len(name)
    for i in range(0,l):
	mat=re.search(a,name[i]['first_name'])
	if mat:
	   nam.append(name[i])
    return dict(nam=nam)
def first2():
    	flag=1
    	temp=request.args(0,cast=int)
    	if auth.user_id==temp:
	    redirect(URL('first'))
	sendto=db((db.friend.send_to==temp)&(db.friend.send_to!=db.friend.send_by)).select(db.friend.ALL)
	sendauth=db((db.friend.send_to==auth.user_id)&(db.friend.send_to!=db.friend.send_by)).select(db.friend.ALL)
	for i in range(len(sendauth)):
	    if sendauth[i]['send_by']==temp:
	    	if sendauth[i]['confirm']==1:
	    		flag=3
	    		break
	    	else:
	    		flag=2
	    		break
	for i in range(len(sendto)):
	    if sendto[i]['send_by']==auth.user_id:
	    	if sendto[i]['confirm']==1:
	    		flag=3
	    		break
	    	else:
	    		flag=2
	    		break	
    	proj=db(db.project.created_by==temp).select(db.project.ALL)
	use=db(db.auth_user.id==temp).select(db.auth_user.ALL)
	return dict(sendauth=sendauth,use=use,flag=flag,proj=proj,temp=temp)
def insert():
    l1=request.args(0,cast=int)
    db.friend.insert(send_to=l1,send_by=auth.user_id,confirm=0)
    redirect(URL('first2',args=l1))
def confirm():
    t=request.args(0,cast=int)
    my=db((db.friend.send_by==t)&(db.friend.send_to==auth.user_id))
    my.update(confirm=1)
    response.flash='friend request accepted'
    redirect(URL(first))
def reject():
   	t=request.args(0,cast=int)	
    	db((db.friend.send_by==t)&(db.friend.send_to==auth.user_id)).delete()
	redirect(URL(first))
def dev():
    	temp=request.args(0,cast=int)
    	cur=db(db.folder.project_id==temp).select(db.folder.ALL)
    	c=[]
    	l=-1
    	for i in range(0,len(cur)):
		c.append(cur[i]['vers'])
	if len(c):
		l=max(c)
	cur_file=db((db.file_add.vers>=l)&(db.file_add.project_id==temp)&(db.file_add.fl3!=1)&(db.file_add.fl2!=1)).select(db.file_add.ALL)
    	col=db(db.collaborators.project_id==temp).select(db.collaborators.ALL)
    	name=db(db.project.id==temp).select(db.project.Name)
    	proj=db(db.project.id==temp).select(db.project.ALL)
    	return dict(proj=proj,name=name,col=col,cur=cur,cur_file=cur_file)
def delete():
    temp=request.args(0,cast=int)
    db(db.project.id==temp).delete()
    db(db.ratecomment.project_id==temp).delete()
    db(db.file_add.project_id==temp).delete()
    db(db.collaborators.project_id==temp).delete()
    db(db.folder.project_id==temp).delete()
    redirect(URL(first))
def add():
	temp=request.args(0,cast=int)
	dic=[]
	alr=db(db.collaborators.project_id==temp).select(db.collaborators.collaborator)
	for i in alr:
		dic.append(i['collaborator'])
	lis=[]
	frid=db(((db.friend.send_to==auth.user_id)|(db.friend.send_by==auth.user_id))&(db.friend.confirm==1)).select(db.friend.ALL)	
	for i in frid:
		if i['send_to']==auth.user_id :
			c=db.auth_user[i['send_by']].email
			if c  not in dic:
				lis.append(db.auth_user[i['send_by']].email)
		elif i['send_by']==auth.user_id:
			c=db.auth_user[i['send_to']].email
			if c  not in dic:
				lis.append(db.auth_user[i['send_to']].email)
	form=SQLFORM.factory(
	    Field('Choose_friend',requires=IS_IN_SET((lis)))
	    )
	if form.process().accepted:
		db.collaborators.insert(project_id=temp,collaborator=request.vars.Choose_friend)
		redirect(URL(add,args=temp))
	return dict(form=form)
def remove():
    	temp=request.args(0,cast=int)
	temp1=request.args(1,cast=int)
    	db(db.collaborators.id==temp).delete()
	redirect(URL(dev,args=temp1))
def file_add():
    temp=request.args(0,cast=int)
    cur=db(db.folder.project_id==temp).select(db.folder.ALL)
    c=[]
    l=0
    for i in range(0,len(cur)):
	c.append(cur[i]['vers'])
    if len(c):
	l=max(c)+1
#if l==3:
#   	db(db.file_add.vers==0).delete()
#   	for i in range(1,3):
#   		db(db.file_add.vers==i).update(vers=i-1)
#   	l-=1
    db.file_add.vers.default=l
    db.file_add.cou.default=session.count
    db.file_add.project_id.default=temp
    db.file_add.added_by.default=auth.user_id
    form=SQLFORM(db.file_add)
    if form.process().accepted:    	
    	redirect(URL('dev',args=temp))
    	response.flash='Added'
    return dict(form=form)
def delete_file():
    temp=request.args(0)
    temp1=request.args(1)
    db(db.file_add.id==temp).update(fl2=1)
    redirect(URL('dev',args=temp1))
def modify():
   	temp=request.args(0,cast=int)	
	db(db.file_add.fl2==1).delete()
	cur=db(db.folder.project_id==temp).select(db.folder.ALL)
	c=[]
	l=0
	flag=0
	for i in range(0,len(cur)):
	    c.append(cur[i]['vers'])
	if len(c):
		l=max(c)+1
	if l==3:
    		db((db.file_add.project_id==temp)&(db.file_add.vers==0)).delete()
    		db((db.file_add.project_id==temp)&(db.file_add.vers==1)).update(vers=0)
    		db((db.file_add.project_id==temp)&(db.file_add.vers==2)&(db.file_add.fl3!=1)).update(vers=1)
    		db((db.file_add.project_id==temp)&(db.file_add.vers==3)).update(vers=2)
#	db((db.file_add.project_id==temp)&(db.file_add.fl==1)).update(vers=1,fl=0)
    		
#	db(db.file_add.vers==0).delete()
#for i in range(1,3):
#   			db(db.file_add.vers==i).update(vers=i-1)
#l-=1
		db(db.folder.vers==2).delete()
    		db.folder.insert(project_id=temp,modified_by=auth.user,vers=2)
    		flag=1
		l=2
    	else:	
    		db(db.folder.vers==l).delete()
		db.folder.insert(project_id=temp,modified_by=auth.user,vers=l)
#if flag==1:
#		cur_file=db((db.file_add.project_id==temp)&(db.file_add.vers==(l))).select(db.file_add.ALL)
#   	else:
    	if flag==1:
		cur_file=db((db.file_add.project_id==temp)&(db.file_add.vers==1)&(db.file_add.fl!=1)).select(db.file_add.ALL)
    	else:
		cur_file=db((db.file_add.project_id==temp)&(db.file_add.vers==(l-1))&(db.file_add.fl3!=1)).select(db.file_add.ALL)
    		if l-1==0:
			db((db.file_add.fl==1)&(db.file_add.project_id==temp)).delete()	
    	for i in range(0,len(cur_file)):
	    	db.file_add.insert(project_id=temp,Name=cur_file[i]['Name'],new_file=cur_file[i]['new_file'],vers=l,added_by=auth.user_id,fl=0,fl2=0,fl3=0)
	db((db.file_add.project_id==temp)&(db.file_add.fl3==1)).update(fl3=0)
#	db((db.file_add.fl==1)&(db.file_add.project_id==temp)).delete()
	redirect(URL('dev',args=temp))
def downm():
    temp=request.args(0,cast=int)
    temp1=request.args(1)
    r=db((db.file_add.project_id==temp1)&(db.file_add.vers==temp)).select(db.file_add.new_file)
    for i in range(0,len(r)):	
    	redirect(URL('down',args=r[i]['new_file']))
def file_show():
    temp=request.args(0,cast=int)
    temp1=request.args(1)
    files=db((db.file_add.project_id==temp)&(db.file_add.vers==temp1)).select(db.file_add.ALL)
    return dict(files=files,temp=temp)
def edit_file():
    temp=request.args(0)
    temp1=request.args(1)
    c=db((db.file_add.id==temp)&(db.file_add.project_id==temp1)).select(db.file_add.ALL)
    db((db.file_add.id==temp)&(db.file_add.project_id==temp1)).update(fl3=1)
    db(db.file_add.fl==1).delete()
    db.file_add.Name.default=c[0]['Name']
    db.file_add.vers.default=c[0]['vers']
    db.file_add.fl.default=1
    db.file_add.project_id.default=temp1
    db.file_add.added_by.default=c[0]['added_by']
    db.file_add.modified_by.default=auth.user_id
    form=SQLFORM(db.file_add)
    if form.process().accepted:
    	response.flash='Your file is modified'
    	redirect(URL(dev,args=temp1))
    return dict(form=form)
    
