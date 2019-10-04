# Django
## Command-line
`python -m django --version` 
  check version of django, if installed
`django-admin startproject {projectname}` 
  start a new project within the CWD; creates an outer and inner directory, both named {projectname}
`py manage.py runserver` 
  start Django development server
`py manage.py startapp {appname}`
  start a new application, creating a new directory named {appname}
## Sources
[Django 2 By Example](https://www.packtpub.com/application-development/django-2-example)
[Django tutorial](https://docs.djangoproject.com/en/2.1/intro/tutorial01/)
## startproject
files created:
`manage.py` 
  ommand-line utility that allows for interaction with the Django project
`{projectname}/__init__.py` 
  empty file that tells Python the directory should be considered a package
`{projectname}/settings.py`
`{projectname}/urls.py` 
  URL declarations: a table of contents
`{projectname}/wsgi.py` 
  entry-point for WSGI-compatible web servers
## startapp
files created:
`{appname}/admin.py`
`{appname}/apps.py`
`{appname}/migrations/__init__.py`
`{appname}/models.py`
`{appname}/tests.py`
`{appname}/views.py`