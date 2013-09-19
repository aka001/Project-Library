# -*- coding: utf-8 -*-

#########################################################################
## This scaffolding model makes your app work on Google App Engine too
## File is released under public domain and you can use without limitations
#########################################################################

## if SSL/HTTPS is properly configured and you want all HTTP requests to
## be redirected to HTTPS, uncomment the line below:
# request.requires_https()

if not request.env.web2py_runtime_gae:
	## if NOT running on Google App Engine use SQLite or other DB
    db = DAL('sqlite://storage.sqlite',pool_size=1,check_reserved=['all'])
else:
	## connect to Google BigTable (optional 'google:datastore://namespace')
    db = DAL('google:datastore')
    ## store sessions and tickets there
    session.connect(request, response, db=db)
    ## or store session in Memcache, Redis, etc.
    ## from gluon.contrib.memdb import MEMDB
    ## from google.appengine.api.memcache import Client
    ## session.connect(request, response, db = MEMDB(Client()))

## by default give a view/generic.extension to all actions from localhost
## none otherwise. a pattern can be 'controller/function.extension'
response.generic_patterns = ['*'] if request.is_local else []
## (optional) optimize handling of static files
# response.optimize_css = 'concat,minify,inline'
# response.optimize_js = 'concat,minify,inline'

#########################################################################
## Here is sample code if you need for
## - email capabilities
## - authentication (registration, login, logout, ... )
## - authorization (role based authorization)
## - services (xml, csv, json, xmlrpc, jsonrpc, amf, rss)
## - old style crud actions
## (more options discussed in gluon/tools.py)
#########################################################################

from gluon.tools import Auth, Crud, Service, PluginManager, prettydate
auth = Auth(db)

#auth.settings.extra_fields['auth_user']=[Field('Photo','upload')]
auth.settings.extra_fields['auth_user']=[Field('User_Type','string',requires=IS_IN_SET(['Admin','user']))]
crud, service, plugins = Crud(db), Service(), PluginManager()

## create all tables needed by auth if not custom tables
auth.define_tables(username=True, signature=False)#,registration_key=False)
## configure email
mail = auth.settings.mailer
mail.settings.server = 'logging' or 'smtp.gmail.com:587'
mail.settings.sender = 'you@gmail.com'
mail.settings.login ='username:password'

## configure auth policy
auth.settings.registration_requires_verification = False
auth.settings.registration_requires_approval = False
auth.settings.reset_password_requires_verification = True
## if you need to use OpenID, Facebook, MySpace, Twitter, Linkedin, etc.
## register with janrain.com, write your domain:api_key in private/janrain.key
from gluon.contrib.login_methods.rpx_account import use_janrain
use_janrain(auth, filename='private/janrain.key')

#########################################################################
## Define your tables below (or better in another model file) for example
##
## >>> db.define_table('mytable',Field('myfield','string'))
##
## Fields can be 'string','text','password','integer','double','boolean'
##       'date','time','datetime','blob','upload', 'reference TABLENAME'
## There is an implicit 'id integer autoincrement' field
## Consult manual for more options, validators, etc.
##
## More API examples for controllers:
##
## >>> db.mytable.insert(myfield='value')
## >>> rows=db(db.mytable.myfield=='value').select(db.mytable.ALL)
## >>> for row in rows: print row.id, row.myfield
#########################################################################

## after defining tables, uncomment below to enable auditing
# auth.enable_record_versioning(db)
#db.define_table('sign_up',
#		Field('username', length=128, notnull=True, unique=True),
#		Field('password', 'password', label='Password',readable=False),
#		Field('email','string',requires=IS_EMAIL()),
#		Field('name','string',notnull=True),
#		Field('age','integer'),
#		Field('gender','string',requires=IS_IN_SET(['Male','Female']),default='Male',widget=SQLFORM.widgets.radio.widget),
#		Field('address', 'text'),
#		Field('phone', 'string'),
#		Field('photo','upload'),
#		Field('date1','datetime',default=request.now))
db.define_table('project',
		Field('Name','string',notnull=True,unique=True),
		Field('category','string',requires=IS_IN_SET(['mobile_applications','games','communications','Development','Science & Engineering','Security & Utilities','Graphics','Audio & Video'])),
		Field('project_type','string',requires=IS_IN_SET(['b.tech','m.tech','m.s'])),
		Field('description','text',notnull=True),
		Field('created_by','integer',default=auth.user_id,readable=False,writable=False),
		Field('count_download','integer',default=1,readable=False,writable=False),
		Field('count_comment','integer',default=1,readable=False,writable=False),
		Field('count_rate','integer',default=0,readable=False,writable=False),
		Field('fl','integer',default=0,readable=False,writable=False)
		)
db.define_table('ratecomment',
	Field('created_by','integer',readable=False,writable=False),
	Field('project_id','reference project',readable=False,writable=False),
	Field('email','string',requires=IS_EMAIL()),
	Field('rate','integer',notnull=True),
	Field('comments','text',notnull=True)
	)
db.define_table('friend',
	Field('send_by','integer'),
	Field('send_to','integer'),
	Field('confirm','integer',default=0)
	)
db.define_table('collaborators',
	Field('project_id','integer'),
	Field('collaborator','string')
	)
db.define_table('folder',
	Field('vers','integer',default=0,readable=False,writable=False),
	Field('modified_by','integer',readable=False,writable=False),
	Field('project_id','integer',readable=False,writable=False)
	)
db.define_table('file_add',
	Field('project_id','integer',readable=False,writable=False),
	Field('Name','string',unique=True),
	Field('new_file','upload'),
	Field('added_by','integer',readable=False,writable=False),
	Field('vers','integer',readable=False,writable=False),
	Field('cou','integer',default=1,readable=False,writable=False),
	Field('modified_by','integer',readable=False,writable=False),
	Field('fl','integer',default=0,readable=False,writable=False),
	Field('fl2','integer',default=0,readable=False,writable=False),
	Field('fl3','integer',default=0,readable=False,writable=False)
	)
db.project.id.readable=False
db.project.id.writable=False
